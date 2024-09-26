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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *digitBtn9;
    QPushButton *multiplicationBtn;
    QPushButton *pointBtn;
    QPushButton *digitBtn7;
    QPushButton *digitBtn8;
    QPushButton *digitBtn5;
    QPushButton *digitBtn6;
    QPushButton *substactionBtn;
    QPushButton *powBtn;
    QPushButton *digitBtn1;
    QPushButton *digitBtn2;
    QPushButton *digitBtn4;
    QPushButton *leftBracketBtn;
    QPushButton *equalBtn;
    QPushButton *digitBtn3;
    QPushButton *addBtn;
    QPushButton *rightBracketBtn;
    QPushButton *divisionBtn;
    QPushButton *digitBtn0;
    QPushButton *signBtn;
    QPushButton *sinBtn;
    QLineEdit *lineEdit;
    QPushButton *lnBtn;
    QPushButton *cosBtn;
    QPushButton *facBtn;
    QPushButton *clearBtn;
    QPushButton *ClearAllBtn;
    QPushButton *piBtn;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        digitBtn9 = new QPushButton(centralWidget);
        digitBtn9->setObjectName("digitBtn9");

        gridLayout->addWidget(digitBtn9, 7, 2, 1, 1);

        multiplicationBtn = new QPushButton(centralWidget);
        multiplicationBtn->setObjectName("multiplicationBtn");

        gridLayout->addWidget(multiplicationBtn, 7, 3, 1, 1);

        pointBtn = new QPushButton(centralWidget);
        pointBtn->setObjectName("pointBtn");

        gridLayout->addWidget(pointBtn, 8, 0, 1, 1);

        digitBtn7 = new QPushButton(centralWidget);
        digitBtn7->setObjectName("digitBtn7");

        gridLayout->addWidget(digitBtn7, 7, 0, 1, 1);

        digitBtn8 = new QPushButton(centralWidget);
        digitBtn8->setObjectName("digitBtn8");

        gridLayout->addWidget(digitBtn8, 7, 1, 1, 1);

        digitBtn5 = new QPushButton(centralWidget);
        digitBtn5->setObjectName("digitBtn5");

        gridLayout->addWidget(digitBtn5, 6, 1, 1, 1);

        digitBtn6 = new QPushButton(centralWidget);
        digitBtn6->setObjectName("digitBtn6");

        gridLayout->addWidget(digitBtn6, 6, 2, 1, 1);

        substactionBtn = new QPushButton(centralWidget);
        substactionBtn->setObjectName("substactionBtn");

        gridLayout->addWidget(substactionBtn, 6, 3, 1, 1);

        powBtn = new QPushButton(centralWidget);
        powBtn->setObjectName("powBtn");

        gridLayout->addWidget(powBtn, 4, 2, 1, 1);

        digitBtn1 = new QPushButton(centralWidget);
        digitBtn1->setObjectName("digitBtn1");

        gridLayout->addWidget(digitBtn1, 5, 0, 1, 1);

        digitBtn2 = new QPushButton(centralWidget);
        digitBtn2->setObjectName("digitBtn2");

        gridLayout->addWidget(digitBtn2, 5, 1, 1, 1);

        digitBtn4 = new QPushButton(centralWidget);
        digitBtn4->setObjectName("digitBtn4");

        gridLayout->addWidget(digitBtn4, 6, 0, 1, 1);

        leftBracketBtn = new QPushButton(centralWidget);
        leftBracketBtn->setObjectName("leftBracketBtn");

        gridLayout->addWidget(leftBracketBtn, 4, 0, 1, 1);

        equalBtn = new QPushButton(centralWidget);
        equalBtn->setObjectName("equalBtn");

        gridLayout->addWidget(equalBtn, 4, 3, 1, 1);

        digitBtn3 = new QPushButton(centralWidget);
        digitBtn3->setObjectName("digitBtn3");

        gridLayout->addWidget(digitBtn3, 5, 2, 1, 1);

        addBtn = new QPushButton(centralWidget);
        addBtn->setObjectName("addBtn");

        gridLayout->addWidget(addBtn, 5, 3, 1, 1);

        rightBracketBtn = new QPushButton(centralWidget);
        rightBracketBtn->setObjectName("rightBracketBtn");

        gridLayout->addWidget(rightBracketBtn, 4, 1, 1, 1);

        divisionBtn = new QPushButton(centralWidget);
        divisionBtn->setObjectName("divisionBtn");

        gridLayout->addWidget(divisionBtn, 8, 3, 1, 1);

        digitBtn0 = new QPushButton(centralWidget);
        digitBtn0->setObjectName("digitBtn0");

        gridLayout->addWidget(digitBtn0, 8, 1, 1, 1);

        signBtn = new QPushButton(centralWidget);
        signBtn->setObjectName("signBtn");

        gridLayout->addWidget(signBtn, 8, 2, 1, 1);

        sinBtn = new QPushButton(centralWidget);
        sinBtn->setObjectName("sinBtn");

        gridLayout->addWidget(sinBtn, 3, 0, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setLayoutDirection(Qt::LeftToRight);
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 4);

        lnBtn = new QPushButton(centralWidget);
        lnBtn->setObjectName("lnBtn");

        gridLayout->addWidget(lnBtn, 3, 1, 1, 1);

        cosBtn = new QPushButton(centralWidget);
        cosBtn->setObjectName("cosBtn");

        gridLayout->addWidget(cosBtn, 3, 2, 1, 1);

        facBtn = new QPushButton(centralWidget);
        facBtn->setObjectName("facBtn");

        gridLayout->addWidget(facBtn, 3, 3, 1, 1);

        clearBtn = new QPushButton(centralWidget);
        clearBtn->setObjectName("clearBtn");

        gridLayout->addWidget(clearBtn, 2, 0, 1, 1);

        ClearAllBtn = new QPushButton(centralWidget);
        ClearAllBtn->setObjectName("ClearAllBtn");

        gridLayout->addWidget(ClearAllBtn, 2, 1, 1, 2);

        piBtn = new QPushButton(centralWidget);
        piBtn->setObjectName("piBtn");

        gridLayout->addWidget(piBtn, 2, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 400, 21));
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
        menu->addAction(action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Calculator_0827", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264&V", nullptr));
        digitBtn9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        multiplicationBtn->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pointBtn->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        digitBtn7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        digitBtn8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        digitBtn5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        digitBtn6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        substactionBtn->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        powBtn->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        digitBtn1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        digitBtn2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        digitBtn4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        leftBracketBtn->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        equalBtn->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        digitBtn3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        addBtn->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        rightBracketBtn->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        divisionBtn->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        digitBtn0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        signBtn->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        sinBtn->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        lnBtn->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        cosBtn->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        facBtn->setText(QCoreApplication::translate("MainWindow", "!", nullptr));
        clearBtn->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        ClearAllBtn->setText(QCoreApplication::translate("MainWindow", "ClearAll", nullptr));
        piBtn->setText(QCoreApplication::translate("MainWindow", "pi", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
