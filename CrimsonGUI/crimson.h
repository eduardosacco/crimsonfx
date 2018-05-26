#ifndef CRIMSON_H
#define CRIMSON_H

#include <QObject>
#include <QSettings>

#include "fx.h"
#include "comms.h"              //Modulo de comunicaciones
#include "mainwindow.h"         //Clase de ventana ppal
#include "dialogoverdrive1.h"   //Clase dialogo Overdrive
#include "dialogreverb1.h"      //Clase dialogo Reverb
#include "dialogdelay1.h"       //Clase dialogo Delay

class Crimson : public QObject
{
    Q_OBJECT
public:
    explicit Crimson(QObject *parent = 0);

signals:

public slots:

    //DIALOGOS *************************************
    void slot_fxCompressor_open(void);
//    void slot_fxCompressor_destroyed(void);
    void slot_fxOverdrive1_open(void);
    void slot_fxOverdrive1_destroyed(void);
    void slot_fx8BandEqualizer_open(void);
//    void slot_fx8BandEqualizer_destroyed(void);
    void slot_fxReverb1_open(void);
    void slot_fxReverb1_destroyed(void);
    void slot_fxDelay1_open(void);
    void slot_fxDelay1_destroyed(void);

    //OVERDRIVE ************************************
    void slot_fxOverdrive1_state_changed(bool state);
    void slot_fxOverdrive1_gain_changed(int position);
    void slot_fxOverdrive1_depth_changed(int position);
    void slot_fxOverdrive1_cutoff_changed(int position);
    void slot_fxOverdrive1_preset_changed(int preset);

    //REVERB ***************************************
    void slot_fxReverb1_state_changed(bool state);
    void slot_fxReverb1_dryWet_changed(int position);
    void slot_fxReverb1_roomSize_changed(int position);
    void slot_fxReverb1_damping_changed(int position);
    void slot_fxReverb1_preset_changed(int preset);

    //DELAY ***************************************
    void slot_fxDelay1_state_changed(bool state);
    void slot_fxDelay1_level_changed(int position);
    void slot_fxDelay1_delay_changed(int position);
    void slot_fxDelay1_feedback_changed(int position);
    void slot_fxDelay1_preset_changed(int preset);


    //Salida del programa
    void slot_exit();

private slots:
    void slot_bank_preset_changed(int preset);

private:

    //OBJETOS **********************************************

    //Efectos
    Fx fx;
    
    //Comunicaciones
    Comms comms;

    //Settings: guardado de presets y otros
    QSettings crimsonSettings;

    //Ventana principal
    MainWindow *mainWindow = NULL;
    //Dialogos efectos 
    DialogOverdrive1 *dialogOverdrive1 = NULL;
    DialogReverb1 *dialogReverb1 = NULL;
    DialogDelay1 *dialogDelay1 = NULL;

    //Private Functions
    void initializeFxParameters(void);
    void changeMainPreset(int preset);
    float pos2Value(int pos, float minValue,float maxValue);
};

#endif // CRIMSON_H
