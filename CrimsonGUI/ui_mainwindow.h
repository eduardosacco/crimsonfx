/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
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
    QPushButton *btnEqualizerSettings;
    QPushButton *btnReverb1State;
    QPushButton *btnCompressorState;
    QPushButton *btnReverb1Settings;
    QPushButton *btnEqualizerState;
    QPushButton *btnDelay1State;
    QPushButton *btnOverdrive1Settings;
    QPushButton *btnOverdrive1State;
    QPushButton *btnCompressorSettings;
    QPushButton *btnDelay1Settings;
    QPushButton *btnDistortionState;
    QPushButton *btnDistortionSettings;
    QPushButton *btnFlangerState;
    QPushButton *btnFlangerSettings;
    QPushButton *btnChorusState;
    QPushButton *btnChorusSettings;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPreset1;
    QPushButton *btnPreset2;
    QPushButton *btnPreset3;
    QPushButton *btnPreset4;
    QPushButton *btnPreset5;
    QPushButton *btnPreset6;
    QPushButton *btnSave;
    QLabel *label;

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
        gridLayoutWidget->setGeometry(QRect(10, 150, 581, 251));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnEqualizerSettings = new QPushButton(gridLayoutWidget);
        btnEqualizerSettings->setObjectName(QStringLiteral("btnEqualizerSettings"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnEqualizerSettings->sizePolicy().hasHeightForWidth());
        btnEqualizerSettings->setSizePolicy(sizePolicy);
        btnEqualizerSettings->setMinimumSize(QSize(40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnEqualizerSettings->setIcon(icon);
        btnEqualizerSettings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnEqualizerSettings, 3, 2, 1, 1);

        btnReverb1State = new QPushButton(gridLayoutWidget);
        btnReverb1State->setObjectName(QStringLiteral("btnReverb1State"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnReverb1State->sizePolicy().hasHeightForWidth());
        btnReverb1State->setSizePolicy(sizePolicy1);
        btnReverb1State->setMinimumSize(QSize(80, 40));
        btnReverb1State->setCheckable(true);

        gridLayout->addWidget(btnReverb1State, 2, 3, 1, 1);

        btnCompressorState = new QPushButton(gridLayoutWidget);
        btnCompressorState->setObjectName(QStringLiteral("btnCompressorState"));
        sizePolicy1.setHeightForWidth(btnCompressorState->sizePolicy().hasHeightForWidth());
        btnCompressorState->setSizePolicy(sizePolicy1);
        btnCompressorState->setMinimumSize(QSize(80, 40));
        btnCompressorState->setCheckable(true);

        gridLayout->addWidget(btnCompressorState, 0, 1, 1, 1);

        btnReverb1Settings = new QPushButton(gridLayoutWidget);
        btnReverb1Settings->setObjectName(QStringLiteral("btnReverb1Settings"));
        sizePolicy.setHeightForWidth(btnReverb1Settings->sizePolicy().hasHeightForWidth());
        btnReverb1Settings->setSizePolicy(sizePolicy);
        btnReverb1Settings->setMinimumSize(QSize(40, 40));
        btnReverb1Settings->setIcon(icon);
        btnReverb1Settings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnReverb1Settings, 2, 4, 1, 1);

        btnEqualizerState = new QPushButton(gridLayoutWidget);
        btnEqualizerState->setObjectName(QStringLiteral("btnEqualizerState"));
        sizePolicy1.setHeightForWidth(btnEqualizerState->sizePolicy().hasHeightForWidth());
        btnEqualizerState->setSizePolicy(sizePolicy1);
        btnEqualizerState->setMinimumSize(QSize(80, 40));
        btnEqualizerState->setCheckable(true);

        gridLayout->addWidget(btnEqualizerState, 3, 1, 1, 1);

        btnDelay1State = new QPushButton(gridLayoutWidget);
        btnDelay1State->setObjectName(QStringLiteral("btnDelay1State"));
        sizePolicy1.setHeightForWidth(btnDelay1State->sizePolicy().hasHeightForWidth());
        btnDelay1State->setSizePolicy(sizePolicy1);
        btnDelay1State->setMinimumSize(QSize(80, 40));
        btnDelay1State->setCheckable(true);

        gridLayout->addWidget(btnDelay1State, 3, 3, 1, 1);

        btnOverdrive1Settings = new QPushButton(gridLayoutWidget);
        btnOverdrive1Settings->setObjectName(QStringLiteral("btnOverdrive1Settings"));
        sizePolicy.setHeightForWidth(btnOverdrive1Settings->sizePolicy().hasHeightForWidth());
        btnOverdrive1Settings->setSizePolicy(sizePolicy);
        btnOverdrive1Settings->setMinimumSize(QSize(40, 40));
        btnOverdrive1Settings->setIcon(icon);
        btnOverdrive1Settings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnOverdrive1Settings, 2, 2, 1, 1);

        btnOverdrive1State = new QPushButton(gridLayoutWidget);
        btnOverdrive1State->setObjectName(QStringLiteral("btnOverdrive1State"));
        sizePolicy1.setHeightForWidth(btnOverdrive1State->sizePolicy().hasHeightForWidth());
        btnOverdrive1State->setSizePolicy(sizePolicy1);
        btnOverdrive1State->setMinimumSize(QSize(80, 40));
        btnOverdrive1State->setCheckable(true);

        gridLayout->addWidget(btnOverdrive1State, 2, 1, 1, 1);

        btnCompressorSettings = new QPushButton(gridLayoutWidget);
        btnCompressorSettings->setObjectName(QStringLiteral("btnCompressorSettings"));
        sizePolicy.setHeightForWidth(btnCompressorSettings->sizePolicy().hasHeightForWidth());
        btnCompressorSettings->setSizePolicy(sizePolicy);
        btnCompressorSettings->setMinimumSize(QSize(40, 40));
        btnCompressorSettings->setIcon(icon);
        btnCompressorSettings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnCompressorSettings, 0, 2, 1, 1);

        btnDelay1Settings = new QPushButton(gridLayoutWidget);
        btnDelay1Settings->setObjectName(QStringLiteral("btnDelay1Settings"));
        sizePolicy.setHeightForWidth(btnDelay1Settings->sizePolicy().hasHeightForWidth());
        btnDelay1Settings->setSizePolicy(sizePolicy);
        btnDelay1Settings->setMinimumSize(QSize(40, 40));
        btnDelay1Settings->setIcon(icon);
        btnDelay1Settings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnDelay1Settings, 3, 4, 1, 1);

        btnDistortionState = new QPushButton(gridLayoutWidget);
        btnDistortionState->setObjectName(QStringLiteral("btnDistortionState"));
        sizePolicy1.setHeightForWidth(btnDistortionState->sizePolicy().hasHeightForWidth());
        btnDistortionState->setSizePolicy(sizePolicy1);
        btnDistortionState->setMinimumSize(QSize(80, 40));
        btnDistortionState->setCheckable(true);

        gridLayout->addWidget(btnDistortionState, 1, 1, 1, 1);

        btnDistortionSettings = new QPushButton(gridLayoutWidget);
        btnDistortionSettings->setObjectName(QStringLiteral("btnDistortionSettings"));
        sizePolicy.setHeightForWidth(btnDistortionSettings->sizePolicy().hasHeightForWidth());
        btnDistortionSettings->setSizePolicy(sizePolicy);
        btnDistortionSettings->setMinimumSize(QSize(40, 40));
        btnDistortionSettings->setIcon(icon);
        btnDistortionSettings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnDistortionSettings, 1, 2, 1, 1);

        btnFlangerState = new QPushButton(gridLayoutWidget);
        btnFlangerState->setObjectName(QStringLiteral("btnFlangerState"));
        sizePolicy1.setHeightForWidth(btnFlangerState->sizePolicy().hasHeightForWidth());
        btnFlangerState->setSizePolicy(sizePolicy1);
        btnFlangerState->setMinimumSize(QSize(80, 40));
        btnFlangerState->setCheckable(true);

        gridLayout->addWidget(btnFlangerState, 1, 3, 1, 1);

        btnFlangerSettings = new QPushButton(gridLayoutWidget);
        btnFlangerSettings->setObjectName(QStringLiteral("btnFlangerSettings"));
        sizePolicy.setHeightForWidth(btnFlangerSettings->sizePolicy().hasHeightForWidth());
        btnFlangerSettings->setSizePolicy(sizePolicy);
        btnFlangerSettings->setMinimumSize(QSize(40, 40));
        btnFlangerSettings->setIcon(icon);
        btnFlangerSettings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnFlangerSettings, 1, 4, 1, 1);

        btnChorusState = new QPushButton(gridLayoutWidget);
        btnChorusState->setObjectName(QStringLiteral("btnChorusState"));
        sizePolicy1.setHeightForWidth(btnChorusState->sizePolicy().hasHeightForWidth());
        btnChorusState->setSizePolicy(sizePolicy1);
        btnChorusState->setMinimumSize(QSize(80, 40));
        btnChorusState->setCheckable(true);

        gridLayout->addWidget(btnChorusState, 0, 3, 1, 1);

        btnChorusSettings = new QPushButton(gridLayoutWidget);
        btnChorusSettings->setObjectName(QStringLiteral("btnChorusSettings"));
        sizePolicy.setHeightForWidth(btnChorusSettings->sizePolicy().hasHeightForWidth());
        btnChorusSettings->setSizePolicy(sizePolicy);
        btnChorusSettings->setMinimumSize(QSize(40, 40));
        btnChorusSettings->setIcon(icon);
        btnChorusSettings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnChorusSettings, 0, 4, 1, 1);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 581, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnPreset1 = new QPushButton(horizontalLayoutWidget);
        btnPreset1->setObjectName(QStringLiteral("btnPreset1"));
        sizePolicy.setHeightForWidth(btnPreset1->sizePolicy().hasHeightForWidth());
        btnPreset1->setSizePolicy(sizePolicy);
        btnPreset1->setMinimumSize(QSize(80, 40));

        horizontalLayout->addWidget(btnPreset1);

        btnPreset2 = new QPushButton(horizontalLayoutWidget);
        btnPreset2->setObjectName(QStringLiteral("btnPreset2"));
        sizePolicy.setHeightForWidth(btnPreset2->sizePolicy().hasHeightForWidth());
        btnPreset2->setSizePolicy(sizePolicy);
        btnPreset2->setMinimumSize(QSize(80, 40));

        horizontalLayout->addWidget(btnPreset2);

        btnPreset3 = new QPushButton(horizontalLayoutWidget);
        btnPreset3->setObjectName(QStringLiteral("btnPreset3"));
        sizePolicy.setHeightForWidth(btnPreset3->sizePolicy().hasHeightForWidth());
        btnPreset3->setSizePolicy(sizePolicy);
        btnPreset3->setMinimumSize(QSize(80, 40));

        horizontalLayout->addWidget(btnPreset3);

        btnPreset4 = new QPushButton(horizontalLayoutWidget);
        btnPreset4->setObjectName(QStringLiteral("btnPreset4"));
        sizePolicy.setHeightForWidth(btnPreset4->sizePolicy().hasHeightForWidth());
        btnPreset4->setSizePolicy(sizePolicy);
        btnPreset4->setMinimumSize(QSize(80, 40));

        horizontalLayout->addWidget(btnPreset4);

        btnPreset5 = new QPushButton(horizontalLayoutWidget);
        btnPreset5->setObjectName(QStringLiteral("btnPreset5"));
        sizePolicy.setHeightForWidth(btnPreset5->sizePolicy().hasHeightForWidth());
        btnPreset5->setSizePolicy(sizePolicy);
        btnPreset5->setMinimumSize(QSize(80, 40));

        horizontalLayout->addWidget(btnPreset5);

        btnPreset6 = new QPushButton(horizontalLayoutWidget);
        btnPreset6->setObjectName(QStringLiteral("btnPreset6"));
        sizePolicy.setHeightForWidth(btnPreset6->sizePolicy().hasHeightForWidth());
        btnPreset6->setSizePolicy(sizePolicy);
        btnPreset6->setMinimumSize(QSize(80, 40));

        horizontalLayout->addWidget(btnPreset6);

        btnSave = new QPushButton(horizontalLayoutWidget);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        sizePolicy.setHeightForWidth(btnSave->sizePolicy().hasHeightForWidth());
        btnSave->setSizePolicy(sizePolicy);
        btnSave->setMinimumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon1);
        btnSave->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(btnSave);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 90, 271, 41));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/crimsonLogo.png")));
        label->setScaledContents(true);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btnEqualizerSettings->setText(QString());
        btnReverb1State->setText(QApplication::translate("MainWindow", "Reverb", 0));
        btnCompressorState->setText(QApplication::translate("MainWindow", "Compressor", 0));
        btnReverb1Settings->setText(QString());
        btnEqualizerState->setText(QApplication::translate("MainWindow", "Equalizer", 0));
        btnDelay1State->setText(QApplication::translate("MainWindow", "Delay", 0));
        btnOverdrive1Settings->setText(QString());
        btnOverdrive1State->setText(QApplication::translate("MainWindow", "Overdrive", 0));
        btnCompressorSettings->setText(QString());
        btnDelay1Settings->setText(QString());
        btnDistortionState->setText(QApplication::translate("MainWindow", "Distortion", 0));
        btnDistortionSettings->setText(QString());
        btnFlangerState->setText(QApplication::translate("MainWindow", "Flanger", 0));
        btnFlangerSettings->setText(QString());
        btnChorusState->setText(QApplication::translate("MainWindow", "Chorus", 0));
        btnChorusSettings->setText(QString());
        btnPreset1->setText(QApplication::translate("MainWindow", "A", 0));
        btnPreset2->setText(QApplication::translate("MainWindow", "B", 0));
        btnPreset3->setText(QApplication::translate("MainWindow", "C", 0));
        btnPreset4->setText(QApplication::translate("MainWindow", "X", 0));
        btnPreset5->setText(QApplication::translate("MainWindow", "Y", 0));
        btnPreset6->setText(QApplication::translate("MainWindow", "Z", 0));
        btnSave->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
