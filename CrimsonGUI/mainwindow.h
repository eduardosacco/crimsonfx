#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fx.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void updateFxStates(Fx::Bank bank);

private slots:
    //Compressor
    void on_btnCompressorState_toggled(bool checked);
    void on_btnCompressorSettings_released();

    //Overdrive
    void on_btnOverdrive1State_toggled(bool checked);
    void on_btnOverdrive1Settings_released();

    //8Band Eq
    void on_btnEqualizerState_toggled(bool checked);
    void on_btnEqualizerSet_released();

    //Reverb
    void on_btnReverb1State_toggled(bool checked);
    void on_btnReverb1Settings_released();

    //Delay
    void on_btnDelay1State_toggled(bool checked);
    void on_btnDelay1Settings_released();

    //Exit program.... Este boton es solo de debuggeo
    void on_btnExit_released();

    //Presets
    void on_btnPreset1_released();
    void on_btnPreset2_released();
    void on_btnPreset3_released();

signals:
    //Señales ON OFF Switches
    void signal_fxCompressor_state_toggled(bool state);
    void signal_fxOverdrive1_state_toggled(bool state);
    void signal_fx8BandEqualizer_state_toggled(bool state);
    void signal_fxReverb1_state_toggled(bool state);
    void signal_fxDelay1_state_toggled(bool state);

    void signal_dialogCompressor_open();
    void signal_dialogOverdrive1_open();
    void signal_dialog8BandEqualizer_open();
    void signal_dialogReverb1_open();
    void signal_dialogDelay1_open();

    void signal_bankPreset_changed(int preset);

    void signal_mainWindow_exit();

    
private:
    Ui::MainWindow *ui;
    void bankPresetSelector(int preset);

};

#endif // MAINWINDOW_H
