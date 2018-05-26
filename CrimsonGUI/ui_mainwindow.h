/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnOverdrive1Settings;
    QPushButton *btnEqualizerSet;
    QPushButton *btnEqualizerState;
    QPushButton *btnOverdrive1State;
    QPushButton *btnCompressorState;
    QPushButton *btnDelay1State;
    QPushButton *btnReverb1State;
    QPushButton *btnReverb1Settings;
    QPushButton *btnDelay1Settings;
    QPushButton *btnCompressorSettings;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPreset1;
    QPushButton *btnPreset2;
    QPushButton *btnPreset3;
    QPushButton *btnPreset4;
    QPushButton *btnPreset5;
    QPushButton *btnPreset6;
    QLabel *label;
    QPushButton *btnSave;
    QPushButton *btnDSPOnOff;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 400);
        MainWindow->setStyleSheet(QLatin1String("QMainWindow{\n"
"background-color:#1d1d1d;\n"
"}\n"
"QDial{\n"
"background-color: #4a4a4a;\n"
"}\n"
"QPushButton {\n"
"font:14pt;\n"
"font-family:Segoe UI;\n"
"color:#fff;\n"
"border: 0px;\n"
"border-radius: 6px;      \n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67,  stop: 0 #4a4a4a, stop: 1 #3d3d3d);\n"
"}\n"
" QPushButton:pressed {\n"
"font:14pt;\n"
"font-family:Segoe UI;\n"
"color:#fff;\n"
"border: 0px;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #3d3d3d, stop: 1 #303030);\n"
"}\n"
"QLabel{\n"
"font:14pt;\n"
"font-family:Segoe UI;\n"
"color:#fff;\n"
"qproperty-alignment:AlignCenter;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 196, 581, 191));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnOverdrive1Settings = new QPushButton(gridLayoutWidget);
        btnOverdrive1Settings->setObjectName(QStringLiteral("btnOverdrive1Settings"));
        btnOverdrive1Settings->setMinimumSize(QSize(0, 40));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOverdrive1Settings->setIcon(icon);
        btnOverdrive1Settings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnOverdrive1Settings, 1, 1, 1, 1);

        btnEqualizerSet = new QPushButton(gridLayoutWidget);
        btnEqualizerSet->setObjectName(QStringLiteral("btnEqualizerSet"));
        btnEqualizerSet->setMinimumSize(QSize(0, 40));
        btnEqualizerSet->setIcon(icon);
        btnEqualizerSet->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnEqualizerSet, 1, 2, 1, 1);

        btnEqualizerState = new QPushButton(gridLayoutWidget);
        btnEqualizerState->setObjectName(QStringLiteral("btnEqualizerState"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnEqualizerState->sizePolicy().hasHeightForWidth());
        btnEqualizerState->setSizePolicy(sizePolicy);
        btnEqualizerState->setMinimumSize(QSize(80, 80));
        btnEqualizerState->setCheckable(true);

        gridLayout->addWidget(btnEqualizerState, 0, 2, 1, 1);

        btnOverdrive1State = new QPushButton(gridLayoutWidget);
        btnOverdrive1State->setObjectName(QStringLiteral("btnOverdrive1State"));
        sizePolicy.setHeightForWidth(btnOverdrive1State->sizePolicy().hasHeightForWidth());
        btnOverdrive1State->setSizePolicy(sizePolicy);
        btnOverdrive1State->setMinimumSize(QSize(80, 80));
        btnOverdrive1State->setCheckable(true);

        gridLayout->addWidget(btnOverdrive1State, 0, 1, 1, 1);

        btnCompressorState = new QPushButton(gridLayoutWidget);
        btnCompressorState->setObjectName(QStringLiteral("btnCompressorState"));
        sizePolicy.setHeightForWidth(btnCompressorState->sizePolicy().hasHeightForWidth());
        btnCompressorState->setSizePolicy(sizePolicy);
        btnCompressorState->setMinimumSize(QSize(80, 80));
        btnCompressorState->setCheckable(true);

        gridLayout->addWidget(btnCompressorState, 0, 0, 1, 1);

        btnDelay1State = new QPushButton(gridLayoutWidget);
        btnDelay1State->setObjectName(QStringLiteral("btnDelay1State"));
        sizePolicy.setHeightForWidth(btnDelay1State->sizePolicy().hasHeightForWidth());
        btnDelay1State->setSizePolicy(sizePolicy);
        btnDelay1State->setMinimumSize(QSize(80, 80));
        btnDelay1State->setCheckable(true);

        gridLayout->addWidget(btnDelay1State, 0, 4, 1, 1);

        btnReverb1State = new QPushButton(gridLayoutWidget);
        btnReverb1State->setObjectName(QStringLiteral("btnReverb1State"));
        sizePolicy.setHeightForWidth(btnReverb1State->sizePolicy().hasHeightForWidth());
        btnReverb1State->setSizePolicy(sizePolicy);
        btnReverb1State->setMinimumSize(QSize(80, 80));
        btnReverb1State->setCheckable(true);

        gridLayout->addWidget(btnReverb1State, 0, 3, 1, 1);

        btnReverb1Settings = new QPushButton(gridLayoutWidget);
        btnReverb1Settings->setObjectName(QStringLiteral("btnReverb1Settings"));
        btnReverb1Settings->setMinimumSize(QSize(0, 40));
        btnReverb1Settings->setIcon(icon);
        btnReverb1Settings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnReverb1Settings, 1, 3, 1, 1);

        btnDelay1Settings = new QPushButton(gridLayoutWidget);
        btnDelay1Settings->setObjectName(QStringLiteral("btnDelay1Settings"));
        btnDelay1Settings->setMinimumSize(QSize(0, 40));
        btnDelay1Settings->setIcon(icon);
        btnDelay1Settings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnDelay1Settings, 1, 4, 1, 1);

        btnCompressorSettings = new QPushButton(gridLayoutWidget);
        btnCompressorSettings->setObjectName(QStringLiteral("btnCompressorSettings"));
        btnCompressorSettings->setMinimumSize(QSize(40, 40));
        btnCompressorSettings->setIcon(icon);
        btnCompressorSettings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnCompressorSettings, 1, 0, 1, 1);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 100, 581, 91));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnPreset1 = new QPushButton(horizontalLayoutWidget);
        btnPreset1->setObjectName(QStringLiteral("btnPreset1"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnPreset1->sizePolicy().hasHeightForWidth());
        btnPreset1->setSizePolicy(sizePolicy1);
        btnPreset1->setMinimumSize(QSize(80, 40));

        horizontalLayout->addWidget(btnPreset1);

        btnPreset2 = new QPushButton(horizontalLayoutWidget);
        btnPreset2->setObjectName(QStringLiteral("btnPreset2"));
        sizePolicy1.setHeightForWidth(btnPreset2->sizePolicy().hasHeightForWidth());
        btnPreset2->setSizePolicy(sizePolicy1);
        btnPreset2->setMinimumSize(QSize(80, 40));

        horizontalLayout->addWidget(btnPreset2);

        btnPreset3 = new QPushButton(horizontalLayoutWidget);
        btnPreset3->setObjectName(QStringLiteral("btnPreset3"));
        sizePolicy1.setHeightForWidth(btnPreset3->sizePolicy().hasHeightForWidth());
        btnPreset3->setSizePolicy(sizePolicy1);
        btnPreset3->setMinimumSize(QSize(80, 40));

        horizontalLayout->addWidget(btnPreset3);

        btnPreset4 = new QPushButton(horizontalLayoutWidget);
        btnPreset4->setObjectName(QStringLiteral("btnPreset4"));
        sizePolicy1.setHeightForWidth(btnPreset4->sizePolicy().hasHeightForWidth());
        btnPreset4->setSizePolicy(sizePolicy1);
        btnPreset4->setMinimumSize(QSize(80, 40));

        horizontalLayout->addWidget(btnPreset4);

        btnPreset5 = new QPushButton(horizontalLayoutWidget);
        btnPreset5->setObjectName(QStringLiteral("btnPreset5"));
        sizePolicy1.setHeightForWidth(btnPreset5->sizePolicy().hasHeightForWidth());
        btnPreset5->setSizePolicy(sizePolicy1);
        btnPreset5->setMinimumSize(QSize(80, 40));

        horizontalLayout->addWidget(btnPreset5);

        btnPreset6 = new QPushButton(horizontalLayoutWidget);
        btnPreset6->setObjectName(QStringLiteral("btnPreset6"));
        sizePolicy1.setHeightForWidth(btnPreset6->sizePolicy().hasHeightForWidth());
        btnPreset6->setSizePolicy(sizePolicy1);
        btnPreset6->setMinimumSize(QSize(80, 40));

        horizontalLayout->addWidget(btnPreset6);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 10, 221, 81));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/crimsonLogo.png")));
        label->setScaledContents(true);
        btnSave = new QPushButton(centralWidget);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setGeometry(QRect(500, 10, 80, 80));
        sizePolicy1.setHeightForWidth(btnSave->sizePolicy().hasHeightForWidth());
        btnSave->setSizePolicy(sizePolicy1);
        btnSave->setMinimumSize(QSize(80, 80));
        btnDSPOnOff = new QPushButton(centralWidget);
        btnDSPOnOff->setObjectName(QStringLiteral("btnDSPOnOff"));
        btnDSPOnOff->setGeometry(QRect(20, 10, 80, 80));
        sizePolicy1.setHeightForWidth(btnDSPOnOff->sizePolicy().hasHeightForWidth());
        btnDSPOnOff->setSizePolicy(sizePolicy1);
        btnDSPOnOff->setMinimumSize(QSize(80, 80));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        btnOverdrive1Settings->setText(QString());
        btnEqualizerSet->setText(QString());
        btnEqualizerState->setText(QApplication::translate("MainWindow", "Equalizer", Q_NULLPTR));
        btnOverdrive1State->setText(QApplication::translate("MainWindow", "Overdrive", Q_NULLPTR));
        btnCompressorState->setText(QApplication::translate("MainWindow", "Compressor", Q_NULLPTR));
        btnDelay1State->setText(QApplication::translate("MainWindow", "Delay", Q_NULLPTR));
        btnReverb1State->setText(QApplication::translate("MainWindow", "Reverb", Q_NULLPTR));
        btnReverb1Settings->setText(QString());
        btnDelay1Settings->setText(QString());
        btnCompressorSettings->setText(QString());
        btnPreset1->setText(QApplication::translate("MainWindow", "A", Q_NULLPTR));
        btnPreset2->setText(QApplication::translate("MainWindow", "B", Q_NULLPTR));
        btnPreset3->setText(QApplication::translate("MainWindow", "C", Q_NULLPTR));
        btnPreset4->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        btnPreset5->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        btnPreset6->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        label->setText(QString());
        btnSave->setText(QApplication::translate("MainWindow", "SAVE", Q_NULLPTR));
        btnDSPOnOff->setText(QApplication::translate("MainWindow", "DSP", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
