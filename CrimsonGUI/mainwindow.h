#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //Compressor
    void on_pBtnFx1_released();
    //Overdrive
    void on_pBtnFx2_released();
    //8Band Eq
    void on_pBtnFx3_released();
    //Reverb
    void on_pBtnFx4_released();
    //Relay
    void on_pBtnFx5_released();
    //Exit program.... Este boton es solo de debuggeo
    void on_pBtnExit_released();

signals:
    void signal_dialogCompressor1_open();
    void signal_dialogOverdrive1_open();
    void signal_dialog8BandEqualizer_open();
    void signal_dialogReverb1_open();
    void signal_dialogDelay1_open();
    void signal_mainWindow_exit();

    
private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
