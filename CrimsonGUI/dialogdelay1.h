#ifndef DIALOGDELAY1_H
#define DIALOGDELAY1_H

#include <QDialog>
#include "Fx.h"

namespace Ui {
class DialogDelay1;
}

class DialogDelay1 : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDelay1(QWidget *parent = 0);
    ~DialogDelay1();
    void sendFxDelay1Param(Fx::Delay1 delay1);

private slots:
    void on_btnClose_released();
    void on_dialLevel_valueChanged(int position);
    void on_dialDelay_valueChanged(int position);
    void on_dialFeedback_valueChanged(int position);
    void on_btnPreset1_released();
    void on_btnPreset2_released();
    void on_btnPreset3_released();
    void presetSelector(int preset);

signals:
    void signal_level_changed(int position);
    void signal_delay_changed(int position);
    void signal_feedback_changed(int position);
    void signal_preset_changed(int preset);

private:
    Ui::DialogDelay1 *ui;
};

#endif // DIALOGDELAY1_H
