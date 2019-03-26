//--------------------------------------------------------------------------------------------------
//              DIALOGFX.H
//--------------------------------------------------------------------------------------------------

#ifndef DIALOGFX_H
#define DIALOGFX_H

#include <QDialog>
#include <QHBoxLayout>
#include <QDial>
#include <QLabel>

#include "fxbank.h"

//*****************************************************************
//                  DIALOG FX
//*****************************************************************
namespace Ui {
class DialogFx;
}

class DialogFx : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFx(QWidget *parent = nullptr);
    ~DialogFx();

    void dialogSettings(int fxNum,Effect fx);
    void setDialValues(Effect fx);
    void updateFxState(bool state);

private slots:
    // Cambio de valor de diales
    void slot_dial0_valueChanged(int position);
    void slot_dial1_valueChanged(int position);
    void slot_dial2_valueChanged(int position);
    void slot_dial3_valueChanged(int position);
    void slot_dial4_valueChanged(int position);
    void slot_dial5_valueChanged(int position);

    // Botones
    void on_btnClose_released();
    void on_btnOnOff_released();

signals:
    // Señales para emitir a MainWindow
    void signal_fx_state_changed(int fx);
    void signal_fx_param_changed(int fx, int param,int position);
    void signal_destroyed();

private:
    Ui::DialogFx *ui;

    int effect;

    // Diales
    QDial *dial0 = new QDial;
    QDial *dial1 = new QDial;
    QDial *dial2 = new QDial;
    QDial *dial3 = new QDial;
    QDial *dial4 = new QDial;
    QDial *dial5 = new QDial;

    // Labels
    QLabel *lblDial0 = new QLabel;
    QLabel *lblDial1 = new QLabel;
    QLabel *lblDial2 = new QLabel;
    QLabel *lblDial3 = new QLabel;
    QLabel *lblDial4 = new QLabel;
    QLabel *lblDial5 = new QLabel;

    // Layouts
    QHBoxLayout *row1 = new QHBoxLayout;
    QHBoxLayout *row2 = new QHBoxLayout;
    QHBoxLayout *row3 = new QHBoxLayout;
    QHBoxLayout *row4 = new QHBoxLayout;

    void setPBtnStyle(QPushButton *button, bool checked);
    void showDebugMsg(char *msg);
};

#endif // DIALOGFX_H
