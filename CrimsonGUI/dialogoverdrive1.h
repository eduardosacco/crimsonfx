#ifndef DIALOGOVERDRIVE1_H
#define DIALOGOVERDRIVE1_H

#include <QDialog>
#include "Fx.h"

namespace Ui {
class DialogOverdrive1;
}

class DialogOverdrive1 : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOverdrive1(QWidget *parent = 0);
    ~DialogOverdrive1();
    void sendFxOverdrive1Param(Fx::Overdrive1 fxOverdrive1);

private slots:
    void on_btnClose_released();
    void on_dialGain_sliderMoved(int position);
    void on_dialDepth_sliderMoved(int position);
    void on_dialCutoff_sliderMoved(int position);
    void on_btnPreset1_released();
    void on_btnPreset2_released();
    void on_btnPreset3_released();

signals:
    void signal_gain_changed(int position);
    void signal_depth_changed(int position);
    void signal_cutoff_changed(int position);
    void signal_preset_changed(int preset);

private:
    Ui::DialogOverdrive1 *ui;
    void presetSelector(int preset);
};

#endif // DIALOGOVERDRIVE1_H
