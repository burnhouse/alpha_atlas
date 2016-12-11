#-------------------------------------------------
#
# Project created by QtCreator 2016-11-29T08:57:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = atlas_qt
TEMPLATE = app

INCLUDEPATH += /usr/include/opencv
INCLUDEPATH +=header
INCLUDEPATH +=src

LIBS += -L /usr/local/lib/
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann

SOURCES += src/atlas.cpp \
    src/atlas_i.cpp \
    src/dialog.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS  += header/atlas.h \
    header/atlas_i.h \
    header/dialog.h \
    header/mainwindow.h

FORMS    += form/dialog.ui \
    form/mainwindow.ui
