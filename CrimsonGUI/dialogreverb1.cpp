#include "dialogreverb1.h"
#include "ui_dialogreverb1.h"


DialogReverb1::DialogReverb1( QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogReverb1)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
}

DialogReverb1::~DialogReverb1()
{
    delete ui;
}

void DialogReverb1::sendFxReverb1Param(Fx::Reverb1 reverb1)
{
    ui->dialDryWet->setValue(reverb1.dryWet);
    ui->dialRoomSize->setValue(reverb1.roomSize);
    ui->dialDamping->setValue(reverb1.damping);
}

void DialogReverb1::on_btnClose_released()
{
    this->close();
}

void DialogReverb1::on_dialDamping_valueChanged(int position)
{
    emit signal_damping_changed(position);
}

void DialogReverb1::on_dialRoomSize_valueChanged(int position)
{
    emit signal_roomSize_changed(position);
}

void DialogReverb1::on_dialDryWet_valueChanged(int position)
{
    emit signal_dryWet_changed(position);
}

void DialogReverb1::on_btnPreset1_released()
{
    presetSelector(1);
}

void DialogReverb1::on_btnPreset2_released()
{
    presetSelector(2);
}

void DialogReverb1::on_btnPreset3_released()
{
    presetSelector(3);
}

void DialogReverb1::presetSelector(int preset)
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

