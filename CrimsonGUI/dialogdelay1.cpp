#include "dialogdelay1.h"
#include "ui_dialogdelay1.h"

DialogDelay1::DialogDelay1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDelay1)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
}

DialogDelay1::~DialogDelay1()
{
    delete ui;
}

void DialogDelay1::sendFxDelay1Param(Fx::Delay1 delay1)
{
    ui->dialLevel->setValue(delay1.level);
    ui->dialDelay->setValue(delay1.delay);
    ui->dialFeedback->setValue(delay1.feedback);
}

void DialogDelay1::on_btnClose_released()
{
    this->close();
}

void DialogDelay1::on_dialLevel_valueChanged(int position)
{
    emit signal_level_changed(position);
}

void DialogDelay1::on_dialDelay_valueChanged(int position)
{
    emit signal_delay_changed(position);
}

void DialogDelay1::on_dialFeedback_valueChanged(int position)
{
    emit signal_feedback_changed(position);
}

void DialogDelay1::on_btnPreset1_released()
{
    presetSelector(1);
}

void DialogDelay1::on_btnPreset2_released()
{
    presetSelector(2);
}

void DialogDelay1::on_btnPreset3_released()
{
    presetSelector(3);
}

void DialogDelay1::presetSelector(int preset)
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
