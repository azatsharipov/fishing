#-------------------------------------------------
#
# Project created by QtCreator 2019-04-02T16:02:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fishing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    player.cpp \
    zone.cpp

HEADERS  += mainwindow.h \
    game.h \
    player.h \
    zone.h

FORMS    += mainwindow.ui
