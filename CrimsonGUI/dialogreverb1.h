#ifndef DIALOGREVERB1_H
#define DIALOGREVERB1_H

#include <QDialog>
#include "Fx.h"

namespace Ui {
class DialogReverb1;
}

class DialogReverb1 : public QDialog
{
    Q_OBJECT

public:
    explicit DialogReverb1(QWidget *parent = 0);
    ~DialogReverb1();
    void sendFxReverb1Param(Fx::Reverb1 reverb1);

private slots:
    void on_btnClose_released();
    void on_dialDryWet_valueChanged(int position);
    void on_dialRoomSize_valueChanged(int position);
    void on_dialDamping_valueChanged(int position);
    void on_btnPreset1_released();
    void on_btnPreset2_released();
    void on_btnPreset3_released();
    void presetSelector(int preset);

signals:
    void signal_dryWet_changed(int position);
    void signal_roomSize_changed(int position);
    void signal_damping_changed(int position);
    void signal_preset_changed(int preset);


private:
    Ui::DialogReverb1 *ui;
};

#endif // DIALOGREVERB1_H
