#ifndef CRIMSON_H
#define CRIMSON_H

#include <QObject>
#include <QSettings>
#include "crimsontypes.h"       //Definiciones de tipos utilizados
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
    void slot_fxCompressor1_open(void);
    void slot_fxOverdrive1_open(void);
    void slot_fx8BandEqualizer_open(void);
    void slot_fxReverb1_open(void);
    void slot_fxDelay1_open(void);

    //OVERDRIVE ************************************
    void slot_fxOverdrive1_gain_changed(int position);
    void slot_fxOverdrive1_depth_changed(int position);
    void slot_fxOverdrive1_cutoff_changed(int position);

    //REVERB ***************************************
    void slot_fxReverb1_dryWet_changed(int position);
    void slot_fxReverb1_roomSize_changed(int position);
    void slot_fxReverb1_damping_changed(int position);

    //DELAY ***************************************
    void slot_fxDelay1_level_changed(int position);
    void slot_fxDelay1_delay_changed(int position);
    void slot_fxDelay1_feedback_changed(int position);


    //Salida del programa
    void slot_exit();

private:

    //Arreglos de direcciones para guardado de variables
    //de los parametros en settings

    //OVERDRIVE
    static const QString sOverdrive1Gain;
    static const QString sOverdrive1Depth;
    static const QString sOverdrive1Cutoff;


    //REVERB
    static const QString sReverb1DryWet;
    static const QString sReverb1RoomSize;
    static const QString sReverb1Damping;

    //DELAY
    static const QString sDelay1Level;
    static const QString sDelay1Delay;
    static const QString sDelay1Feedback;

    //OBJETOS **********************************************

    //Estructuras para el manejo de variables de los efectos
    FxOverdrive1 fxOverdrive1;
    FxDelay1    fxDelay1;
    FxReverb1   fxReverb1;
    
    //Comunicaciones
    Comms comms;

    //Settings: guardado de presets y otros
    QSettings crimsonSettings;

    //Ventana principal
    MainWindow *mainWindow;  
    //Dialogos efectos 
    DialogOverdrive1 *dialogOverdrive1;
    DialogReverb1 *dialogReverb1;
    DialogDelay1 *dialogDelay1;

    //Private Functions
    void initializeFxParameters(void);
};

#endif // CRIMSON_H
