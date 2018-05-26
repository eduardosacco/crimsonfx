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

void DialogFx::dialogSettings(int fxNum,Effect fx)
{           
    //Aca hay que inicializar los botones de encendido y apagado de los
    // efectos y del preset en el que esten

    effect = fxNum;

    ui->btnOnOff->setChecked(fx.state);

    //Esto se podria evitar haciendo un for
    //si es que se usaran arreglos de punteros a botones
    switch(fx.preset)
    {
    case PRESET1:
        setPBtnStyle(ui->btnPreset1,true);
        break;
    case PRESET2:
        setPBtnStyle(ui->btnPreset2,true);
        break;
    case PRESET3:
        setPBtnStyle(ui->btnPreset3,true);
        break;
    }

    if(fx.state)
        ui->btnOnOff->setChecked(true);

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

void DialogFx::setDialValues(Effect fx)
{

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
        setPBtnStyle(ui->btnPreset1,true);
        setPBtnStyle(ui->btnPreset2,false);
        setPBtnStyle(ui->btnPreset3,false);
        emit signal_fx_preset_changed(effect,preset);

        break;

        case 2:
        setPBtnStyle(ui->btnPreset1,false);
        setPBtnStyle(ui->btnPreset2,true);
        setPBtnStyle(ui->btnPreset3,false);
        emit signal_fx_preset_changed(effect,preset);
        break;

        case 3:
        setPBtnStyle(ui->btnPreset1,false);
        setPBtnStyle(ui->btnPreset2,false);
        setPBtnStyle(ui->btnPreset3,true);
        emit signal_fx_preset_changed(effect,preset);
        break;

    }
}

void DialogFx::on_btnOnOff_toggled(bool checked)
{
    setPBtnStyle(ui->btnOnOff,checked);
    emit signal_fx_state_changed(effect,checked);
}

void DialogFx::on_btnClose_released()
{
    this->close();
}

void DialogFx::setPBtnStyle(QPushButton *button, bool checked)
{
    if(checked)
        button->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #dc143c, stop: 1 #a60f2d)");
    else
        button->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
}

