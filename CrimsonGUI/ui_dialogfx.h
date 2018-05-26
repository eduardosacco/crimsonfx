/********************************************************************************
** Form generated from reading UI file 'dialogfx.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogFx
{
public:
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *hLayout;
    QPushButton *btnClose;
    QPushButton *btnOnOff;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *vLayout;

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
        horizontalLayoutWidget_2 = new QWidget(DialogFx);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 10, 191, 51));
        hLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        hLayout->setSpacing(10);
        hLayout->setObjectName(QStringLiteral("hLayout"));
        hLayout->setContentsMargins(0, 0, 0, 0);
        btnClose = new QPushButton(horizontalLayoutWidget_2);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnClose->sizePolicy().hasHeightForWidth());
        btnClose->setSizePolicy(sizePolicy);
        btnClose->setMinimumSize(QSize(80, 40));

        hLayout->addWidget(btnClose);

        btnOnOff = new QPushButton(horizontalLayoutWidget_2);
        btnOnOff->setObjectName(QStringLiteral("btnOnOff"));
        sizePolicy.setHeightForWidth(btnOnOff->sizePolicy().hasHeightForWidth());
        btnOnOff->setSizePolicy(sizePolicy);
        btnOnOff->setMinimumSize(QSize(80, 40));
        btnOnOff->setCheckable(true);

        hLayout->addWidget(btnOnOff);

        verticalLayoutWidget = new QWidget(DialogFx);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, 69, 601, 331));
        vLayout = new QVBoxLayout(verticalLayoutWidget);
        vLayout->setObjectName(QStringLiteral("vLayout"));
        vLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(DialogFx);

        QMetaObject::connectSlotsByName(DialogFx);
    } // setupUi

    void retranslateUi(QDialog *DialogFx)
    {
        DialogFx->setWindowTitle(QApplication::translate("DialogFx", "Dialog", Q_NULLPTR));
        btnClose->setText(QApplication::translate("DialogFx", "CLOSE", Q_NULLPTR));
        btnOnOff->setText(QApplication::translate("DialogFx", "IO", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogFx: public Ui_DialogFx {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFX_H
