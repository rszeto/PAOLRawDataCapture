#-------------------------------------------------
#
# Project created by QtCreator 2015-03-28T14:32:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rawDataCapture
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    choosecamerawidget.cpp \
    capturewidget.cpp \
    mattoqimageutil.cpp

HEADERS  += mainwindow.h \
    choosecamerawidget.h \
    capturewidget.h \
    mattoqimageutil.h

FORMS    += mainwindow.ui \
    choosecamerawidget.ui \
    capturewidget.ui

LIBS += `pkg-config opencv --libs`
