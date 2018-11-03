QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = kalk

TEMPLATE = app
RC_ICONS = favicon.ico

SOURCES += main.cpp \
    Model/razionale.cpp \
    Model/monomio.cpp \
    Model/equazione.cpp \
    Model/primogrado.cpp \
    Model/polinomio.cpp \
    Model/secondogrado.cpp \
    Model/pura.cpp \
    Model/spuria.cpp \
    View/kalkpolinomi.cpp \
    View/tastiera.cpp \
    View/kalkequazioni.cpp \
    View/kalk.cpp \
    Model/modelpolinomio.cpp \
    Model/modelequazioni.cpp

HEADERS  += \
    Model/razionale.h \
    Model/monomio.h \
    Model/config.h \
    Model/equazione.h \
    Model/primogrado.h \
    Model/polinomio.h \
    Model/secondogrado.h \
    Model/pura.h \
    Model/spuria.h \
    View/kalkpolinomi.h \
    View/tastiera.h \
    View/kalkequazioni.h \
    View/kalk.h \
    Model/modelpolinomio.h \
    Model/modelequazioni.h
