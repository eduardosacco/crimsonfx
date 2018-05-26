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
    comms.cpp \
    crimson.cpp \
    tinyosc.c \
    fxbank.cpp \
    dialogfx.cpp

HEADERS  += mainwindow.h \
    comms.h \
    crimson.h \
    tinyosc.h \
    fxbank.h \
    dialogfx.h

FORMS    += mainwindow.ui \
    dialogfx.ui

OTHER_FILES +=
