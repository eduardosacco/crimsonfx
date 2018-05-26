#include "dialogoverdrive1.h"
#include "ui_dialogoverdrive1.h"


DialogOverdrive1::DialogOverdrive1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOverdrive1)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
}

DialogOverdrive1::~DialogOverdrive1()
{
    delete ui;
}

void DialogOverdrive1::sendFxOverdrive1Param(Fx::Overdrive1 overdrive1)
{
    ui->dialGain->setValue(overdrive1.gain);
    ui->dialDepth->setValue(overdrive1.depth);
    ui->dialCutoff->setValue(overdrive1.cutoff);
}

void DialogOverdrive1::on_btnClose_released()
{
    this->hide();
}

void DialogOverdrive1::on_dialGain_sliderMoved(int position)
{
    emit signal_gain_changed(position);
}

void DialogOverdrive1::on_dialDepth_sliderMoved(int position)
{
    emit signal_depth_changed(position);
}

void DialogOverdrive1::on_dialCutoff_sliderMoved(int position)
{
    emit signal_cutoff_changed(position);
}

void DialogOverdrive1::on_btnPreset1_released()
{
    presetSelector(1);
}

void DialogOverdrive1::on_btnPreset2_released()
{
    presetSelector(2);
}

void DialogOverdrive1::on_btnPreset3_released()
{
    presetSelector(3);
}

void DialogOverdrive1::presetSelector(int preset)
{
    switch(preset)
    {
        case 1:
        ui->btnPreset1->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #dc143c, stop: 1 #a60f2d)");
        ui->btnPreset2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
        ui->btnPreset3->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
        emit signal_preset_changed(1);

        break;

        case 2:
        ui->btnPreset2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #dc143c, stop: 1 #a60f2d)");
        ui->btnPreset1->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
        ui->btnPreset3->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
        emit signal_preset_changed(2);
        break;

        case 3:
        ui->btnPreset3->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #dc143c, stop: 1 #a60f2d)");
        ui->btnPreset1->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
        ui->btnPreset2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
        emit signal_preset_changed(3);
        break;

    }

}
