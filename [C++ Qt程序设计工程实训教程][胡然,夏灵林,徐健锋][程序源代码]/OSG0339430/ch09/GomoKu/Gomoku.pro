#-------------------------------------------------
# 项目：实训九，人机对战五子棋
# 功能：人机对战、可悔棋的五子棋
# 位置：code\ch09\Gomoku
# 说明：
#-------------------------------------------------
QT       += core gui
QT += core gui widgets
QT += widgets
QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gomoku
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
        gamewidget.cpp \
    boardwidget.cpp \
    gomokuai.cpp

HEADERS += \
        gamewidget.h \
    boardwidget.h \
    gomokuai.h
