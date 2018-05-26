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

void MainWindow::initPulse(int bankPreset)
{
    bankPresetSelector(bankPreset);
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
    case fxOverdrive:
        setPBtnStyle(ui->btnOverdrive1State,state);
        break;
    case fxEqualizer:
        setPBtnStyle(ui->btnEqualizerState,state);
        break;
    case fxReverb:
        setPBtnStyle(ui->btnReverb1State,state);
        break;
    case fxDelay:
        setPBtnStyle(ui->btnDelay1State,state);
        break;
    }
}

void MainWindow::on_btnCompressorState_released()
{
    emit signal_fx_state_toggled(fxCompressor);
}

void MainWindow::on_btnOverdrive1State_released()
{
    emit signal_fx_state_toggled(fxOverdrive);
}

void MainWindow::on_btnEqualizerState_released()
{
    emit signal_fx_state_toggled(fxEqualizer);
}

void MainWindow::on_btnReverb1State_released()
{
    emit signal_fx_state_toggled(fxReverb);
}

void MainWindow::on_btnDelay1State_released()
{
    emit signal_fx_state_toggled(fxDelay);
}

void MainWindow::on_btnCompressorSettings_released()
{
    emit signal_dialogFx_open(fxCompressor);
}

void MainWindow::on_btnOverdrive1Settings_released()
{
    emit signal_dialogFx_open(fxOverdrive);
}

void MainWindow::on_btnEqualizerSet_released()
{
    emit signal_dialogFx_open(fxEqualizer);
}

void MainWindow::on_btnReverb1Settings_released()
{
    emit signal_dialogFx_open(fxReverb);
}

void MainWindow::on_btnDelay1Settings_released()
{
    emit signal_dialogFx_open(fxDelay);
}

void MainWindow::on_btnPreset1_released()
{
    bankPresetSelector(1);
}

void MainWindow::on_btnPreset2_released()
{
    bankPresetSelector(2);
}

void MainWindow::on_btnPreset3_released()
{
    bankPresetSelector(3);
}

void MainWindow::bankPresetSelector(int preset)
{
    switch(preset)
    {
        case 1:
        setPBtnStyle(ui->btnPreset1,true);
        setPBtnStyle(ui->btnPreset2,false);
        setPBtnStyle(ui->btnPreset3,false);
        emit signal_bankPreset_changed(1);
        break;

        case 2:
        setPBtnStyle(ui->btnPreset1,false);
        setPBtnStyle(ui->btnPreset2,true);
        setPBtnStyle(ui->btnPreset3,false);
        emit signal_bankPreset_changed(2);
        break;

        case 3:
        setPBtnStyle(ui->btnPreset1,false);
        setPBtnStyle(ui->btnPreset2,false);
        setPBtnStyle(ui->btnPreset3,true);
        emit signal_bankPreset_changed(3);
        break;
    }

}

void MainWindow::setPBtnStyle(QPushButton *button, bool checked)
{
    if(checked)
        button->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #dc143c, stop: 1 #a60f2d)");
    else
        button->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
}


