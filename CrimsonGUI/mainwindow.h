#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "fxbank.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initPulse(int bankPreset);
    void updateFxStates(FxBank fxBank);

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

    //Presets
    void on_btnPreset1_released();
    void on_btnPreset2_released();
    void on_btnPreset3_released();

signals:
    //Señales ON OFF Switches
    void signal_fx_state_toggled(int fx,bool state);
    void signal_dialogFx_open(int fx);
    void signal_bankPreset_changed(int preset);
    
private:
    Ui::MainWindow *ui;
    void bankPresetSelector(int preset);
    void setPBtnStyle(QPushButton *button, bool checked);

};

#endif // MAINWINDOW_H
