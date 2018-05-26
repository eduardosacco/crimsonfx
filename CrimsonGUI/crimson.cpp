#include "crimson.h"

Crimson::Crimson(QObject *parent) :
    QObject(parent)
{
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
//CRIMSONSETTINGS ADDRESSES
//*****************************************************************
//Direcciones para guardar parametros en settings

//OVERDRIVE
const QString Crimson::sOverdrive1Gain = "over/g";
const QString Crimson::sOverdrive1Depth = "over/d";
const QString Crimson::sOverdrive1Cutoff = "over/c";

//REVERB
const QString Crimson::sReverb1DryWet = "rev/dw";
const QString Crimson::sReverb1Damping = "rev/d";
const QString Crimson::sReverb1RoomSize = "rev/rs";

//DELAY
const QString Crimson::sDelay1Level = "del/l";
const QString Crimson::sDelay1Delay = "del/d";
const QString Crimson::sDelay1Feedback = "del/f";

//*****************************************************************
//INIT ALL FX PARAMETERS!!!
//*****************************************************************
void Crimson::initializeFxParameters()
{
     fxOverdrive1.gain = crimsonSettings.value(sOverdrive1Gain, 50).toInt();
     fxOverdrive1.depth = crimsonSettings.value(sOverdrive1Depth,50).toInt();
     fxOverdrive1.cutoff = crimsonSettings.value(sOverdrive1Cutoff, 50).toInt();

     fxDelay1.level = crimsonSettings.value(sDelay1Level,80).toInt();
     fxDelay1.level = crimsonSettings.value(sDelay1Delay,22).toInt();
     fxDelay1.feedback = crimsonSettings.value(sDelay1Feedback,15).toInt();

     fxReverb1.dryWet = crimsonSettings.value(sReverb1DryWet,80).toInt();
     fxReverb1.roomSize = crimsonSettings.value(sReverb1RoomSize,30).toInt();
     fxReverb1.damping = crimsonSettings.value(sReverb1Damping,25).toInt();

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

    //Conexiones con señales de mainWindow con dialogOverdrive1
    connect(dialogReverb1,SIGNAL(signal_dryWet_changed(int)),
            this,SLOT(slot_fxReverb1_dryWet_changed(int)));
    connect(dialogReverb1,SIGNAL(signal_roomSize_changed(int)),
            this,SLOT(slot_fxReverb1_roomSize_changed(int)));
    connect(dialogReverb1,SIGNAL(signal_damping_changed(int)),
            this,SLOT(slot_fxReverb1_damping_changed(int)));

    //Settings: Inicializar variables correspondientes

    dialogReverb1->show();
}

void Crimson::slot_fxReverb1_dryWet_changed(int position)
{
    fxReverb1.dryWet = position;
    comms.oscSendInt(Comms::oscReverb1DryWet, position);
}

void Crimson::slot_fxReverb1_roomSize_changed(int position)
{
    fxReverb1.roomSize = position;
    comms.oscSendInt(Comms::oscReverb1RoomSize, position);
}

void Crimson::slot_fxReverb1_damping_changed(int position)
{
    fxReverb1.damping = position;
    comms.oscSendInt(Comms::oscReverb1Damping, position);
}

//DELAY ***********************************************************
void Crimson::slot_fxDelay1_open()
{
    dialogDelay1 = new DialogDelay1();
    dialogDelay1->sendFxDelay1Param(fxDelay1);

    //Conexiones con señales de mainWindow con dialogOverdrive1
    connect(dialogDelay1,SIGNAL(signal_level_changed(int)),
            this,SLOT(slot_fxDelay1_level_changed(int)));
    connect(dialogDelay1,SIGNAL(signal_delay_changed(int)),
            this,SLOT(slot_fxDelay1_delay_changed(int)));
    connect(dialogDelay1,SIGNAL(signal_feedback_changed(int)),
            this,SLOT(slot_fxDelay1_feedback_changed(int)));

    dialogDelay1->show();
}

void Crimson::slot_fxDelay1_level_changed(int position)
{
    fxDelay1.level = position;
    comms.oscSendInt(Comms::oscDelay1Level,position);
}

void Crimson::slot_fxDelay1_delay_changed(int position)
{
    fxDelay1.delay = position;
    comms.oscSendInt(Comms::oscDelay1Delay,position);
}

void Crimson::slot_fxDelay1_feedback_changed(int position)
{
    fxDelay1.feedback = position;
    comms.oscSendInt(Comms::oscDelay1Feedback,position);
}

//OVERDRIVE ***********************************************************
void Crimson::slot_fxOverdrive1_open()
{
    dialogOverdrive1 = new DialogOverdrive1();
    dialogOverdrive1->sendFxOverdrive1Param(fxOverdrive1);

    //Conexiones con señales de mainWindow con dialogOverdrive1
    connect(dialogOverdrive1,SIGNAL(signal_gain_changed(int)),
            this,SLOT(slot_fxOverdrive1_gain_changed(int)));
    connect(dialogOverdrive1,SIGNAL(signal_depth_changed(int)),
            this,SLOT(slot_fxOverdrive1_depth_changed(int)));
    connect(dialogOverdrive1,SIGNAL(signal_cutoff_changed(int)),
            this,SLOT(slot_fxOverdrive1_cutoff_changed(int)));

    dialogOverdrive1->show();
}

void Crimson::slot_fxOverdrive1_gain_changed(int position)
{
    fxOverdrive1.gain = position;
    comms.oscSendInt(Comms::oscOverdrive1Gain,position);
}

void Crimson::slot_fxOverdrive1_depth_changed(int position)
{
    fxOverdrive1.depth = position;
    comms.oscSendInt(Comms::oscOverdrive1Depth, position);
}

void Crimson::slot_fxOverdrive1_cutoff_changed(int position)
{
    fxOverdrive1.cutoff = position;
    comms.oscSendInt(Comms::oscOverdrive1Cutoff,position);
}
