//--------------------------------------------------------------------------------------------------
//              CRIMSON.H
//--------------------------------------------------------------------------------------------------

// WARNING: Definir TESTMODE unicamente para correr CrimsonGUITests
//#define TESTMODE

// Definir RPI para funcionalidad completa de hardware para la RPI
#define RPI

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

//*****************************************************************
//                  DEFINES
//*****************************************************************
#define PIN_POWER_LED 4
#define PIN_LEFT_PEDAL 17
#define PIN_RIGHT_PEDAL 27
#define POLLING_TIME 250

//*****************************************************************
//                  CRIMSON CLASS
//*****************************************************************
class Crimson : public QObject
{
    Q_OBJECT

#ifdef TESTMODE
public:
#else
private:
#endif
    FxBank fxBank;                      // Efectos
    Comms comms;                        // Comunicaciones
    QSettings crimsonSettings;          // Settings: guardado de presets y otros
    MainWindow *mainWindow = nullptr;   // Ventana principal
    DialogFx *dialogFx = nullptr;       // Dialogos efectos
    QTimer *timer;                      // Timer for polling pin inputs

#ifdef RPI
    void initializeGPIO(void);
    mmapGpio *rpiGpio;                  //mmapGpio class para controlar GPIO
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
    void slot_dialogFx_open(int fx);
    void slot_fx_state_changed(int fx);
    void slot_fx_param_changed(int fx,int param, int value);
    void slot_fx_preset_saved();
    void slot_exit();
    void slot_bank_preset_changed(int bankPreset);
    void slot_dialogFx_closed();

#ifdef RPI
    void slot_pedals_read();
    void slot_led_on();
    void slot_led_off();
#endif

};

#endif // CRIMSON_H
