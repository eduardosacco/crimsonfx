#include "crimson.h"

#include <QDebug>

Crimson::Crimson(QObject *parent) :
    QObject(parent)
{
    crimsonSettings.setPath(QSettings::IniFormat,QSettings::UserScope, "crimsonSettings.ini");
    qDebug() << crimsonSettings.fileName();
    
    //Settings: Inicializar variables correspondientes
    initializeFxParameters();

    mainWindow = new MainWindow();
    mainWindow->setWindowFlags(Qt::FramelessWindowHint);
    
    //Conexiones con señales de mainWindow
    //On off de cada efecto
    connect(mainWindow,SIGNAL(signal_fxOverdrive1_state_toggled(bool)),
            this,SLOT(slot_fxOverdrive1_state_changed(bool)));
    connect(mainWindow,SIGNAL(signal_fxReverb1_state_toggled(bool)),
            this,SLOT(slot_fxReverb1_state_changed(bool)));
    connect(mainWindow,SIGNAL(signal_fxDelay1_state_toggled(bool)),
            this,SLOT(slot_fxReverb1_state_changed(bool)));

    //Presets
    connect(mainWindow,SIGNAL(signal_bankPreset_changed(int)),
            this,SLOT(slot_bank_preset_changed(int)));

    //Settings de cada efecto
    connect(mainWindow,SIGNAL(signal_dialogCompressor_open()),
            this,SLOT(slot_fxCompressor_open()));
    connect(mainWindow,SIGNAL(signal_dialogOverdrive1_open()),
            this,SLOT(slot_fxOverdrive1_open()));
    connect(mainWindow,SIGNAL(signal_dialog8BandEqualizer_open()),
            this,SLOT(slot_fx8BandEqualizer_open()));
    connect(mainWindow,SIGNAL(signal_dialogReverb1_open()),
            this,SLOT(slot_fxReverb1_open()));
    connect(mainWindow,SIGNAL(signal_mainWindow_exit()),
            this,SLOT(slot_exit()));
    connect(mainWindow,SIGNAL(signal_dialogDelay1_open()),
            this,SLOT(slot_fxDelay1_open()));
    
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
    int lastPreset = crimsonSettings.value(fx.bank.addrPreset,DEFAULTPRESET).toInt();
    slot_bank_preset_changed(lastPreset);

}

//***********************************************************************
// FX BANK
//***********************************************************************
void Crimson::slot_bank_preset_changed(int preset)
{
    //Si este bank preset ya estaba seleccionado guardo la config actual
    if(fx.bank.preset == preset)
    {
        //guardo los presets de cada efecto
        crimsonSettings.setValue(QString(fx.bank.addrOverdrive1Preset)+QString::number(preset),
                                 fx.overdrive1.preset);
        crimsonSettings.setValue(QString(fx.bank.addrReverb1Preset)+QString::number(preset),
                                 fx.reverb1.preset);
        crimsonSettings.setValue(QString(fx.bank.addrDelay1Preset)+QString::number(preset),
                                 fx.delay1.preset);

        //guardo los estados de cada efecto
        crimsonSettings.setValue(QString(fx.bank.addrOverdrive1State)+QString::number(preset),
                                 fx.bank.overdrive1State);
        crimsonSettings.setValue(QString(fx.bank.addrReverb1State)+QString::number(preset),
                                 fx.bank.reverb1State);
        crimsonSettings.setValue(QString(fx.bank.addrDelay1State)+QString::number(preset),
                                 fx.bank.delay1State);
    }
    //si no era el preset seleccionado cargo la configuracion guardada
    else
    {
        fx.bank.preset = preset;

        //Inicializo los presets de los efectos segun el banco cargado
        int presetOverdrive1 = crimsonSettings.value(
                    QString(fx.bank.addrOverdrive1Preset)+QString::number(fx.bank.preset),DEFAULTPRESET).toInt();
        int presetReverb1 = crimsonSettings.value(
                    QString(fx.bank.addrReverb1Preset)+QString::number(fx.bank.preset),DEFAULTPRESET).toInt();
        int presetDelay1 = crimsonSettings.value(
                    QString(fx.bank.addrDelay1Preset)+QString::number(fx.bank.preset),DEFAULTPRESET).toInt();

        //Las variables que almacenan el numero de preset
        //comienzan en el valor NONINIT
        slot_fxOverdrive1_preset_changed(presetOverdrive1);
        slot_fxReverb1_preset_changed(presetReverb1);
        slot_fxDelay1_preset_changed(presetDelay1);

        //cargo los estados de cada efecto
        fx.bank.overdrive1State = crimsonSettings.value(
                    QString(fx.bank.addrOverdrive1State)+QString::number(fx.bank.preset),DEFAULTSTATE).toBool();
        fx.bank.reverb1State = crimsonSettings.value(
                    QString(fx.bank.addrReverb1State)+QString::number(fx.bank.preset),DEFAULTSTATE).toBool();
        fx.bank.delay1State = crimsonSettings.value(
                    QString(fx.bank.addrDelay1State)+QString::number(fx.bank.preset),DEFAULTSTATE).toBool();

        //Actualizo cues visuales de que efectos estan prendidos
        if(mainWindow != NULL)
        {
            mainWindow->updateFxStates(fx.bank);
        }


    }
}

//*****************************************************************
//                  SLOTS
//*****************************************************************

//*****************************************************************
//                  COMPRESOR
//*****************************************************************
void Crimson::slot_fxCompressor_open()
{

}

//*****************************************************************
//                  EQUALIZER
//*****************************************************************
void Crimson::slot_fx8BandEqualizer_open()
{

}

//*****************************************************************
//                  REVERB
//*****************************************************************
void Crimson::slot_fxReverb1_open()
{
    dialogReverb1 = new DialogReverb1();
    dialogReverb1->sendFxReverb1Param(fx.reverb1);

    //Conexiones con señales de mainWindow con dialogOverdrive1
    connect(dialogReverb1,SIGNAL(signal_dryWet_changed(int)),
            this,SLOT(slot_fxReverb1_dryWet_changed(int)));
    connect(dialogReverb1,SIGNAL(signal_roomSize_changed(int)),
            this,SLOT(slot_fxReverb1_roomSize_changed(int)));
    connect(dialogReverb1,SIGNAL(signal_damping_changed(int)),
            this,SLOT(slot_fxReverb1_damping_changed(int)));
    connect(dialogReverb1,SIGNAL(signal_preset_changed(int)),
            this,SLOT(slot_fxReverb1_preset_changed(int)));

    dialogReverb1->show();
}

void Crimson::slot_fxReverb1_destroyed()
{
    dialogReverb1 = NULL;
}

void Crimson::slot_fxReverb1_dryWet_changed(int position)
{
    fx.reverb1.dryWet = position;
    comms.oscSendInt(Comms::oscReverb1DryWet, position);
}

void Crimson::slot_fxReverb1_roomSize_changed(int position)
{
    fx.reverb1.roomSize = position;
    comms.oscSendInt(Comms::oscReverb1RoomSize, position);
}

void Crimson::slot_fxReverb1_damping_changed(int position)
{
    fx.reverb1.damping = position;
    comms.oscSendInt(Comms::oscReverb1Damping, position);
}

void Crimson::slot_fxReverb1_state_changed(bool state)
{
    fx.bank.reverb1State = state;
    comms.oscSendInt(Comms::oscReverb1State,(int)state);
}

void Crimson::slot_fxReverb1_preset_changed(int preset)
{
    //Si este preset ya estaba seleccionado guardo la config actual
    if(fx.reverb1.preset == preset)
    {
        crimsonSettings.setValue(QString(fx.reverb1.addrWet)+QString::number(preset),
                                 fx.reverb1.addrWet);
        crimsonSettings.setValue(QString(fx.reverb1.addrRoomSize)+QString::number(preset),
                                 fx.reverb1.addrRoomSize);
        crimsonSettings.setValue(QString(fx.reverb1.addrDamping)+QString::number(preset),
                                 fx.reverb1.damping);

    }
    //si no era el preset seleccionado cargo la configuracion guardada
    else
    {
        fx.reverb1.preset = preset;

        fx.reverb1.dryWet  = crimsonSettings.value(
                    QString(fx.reverb1.addrWet)+QString::number(preset), DEFAULTOVERDRIVE1G).toInt();
        fx.reverb1.roomSize = crimsonSettings.value(
                    QString(fx.reverb1.addrRoomSize)+QString::number(preset),DEFAULTOVERDRIVE1D).toInt();
        fx.reverb1.damping = crimsonSettings.value(
                    QString(fx.reverb1.addrDamping)+QString::number(preset),DEFAULTOVERDRIVE1C).toInt();

        //Actualizo los diales
        if(dialogReverb1!=NULL)
        {
            dialogReverb1->sendFxReverb1Param(fx.reverb1);
        }

        //envio parametros a pd
        comms.oscSendInt(fx.reverb1.addrWet,fx.reverb1.dryWet);
        comms.oscSendInt(fx.reverb1.addrRoomSize,fx.reverb1.roomSize);
        comms.oscSendInt(fx.reverb1.addrDamping,fx.reverb1.damping);

    }

}
//*****************************************************************
//                  DELAY
//*****************************************************************
void Crimson::slot_fxDelay1_open()
{
    dialogDelay1 = new DialogDelay1();
    dialogDelay1->sendFxDelay1Param(fx.delay1);

    //Conexiones con señales de mainWindow con dialogOverdrive1
    connect(dialogDelay1,SIGNAL(signal_level_changed(int)),
            this,SLOT(slot_fxDelay1_level_changed(int)));
    connect(dialogDelay1,SIGNAL(signal_delay_changed(int)),
            this,SLOT(slot_fxDelay1_delay_changed(int)));
    connect(dialogDelay1,SIGNAL(signal_feedback_changed(int)),
            this,SLOT(slot_fxDelay1_feedback_changed(int)));
    connect(dialogDelay1,SIGNAL(signal_preset_changed(int)),
            this,SLOT(slot_fxDelay1_preset_changed(int)));

    dialogDelay1->show();
}

void Crimson::slot_fxDelay1_destroyed()
{
    dialogDelay1 = NULL;
}

void Crimson::slot_fxDelay1_level_changed(int position)
{
    fx.delay1.level = position;
    comms.oscSendInt(Comms::oscDelay1Level,position);
}

void Crimson::slot_fxDelay1_delay_changed(int position)
{
    fx.delay1.delay = position;
    comms.oscSendInt(Comms::oscDelay1Delay,position);
}

void Crimson::slot_fxDelay1_feedback_changed(int position)
{
    fx.delay1.feedback = position;
    comms.oscSendInt(Comms::oscDelay1Feedback,position);
}

void Crimson::slot_fxDelay1_state_changed(bool state)
{
    fx.bank.delay1State = state;
    comms.oscSendInt(Comms::oscDelay1State,(int)state);
}

void Crimson::slot_fxDelay1_preset_changed(int preset)
{
    //Si este preset ya estaba seleccionado guardo la config actual
    if(fx.delay1.preset == preset)
    {
        crimsonSettings.setValue(QString(fx.delay1.addrLevel)+QString::number(preset),
                                 fx.delay1.level);
        crimsonSettings.setValue(QString(fx.delay1.addrDelay)+QString::number(preset),
                                 fx.delay1.delay);
        crimsonSettings.setValue(QString(fx.delay1.addrFeedback)+QString::number(preset),
                                 fx.delay1.feedback);

    }
    //si no era el preset seleccionado cargo la configuracion guardada
    else
    {
        fx.delay1.preset = preset;

        fx.delay1.level = crimsonSettings.value(
                    QString(fx.delay1.addrLevel)+QString::number(preset),DEFAULTDELAY1L).toInt();
        fx.delay1.delay = crimsonSettings.value(
                    QString(fx.delay1.addrDelay)+QString::number(preset),DEFAULTDELAY1D).toInt();
        fx.delay1.feedback = crimsonSettings.value(
                    QString(fx.delay1.addrFeedback)+QString::number(preset),DEFAULTDELAY1F).toInt();

        //Actualizo los diales
        if(dialogDelay1!=NULL)
        {
            dialogDelay1->sendFxDelay1Param(fx.delay1);
        }

        //envio parametros a pd
        comms.oscSendInt(fx.delay1.addrLevel ,fx.delay1.level);
        comms.oscSendInt(fx.delay1.addrDelay,fx.delay1.delay);
        comms.oscSendInt(fx.delay1.addrFeedback,fx.delay1.feedback);
    }
}

//*****************************************************************
//                  OVERDRIVE
//*****************************************************************
void Crimson::slot_fxOverdrive1_open()
{
    dialogOverdrive1 = new DialogOverdrive1();
    dialogOverdrive1->sendFxOverdrive1Param(fx.overdrive1);

    //Conexiones con señales de mainWindow con dialogOverdrive1
    connect(dialogOverdrive1,SIGNAL(signal_gain_changed(int)),
            this,SLOT(slot_fxOverdrive1_gain_changed(int)));
    connect(dialogOverdrive1,SIGNAL(signal_depth_changed(int)),
            this,SLOT(slot_fxOverdrive1_depth_changed(int)));
    connect(dialogOverdrive1,SIGNAL(signal_cutoff_changed(int)),
            this,SLOT(slot_fxOverdrive1_cutoff_changed(int)));
    connect(dialogOverdrive1,SIGNAL(signal_preset_changed(int)),
            this,SLOT(slot_fxOverdrive_preset_changed(int)));
    connect(dialogOverdrive1,SIGNAL(destroyed()),
            this,SLOT(slot_fxOverdrive1_destroyed()));

    dialogOverdrive1->show();
}

void Crimson::slot_fxOverdrive1_destroyed()
{
    dialogOverdrive1 = NULL;
}

void Crimson::slot_fxOverdrive1_gain_changed(int position)
{
    fx.overdrive1.gain = position;
    comms.oscSendInt(Comms::oscOverdrive1Gain,position);
}

void Crimson::slot_fxOverdrive1_depth_changed(int position)
{
    fx.overdrive1.depth = position;
    comms.oscSendInt(Comms::oscOverdrive1Depth, position);
}

void Crimson::slot_fxOverdrive1_cutoff_changed(int position)
{
    fx.overdrive1.cutoff = position;
    comms.oscSendInt(Comms::oscOverdrive1Cutoff,position);
}

void Crimson::slot_fxOverdrive1_state_changed(bool state)
{
    fx.bank.overdrive1State = state;
    comms.oscSendInt(Comms::oscOverdrive1State,(int)state);
}

void Crimson::slot_fxOverdrive1_preset_changed(int preset)
{
    //Si este preset ya estaba seleccionado guardo la config actual
    if(fx.overdrive1.preset == preset)
    {
        crimsonSettings.setValue(QString(fx.overdrive1.addrGain)+QString::number(preset),
                                 fx.overdrive1.gain);
        crimsonSettings.setValue(QString(fx.overdrive1.addrDepth)+QString::number(preset),
                                 fx.overdrive1.depth);
        crimsonSettings.setValue(QString(fx.overdrive1.addrCuttof)+QString::number(preset),
                                 fx.overdrive1.cutoff);

    }
    //si no era el preset seleccionado cargo la configuracion guardada
    else
    {
        fx.overdrive1.preset = preset;

        fx.overdrive1.gain  = crimsonSettings.value(
                    QString(fx.overdrive1.addrGain)+QString::number(preset), DEFAULTOVERDRIVE1G).toInt();
        fx.overdrive1.depth = crimsonSettings.value(
                    QString(fx.overdrive1.addrDepth)+QString::number(preset),DEFAULTOVERDRIVE1D).toInt();
        fx.overdrive1.cutoff = crimsonSettings.value(
                    QString(fx.overdrive1.addrCuttof)+QString::number(preset),DEFAULTOVERDRIVE1C).toInt();

        //Actualizo los diales
        if(dialogOverdrive1!=NULL)
        {
            dialogOverdrive1->sendFxOverdrive1Param(fx.overdrive1);
        }

        //envio parametros a pd
        comms.oscSendInt(fx.overdrive1.addrGain,fx.overdrive1.gain);
        comms.oscSendInt(fx.overdrive1.addrDepth,fx.overdrive1.depth);
        comms.oscSendInt(fx.overdrive1.addrCuttof,fx.overdrive1.cutoff);

    }
}

//*****************************************************************
//                  Misc
//*****************************************************************

//Convertidor de posicion del dial de Qt a valor del efecto de Pd
float Crimson::pos2Value(int pos, float minValue,float maxValue)
{
    float value = (pos/99)*(maxValue-minValue)+minValue;
    return value;
}
