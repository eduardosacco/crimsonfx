#ifndef CRIMSON_H
#define CRIMSON_H

#include <QObject>
#include <QSettings>

#include "fxbank.h"
#include "comms.h"              //Modulo de comunicaciones
#include "mainwindow.h"         //Clase de ventana ppal
#include "dialogfx.h"

class Crimson : public QObject
{
    Q_OBJECT
public:
    explicit Crimson(QObject *parent = 0);

signals:

public slots:

    //DIALOGOS *************************************
    void slot_dialogFx_open(int fx);

    //EFECTOS
    void slot_fx_state_changed(int fx);
    void slot_fx_param_changed(int fx,int param, int value);
    void slot_fx_preset_changed(int fx, int preset);

    //Salida del programa
    void slot_exit();

private slots:
    void slot_bank_preset_changed(int bankPreset);
    void slot_dialogFx_closed();

private:

    //OBJETOS **********************************************

    //Efectos
    FxBank fxBank;
    
    //Comunicaciones
    Comms comms;

    //Settings: guardado de presets y otros
    QSettings crimsonSettings;

    //Ventana principal
    MainWindow *mainWindow = NULL;
    //Dialogos efectos 
    DialogFx *dialogFx = NULL;


    //Private Functions
    void initializeFxParameters(void);

};

#endif // CRIMSON_H
