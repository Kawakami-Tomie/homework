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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        digitBtn9 = new QPushButton(centralWidget);
        digitBtn9->setObjectName(QStringLiteral("digitBtn9"));

        gridLayout->addWidget(digitBtn9, 7, 2, 1, 1);

        multiplicationBtn = new QPushButton(centralWidget);
        multiplicationBtn->setObjectName(QStringLiteral("multiplicationBtn"));

        gridLayout->addWidget(multiplicationBtn, 7, 3, 1, 1);

        pointBtn = new QPushButton(centralWidget);
        pointBtn->setObjectName(QStringLiteral("pointBtn"));

        gridLayout->addWidget(pointBtn, 8, 0, 1, 1);

        digitBtn7 = new QPushButton(centralWidget);
        digitBtn7->setObjectName(QStringLiteral("digitBtn7"));

        gridLayout->addWidget(digitBtn7, 7, 0, 1, 1);

        digitBtn8 = new QPushButton(centralWidget);
        digitBtn8->setObjectName(QStringLiteral("digitBtn8"));

        gridLayout->addWidget(digitBtn8, 7, 1, 1, 1);

        digitBtn5 = new QPushButton(centralWidget);
        digitBtn5->setObjectName(QStringLiteral("digitBtn5"));

        gridLayout->addWidget(digitBtn5, 6, 1, 1, 1);

        digitBtn6 = new QPushButton(centralWidget);
        digitBtn6->setObjectName(QStringLiteral("digitBtn6"));

        gridLayout->addWidget(digitBtn6, 6, 2, 1, 1);

        substactionBtn = new QPushButton(centralWidget);
        substactionBtn->setObjectName(QStringLiteral("substactionBtn"));

        gridLayout->addWidget(substactionBtn, 6, 3, 1, 1);

        powBtn = new QPushButton(centralWidget);
        powBtn->setObjectName(QStringLiteral("powBtn"));

        gridLayout->addWidget(powBtn, 4, 2, 1, 1);

        digitBtn1 = new QPushButton(centralWidget);
        digitBtn1->setObjectName(QStringLiteral("digitBtn1"));

        gridLayout->addWidget(digitBtn1, 5, 0, 1, 1);

        digitBtn2 = new QPushButton(centralWidget);
        digitBtn2->setObjectName(QStringLiteral("digitBtn2"));

        gridLayout->addWidget(digitBtn2, 5, 1, 1, 1);

        digitBtn4 = new QPushButton(centralWidget);
        digitBtn4->setObjectName(QStringLiteral("digitBtn4"));

        gridLayout->addWidget(digitBtn4, 6, 0, 1, 1);

        leftBracketBtn = new QPushButton(centralWidget);
        leftBracketBtn->setObjectName(QStringLiteral("leftBracketBtn"));

        gridLayout->addWidget(leftBracketBtn, 4, 0, 1, 1);

        equalBtn = new QPushButton(centralWidget);
        equalBtn->setObjectName(QStringLiteral("equalBtn"));

        gridLayout->addWidget(equalBtn, 4, 3, 1, 1);

        digitBtn3 = new QPushButton(centralWidget);
        digitBtn3->setObjectName(QStringLiteral("digitBtn3"));

        gridLayout->addWidget(digitBtn3, 5, 2, 1, 1);

        addBtn = new QPushButton(centralWidget);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        gridLayout->addWidget(addBtn, 5, 3, 1, 1);

        rightBracketBtn = new QPushButton(centralWidget);
        rightBracketBtn->setObjectName(QStringLiteral("rightBracketBtn"));

        gridLayout->addWidget(rightBracketBtn, 4, 1, 1, 1);

        divisionBtn = new QPushButton(centralWidget);
        divisionBtn->setObjectName(QStringLiteral("divisionBtn"));

        gridLayout->addWidget(divisionBtn, 8, 3, 1, 1);

        digitBtn0 = new QPushButton(centralWidget);
        digitBtn0->setObjectName(QStringLiteral("digitBtn0"));

        gridLayout->addWidget(digitBtn0, 8, 1, 1, 1);

        signBtn = new QPushButton(centralWidget);
        signBtn->setObjectName(QStringLiteral("signBtn"));

        gridLayout->addWidget(signBtn, 8, 2, 1, 1);

        sinBtn = new QPushButton(centralWidget);
        sinBtn->setObjectName(QStringLiteral("sinBtn"));

        gridLayout->addWidget(sinBtn, 3, 0, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setLayoutDirection(Qt::LeftToRight);
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 4);

        lnBtn = new QPushButton(centralWidget);
        lnBtn->setObjectName(QStringLiteral("lnBtn"));

        gridLayout->addWidget(lnBtn, 3, 1, 1, 1);

        cosBtn = new QPushButton(centralWidget);
        cosBtn->setObjectName(QStringLiteral("cosBtn"));

        gridLayout->addWidget(cosBtn, 3, 2, 1, 1);

        facBtn = new QPushButton(centralWidget);
        facBtn->setObjectName(QStringLiteral("facBtn"));

        gridLayout->addWidget(facBtn, 3, 3, 1, 1);

        clearBtn = new QPushButton(centralWidget);
        clearBtn->setObjectName(QStringLiteral("clearBtn"));

        gridLayout->addWidget(clearBtn, 2, 0, 1, 1);

        ClearAllBtn = new QPushButton(centralWidget);
        ClearAllBtn->setObjectName(QStringLiteral("ClearAllBtn"));

        gridLayout->addWidget(ClearAllBtn, 2, 1, 1, 2);

        piBtn = new QPushButton(centralWidget);
        piBtn->setObjectName(QStringLiteral("piBtn"));

        gridLayout->addWidget(piBtn, 2, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
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
        menu->addAction(action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculator_0827", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264&V", Q_NULLPTR));
        digitBtn9->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        multiplicationBtn->setText(QApplication::translate("MainWindow", "*", Q_NULLPTR));
        pointBtn->setText(QApplication::translate("MainWindow", ".", Q_NULLPTR));
        digitBtn7->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        digitBtn8->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        digitBtn5->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        digitBtn6->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        substactionBtn->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        powBtn->setText(QApplication::translate("MainWindow", "^", Q_NULLPTR));
        digitBtn1->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        digitBtn2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        digitBtn4->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        leftBracketBtn->setText(QApplication::translate("MainWindow", "(", Q_NULLPTR));
        equalBtn->setText(QApplication::translate("MainWindow", "=", Q_NULLPTR));
        digitBtn3->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        addBtn->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        rightBracketBtn->setText(QApplication::translate("MainWindow", ")", Q_NULLPTR));
        divisionBtn->setText(QApplication::translate("MainWindow", "/", Q_NULLPTR));
        digitBtn0->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        signBtn->setText(QApplication::translate("MainWindow", "+/-", Q_NULLPTR));
        sinBtn->setText(QApplication::translate("MainWindow", "sin", Q_NULLPTR));
        lnBtn->setText(QApplication::translate("MainWindow", "ln", Q_NULLPTR));
        cosBtn->setText(QApplication::translate("MainWindow", "cos", Q_NULLPTR));
        facBtn->setText(QApplication::translate("MainWindow", "!", Q_NULLPTR));
        clearBtn->setText(QApplication::translate("MainWindow", "clear", Q_NULLPTR));
        ClearAllBtn->setText(QApplication::translate("MainWindow", "ClearAll", Q_NULLPTR));
        piBtn->setText(QApplication::translate("MainWindow", "pi", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\350\217\234\345\215\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
