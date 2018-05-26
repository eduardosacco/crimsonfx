#ifndef DIALOGREVERB1_H
#define DIALOGREVERB1_H

#include <QDialog>
#include "crimsontypes.h"

namespace Ui {
class DialogReverb1;
}

class DialogReverb1 : public QDialog
{
    Q_OBJECT

public:
    explicit DialogReverb1(QWidget *parent = 0);
    ~DialogReverb1();
    void sendFxReverb1Param(FxReverb1 fxReverb1);

private slots:
    void on_tBtnClose_released();
    void on_dialDryWet_valueChanged(int position);
    void on_dialRoomSize_valueChanged(int position);
    void on_dialDamping_valueChanged(int position);

signals:
    void signal_dryWet_changed(int position);
    void signal_roomSize_changed(int position);
    void signal_damping_changed(int position);


private:
    Ui::DialogReverb1 *ui;
};

#endif // DIALOGREVERB1_H
