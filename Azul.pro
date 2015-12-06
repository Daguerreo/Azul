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
VERSION = 0.2.0
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

INCLUDEPATH += $$PWD/gui \
               $$PWD/gui/widget \
               $$PWD/gui/dialog

SOURCES += main.cpp\
    gui/widget/CommitButtonsFrame.cpp \
    gui/widget/DoubleSliderGroupBox.cpp \
    gui/widget/ImageFrame.cpp \
    gui/widget/OptionsFrame.cpp \
    gui/widget/RadioButtonGroupBox.cpp \
    gui/widget/SliderGroupBox.cpp \
    gui/widget/DoubleSlider.cpp \
    gui/dialog/BaseDialog.cpp \
    ImageProcessing.cpp \
    Image.cpp \
    gui/dialog/GrayscaleDialog.cpp \
    Mediator.cpp \
    mainwindow.cpp \
    gui/dialog/ContrastDialog.cpp


HEADERS  += \
    gui/widget/CommitButtonsFrame.h \
    gui/widget/DoubleSliderGroupBox.h \
    gui/widget/ImageFrame.h \
    gui/widget/OptionsFrame.h \
    gui/widget/RadioButtonGroupBox.h \
    gui/widget/Doubleslider.h \
    gui/widget/SliderGroupBox.h \
    gui/dialog/BaseDialog.h \
    ImageProcessing.h \
    Image.h \
    gui/dialog/GrayscaleDialog.h \
    Mediator.h \
    mainwindow.h \
    mainwindow.h \
    gui/dialog/ContrastDialog.h

FORMS    += \
    mainwindow.ui

CONFIG(debug, debug|release){
    INCLUDEPATH += $$(OPENCV_DIR)\\build\\include
    LIBS += -L$$(OPENCV_DIR)\\build\\x64\\vc12\\lib \
                -lopencv_core2410d \
                -lopencv_highgui2410d \
                -lopencv_imgproc2410d
}

CONFIG(release, debug|release) {
    INCLUDEPATH += $$(OPENCV_DIR)\\build\\include
    LIBS += -L$$(OPENCV_DIR)\\build\\x64\\vc12\\lib \
                -lopencv_core2410 \
                -lopencv_highgui2410 \
                -lopencv_imgproc2410
}

RESOURCES += \
    icon.qrc
