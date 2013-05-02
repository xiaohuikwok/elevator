#-------------------------------------------------
#
# Project created by QtCreator 2011-09-01T11:01:33
#
#-------------------------------------------------

QT       += core gui network

TARGET = simulated-elevator
TEMPLATE = app


SOURCES += main.cpp

HEADERS  += mainwindow.h \
    elevator.h \
    request.h \
    dispatcher.h \
    receiver.h

FORMS    += mainwindow.ui \
    elevator.ui

RESOURCES += \
    res.qrc
