
QT       += core gui

TARGET = bone
TEMPLATE = app
SOURCES += main.cpp \
    bone.cpp \
    link.cpp \
    basicmodel.cpp \
    pendulum.cpp \
    mainwindow.cpp \
    qmlink.cpp \
    device_data.cpp

HEADERS += \
    bone.h \
    link.h \
    TYPEDEF.H \
    basicmodel.h \
    pendulum.h \
    mainwindow.h \
    qmlink.h \
    device_data.h

FORMS += \
    mainwindow.ui

