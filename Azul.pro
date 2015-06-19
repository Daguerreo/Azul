#-------------------------------------------------
#
# Project created by QtCreator 2015-05-12T22:55:53
#
# Author: Maurizio Ingrassia
# Mail: maurizio.ingrassia@gmail.com
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Azul
TEMPLATE = app
DEFINES += APP_NAME=\\\"Azul\\\"
VERSION = 0.1.0
DEFINES += APP_VERSION=\\\"$$VERSION\\\"


SOURCES += main.cpp\
        mainwindow.cpp \
    pixelinfodialog.cpp \
    grayscaledialog.cpp \
    contrastdialog.cpp \
    sharpendialog.cpp \
    smoothingdialog.cpp \
    gui/component/azulradiobuttongroupbox.cpp \
    morphologydialog.cpp


HEADERS  += mainwindow.h \
    pixelinfodialog.h \
    grayscaledialog.h \
    contrastdialog.h \
    sharpendialog.h \
    smoothingdialog.h \
    gui/component/azulradiobuttongroupbox.h \
    morphologydialog.h

FORMS    += mainwindow.ui \
    pixelinfodialog.ui \
    grayscaledialog.ui \
    contrastdialog.ui \
    sharpendialog.ui \
    smoothingdialog.ui \
    morphologydialog.ui

INCLUDEPATH += C:\\opencv\\opencv2410\\build\\include

LIBS += -LC:\\opencv\\opencv2410\\build\\x64\\vc12\\lib \
   -lopencv_core2410d \
    -lopencv_highgui2410d \
    -lopencv_imgproc2410d \
    -lopencv_calib3d2410d \
    -lopencv_contrib2410d \
    -lopencv_features2d2410d \
    -lopencv_flann2410d \
    -lopencv_gpu2410d \
    -lopencv_legacy2410d \
    -lopencv_ml2410d \
    -lopencv_objdetect2410d \
    -lopencv_ts2410d \
    -lopencv_video2410d

RESOURCES += \
    icon.qrc
