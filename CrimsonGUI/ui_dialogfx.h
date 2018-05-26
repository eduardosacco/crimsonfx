/********************************************************************************
** Form generated from reading UI file 'dialogfx.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFX_H
#define UI_DIALOGFX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogFx
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *vLayout;
    QPushButton *btnOnOff;
    QPushButton *btnClose;
    QLabel *lblFx;

    void setupUi(QDialog *DialogFx)
    {
        if (DialogFx->objectName().isEmpty())
            DialogFx->setObjectName(QStringLiteral("DialogFx"));
        DialogFx->resize(600, 400);
        DialogFx->setStyleSheet(QLatin1String("QDialog{\n"
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
        verticalLayoutWidget = new QWidget(DialogFx);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, 69, 601, 331));
        vLayout = new QVBoxLayout(verticalLayoutWidget);
        vLayout->setObjectName(QStringLiteral("vLayout"));
        vLayout->setContentsMargins(0, 0, 0, 0);
        btnOnOff = new QPushButton(DialogFx);
        btnOnOff->setObjectName(QStringLiteral("btnOnOff"));
        btnOnOff->setGeometry(QRect(510, 10, 80, 40));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnOnOff->sizePolicy().hasHeightForWidth());
        btnOnOff->setSizePolicy(sizePolicy);
        btnOnOff->setMinimumSize(QSize(80, 40));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/onOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOnOff->setIcon(icon);
        btnOnOff->setIconSize(QSize(30, 35));
        btnOnOff->setCheckable(true);
        btnClose = new QPushButton(DialogFx);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setGeometry(QRect(10, 10, 80, 40));
        sizePolicy.setHeightForWidth(btnClose->sizePolicy().hasHeightForWidth());
        btnClose->setSizePolicy(sizePolicy);
        btnClose->setMinimumSize(QSize(80, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon1);
        btnClose->setIconSize(QSize(40, 20));
        lblFx = new QLabel(DialogFx);
        lblFx->setObjectName(QStringLiteral("lblFx"));
        lblFx->setGeometry(QRect(180, 10, 241, 41));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lblFx->setFont(font);

        retranslateUi(DialogFx);

        QMetaObject::connectSlotsByName(DialogFx);
    } // setupUi

    void retranslateUi(QDialog *DialogFx)
    {
        DialogFx->setWindowTitle(QApplication::translate("DialogFx", "Dialog", Q_NULLPTR));
        btnOnOff->setText(QString());
        btnClose->setText(QString());
        lblFx->setText(QApplication::translate("DialogFx", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogFx: public Ui_DialogFx {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFX_H
