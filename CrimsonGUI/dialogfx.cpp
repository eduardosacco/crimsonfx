#include "dialogfx.h"
#include "ui_dialogfx.h"

DialogFx::DialogFx(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFx)
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);

}

DialogFx::~DialogFx()
{
    delete ui;
}

void DialogFx::dialogSettings(int fx)
{           
    effect = fx;

    //Esta funcion debe crear dinamicamente
    //los widgets necesarios para cada efecto

    dial0->setNotchesVisible(true);
    dial1->setNotchesVisible(true);
    dial2->setNotchesVisible(true);
    dial3->setNotchesVisible(true);
    dial4->setNotchesVisible(true);



//    rowOne->setAlignment(Qt::AlignJustify);
//    row2->setAlignment(Qt::AlignJustify);

    ui->vLayout->addLayout(row1); //hehe rowOne a Star Wars Stwory
    ui->vLayout->addLayout(row2);
    ui->vLayout->addLayout(row3);
    ui->vLayout->addLayout(row4);

    row1->addWidget(dial0);
    row1->addWidget(dial1);
    row2->addWidget(lblDial0);
    row2->addWidget(lblDial1);
    row3->addWidget(dial2);
    row3->addWidget(dial3);
    row3->addWidget(dial4);
    row4->addWidget(lblDial2);
    row4->addWidget(lblDial3);
    row4->addWidget(lblDial4);


    connect(dial0,SIGNAL(valueChanged(int)),
            this,SLOT(slot_dial0_valueChanged(int)));
    connect(dial1,SIGNAL(valueChanged(int)),
            this,SLOT(slot_dial1_valueChanged(int)));
    connect(dial2,SIGNAL(valueChanged(int)),
            this,SLOT(slot_dial2_valueChanged(int)));
    connect(dial3,SIGNAL(valueChanged(int)),
            this,SLOT(slot_dial3_valueChanged(int)));
    connect(dial4,SIGNAL(valueChanged(int)),
            this,SLOT(slot_dial4_valueChanged(int)));

    this->show();

}

void DialogFx::slot_dial0_valueChanged(int position)
{
    emit signal_fx_param_changed(effect,PARAM0,position);
}

void DialogFx::slot_dial1_valueChanged(int position)
{
    emit signal_fx_param_changed(effect,PARAM1,position);
}

void DialogFx::slot_dial2_valueChanged(int position)
{
    emit signal_fx_param_changed(effect,PARAM2,position);
}

void DialogFx::slot_dial3_valueChanged(int position)
{
    emit signal_fx_param_changed(effect,PARAM3,position);
}

void DialogFx::slot_dial4_valueChanged(int position)
{
    emit signal_fx_param_changed(effect,PARAM4,position);
}

void DialogFx::on_btnPreset1_released()
{
    presetSelector(PRESET1);
}

void DialogFx::on_btnPreset2_released()
{
    presetSelector(PRESET2);
}

void DialogFx::on_btnPreset3_released()
{
    presetSelector(PRESET3);
}

void DialogFx::presetSelector(int preset)
{
    switch(preset)
    {
        case 1:
        ui->btnPreset1->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #dc143c, stop: 1 #a60f2d)");
        ui->btnPreset2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
        ui->btnPreset3->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
        emit signal_preset_changed(effect,preset);

        break;

        case 2:
        ui->btnPreset2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #dc143c, stop: 1 #a60f2d)");
        ui->btnPreset1->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
        ui->btnPreset3->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
        emit signal_preset_changed(effect,preset);
        break;

        case 3:
        ui->btnPreset3->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #dc143c, stop: 1 #a60f2d)");
        ui->btnPreset1->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
        ui->btnPreset2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
        emit signal_preset_changed(effect,preset);
        break;

    }

}

void DialogFx::on_btnClose_released()
{
    this->close();
}
