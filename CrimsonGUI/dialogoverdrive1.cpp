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

void DialogOverdrive1::sendFxOverdrive1Param(FxOverdrive1 fxOverdrive1)
{
    ui->dialGain->setValue(fxOverdrive1.gain);
    ui->dialDepth->setValue(fxOverdrive1.depth);
    ui->dialCutoff->setValue(fxOverdrive1.cutoff);
}

void DialogOverdrive1::on_tBtnClose_released()
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
