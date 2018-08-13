#-------------------------------------------------
#
# Project created by QtCreator 2018-08-01T08:54:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Assembling_flow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    motor_initialization.cpp \
    error_holder.cpp \
    i_o_control.cpp

HEADERS  += mainwindow.h \
    motor_initialization.h \
    error_holder.h \
    i_o_control.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$quote(C:\Program Files (x86)\Advantech\AMONet\Include)\
               $$quote(C:\Program Files\Advantech\AMONet\Include)

LIBS += $$quote(C:\Program Files (x86)\Advantech\AMONet\Lib\AMONet.lib)\
