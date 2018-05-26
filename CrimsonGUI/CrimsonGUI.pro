#-------------------------------------------------
#
# Project created by QtCreator 2018-01-12T18:11:51
#
#-------------------------------------------------

QMAKE_CFLAGS += -std=gnu99
QMAKE_CXXFLAGS += -std=gnu++11

LIBS += -lwsock32

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CrimsonGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialogoverdrive1.cpp \
    dialogreverb1.cpp \
    comms.cpp \
    crimson.cpp \
    tinyosc.c \
    dialogdelay1.cpp \
    fx.cpp

HEADERS  += mainwindow.h \
    dialogoverdrive1.h \
    dialogreverb1.h \
    comms.h \
    crimson.h \
    tinyosc.h \
    dialogdelay1.h \
    fx.h

FORMS    += mainwindow.ui \
    dialogoverdrive1.ui \
    dialogreverb1.ui \
    dialogdelay1.ui

OTHER_FILES += \
    Log.txt
