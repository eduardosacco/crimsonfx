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

void MainWindow::on_btnExit_released()
{
    emit signal_mainWindow_exit();
}

void MainWindow::on_btnCompressorState_toggled(bool checked)
{
    emit signal_fxCompressor_state_toggled(checked);
}

void MainWindow::on_btnCompressorSettings_released()
{
    emit signal_dialogCompressor_open();
}

void MainWindow::on_btnOverdrive1State_toggled(bool checked)
{
    emit signal_fxOverdrive1_state_toggled(checked);
}

void MainWindow::on_btnOverdrive1Settings_released()
{
    emit signal_dialogOverdrive1_open();
}

void MainWindow::on_btnEqualizerState_toggled(bool checked)
{
    emit signal_fx8BandEqualizer_state_toggled(checked);
}

void MainWindow::on_btnEqualizerSet_released()
{
    emit signal_dialog8BandEqualizer_open();
}

void MainWindow::on_btnReverb1State_toggled(bool checked)
{
    emit signal_fxReverb1_state_toggled(checked);
}

void MainWindow::on_btnReverb1Settings_released()
{
    emit signal_dialogReverb1_open();
}

void MainWindow::on_btnDelay1State_toggled(bool checked)
{
    emit signal_fxDelay1_state_toggled(checked);
}

void MainWindow::on_btnDelay1Settings_released()
{
    emit signal_dialogDelay1_open();
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
        ui->btnPreset1->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #dc143c, stop: 1 #a60f2d)");
        ui->btnPreset2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
        ui->btnPreset3->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
        emit signal_bankPreset_changed(1);

        break;

        case 2:
        ui->btnPreset2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #dc143c, stop: 1 #a60f2d)");
        ui->btnPreset1->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
        ui->btnPreset3->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
        emit signal_bankPreset_changed(2);
        break;

        case 3:
        ui->btnPreset3->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #dc143c, stop: 1 #a60f2d)");
        ui->btnPreset1->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
        ui->btnPreset2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
        emit signal_bankPreset_changed(3);
        break;
    }

}

//Es usada cuando el cambio no se produce desde mainwindow sino de crimson
//basicamente cuando se carga un nuevo bank preset
void MainWindow::updateFxStates(Fx::Bank bank)
{
    //Actualizar la GUI con los estados de los efectos
    ui->btnOverdrive1State->setChecked(bank.overdrive1State);
    ui->btnReverb1State->setChecked(bank.reverb1State);
    ui->btnDelay1State->setChecked(bank.delay1State);
}
