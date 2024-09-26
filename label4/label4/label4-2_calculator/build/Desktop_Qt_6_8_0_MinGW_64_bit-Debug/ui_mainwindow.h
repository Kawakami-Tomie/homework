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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_V;
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *tanBtn;
    QPushButton *digitBtn9;
    QPushButton *digitBtn0;
    QPushButton *powBtn;
    QPushButton *substactionBtn;
    QPushButton *digitBtn4;
    QPushButton *equalBtn;
    QPushButton *multiplicationBtn;
    QPushButton *signBtn;
    QPushButton *pointBtn;
    QPushButton *digitBtn6;
    QPushButton *digitBtn2;
    QPushButton *digitBtn3;
    QPushButton *divisionBtn;
    QPushButton *digitBtn1;
    QPushButton *cosBtn;
    QPushButton *digitBtn7;
    QPushButton *lnBtn;
    QPushButton *digitBtn8;
    QPushButton *digitBtn5;
    QPushButton *lgBtn;
    QPushButton *addBtn;
    QPushButton *rightBracketBtn;
    QPushButton *leftBracketBtn;
    QTextEdit *textEdit;
    QPushButton *percentBtn;
    QPushButton *sinBtn;
    QPushButton *clearBtn;
    QPushButton *ClearAllBtn;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(450, 490);
        action_V = new QAction(MainWindow);
        action_V->setObjectName("action_V");
        action = new QAction(MainWindow);
        action->setObjectName("action");
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        action_3 = new QAction(MainWindow);
        action_3->setObjectName("action_3");
        action_3->setCheckable(true);
        action_4 = new QAction(MainWindow);
        action_4->setObjectName("action_4");
        action_5 = new QAction(MainWindow);
        action_5->setObjectName("action_5");
        action_5->setMenuRole(QAction::TextHeuristicRole);
        action_6 = new QAction(MainWindow);
        action_6->setObjectName("action_6");
        action_6->setMenuRole(QAction::TextHeuristicRole);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        tanBtn = new QPushButton(centralWidget);
        tanBtn->setObjectName("tanBtn");

        gridLayout->addWidget(tanBtn, 4, 0, 1, 1);

        digitBtn9 = new QPushButton(centralWidget);
        digitBtn9->setObjectName("digitBtn9");

        gridLayout->addWidget(digitBtn9, 5, 3, 1, 1);

        digitBtn0 = new QPushButton(centralWidget);
        digitBtn0->setObjectName("digitBtn0");

        gridLayout->addWidget(digitBtn0, 6, 2, 1, 1);

        powBtn = new QPushButton(centralWidget);
        powBtn->setObjectName("powBtn");

        gridLayout->addWidget(powBtn, 2, 3, 1, 1);

        substactionBtn = new QPushButton(centralWidget);
        substactionBtn->setObjectName("substactionBtn");

        gridLayout->addWidget(substactionBtn, 4, 4, 1, 1);

        digitBtn4 = new QPushButton(centralWidget);
        digitBtn4->setObjectName("digitBtn4");

        gridLayout->addWidget(digitBtn4, 4, 1, 1, 1);

        equalBtn = new QPushButton(centralWidget);
        equalBtn->setObjectName("equalBtn");

        gridLayout->addWidget(equalBtn, 2, 4, 1, 1);

        multiplicationBtn = new QPushButton(centralWidget);
        multiplicationBtn->setObjectName("multiplicationBtn");

        gridLayout->addWidget(multiplicationBtn, 5, 4, 1, 1);

        signBtn = new QPushButton(centralWidget);
        signBtn->setObjectName("signBtn");

        gridLayout->addWidget(signBtn, 6, 3, 1, 1);

        pointBtn = new QPushButton(centralWidget);
        pointBtn->setObjectName("pointBtn");

        gridLayout->addWidget(pointBtn, 6, 1, 1, 1);

        digitBtn6 = new QPushButton(centralWidget);
        digitBtn6->setObjectName("digitBtn6");

        gridLayout->addWidget(digitBtn6, 4, 3, 1, 1);

        digitBtn2 = new QPushButton(centralWidget);
        digitBtn2->setObjectName("digitBtn2");

        gridLayout->addWidget(digitBtn2, 3, 2, 1, 1);

        digitBtn3 = new QPushButton(centralWidget);
        digitBtn3->setObjectName("digitBtn3");

        gridLayout->addWidget(digitBtn3, 3, 3, 1, 1);

        divisionBtn = new QPushButton(centralWidget);
        divisionBtn->setObjectName("divisionBtn");

        gridLayout->addWidget(divisionBtn, 6, 4, 1, 1);

        digitBtn1 = new QPushButton(centralWidget);
        digitBtn1->setObjectName("digitBtn1");

        gridLayout->addWidget(digitBtn1, 3, 1, 1, 1);

        cosBtn = new QPushButton(centralWidget);
        cosBtn->setObjectName("cosBtn");

        gridLayout->addWidget(cosBtn, 3, 0, 1, 1);

        digitBtn7 = new QPushButton(centralWidget);
        digitBtn7->setObjectName("digitBtn7");

        gridLayout->addWidget(digitBtn7, 5, 1, 1, 1);

        lnBtn = new QPushButton(centralWidget);
        lnBtn->setObjectName("lnBtn");

        gridLayout->addWidget(lnBtn, 5, 0, 1, 1);

        digitBtn8 = new QPushButton(centralWidget);
        digitBtn8->setObjectName("digitBtn8");

        gridLayout->addWidget(digitBtn8, 5, 2, 1, 1);

        digitBtn5 = new QPushButton(centralWidget);
        digitBtn5->setObjectName("digitBtn5");

        gridLayout->addWidget(digitBtn5, 4, 2, 1, 1);

        lgBtn = new QPushButton(centralWidget);
        lgBtn->setObjectName("lgBtn");

        gridLayout->addWidget(lgBtn, 6, 0, 1, 1);

        addBtn = new QPushButton(centralWidget);
        addBtn->setObjectName("addBtn");

        gridLayout->addWidget(addBtn, 3, 4, 1, 1);

        rightBracketBtn = new QPushButton(centralWidget);
        rightBracketBtn->setObjectName("rightBracketBtn");

        gridLayout->addWidget(rightBracketBtn, 2, 2, 1, 1);

        leftBracketBtn = new QPushButton(centralWidget);
        leftBracketBtn->setObjectName("leftBracketBtn");

        gridLayout->addWidget(leftBracketBtn, 2, 1, 1, 1);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName("textEdit");

        gridLayout->addWidget(textEdit, 0, 0, 1, 5);

        percentBtn = new QPushButton(centralWidget);
        percentBtn->setObjectName("percentBtn");

        gridLayout->addWidget(percentBtn, 1, 0, 1, 1);

        sinBtn = new QPushButton(centralWidget);
        sinBtn->setObjectName("sinBtn");

        gridLayout->addWidget(sinBtn, 2, 0, 1, 1);

        clearBtn = new QPushButton(centralWidget);
        clearBtn->setObjectName("clearBtn");

        gridLayout->addWidget(clearBtn, 1, 1, 1, 2);

        ClearAllBtn = new QPushButton(centralWidget);
        ClearAllBtn->setObjectName("ClearAllBtn");

        gridLayout->addWidget(ClearAllBtn, 1, 3, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 450, 24));
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_V);
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addAction(action_3);
        menu->addAction(action_4);
        mainToolBar->addAction(action);
        mainToolBar->addAction(action_2);
        mainToolBar->addAction(action_3);
        mainToolBar->addAction(action_4);
        mainToolBar->addAction(action_5);
        mainToolBar->addAction(action_6);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Calculator_0827", nullptr));
        action_V->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264 & Ctrl+V", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\350\256\260\345\275\225", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\347\247\221\345\255\246\350\256\241\347\256\227\345\231\250", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\344\272\214\350\277\233\345\210\266", nullptr));
#if QT_CONFIG(tooltip)
        action_4->setToolTip(QCoreApplication::translate("MainWindow", "\344\272\214\350\277\233\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
        action_5->setText(QCoreApplication::translate("MainWindow", "\346\227\245\346\234\237", nullptr));
#if QT_CONFIG(tooltip)
        action_5->setToolTip(QCoreApplication::translate("MainWindow", "\346\227\245\346\234\237", nullptr));
#endif // QT_CONFIG(tooltip)
        action_6->setText(QCoreApplication::translate("MainWindow", "\347\250\213\345\272\217\345\221\230", nullptr));
#if QT_CONFIG(tooltip)
        action_6->setToolTip(QCoreApplication::translate("MainWindow", "\347\250\213\345\272\217\345\221\230", nullptr));
#endif // QT_CONFIG(tooltip)
        tanBtn->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        digitBtn9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        digitBtn0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        powBtn->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        substactionBtn->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        digitBtn4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        equalBtn->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        multiplicationBtn->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        signBtn->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        pointBtn->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        digitBtn6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        digitBtn2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        digitBtn3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        divisionBtn->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        digitBtn1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        cosBtn->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        digitBtn7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        lnBtn->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        digitBtn8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        digitBtn5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        lgBtn->setText(QCoreApplication::translate("MainWindow", "lg", nullptr));
        addBtn->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        rightBracketBtn->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        leftBracketBtn->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        percentBtn->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        sinBtn->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        clearBtn->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        ClearAllBtn->setText(QCoreApplication::translate("MainWindow", "ClearAll", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
