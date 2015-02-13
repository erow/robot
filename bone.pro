
QT       += core gui

TARGET = bone
TEMPLATE = app
SOURCES += main.cpp \
    bone.cpp \
    link.cpp \
    basicmodel.cpp \
    pendulum.cpp \
    mainwindow.cpp \
    qmlink.cpp

HEADERS += \
    bone.h \
    link.h \
    TYPEDEF.H \
    basicmodel.h \
    pendulum.h \
    mainwindow.h \
    qmlink.h

FORMS += \
    mainwindow.ui

