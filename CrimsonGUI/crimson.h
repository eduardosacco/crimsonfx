// WARNING: Define TESTMODE only to grant public access to every member of Crimson in order to test
#define TESTMODE

// Define RPI to have full RPI HW functionality
//#define RPI

#ifndef CRIMSON_H
#define CRIMSON_H

#include <QObject>
#include <QSettings>
#include <QTimer>
#include "fxbank.h"
#include "comms.h"
#include "mainwindow.h"
#include "dialogfx.h"

#ifdef RPI
#include "mmapgpio.h"
#endif

#define PIN_POWER_LED 4
#define PIN_LEFT_PEDAL 17
#define PIN_RIGHT_PEDAL 27
#define POLLING_TIME 250

class Crimson : public QObject
{
    Q_OBJECT

#ifdef TESTMODE
public:
#else
private:
#endif
    //OBJETOS Y METODOS PRIVADOS **********************************************
    FxBank fxBank;                      //Efectos
    Comms comms;                        //Comunicaciones
    QSettings crimsonSettings;          //Settings: guardado de presets y otros
    MainWindow *mainWindow = nullptr;   //Ventana principal
    DialogFx *dialogFx = nullptr;       //Dialogos efectos
    QTimer *timer;                      //Timer for polling pin inputs

#ifdef RPI
    void initializeGPIO(void);
    mmapGpio *rpiGpio;                  //mmapGpio class to control the GPIO
#endif

    void initializeFxParameters(void);

public:
    explicit Crimson(QObject *parent = nullptr);
    bool getDebugMode();
    void sendDebugMes(QString msg);

signals:

#ifdef TESTMODE
public slots:
#else
private slots:
#endif
    //DIALOGOS *************************************
    void slot_dialogFx_open(int fx);

    //EFECTOS
    void slot_fx_state_changed(int fx);
    void slot_fx_param_changed(int fx,int param, int value);
    void slot_fx_preset_saved();

    //Salida del programa
    void slot_exit();

    //private slots:
    void slot_bank_preset_changed(int bankPreset);
    void slot_dialogFx_closed();

#ifdef RPI
    void slot_pedals_read();
    void slot_led_on();
    void slot_led_off();
#endif

};

#endif // CRIMSON_H
