/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_V;
    QWidget *centralWidget;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *le_show;
    QGridLayout *gridLayout_2;
    QPushButton *btn_clear;
    QGridLayout *gridLayout;
    QPushButton *btn_left;
    QPushButton *btn_right;
    QPushButton *btn_mul;
    QPushButton *btn_equal;
    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QPushButton *btn_add;
    QPushButton *btn_4;
    QPushButton *btn_5;
    QPushButton *btn_6;
    QPushButton *btn_sub;
    QPushButton *btn_7;
    QPushButton *btn_8;
    QPushButton *btn_9;
    QPushButton *btn_multiply;
    QPushButton *btn_point;
    QPushButton *btn_0;
    QPushButton *pushButton_18;
    QPushButton *btn_divide;
    QPushButton *btn_back;
    QPushButton *btn_qufan;
    QPushButton *btn_jueduizhi;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(470, 349);
        action_V = new QAction(MainWindow);
        action_V->setObjectName(QStringLiteral("action_V"));
        action_V->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 10, 401, 274));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        le_show = new QLineEdit(widget);
        le_show->setObjectName(QStringLiteral("le_show"));

        verticalLayout->addWidget(le_show);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btn_clear = new QPushButton(widget);
        btn_clear->setObjectName(QStringLiteral("btn_clear"));

        gridLayout_2->addWidget(btn_clear, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn_left = new QPushButton(widget);
        btn_left->setObjectName(QStringLiteral("btn_left"));

        gridLayout->addWidget(btn_left, 0, 0, 1, 1);

        btn_right = new QPushButton(widget);
        btn_right->setObjectName(QStringLiteral("btn_right"));

        gridLayout->addWidget(btn_right, 0, 1, 1, 1);

        btn_mul = new QPushButton(widget);
        btn_mul->setObjectName(QStringLiteral("btn_mul"));

        gridLayout->addWidget(btn_mul, 0, 2, 1, 1);

        btn_equal = new QPushButton(widget);
        btn_equal->setObjectName(QStringLiteral("btn_equal"));

        gridLayout->addWidget(btn_equal, 0, 3, 1, 1);

        btn_1 = new QPushButton(widget);
        btn_1->setObjectName(QStringLiteral("btn_1"));

        gridLayout->addWidget(btn_1, 1, 0, 1, 1);

        btn_2 = new QPushButton(widget);
        btn_2->setObjectName(QStringLiteral("btn_2"));

        gridLayout->addWidget(btn_2, 1, 1, 1, 1);

        btn_3 = new QPushButton(widget);
        btn_3->setObjectName(QStringLiteral("btn_3"));

        gridLayout->addWidget(btn_3, 1, 2, 1, 1);

        btn_add = new QPushButton(widget);
        btn_add->setObjectName(QStringLiteral("btn_add"));

        gridLayout->addWidget(btn_add, 1, 3, 1, 1);

        btn_4 = new QPushButton(widget);
        btn_4->setObjectName(QStringLiteral("btn_4"));

        gridLayout->addWidget(btn_4, 2, 0, 1, 1);

        btn_5 = new QPushButton(widget);
        btn_5->setObjectName(QStringLiteral("btn_5"));

        gridLayout->addWidget(btn_5, 2, 1, 1, 1);

        btn_6 = new QPushButton(widget);
        btn_6->setObjectName(QStringLiteral("btn_6"));

        gridLayout->addWidget(btn_6, 2, 2, 1, 1);

        btn_sub = new QPushButton(widget);
        btn_sub->setObjectName(QStringLiteral("btn_sub"));

        gridLayout->addWidget(btn_sub, 2, 3, 1, 1);

        btn_7 = new QPushButton(widget);
        btn_7->setObjectName(QStringLiteral("btn_7"));

        gridLayout->addWidget(btn_7, 3, 0, 1, 1);

        btn_8 = new QPushButton(widget);
        btn_8->setObjectName(QStringLiteral("btn_8"));

        gridLayout->addWidget(btn_8, 3, 1, 1, 1);

        btn_9 = new QPushButton(widget);
        btn_9->setObjectName(QStringLiteral("btn_9"));

        gridLayout->addWidget(btn_9, 3, 2, 1, 1);

        btn_multiply = new QPushButton(widget);
        btn_multiply->setObjectName(QStringLiteral("btn_multiply"));

        gridLayout->addWidget(btn_multiply, 3, 3, 1, 1);

        btn_point = new QPushButton(widget);
        btn_point->setObjectName(QStringLiteral("btn_point"));

        gridLayout->addWidget(btn_point, 4, 0, 1, 1);

        btn_0 = new QPushButton(widget);
        btn_0->setObjectName(QStringLiteral("btn_0"));

        gridLayout->addWidget(btn_0, 4, 1, 1, 1);

        pushButton_18 = new QPushButton(widget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));

        gridLayout->addWidget(pushButton_18, 4, 2, 1, 1);

        btn_divide = new QPushButton(widget);
        btn_divide->setObjectName(QStringLiteral("btn_divide"));

        gridLayout->addWidget(btn_divide, 4, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 2);

        btn_back = new QPushButton(widget);
        btn_back->setObjectName(QStringLiteral("btn_back"));

        gridLayout_2->addWidget(btn_back, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 4);

        btn_qufan = new QPushButton(widget);
        btn_qufan->setObjectName(QStringLiteral("btn_qufan"));

        gridLayout_3->addWidget(btn_qufan, 1, 0, 1, 1);

        btn_jueduizhi = new QPushButton(widget);
        btn_jueduizhi->setObjectName(QStringLiteral("btn_jueduizhi"));

        gridLayout_3->addWidget(btn_jueduizhi, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_3->addWidget(pushButton_3, 1, 2, 1, 1);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_3->addWidget(pushButton_4, 1, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 470, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_V);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action_V->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264(&V)", Q_NULLPTR));
        btn_clear->setText(QApplication::translate("MainWindow", "Clear All", Q_NULLPTR));
        btn_left->setText(QApplication::translate("MainWindow", "(", Q_NULLPTR));
        btn_right->setText(QApplication::translate("MainWindow", "\357\274\211", Q_NULLPTR));
        btn_mul->setText(QApplication::translate("MainWindow", "^", Q_NULLPTR));
        btn_equal->setText(QApplication::translate("MainWindow", "=", Q_NULLPTR));
        btn_1->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        btn_2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        btn_3->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        btn_add->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        btn_4->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        btn_5->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        btn_6->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        btn_sub->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        btn_7->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        btn_8->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        btn_9->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        btn_multiply->setText(QApplication::translate("MainWindow", "*", Q_NULLPTR));
        btn_point->setText(QApplication::translate("MainWindow", ".", Q_NULLPTR));
        btn_0->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        pushButton_18->setText(QApplication::translate("MainWindow", "+/-", Q_NULLPTR));
        btn_divide->setText(QApplication::translate("MainWindow", "/", Q_NULLPTR));
        btn_back->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        btn_qufan->setText(QApplication::translate("MainWindow", "!", Q_NULLPTR));
        btn_jueduizhi->setText(QApplication::translate("MainWindow", "| |", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "<<", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", ">>", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\350\217\234\345\215\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
