#-------------------------------------------------
#
# Project created by QtCreator 2017-09-27T13:31:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SecRTC
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    src/screendialog.cpp \
    src/linklistwidget.cpp \
    src/linkcmdwidget.cpp \
    src/maintabwidget.cpp \
    src/linkfilewidget.cpp \
    src/linkprocesswidget.cpp \
    src/filetreeview.cpp \
    src/processtreeview.cpp \
    src/servicetreeview.cpp \
    src/linkservicewidget.cpp \
    src/iocpserver.cpp \
    src/listwidgetitem.cpp

HEADERS += \
        mainwindow.h \
    inlcude/screendialog.h \
    inlcude/maintabwidget.h \
    inlcude/linkcmdwidget.h \
    inlcude/linklistwidget.h \
    inlcude/linkfilewidget.h \
    inlcude/linkprocesswidget.h \
    inlcude/filetreeview.h \
    inlcude/processtreeview.h \
    inlcude/servicetreeview.h \
    inlcude/linkservicewidget.h \
    inlcude/iocpserver.h \
    inlcude/listwidgetitem.h

LIBS += -lws2_32 \

LIBS += -lkernel32
FORMS += \
        mainwindow.ui

RESOURCES += \
    secrtc.qrc


