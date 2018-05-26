#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pBtnFx1_released()
{
    emit signal_dialogCompressor1_open();
}

void MainWindow::on_pBtnFx2_released()
{
    emit signal_dialogOverdrive1_open();
}

void MainWindow::on_pBtnFx3_released()
{
    emit signal_dialog8BandEqualizer_open();
}

void MainWindow::on_pBtnFx4_released()
{
    emit signal_dialogReverb1_open();
}

void MainWindow::on_pBtnFx5_released()
{
    emit signal_dialogDelay1_open();
}

void MainWindow::on_pBtnExit_released()
{
    emit signal_mainWindow_exit();
}
