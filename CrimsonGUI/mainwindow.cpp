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
void MainWindow::updateFxStates(FxBank fxBank)
{
    //Actualizar la GUI con los estados de los efectos

    //DESPUES HABRIA QUE HACER UN FOR LOOP
    //Si tuviesemos un arreglo de punteros a pBtns
    setPBtnStyle(ui->btnCompressorState,fxBank.fx[fxCompressor].state);
    setPBtnStyle(ui->btnOverdrive1State,fxBank.fx[fxOverdrive].state);
    setPBtnStyle(ui->btnEqualizerState,fxBank.fx[fxEqualizer].state);
    setPBtnStyle(ui->btnReverb1State,fxBank.fx[fxReverb].state);
    setPBtnStyle(ui->btnDelay1State,fxBank.fx[fxDelay].state);
}

void MainWindow::on_btnCompressorState_toggled(bool checked)
{
    setPBtnStyle(ui->btnCompressorState,checked);
    emit signal_fx_state_toggled(fxCompressor,checked);
}

void MainWindow::on_btnCompressorSettings_released()
{
    emit signal_dialogFx_open(fxCompressor);
}

void MainWindow::on_btnOverdrive1State_toggled(bool checked)
{
    setPBtnStyle(ui->btnOverdrive1State,checked);
    emit signal_fx_state_toggled(fxOverdrive,checked);
}

void MainWindow::on_btnOverdrive1Settings_released()
{
    emit signal_dialogFx_open(fxOverdrive);
}

void MainWindow::on_btnEqualizerState_toggled(bool checked)
{
    setPBtnStyle(ui->btnEqualizerState,checked);
    emit signal_fx_state_toggled(fxEqualizer,checked);
}

void MainWindow::on_btnEqualizerSet_released()
{
    emit signal_dialogFx_open(fxEqualizer);
}

void MainWindow::on_btnReverb1State_toggled(bool checked)
{
    setPBtnStyle(ui->btnReverb1State,checked);
    emit signal_fx_state_toggled(fxReverb,checked);
}

void MainWindow::on_btnReverb1Settings_released()
{
    emit signal_dialogFx_open(fxReverb);
}

void MainWindow::on_btnDelay1State_toggled(bool checked)
{
    setPBtnStyle(ui->btnDelay1State,checked);
    emit signal_fx_state_toggled(fxDelay,checked);
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
