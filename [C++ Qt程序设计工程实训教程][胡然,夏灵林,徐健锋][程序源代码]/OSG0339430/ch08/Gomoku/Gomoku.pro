#-------------------------------------------------
# 项目：实训八，双人对战五子棋
# 功能：黑白任一方先连成5个棋子形成的直线（横线、竖线、对角线），则标记这5颗棋子，判该方赢对方输。
# 位置：code\ch08\Gomoku
# 说明：
#-------------------------------------------------

QT       += core gui

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
    boardwidget.cpp

HEADERS += \
        gamewidget.h \
    boardwidget.h
