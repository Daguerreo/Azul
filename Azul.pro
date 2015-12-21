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
#CONFIG += debug_and_release

INCLUDEPATH += $$PWD\\gui \
               $$PWD\\gui\\widget \
               $$PWD\\gui\\dialog

SOURCES += main.cpp\
    gui/widget/CommitButtonsFrame.cpp \
    gui/widget/DoubleSliderGroupBox.cpp \
    gui/widget/ImageFrame.cpp \
    gui/widget/OptionsFrame.cpp \
    gui/widget/RadioButtonGroupBox.cpp \
    gui/widget/SliderGroupBox.cpp \
    gui/widget/DoubleSlider.cpp \
    gui/dialog/BaseDialog.cpp \
    Image.cpp \
    mainwindow.cpp \
    gui/dialog/ContrastDialog.cpp \
    ImageProcessor.cpp \
    gui/dialog/NegativeFilterDialog.cpp \
    gui/dialog/GrayscaleFilterDialog.cpp \
    gui/dialog/PixelInfoDialog.cpp \
    Controller.cpp \
    gui/dialog/SmoothingFilterDialog.cpp \
    gui/dialog/CannyFilterDialog.cpp \
    gui/widget/EntryGroupBox.cpp \
    gui/dialog/MorphologyDialog.cpp \
    gui/dialog/Dialog.cpp \
    gui/dialog/ThresholdDialog.cpp


HEADERS  += \
    gui/widget/CommitButtonsFrame.h \
    gui/widget/DoubleSliderGroupBox.h \
    gui/widget/ImageFrame.h \
    gui/widget/OptionsFrame.h \
    gui/widget/RadioButtonGroupBox.h \
    gui/widget/Doubleslider.h \
    gui/widget/SliderGroupBox.h \
    gui/dialog/BaseDialog.h \
    Image.h \
    mainwindow.h \
    mainwindow.h \
    gui/dialog/ContrastDialog.h \
    ImageProcessor.h \
    gui/dialog/NegativeFilterDialog.h \
    gui/dialog/GrayscaleFilterDialog.h \
    ui_mainwindow.h \
    gui/dialog/PixelInfoDialog.h \
    Controller.h \
    gui/dialog/SmoothingFilterDialog.h \
    gui/dialog/CannyFilterDialog.h \
    gui/widget/EntryGroupBox.h \
    gui/dialog/MorphologyDialog.h \
    gui/dialog/Dialog.h \
    gui/dialog/ThresholdDialog.h

FORMS    += \
    mainwindow.ui \
    gui/dialog/pixelinfodialog.ui

win32{
    contains(QMAKE_TARGET.arch, x86_64) {
        message("64 bit")
        CONFIG(debug, debug|release){
            message("Debug Mode")
            INCLUDEPATH += $$(OPENCV_DIR)\\build\\include
            LIBS += -L$$(OPENCV_DIR)\\build\\x64\\vc12\\lib \
                        -lopencv_core2410d \
                        -lopencv_highgui2410d \
                        -lopencv_imgproc2410d
        }else{
            message("Release Mode")
            INCLUDEPATH += $$(OPENCV_DIR)\\build\\include
            LIBS += -L$$(OPENCV_DIR)\\build\\x64\\vc12\\lib \
                        -lopencv_core2410 \
                        -lopencv_highgui2410 \
                        -lopencv_imgproc2410
        }
    }
    contains(QMAKE_TARGET.arch, x86){
        message("32 bit")
        CONFIG(debug, debug|release){
            message("Debug Mode")
            INCLUDEPATH += $$(OPENCV_DIR)\\build\\include
            LIBS += -L$$(OPENCV_DIR)\\build\\x86\\vc12\\lib \
                        -lopencv_core2410d \
                        -lopencv_highgui2410d \
                        -lopencv_imgproc2410d
        }else{
            message("Release Mode")
            INCLUDEPATH += $$(OPENCV_DIR)\\build\\include
            LIBS += -L$$(OPENCV_DIR)\\build\\x86\\vc12\\lib \
                        -lopencv_core2410 \
                        -lopencv_highgui2410 \
                        -lopencv_imgproc2410
        }
    }
}

RESOURCES += \
    icon.qrc \
    image.qrc
