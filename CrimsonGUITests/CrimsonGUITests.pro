QMAKE_CFLAGS += -std=gnu99
#QMAKE_LFLAGS += -no-pie
QMAKE_CXXFLAGS += -std=gnu++11

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

INCLUDEPATH += ../CrimsonGUI/

SOURCES +=  tst_crimsonguitests.cpp \
    ../CrimsonGUI/mainwindow.cpp \
    ../CrimsonGUI/crimson.cpp \
    ../CrimsonGUI/fxbank.cpp \
    ../CrimsonGUI/dialogfx.cpp \
    ../CrimsonGUI/tinyosc.c \
    ../CrimsonGUI/mmapgpio.cpp \
    ../CrimsonGUI/comms.cpp

HEADERS  += ../CrimsonGUI/mainwindow.h \
    ../CrimsonGUI/comms.h \
    ../CrimsonGUI/crimson.h \
    ../CrimsonGUI/fxbank.h \
    ../CrimsonGUI/dialogfx.h \
    ../CrimsonGUI/tinyosc.h \
    ../CrimsonGUI/mmapgpio.h

FORMS    += ../CrimsonGUI/mainwindow.ui \
    ../CrimsonGUI/dialogfx.ui

OTHER_FILES +=

RESOURCES += \
    ../CrimsonGUI/resources.qrc
