#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Es usada cuando el cambio no se produce desde mainwindow sino de crimson
//basicamente cuando se carga un nuevo bank preset
void MainWindow::updateFxState(int fxNum, bool state)
{
    //Actualizar la GUI con los estados de los efectos
    switch(fxNum)
    {
    case fxCompressor:
        setPBtnStyle(ui->btnCompressorState,state);
        break;
    case fxDistortion:
        setPBtnStyle(ui->btnDistortionState,state);
        break;
    case fxOverdrive:
        setPBtnStyle(ui->btnOverdrive1State,state);
        break;
    case fxEqualizer:
        setPBtnStyle(ui->btnEqualizerState,state);
        break;
    case fxChorus:
        setPBtnStyle(ui->btnChorusState,state);
        break;
    case fxFlanger:
        setPBtnStyle(ui->btnFlangerState,state);
        break;
    case fxReverb:
        setPBtnStyle(ui->btnReverb1State,state);
        break;
    case fxDelay:
        setPBtnStyle(ui->btnDelay1State,state);
        break;
    }
}

//++++++++++ Compressor ++++++++++
void MainWindow::on_btnCompressorState_released()
{
    emit signal_fx_state_toggled(fxCompressor);
}

void MainWindow::on_btnCompressorSettings_released()
{
    emit signal_dialogFx_open(fxCompressor);
}

//++++++++++ Overdrive ++++++++++
void MainWindow::on_btnOverdrive1State_released()
{
    emit signal_fx_state_toggled(fxOverdrive);
}

void MainWindow::on_btnOverdrive1Settings_released()
{
    emit signal_dialogFx_open(fxOverdrive);
}

//++++++++++ Equalizer ++++++++++
void MainWindow::on_btnEqualizerState_released()
{
    emit signal_fx_state_toggled(fxEqualizer);
}

void MainWindow::on_btnEqualizerSettings_released()
{
    emit signal_dialogFx_open(fxEqualizer);
}

//++++++++++ Reverb ++++++++++
void MainWindow::on_btnReverb1State_released()
{
    emit signal_fx_state_toggled(fxReverb);
}

void MainWindow::on_btnReverb1Settings_released()
{
    emit signal_dialogFx_open(fxReverb);
}

//++++++++++ Delay ++++++++++
void MainWindow::on_btnDelay1State_released()
{
    emit signal_fx_state_toggled(fxDelay);
}

void MainWindow::on_btnDelay1Settings_released()
{
    emit signal_dialogFx_open(fxDelay);
}

//++++++++++ Disto ++++++++++
void MainWindow::on_btnDistortionState_released()
{
    emit signal_fx_state_toggled(fxDistortion);
}

void MainWindow::on_btnDistortionSettings_released()
{
    emit signal_dialogFx_open(fxDistortion);
}

//++++++++++ Flanger ++++++++++
void MainWindow::on_btnFlangerState_released()
{
    emit signal_fx_state_toggled(fxFlanger);
}

void MainWindow::on_btnFlangerSettings_released()
{
    emit signal_dialogFx_open(fxFlanger);
}

//++++++++++ Chorus ++++++++++
void MainWindow::on_btnChorusState_released()
{
    emit signal_fx_state_toggled(fxChorus);
}

void MainWindow::on_btnChorusSettings_released()
{
    emit signal_dialogFx_open(fxChorus);
}

//++++++++++ Presets ++++++++++
void MainWindow::on_btnPreset1_released()
{
    bankPresetSelector(bPreset1);
}

void MainWindow::on_btnPreset2_released()
{
    bankPresetSelector(bPreset2);
}

void MainWindow::on_btnPreset3_released()
{
    bankPresetSelector(bPreset3);
}

void MainWindow::on_btnPreset4_released()
{
    bankPresetSelector(bPreset4);
}

void MainWindow::on_btnPreset5_released()
{
    bankPresetSelector(bPreset5);
}

void MainWindow::on_btnPreset6_released()
{
    bankPresetSelector(bPreset6);
}

void MainWindow::on_btnSave_released()
{
    emit signal_preset_saved();
}

void MainWindow::bankPresetSelector(int preset)
{
    //Apago todos los botones
    setPBtnStyle(ui->btnPreset1,false);
    setPBtnStyle(ui->btnPreset2,false);
    setPBtnStyle(ui->btnPreset3,false);
    setPBtnStyle(ui->btnPreset4,false);
    setPBtnStyle(ui->btnPreset5,false);
    setPBtnStyle(ui->btnPreset6,false);

    //prendo el boton que corresponda
    switch(preset)
    {
        case bPreset1:
        setPBtnStyle(ui->btnPreset1,true);
        break;

        case bPreset2:
        setPBtnStyle(ui->btnPreset2,true);
        break;

        case bPreset3:
        setPBtnStyle(ui->btnPreset3,true);
        break;

        case bPreset4:
        setPBtnStyle(ui->btnPreset4,true);
        break;

        case bPreset5:
        setPBtnStyle(ui->btnPreset5,true);
        break;

        case bPreset6:
        setPBtnStyle(ui->btnPreset6,true);
        break;
    }
    //emito la señal
    emit signal_preset_changed(preset);
}

void MainWindow::setPBtnStyle(QPushButton *button, bool checked)
{
    if(checked)
        button->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #dc143c, stop: 1 #a60f2d)");
    else
        button->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
}

