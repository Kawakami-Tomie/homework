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
    QAction *line;
    QAction *color;
    QAction *cuxi;
    QAction *circle;
    QAction *rect;
    QAction *clear;
    QAction *style;
    QAction *bgcolor;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        line = new QAction(MainWindow);
        line->setObjectName("line");
        color = new QAction(MainWindow);
        color->setObjectName("color");
        cuxi = new QAction(MainWindow);
        cuxi->setObjectName("cuxi");
        circle = new QAction(MainWindow);
        circle->setObjectName("circle");
        rect = new QAction(MainWindow);
        rect->setObjectName("rect");
        clear = new QAction(MainWindow);
        clear->setObjectName("clear");
        style = new QAction(MainWindow);
        style->setObjectName("style");
        bgcolor = new QAction(MainWindow);
        bgcolor->setObjectName("bgcolor");
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 400, 24));
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName("menu_2");
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(line);
        menu->addAction(circle);
        menu->addAction(rect);
        menu->addAction(clear);
        menu_2->addAction(color);
        menu_2->addAction(cuxi);
        menu_2->addAction(style);
        menu_2->addAction(bgcolor);
        mainToolBar->addAction(line);
        mainToolBar->addAction(circle);
        mainToolBar->addAction(rect);
        mainToolBar->addAction(clear);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        line->setText(QCoreApplication::translate("MainWindow", "\347\233\264\347\272\277", nullptr));
        color->setText(QCoreApplication::translate("MainWindow", "\350\276\271\346\241\206\351\242\234\350\211\262", nullptr));
        cuxi->setText(QCoreApplication::translate("MainWindow", "\350\276\271\346\241\206\347\262\227\347\273\206", nullptr));
        circle->setText(QCoreApplication::translate("MainWindow", "\345\234\206", nullptr));
        rect->setText(QCoreApplication::translate("MainWindow", "\347\237\251\345\275\242", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        style->setText(QCoreApplication::translate("MainWindow", "\350\276\271\346\241\206\346\240\267\345\274\217", nullptr));
        bgcolor->setText(QCoreApplication::translate("MainWindow", "\350\203\214\346\231\257\351\242\234\350\211\262", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\347\273\230\345\210\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
