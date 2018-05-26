#include "crimson.h"

#include <QDebug>

Crimson::Crimson(QObject *parent) :
    QObject(parent)
{
    crimsonSettings.setPath(QSettings::IniFormat,QSettings::UserScope, "crimsonSettings.ini");
    crimsonSettings.clear();

    qDebug() << crimsonSettings.fileName();

    mainWindow = new MainWindow();
    //SETEAR EN FRAMELESS DSPS
    //mainWindow->setWindowFlags(Qt::FramelessWindowHint);

    //Conexiones con señales de mainWindow

    //On off de cada efecto
    connect(mainWindow,SIGNAL(signal_fx_state_toggled(int,bool)),
            this,SLOT(slot_fx_state_changed(int,bool)));

    //Presets
    connect(mainWindow,SIGNAL(signal_bankPreset_changed(int)),
            this,SLOT(slot_bank_preset_changed(int)));

    //Settings de cada efecto
    connect(mainWindow,SIGNAL(signal_dialogFx_open(int)),
            this,SLOT(slot_dialogFx_open(int)));

    //INICIALIZAR EVERYTHING
    initializeFxParameters();

    mainWindow->show();
}

void Crimson::slot_exit()
{
    mainWindow->close();
}

//*****************************************************************
//INIT ALL FX PARAMETERS!!!
//*****************************************************************
void Crimson::initializeFxParameters()
{
    //inicializo los efectos con el ultimo preset bank cargado
    //Por defecto es el numero 1.
    //Al inicial el programa fx.bank.preset comienza en NONINIT
    int lastBankPreset = crimsonSettings.value(fxBank.presetAddr,DEFAULTPRESET).toInt();
    mainWindow->initPulse(lastBankPreset); //desde mainwindow emite signal de vuelta a crimson

}

//***********************************************************************
// FX BANK
//***********************************************************************
void Crimson::slot_bank_preset_changed(int bankPreset)
{
    int k,fxPreset;
    QString addr;

    //Si este bank preset ya estaba seleccionado guardo la config actual
    if(fxBank.preset == bankPreset)
    {
        for(k=0;k<MAXEFFECTS;k++)
        {
            //guardo los presets de cada efecto
            addr = QString(fxBank.fx[k].presetAddr).append(QString::number(bankPreset));
            crimsonSettings.setValue(addr,fxBank.fx[k].preset);
            //guardo los estados de cada efecto
            addr = QString(fxBank.fx[k].stateAddr).append(QString::number(bankPreset));
            crimsonSettings.setValue(addr,fxBank.fx[k].state);
        }
    }
    //si no era el preset seleccionado cargo la configuracion guardada
    else
    {
        fxBank.preset = bankPreset;

        for(k=0;k<MAXEFFECTS;k++)
        {
            //Inicializo los presets de los efectos segun el banco cargado
            addr = QString(fxBank.fx[k].presetAddr).append(QString::number(bankPreset));
            fxPreset = crimsonSettings.value(addr,DEFAULTPRESET).toInt();
            //Las variables que almacenan el numero de preset
            //comienzan en el valor NONINIT
            slot_fx_preset_changed((int)k,fxPreset);
            //cargo los estados de cada efecto
            addr = QString(fxBank.fx[k].stateAddr).append(QString::number(bankPreset));
            fxBank.fx[k].state = crimsonSettings.value(addr,DEFAULTSTATE).toInt();
        }

        //Actualizo cues visuales de que efectos estan prendidos
        if(mainWindow != NULL)
        {
            mainWindow->updateFxStates(fxBank);
        }
        //else manejo error si fuera necesario
    }
}

//*****************************************************************
//                  SLOTS
//*****************************************************************

void Crimson::slot_fx_state_changed(int fx, bool state)
{
    fxBank.fx[fx].state = state;
    QString addr = QString(fxBank.fx[fx].stateAddr).prepend("/");
    comms.oscSendInt(addr,(int)state);
}


void Crimson::slot_fx_param_changed(int fx, int param, int value)
{
    fxBank.fx[fx].param[param].value = value;
    QString addr = QString(fxBank.fx[fx].param[param].addr).prepend("/");
    comms.oscSendInt(addr, value);
}

void Crimson::slot_fx_preset_changed(int fx, int preset)
{
    int k;
    int nParam = fxBank.fx[fx].nParam;
    QString addr;

    //Si este preset ya estaba seleccionado guardo la config actual
    if(fxBank.fx[fx].preset == preset)
    {
        for(k=0;k<nParam;k++)
        {
            addr = QString(fxBank.fx[fx].param[k].addr).append(QString::number(preset));
            crimsonSettings.setValue(addr,fxBank.fx[fx].param[k].value);
        }

    }
    //si no era el preset seleccionado cargo la configuracion guardada
    else
    {
        fxBank.fx[fx].preset = preset;

        for(k=0;k<nParam;k++)
        {
            addr = QString(fxBank.fx[fx].param[k].addr).append(QString::number(preset));
            fxBank.fx[fx].param[k].value = crimsonSettings.value(
                        addr,fxBank.fx[fx].param[k].defValue).toInt();

            //envio parametros a pd
            addr = QString(fxBank.fx[fx].param[k].addr).prepend("/");
            comms.oscSendInt(addr,fxBank.fx[fx].param[k].value);
        }
        //Actualizo los diales
        switch(fx)
        {
        case fxCompressor:
            //stuff
            break;

        case fxOverdrive:
//            if(dialogOverdrive1!=NULL)
//                dialogOverdrive1->sendFxParam(fxBank.fx[fx]);
            break;

        case fxEqualizer:
            //stuffity
            break;

        case fxReverb:
//            if(dialogReverb1!=NULL)
//                dialogReverb1->sendFxParam(fxBank.fx[fx]);
            break;

        case fxDelay:
//            if(dialogDelay1!=NULL)
//                dialogDelay1->sendFxParam(fxBank.fx[fx]);
            break;
        }
    }
}


//*****************************************************************
//                  FX DIALOG
//*****************************************************************
void Crimson::slot_dialogFx_open(int fx)
{
    DialogFx *dialogFx = new DialogFx;
    //Para framelessiar
//    dialogFx->setWindowFlags(Qt::FramelessWindowHint);
    dialogFx->dialogSettings(fx);

    connect(dialogFx,SIGNAL(signal_fx_param_changed(int,int,int)),
            this,SLOT(slot_fx_param_changed(int,int,int)));
}


