#include "dialogreverb1.h"
#include "ui_dialogreverb1.h"
#include "crimson.h"

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

void DialogReverb1::sendFxReverb1Param(FxReverb1 fxReverb1)
{
    ui->dialDryWet->setValue(fxReverb1.dryWet);
    ui->dialRoomSize->setValue(fxReverb1.roomSize);
    ui->dialDamping->setValue(fxReverb1.damping);
}

void DialogReverb1::on_tBtnClose_released()
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
