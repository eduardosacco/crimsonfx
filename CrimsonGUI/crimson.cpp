#include "crimson.h"

#include <QDebug>

Crimson::Crimson(QObject *parent) :
    QObject(parent)
{
    crimsonSettings.setPath(QSettings::IniFormat,QSettings::UserScope, "crimsonSettings.ini");
    qDebug() << crimsonSettings.fileName();

    //ACA TENGO QUE CONECTAR LA GILADA
    
    mainWindow = new MainWindow();
    mainWindow->setWindowFlags(Qt::FramelessWindowHint);
    
    //Conexiones con señales de mainWindow
    connect(mainWindow,SIGNAL(signal_dialogCompressor1_open()),
            this,SLOT(slot_fxCompressor1_open()));
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

    //Settings: Inicializar variables correspondientes
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
    //ACA SOLO HABRIA QUE LEER CUAL FUE EL ULTIMO MAIN PRESET Y CARGARLO

     fx.overdrive1.gain  = crimsonSettings.value(fx.overdrive1.pdAddrGain , OVERDRIVE1DEFAULTG).toInt();
     fx.overdrive1.depth = crimsonSettings.value(fx.overdrive1.pdAddrDepth,OVERDRIVE1DEFAULTD).toInt();
     fx.overdrive1.cutoff = crimsonSettings.value(fx.overdrive1.pdAddrCuttof, OVERDRIVE1DEFAULTC).toInt();

     fx.reverb1.dryWet = crimsonSettings.value(fx.reverb1.pdAddrWet,REVERB1DEFAULTDW).toInt();
     fx.reverb1.roomSize = crimsonSettings.value(fx.reverb1.pdAddrRoomSize,REVERB1DEFAULTRS).toInt();
     fx.reverb1.damping = crimsonSettings.value(fx.reverb1.pdAddrDamping,REVERB1DEFAULTD).toInt();

}

//*****************************************************************
//SLOTS
//*****************************************************************

//COMPRESOR *******************************************************
void Crimson::slot_fxCompressor1_open()
{

}

//EQUALIZER *******************************************************
void Crimson::slot_fx8BandEqualizer_open()
{

}

//REVERB ***********************************************************
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

//DELAY ***********************************************************
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

void Crimson::slot_fxDelay1_level_changed(int position)
{
//    float value = pos2Value(position,fx.delay1.)
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

void Crimson::slot_fxDelay1_preset_changed(int preset)
{
    //Si este preset ya estaba seleccionado guardo la config actual
    if(fx.delay1.preset == preset)
    {
        fx.delay1.level = crimsonSettings.setValue(
                    QString(fx.delay1.pdAddrLevel).arg(preset),DELAY1DEFAULTL);
        fx.delay1.level = crimsonSettings.setValue(
                    QString(fx.delay1.pdAddrDelay).arg(preset),DELAY1DEFAULTD);
        fx.delay1.feedback = crimsonSettings.value(
                    QString(fx.delay1.pdAddrFeedback).arg(preset),DELAY1DEFAULTF).toInt());

    }
    //si no era el preset seleccionado cargo la configuracion guardada
    else
    {

    }
}

//OVERDRIVE ***********************************************************
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

    dialogOverdrive1->show();
}

void Crimson::slot_fxOverdrive1_gain_changed(int position)
{
//    float value = pos2Value(position,fx.overdrive1.minGain,fx.overdrive1.maxGain);
    fx.overdrive1.gain = position;
    comms.oscSendInt(Comms::oscOverdrive1Gain,position);
}

void Crimson::slot_fxOverdrive1_depth_changed(int position)
{
//    float value = pos2Value(position,fx.overdrive1.minDepth,fx.overdrive1.maxDepth);
    fx.overdrive1.depth = position;
    comms.oscSendInt(Comms::oscOverdrive1Depth, position);
}

void Crimson::slot_fxOverdrive1_cutoff_changed(int position)
{
//    float value = pos2Value(position,fx.overdrive1.minCutoff,fx.overdrive1.maxCutoff);
    fx.overdrive1.cutoff = position;
    comms.oscSendInt(Comms::oscOverdrive1Cutoff,position);
}

void Crimson::changeMainPreset(int preset)
{
//    if(1)
//        else

}

//Convertidor de posicion del dial de Qt a valor del efecto de Pd
float Crimson::pos2Value(int pos, float minValue,float maxValue)
{
    float value = (pos/99)*(maxValue-minValue)+minValue;
    return value;
}
