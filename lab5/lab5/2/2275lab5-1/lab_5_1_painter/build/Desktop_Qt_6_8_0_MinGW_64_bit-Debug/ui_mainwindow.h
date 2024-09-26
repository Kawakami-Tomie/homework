/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_draw_line;
    QAction *action_draw_circle;
    QAction *action_draw_rect;
    QAction *action_clear;
    QAction *action_pen_color;
    QAction *action_pen_thick;
    QAction *action_pen_style;
    QAction *action_brush_color;
    QAction *action_draw_pie;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 551);
        action_draw_line = new QAction(MainWindow);
        action_draw_line->setObjectName("action_draw_line");
        action_draw_circle = new QAction(MainWindow);
        action_draw_circle->setObjectName("action_draw_circle");
        action_draw_rect = new QAction(MainWindow);
        action_draw_rect->setObjectName("action_draw_rect");
        action_clear = new QAction(MainWindow);
        action_clear->setObjectName("action_clear");
        action_pen_color = new QAction(MainWindow);
        action_pen_color->setObjectName("action_pen_color");
        action_pen_thick = new QAction(MainWindow);
        action_pen_thick->setObjectName("action_pen_thick");
        action_pen_style = new QAction(MainWindow);
        action_pen_style->setObjectName("action_pen_style");
        action_brush_color = new QAction(MainWindow);
        action_brush_color->setObjectName("action_brush_color");
        action_draw_pie = new QAction(MainWindow);
        action_draw_pie->setObjectName("action_draw_pie");
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 500, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName("menu_2");
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action_draw_circle);
        menu->addAction(action_draw_rect);
        menu->addAction(action_draw_pie);
        menu->addAction(action_clear);
        menu_2->addAction(action_pen_color);
        menu_2->addAction(action_pen_thick);
        menu_2->addAction(action_pen_style);
        menu_2->addAction(action_brush_color);
        toolBar->addAction(action_draw_line);
        toolBar->addAction(action_draw_circle);
        toolBar->addAction(action_draw_rect);
        toolBar->addAction(action_draw_pie);
        toolBar->addAction(action_clear);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_draw_line->setText(QCoreApplication::translate("MainWindow", "\347\233\264\347\272\277", nullptr));
        action_draw_circle->setText(QCoreApplication::translate("MainWindow", "\345\234\206", nullptr));
        action_draw_rect->setText(QCoreApplication::translate("MainWindow", "\347\237\251\345\275\242", nullptr));
        action_clear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        action_pen_color->setText(QCoreApplication::translate("MainWindow", "\350\276\271\346\241\206\351\242\234\350\211\262", nullptr));
        action_pen_thick->setText(QCoreApplication::translate("MainWindow", "\350\276\271\346\241\206\347\262\227\347\273\206", nullptr));
        action_pen_style->setText(QCoreApplication::translate("MainWindow", "\350\276\271\346\241\206\346\240\267\345\274\217", nullptr));
        action_brush_color->setText(QCoreApplication::translate("MainWindow", "\350\203\214\346\231\257\351\242\234\350\211\262", nullptr));
        action_draw_pie->setText(QCoreApplication::translate("MainWindow", "\346\211\207\345\275\242", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\347\273\230\345\210\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
