/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPreset1;
    QPushButton *btnPreset2;
    QPushButton *btnPreset3;
    QPushButton *btnPreset4;
    QPushButton *btnPreset5;
    QPushButton *btnPreset6;
    QPushButton *btnSave;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QGridLayout *gridLayout;
    QPushButton *btnEqualizerSettings;
    QPushButton *btnCompressorState;
    QPushButton *btnReverb1Settings;
    QPushButton *btnReverb1State;
    QPushButton *btnEqualizerState;
    QPushButton *btnDelay1State;
    QPushButton *btnOverdrive1Settings;
    QPushButton *btnOverdrive1State;
    QPushButton *btnCompressorSettings;
    QPushButton *btnDelay1Settings;
    QPushButton *btnDistortionState;
    QPushButton *btnFlangerSettings;
    QPushButton *btnDistortionSettings;
    QPushButton *btnFlangerState;
    QPushButton *btnChorusState;
    QPushButton *btnChorusSettings;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
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
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnPreset1 = new QPushButton(centralWidget);
        btnPreset1->setObjectName(QStringLiteral("btnPreset1"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnPreset1->sizePolicy().hasHeightForWidth());
        btnPreset1->setSizePolicy(sizePolicy);
        btnPreset1->setMinimumSize(QSize(80, 80));

        horizontalLayout->addWidget(btnPreset1);

        btnPreset2 = new QPushButton(centralWidget);
        btnPreset2->setObjectName(QStringLiteral("btnPreset2"));
        sizePolicy.setHeightForWidth(btnPreset2->sizePolicy().hasHeightForWidth());
        btnPreset2->setSizePolicy(sizePolicy);
        btnPreset2->setMinimumSize(QSize(80, 80));

        horizontalLayout->addWidget(btnPreset2);

        btnPreset3 = new QPushButton(centralWidget);
        btnPreset3->setObjectName(QStringLiteral("btnPreset3"));
        sizePolicy.setHeightForWidth(btnPreset3->sizePolicy().hasHeightForWidth());
        btnPreset3->setSizePolicy(sizePolicy);
        btnPreset3->setMinimumSize(QSize(80, 80));

        horizontalLayout->addWidget(btnPreset3);

        btnPreset4 = new QPushButton(centralWidget);
        btnPreset4->setObjectName(QStringLiteral("btnPreset4"));
        sizePolicy.setHeightForWidth(btnPreset4->sizePolicy().hasHeightForWidth());
        btnPreset4->setSizePolicy(sizePolicy);
        btnPreset4->setMinimumSize(QSize(80, 80));

        horizontalLayout->addWidget(btnPreset4);

        btnPreset5 = new QPushButton(centralWidget);
        btnPreset5->setObjectName(QStringLiteral("btnPreset5"));
        sizePolicy.setHeightForWidth(btnPreset5->sizePolicy().hasHeightForWidth());
        btnPreset5->setSizePolicy(sizePolicy);
        btnPreset5->setMinimumSize(QSize(80, 80));

        horizontalLayout->addWidget(btnPreset5);

        btnPreset6 = new QPushButton(centralWidget);
        btnPreset6->setObjectName(QStringLiteral("btnPreset6"));
        sizePolicy.setHeightForWidth(btnPreset6->sizePolicy().hasHeightForWidth());
        btnPreset6->setSizePolicy(sizePolicy);
        btnPreset6->setMinimumSize(QSize(80, 80));

        horizontalLayout->addWidget(btnPreset6);

        btnSave = new QPushButton(centralWidget);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        sizePolicy.setHeightForWidth(btnSave->sizePolicy().hasHeightForWidth());
        btnSave->setSizePolicy(sizePolicy);
        btnSave->setMinimumSize(QSize(80, 80));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon);
        btnSave->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(btnSave);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(200, 40));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/crimsonLogo.png")));
        label->setScaledContents(true);

        horizontalLayout_2->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        btnEqualizerSettings = new QPushButton(centralWidget);
        btnEqualizerSettings->setObjectName(QStringLiteral("btnEqualizerSettings"));
        sizePolicy.setHeightForWidth(btnEqualizerSettings->sizePolicy().hasHeightForWidth());
        btnEqualizerSettings->setSizePolicy(sizePolicy);
        btnEqualizerSettings->setMinimumSize(QSize(60, 60));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnEqualizerSettings->setIcon(icon1);
        btnEqualizerSettings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnEqualizerSettings, 3, 1, 1, 1);

        btnCompressorState = new QPushButton(centralWidget);
        btnCompressorState->setObjectName(QStringLiteral("btnCompressorState"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnCompressorState->sizePolicy().hasHeightForWidth());
        btnCompressorState->setSizePolicy(sizePolicy1);
        btnCompressorState->setMinimumSize(QSize(80, 60));
        btnCompressorState->setCheckable(true);

        gridLayout->addWidget(btnCompressorState, 0, 0, 1, 1);

        btnReverb1Settings = new QPushButton(centralWidget);
        btnReverb1Settings->setObjectName(QStringLiteral("btnReverb1Settings"));
        sizePolicy.setHeightForWidth(btnReverb1Settings->sizePolicy().hasHeightForWidth());
        btnReverb1Settings->setSizePolicy(sizePolicy);
        btnReverb1Settings->setMinimumSize(QSize(60, 60));
        btnReverb1Settings->setIcon(icon1);
        btnReverb1Settings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnReverb1Settings, 2, 3, 1, 1);

        btnReverb1State = new QPushButton(centralWidget);
        btnReverb1State->setObjectName(QStringLiteral("btnReverb1State"));
        sizePolicy1.setHeightForWidth(btnReverb1State->sizePolicy().hasHeightForWidth());
        btnReverb1State->setSizePolicy(sizePolicy1);
        btnReverb1State->setMinimumSize(QSize(80, 60));
        btnReverb1State->setCheckable(true);

        gridLayout->addWidget(btnReverb1State, 2, 2, 1, 1);

        btnEqualizerState = new QPushButton(centralWidget);
        btnEqualizerState->setObjectName(QStringLiteral("btnEqualizerState"));
        sizePolicy1.setHeightForWidth(btnEqualizerState->sizePolicy().hasHeightForWidth());
        btnEqualizerState->setSizePolicy(sizePolicy1);
        btnEqualizerState->setMinimumSize(QSize(80, 60));
        btnEqualizerState->setCheckable(true);

        gridLayout->addWidget(btnEqualizerState, 3, 0, 1, 1);

        btnDelay1State = new QPushButton(centralWidget);
        btnDelay1State->setObjectName(QStringLiteral("btnDelay1State"));
        sizePolicy1.setHeightForWidth(btnDelay1State->sizePolicy().hasHeightForWidth());
        btnDelay1State->setSizePolicy(sizePolicy1);
        btnDelay1State->setMinimumSize(QSize(80, 60));
        btnDelay1State->setCheckable(true);

        gridLayout->addWidget(btnDelay1State, 3, 2, 1, 1);

        btnOverdrive1Settings = new QPushButton(centralWidget);
        btnOverdrive1Settings->setObjectName(QStringLiteral("btnOverdrive1Settings"));
        sizePolicy.setHeightForWidth(btnOverdrive1Settings->sizePolicy().hasHeightForWidth());
        btnOverdrive1Settings->setSizePolicy(sizePolicy);
        btnOverdrive1Settings->setMinimumSize(QSize(60, 60));
        btnOverdrive1Settings->setIcon(icon1);
        btnOverdrive1Settings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnOverdrive1Settings, 2, 1, 1, 1);

        btnOverdrive1State = new QPushButton(centralWidget);
        btnOverdrive1State->setObjectName(QStringLiteral("btnOverdrive1State"));
        sizePolicy1.setHeightForWidth(btnOverdrive1State->sizePolicy().hasHeightForWidth());
        btnOverdrive1State->setSizePolicy(sizePolicy1);
        btnOverdrive1State->setMinimumSize(QSize(80, 60));
        btnOverdrive1State->setCheckable(true);

        gridLayout->addWidget(btnOverdrive1State, 2, 0, 1, 1);

        btnCompressorSettings = new QPushButton(centralWidget);
        btnCompressorSettings->setObjectName(QStringLiteral("btnCompressorSettings"));
        sizePolicy.setHeightForWidth(btnCompressorSettings->sizePolicy().hasHeightForWidth());
        btnCompressorSettings->setSizePolicy(sizePolicy);
        btnCompressorSettings->setMinimumSize(QSize(60, 60));
        btnCompressorSettings->setIcon(icon1);
        btnCompressorSettings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnCompressorSettings, 0, 1, 1, 1);

        btnDelay1Settings = new QPushButton(centralWidget);
        btnDelay1Settings->setObjectName(QStringLiteral("btnDelay1Settings"));
        sizePolicy.setHeightForWidth(btnDelay1Settings->sizePolicy().hasHeightForWidth());
        btnDelay1Settings->setSizePolicy(sizePolicy);
        btnDelay1Settings->setMinimumSize(QSize(60, 60));
        btnDelay1Settings->setIcon(icon1);
        btnDelay1Settings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnDelay1Settings, 3, 3, 1, 1);

        btnDistortionState = new QPushButton(centralWidget);
        btnDistortionState->setObjectName(QStringLiteral("btnDistortionState"));
        sizePolicy1.setHeightForWidth(btnDistortionState->sizePolicy().hasHeightForWidth());
        btnDistortionState->setSizePolicy(sizePolicy1);
        btnDistortionState->setMinimumSize(QSize(80, 60));
        btnDistortionState->setCheckable(true);

        gridLayout->addWidget(btnDistortionState, 1, 0, 1, 1);

        btnFlangerSettings = new QPushButton(centralWidget);
        btnFlangerSettings->setObjectName(QStringLiteral("btnFlangerSettings"));
        sizePolicy.setHeightForWidth(btnFlangerSettings->sizePolicy().hasHeightForWidth());
        btnFlangerSettings->setSizePolicy(sizePolicy);
        btnFlangerSettings->setMinimumSize(QSize(60, 60));
        btnFlangerSettings->setIcon(icon1);
        btnFlangerSettings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnFlangerSettings, 1, 3, 1, 1);

        btnDistortionSettings = new QPushButton(centralWidget);
        btnDistortionSettings->setObjectName(QStringLiteral("btnDistortionSettings"));
        sizePolicy.setHeightForWidth(btnDistortionSettings->sizePolicy().hasHeightForWidth());
        btnDistortionSettings->setSizePolicy(sizePolicy);
        btnDistortionSettings->setMinimumSize(QSize(60, 60));
        btnDistortionSettings->setIcon(icon1);
        btnDistortionSettings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnDistortionSettings, 1, 1, 1, 1);

        btnFlangerState = new QPushButton(centralWidget);
        btnFlangerState->setObjectName(QStringLiteral("btnFlangerState"));
        sizePolicy1.setHeightForWidth(btnFlangerState->sizePolicy().hasHeightForWidth());
        btnFlangerState->setSizePolicy(sizePolicy1);
        btnFlangerState->setMinimumSize(QSize(80, 60));
        btnFlangerState->setCheckable(true);

        gridLayout->addWidget(btnFlangerState, 1, 2, 1, 1);

        btnChorusState = new QPushButton(centralWidget);
        btnChorusState->setObjectName(QStringLiteral("btnChorusState"));
        sizePolicy1.setHeightForWidth(btnChorusState->sizePolicy().hasHeightForWidth());
        btnChorusState->setSizePolicy(sizePolicy1);
        btnChorusState->setMinimumSize(QSize(80, 60));
        btnChorusState->setCheckable(true);

        gridLayout->addWidget(btnChorusState, 0, 2, 1, 1);

        btnChorusSettings = new QPushButton(centralWidget);
        btnChorusSettings->setObjectName(QStringLiteral("btnChorusSettings"));
        sizePolicy.setHeightForWidth(btnChorusSettings->sizePolicy().hasHeightForWidth());
        btnChorusSettings->setSizePolicy(sizePolicy);
        btnChorusSettings->setMinimumSize(QSize(60, 60));
        btnChorusSettings->setIcon(icon1);
        btnChorusSettings->setIconSize(QSize(35, 35));

        gridLayout->addWidget(btnChorusSettings, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        btnPreset1->setText(QApplication::translate("MainWindow", "A", Q_NULLPTR));
        btnPreset2->setText(QApplication::translate("MainWindow", "B", Q_NULLPTR));
        btnPreset3->setText(QApplication::translate("MainWindow", "C", Q_NULLPTR));
        btnPreset4->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        btnPreset5->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        btnPreset6->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        btnSave->setText(QString());
        label->setText(QString());
        btnEqualizerSettings->setText(QString());
        btnCompressorState->setText(QApplication::translate("MainWindow", "Compressor", Q_NULLPTR));
        btnReverb1Settings->setText(QString());
        btnReverb1State->setText(QApplication::translate("MainWindow", "Reverb", Q_NULLPTR));
        btnEqualizerState->setText(QApplication::translate("MainWindow", "Equalizer", Q_NULLPTR));
        btnDelay1State->setText(QApplication::translate("MainWindow", "Delay", Q_NULLPTR));
        btnOverdrive1Settings->setText(QString());
        btnOverdrive1State->setText(QApplication::translate("MainWindow", "Overdrive", Q_NULLPTR));
        btnCompressorSettings->setText(QString());
        btnDelay1Settings->setText(QString());
        btnDistortionState->setText(QApplication::translate("MainWindow", "Distortion", Q_NULLPTR));
        btnFlangerSettings->setText(QString());
        btnDistortionSettings->setText(QString());
        btnFlangerState->setText(QApplication::translate("MainWindow", "Flanger", Q_NULLPTR));
        btnChorusState->setText(QApplication::translate("MainWindow", "Chorus", Q_NULLPTR));
        btnChorusSettings->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
