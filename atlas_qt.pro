#-------------------------------------------------
#
# Project created by QtCreator 2016-11-29T08:57:27
#
#-------------------------------------------------

QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11
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
    atlas_i.cpp \
    src/atlas.cpp \
    src/atlas_i.cpp \
    src/dialog.cpp \
    src/divers.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    moc_dialog.cpp \
    moc_mainwindow.cpp

HEADERS  += mainwindow.h \
    atlas.h \
    dialog.h \
    atlas_i.h \
    header/atlas.h \
    header/atlas_i.h \
    header/dialog.h \
    header/divers.h \
    header/mainwindow.h \
    header/ui_dialog.h \
    header/ui_mainwindow.h

FORMS    += mainwindow.ui \
    dialog.ui \
    form/dialog.ui \
    form/mainwindow.ui
