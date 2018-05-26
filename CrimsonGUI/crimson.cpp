#include "crimson.h"

#include <QDebug>

Crimson::Crimson(QObject *parent) :
    QObject(parent)
{
    qDebug() << "CRIMSON FX 2018";
    qDebug() << "Config File in: " << crimsonSettings.fileName() << endl;
    qDebug() << "Debug Log:";

    mainWindow = new MainWindow();
    //SETEAR EN FRAMELESS DSPS
    //mainWindow->setWindowFlags(Qt::FramelessWindowHint);

    //Conexiones con señales de mainWindow

    //On off de cada efecto
    connect(mainWindow,SIGNAL(signal_fx_state_toggled(int)),
            this,SLOT(slot_fx_state_changed(int)));

    //Presets
    connect(mainWindow,SIGNAL(signal_preset_changed(int)),
            this,SLOT(slot_bank_preset_changed(int)));

    //Settings de cada efecto
    connect(mainWindow,SIGNAL(signal_dialogFx_open(int)),
            this,SLOT(slot_dialogFx_open(int)));

    connect(mainWindow,SIGNAL(signal_preset_saved()),
            this,SLOT(slot_fx_preset_saved()));

    //INICIALIZAR EVERYTHING
    initializeFxParameters(); //Simula apretar un boton de presetBank

    mainWindow->show();
}

void Crimson::slot_exit()
{
    mainWindow->close();
}

//*****************************************************************
//                  INIT ALL FX PARAMETERS!!!
//*****************************************************************
void Crimson::initializeFxParameters()
{
    //inicializo los efectos con el ultimo preset bank cargado
    //Por defecto es el numero 1.
    //Al inicial el programa fx.bank.preset comienza en NONINIT
    QString addr = QString(fxBank.presetAddr);
    int lastBankPreset = crimsonSettings.value(addr,DEFAULTPRESET).toInt();
    mainWindow->initPulse(lastBankPreset); //desde mainwindow emite signal de vuelta a crimson
}

//*****************************************************************
//                  SLOTS
//*****************************************************************

void Crimson::slot_bank_preset_changed(int preset)
{
    int fx,param;      //para ciclar los for

    QString addr = QString(fxBank.presetAddr);
    //Primero guardo el preset al cual se cambio para que quede almacenado
    //como lastPreset para cuando se inicialice el programa de nuevo
    crimsonSettings.setValue(addr,preset);

    //Si no es el preset seleccionado cargo la configuracion guardada
    if(fxBank.preset != preset)
    {
        fxBank.preset = preset;

        for(fx=0;fx<MAXEFFECTS;fx++)
        {
            //cargo los estados de cada efecto
            addr = QString(fxBank.fx[fx].stateAddr).append(QString::number(preset));
            //armo dir ej: over/state1
            fxBank.fx[fx].state = crimsonSettings.value(addr,DEFAULTSTATE).toBool();
            qDebug() << "Loaded" << addr << " " << QString::number(fxBank.fx[fx].state);

            //Envio el nuevo estado a Pd
            QString addr = QString(fxBank.fx[fx].stateAddr).prepend("/");
            comms.oscSendInt(addr,fxBank.fx[fx].state);

            //Actualizo cues visuales de que efectos estan prendidos
            if(mainWindow != NULL)
                mainWindow->updateFxState(fx,fxBank.fx[fx].state);


            int nParam = fxBank.fx[fx].nParam;
            //Inicializo los valores de los parametros de los efectos
            for(param=0;param<nParam;param++)
            {
                addr = QString(fxBank.fx[fx].param[param].addr).append(QString::number(preset));
                fxBank.fx[fx].param[param].value = crimsonSettings.value(
                            addr,fxBank.fx[fx].param[param].defValue).toInt();

                //envio parametros a pd
                addr = QString(fxBank.fx[fx].param[param].addr).prepend("/");
                comms.oscSendInt(addr,fxBank.fx[fx].param[param].value);
            }

            //Actualizo los diales
            if(dialogFx != NULL)
                dialogFx->setDialValues(fxBank.fx[fx]);

        }
    }
}

void Crimson::slot_fx_state_changed(int fx)
{
    //Actualizo el nuevo estado del efecto
    fxBank.fx[fx].state = !fxBank.fx[fx].state;
    //Actualizar estado de botones de mainwindow
    //y de dialogfx si es que esta activo
    mainWindow->updateFxState(fx,fxBank.fx[fx].state);
    if(dialogFx != NULL)
        dialogFx->updateFxState(fxBank.fx[fx].state);

    //Envio el nuevo estado a Pd
    QString addr = QString(fxBank.fx[fx].stateAddr).prepend("/");
    comms.oscSendInt(addr,fxBank.fx[fx].state);
}

void Crimson::slot_fx_param_changed(int fx, int param, int value)
{
    //Actualizo el valor del parametro
    fxBank.fx[fx].param[param].value = value;
    //Envio el nuevo valor del parametro a Pd
    QString addr = QString(fxBank.fx[fx].param[param].addr).prepend("/");
    comms.oscSendInt(addr, value);
}

//Habria que implementar el dirty bit asi no guardo todo en el reg al pedo
void Crimson::slot_fx_preset_saved()
{
    int fx,param;

    for(fx=0;fx<MAXEFFECTS;fx++)
    {
        //guardo los estados de cada efecto
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
    //Para framelessiar
//    dialogFx->setWindowFlags(Qt::FramelessWindowHint);
    dialogFx->dialogSettings(fx,fxBank.fx[fx]);

    connect(dialogFx,SIGNAL(signal_fx_state_changed(int)),
            this,SLOT(slot_fx_state_changed(int)));
    connect(dialogFx,SIGNAL(signal_fx_preset_changed(int,int)),
            this,SLOT(slot_fx_preset_changed(int,int)));
    connect(dialogFx,SIGNAL(signal_fx_param_changed(int,int,int)),
            this,SLOT(slot_fx_param_changed(int,int,int)));
    connect(dialogFx,SIGNAL(signal_destroyed()),
            this,SLOT(slot_dialogFx_closed()));

}

void Crimson::slot_dialogFx_closed()
{
    dialogFx = NULL;\
}


