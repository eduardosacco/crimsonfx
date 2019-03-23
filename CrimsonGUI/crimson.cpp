//--------------------------------------------------------------------------------------------------
//              CRIMSON.CPP
//--------------------------------------------------------------------------------------------------

//#define RPI
#include "crimson.h"
#include <QDebug>

Crimson::Crimson(QObject *parent) :
    QObject(parent)
{
    qDebug() << "CRIMSON FX 2018";
    qDebug() << "Config File in: " << crimsonSettings.fileName() << endl;
    qDebug() << "Debug Log:";

    timer = new QTimer();

    mainWindow = new MainWindow();

    connect(mainWindow, SIGNAL(signal_fx_state_toggled(int)),
            this, SLOT(slot_fx_state_changed(int)));
    connect(mainWindow, SIGNAL(signal_preset_changed(int)),
            this, SLOT(slot_bank_preset_changed(int)));
    connect(mainWindow, SIGNAL(signal_dialogFx_open(int)),
            this, SLOT(slot_dialogFx_open(int)));
    connect(mainWindow, SIGNAL(signal_preset_saved()),
            this, SLOT(slot_fx_preset_saved()));

    // FX INIT
    initializeFxParameters(); // Simula apretar un boton de presetBank

    // GPIO HARDWARE
#ifdef RPI
    rpiGpio = new mmapGpio();
    initializeGPIO();
    slot_led_on();

    connect(timer,SIGNAL(timeout()),
            this, SLOT(slot_pedals_read()));

    timer->start(POLLING_TIME);
#endif

    mainWindow->show();
}

void Crimson::slot_exit()
{
    mainWindow->close();
}

//*****************************************************************
//                  INIT
//*****************************************************************
void Crimson::initializeFxParameters()
{
    // Inicializo los efectos con el ultimo preset bank cargado
    // Por defecto es el numero 1.
    // Al iniciar el programa fx.bank.preset comienza en NONINIT
    QString addr = QString(fxBank.presetAddr);
    int lastBankPreset = crimsonSettings.value(addr,DEFAULTPRESET).toInt();

    // desde mainwindow emite signal de vuelta a crimson
    mainWindow->bankPresetSelector(lastBankPreset);
}

//*****************************************************************
//                  SLOTS
//*****************************************************************
void Crimson::slot_bank_preset_changed(int preset)
{
    int fx,param;

    // Si no es el preset seleccionado cargo la configuracion guardada
    if(fxBank.preset != preset)
    {
        QString addr = QString(fxBank.presetAddr);

        // Primero guardo el preset al cual se cambio para que quede almacenado
        // como lastPreset para cuando se inicialice el programa de nuevo
        crimsonSettings.setValue(addr,preset);

        fxBank.preset = preset;

        for(fx=0;fx<MAXEFFECTS;fx++)
        {
            // cargo los estados de cada efecto
            addr = QString(fxBank.fx[fx].stateAddr).append(QString::number(preset));

            // armo dir ej: over/state1
            fxBank.fx[fx].state = crimsonSettings.value(addr,DEFAULTSTATE).toBool();
            qDebug() << "Loaded" << addr << " " << QString::number(fxBank.fx[fx].state);

            // Envio el nuevo estado a Pd
            QString addr = QString(fxBank.fx[fx].stateAddr).prepend("/");
            comms.oscSendInt(addr,fxBank.fx[fx].state);

            // Actualizo señales visuales de que efectos estan prendidos
            if(mainWindow != nullptr)
                mainWindow->updateFxState(fx,fxBank.fx[fx].state);


            int nParam = fxBank.fx[fx].nParam;
            // Inicializo los valores de los parametros de los efectos
            for(param=0;param<nParam;param++)
            {
                addr = QString(fxBank.fx[fx].param[param].addr).append(QString::number(preset));
                fxBank.fx[fx].param[param].value = crimsonSettings.value(
                            addr,fxBank.fx[fx].param[param].defValue).toInt();

                // envio parametros a pd
                addr = QString(fxBank.fx[fx].param[param].addr).prepend("/");
                comms.oscSendInt(addr,fxBank.fx[fx].param[param].value);
            }

            // Actualizo los diales
            if(dialogFx != nullptr)
                dialogFx->setDialValues(fxBank.fx[fx]);
        }
    }
}

void Crimson::slot_fx_state_changed(int fx)
{
    // Actualizo el nuevo estado del efecto
    fxBank.fx[fx].state = !fxBank.fx[fx].state;

    // Actualizar estado de botones de mainwindow
    // y de dialogfx si es que esta activo
    mainWindow->updateFxState(fx,fxBank.fx[fx].state);
    if(dialogFx != nullptr)
        dialogFx->updateFxState(fxBank.fx[fx].state);

    // Envio el nuevo estado a Pd
    QString addr = QString(fxBank.fx[fx].stateAddr).prepend("/");
    comms.oscSendInt(addr,fxBank.fx[fx].state);
}

void Crimson::slot_fx_param_changed(int fx, int param, int value)
{
    // Actualizo el valor del parametro
    fxBank.fx[fx].param[param].value = value;

    // Envio el nuevo valor del parametro a Pd
    QString addr = QString(fxBank.fx[fx].param[param].addr).prepend("/");
    comms.oscSendInt(addr, value);
}

// TODO: Mejora habria que implementar dirty bit y guardar solo cosas que se hayan cambiado
void Crimson::slot_fx_preset_saved()
{
    int fx,param;

    for(fx=0;fx<MAXEFFECTS;fx++)
    {
        // guardo los estados de cada efecto
        QString addr = QString(fxBank.fx[fx].stateAddr).append(QString::number(fxBank.preset));
        crimsonSettings.setValue(addr,fxBank.fx[fx].state);

        qDebug() << "Saved" << addr << " " << QString::number(fxBank.fx[fx].state);

        int nParam = fxBank.fx[fx].nParam;

        for(param=0;param<nParam;param++)
        {
            addr = QString(fxBank.fx[fx].param[param].addr).append(QString::number(fxBank.preset));
            crimsonSettings.setValue(addr,fxBank.fx[fx].param[param].value);
        }
    }
}

//*****************************************************************
//                  FX DIALOG
//*****************************************************************
void Crimson::slot_dialogFx_open(int fx)
{
    dialogFx = new DialogFx;

    dialogFx->dialogSettings(fx,fxBank.fx[fx]);

    connect(dialogFx,SIGNAL(signal_fx_state_changed(int)),
            this,SLOT(slot_fx_state_changed(int)));
    connect(dialogFx,SIGNAL(signal_fx_param_changed(int,int,int)),
            this,SLOT(slot_fx_param_changed(int,int,int)));
    connect(dialogFx,SIGNAL(signal_destroyed()),
            this,SLOT(slot_dialogFx_closed()));

}

bool Crimson::getDebugMode()
{
    return mainWindow->getDebugMode();
}

void Crimson::sendDebugMes(QString msg)
{
    if (getDebugMode())
    {
        mainWindow->showDebugMsg(msg);
    }
}

void Crimson::slot_dialogFx_closed()
{
    dialogFx = nullptr;
}

//*****************************************************************
//                  GPIO
//*****************************************************************
#ifdef RPI

void Crimson::initializeGPIO()
{
    rpiGpio->setPinDir(PIN_POWER_LED, mmapGpio::OUTPUT);
    rpiGpio->setPinDir(PIN_LEFT_PEDAL, mmapGpio::INPUT);
    rpiGpio->setPinDir(PIN_RIGHT_PEDAL, mmapGpio::INPUT);
}

void Crimson::slot_pedals_read()
{
    static bool prevLeftValue = false;
    static bool prevRightValue = false;

    // ACTIVE LOW
    bool leftValue = rpiGpio->readPin(PIN_LEFT_PEDAL) == mmapGpio::LOW;
    bool rightValue = rpiGpio->readPin(PIN_RIGHT_PEDAL) == mmapGpio::LOW;

    // Logica ciclar entre presets al apretar los pedales
    if((leftValue || rightValue) && (leftValue != rightValue)) {
        if((leftValue && (leftValue != prevLeftValue)) || (rightValue && (rightValue != prevRightValue))) {
            if(leftValue) {
                qDebug() << "Left pedal pressed";
                mainWindow->bankPresetSelector((fxBank.preset-1)>=bPreset1 ? fxBank.preset-1 : bPreset6);
            } else {
                qDebug() << "Right pedal pressed";
                mainWindow->bankPresetSelector((fxBank.preset+1)<=bPreset6 ? fxBank.preset+1 : bPreset1);
            }
        }
    }
}

void Crimson::slot_led_on()
{
    rpiGpio->writePinHigh(PIN_POWER_LED);
}

void Crimson::slot_led_off()
{
    rpiGpio->writePinLow(PIN_POWER_LED);
}

#endif
