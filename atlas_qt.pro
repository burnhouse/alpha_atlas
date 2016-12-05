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

SOURCES += main.cpp\
        mainwindow.cpp \
    atlas.cpp \
    divers.cpp \
    dialog.cpp \
    atlas_i.cpp

HEADERS  += mainwindow.h \
    atlas.h \
    dialog.h \
    atlas_i.h

FORMS    += mainwindow.ui \
    dialog.ui
