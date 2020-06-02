#-------------------------------------------------
#
# Project created by QtCreator 2019-04-02T16:02:58
#
#-------------------------------------------------

QT       += core gui
QT       += network
CONFIG   += c++11
QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = fishing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    player.cpp \
    zone.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    game.h \
    player.h \
    zone.h \
    qcustomplot.h

FORMS    += mainwindow.ui
