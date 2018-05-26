#ifndef DIALOGOVERDRIVE1_H
#define DIALOGOVERDRIVE1_H

#include <QDialog>
#include "crimsontypes.h"


namespace Ui {
class DialogOverdrive1;
}

class DialogOverdrive1 : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOverdrive1(QWidget *parent = 0);
    ~DialogOverdrive1();
    void sendFxOverdrive1Param(FxOverdrive1 fxOverdrive1);

private slots:
    void on_tBtnClose_released();
    void on_dialGain_sliderMoved(int position);
    void on_dialDepth_sliderMoved(int position);
    void on_dialCutoff_sliderMoved(int position);

signals:
    void signal_gain_changed(int position);
    void signal_depth_changed(int position);
    void signal_cutoff_changed(int position);

private:
    Ui::DialogOverdrive1 *ui;
};

#endif // DIALOGOVERDRIVE1_H
