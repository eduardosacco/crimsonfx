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

void DialogDelay1::sendFxDelay1Param(FxDelay1 fxDelay1)
{
    ui->dialLevel->setValue(fxDelay1.level);
    ui->dialDelay->setValue(fxDelay1.delay);
    ui->dialFeedback->setValue(fxDelay1.feedback);
}

void DialogDelay1::on_tBtnClose_released()
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
