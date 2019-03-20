//--------------------------------------------------------------------------------------------------
//              MAINWINDOW.H
//--------------------------------------------------------------------------------------------------

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <qpixmap.h>
#include <QTimer>

#include "fxbank.h"

//*****************************************************************
//                  MAINWINDOW
//*****************************************************************
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QTimer *timerLockBtn = new QTimer();
    QTimer *timerSaveBtn = new QTimer();
    bool lockDownMode = false;
    bool debugMode = false;
    void toggleLockDownMode();
    void toggleDebugMode();
    void setEnableBtns(bool enabled);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void bankPresetSelector(int preset);
    void updateFxState(int fxNum,bool state);
    void setPBtnStyle(QPushButton *button, bool checked);
    bool getDebugMode();
    void showDebugMsg(QString msg);

signals:
    // Señales ON OFF Switches
    void signal_fx_state_toggled(int fx);
    void signal_dialogFx_open(int fx);
    void signal_preset_changed(int preset);
    void signal_preset_saved();
    void signal_debug_menu_toggled();

private slots:
    // Compressor
    void on_btnCompressorState_released();
    void on_btnCompressorSettings_released();

    // Distortion
    void on_btnDistortionState_released();
    void on_btnDistortionSettings_released();

    // Overdrive
    void on_btnOverdrive1State_released();
    void on_btnOverdrive1Settings_released();

    // 8Band Eq
    void on_btnEqualizerState_released();
    void on_btnEqualizerSettings_released();

    // Reverb
    void on_btnReverb1State_released();
    void on_btnReverb1Settings_released();

    // Chorus
    void on_btnChorusState_released();
    void on_btnChorusSettings_released();

    // Flanger
    void on_btnFlangerState_released();
    void on_btnFlangerSettings_released();

    // Delay
    void on_btnDelay1State_released();
    void on_btnDelay1Settings_released();

    // Presets
    void on_btnPreset1_released();
    void on_btnPreset2_released();
    void on_btnPreset3_released();
    void on_btnPreset4_released();
    void on_btnPreset5_released();
    void on_btnPreset6_released();

    void on_btnSave_pressed();
    void on_btnSave_released();
    void on_btnLock_pressed();
    void on_btnLock_released();
};

#endif // MAINWINDOW_H
