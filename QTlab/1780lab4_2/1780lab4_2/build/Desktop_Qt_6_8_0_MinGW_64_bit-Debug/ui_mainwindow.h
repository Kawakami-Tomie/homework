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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QRadioButton *radio_2;
    QRadioButton *radio_8;
    QRadioButton *radio_10;
    QRadioButton *radio_16;
    QPushButton *btn_transition;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *percentBtn;
    QPushButton *clearBtn;
    QPushButton *clearAllBtn;
    QPushButton *powBtn;
    QPushButton *equalBtn;
    QPushButton *sinBtn;
    QPushButton *leftBracketBtn;
    QPushButton *rightBracketBtn;
    QPushButton *signBtn;
    QPushButton *addBtn;
    QPushButton *cosBtn;
    QPushButton *digitBtn1;
    QPushButton *digitBtn2;
    QPushButton *digitBtn3;
    QPushButton *subtractionBtn;
    QPushButton *tanBtn;
    QPushButton *digitBtn4;
    QPushButton *digitBtn5;
    QPushButton *digitBtn6;
    QPushButton *multiplicationBtn;
    QPushButton *lnBtn;
    QPushButton *digitBtn7;
    QPushButton *digitBtn8;
    QPushButton *digitBtn9;
    QPushButton *divisionBtn;
    QPushButton *lgBtn;
    QPushButton *pointBtn;
    QPushButton *digitBtn0;
    QPushButton *levelBtn;
    QPushButton *genhaoBtn;
    QLineEdit *le_2;
    QLineEdit *le_cin;
    QLineEdit *le_8;
    QLineEdit *le_10;
    QLineEdit *le_16;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(566, 346);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        action_3 = new QAction(MainWindow);
        action_3->setObjectName("action_3");
        action_4 = new QAction(MainWindow);
        action_4->setObjectName("action_4");
        action_4->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName("textEdit");
        textEdit->setMinimumSize(QSize(200, 0));
        QFont font;
        font.setPointSize(11);
        textEdit->setFont(font);

        gridLayout->addWidget(textEdit, 0, 0, 7, 5);

        radio_2 = new QRadioButton(centralWidget);
        radio_2->setObjectName("radio_2");
        radio_2->setCheckable(true);
        radio_2->setChecked(false);

        gridLayout->addWidget(radio_2, 0, 5, 1, 2);

        radio_8 = new QRadioButton(centralWidget);
        radio_8->setObjectName("radio_8");

        gridLayout->addWidget(radio_8, 0, 7, 1, 2);

        radio_10 = new QRadioButton(centralWidget);
        radio_10->setObjectName("radio_10");

        gridLayout->addWidget(radio_10, 1, 5, 1, 2);

        radio_16 = new QRadioButton(centralWidget);
        radio_16->setObjectName("radio_16");

        gridLayout->addWidget(radio_16, 1, 7, 1, 2);

        btn_transition = new QPushButton(centralWidget);
        btn_transition->setObjectName("btn_transition");

        gridLayout->addWidget(btn_transition, 2, 8, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 3, 5, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 4, 5, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 5, 5, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 6, 5, 1, 1);

        percentBtn = new QPushButton(centralWidget);
        percentBtn->setObjectName("percentBtn");

        gridLayout->addWidget(percentBtn, 7, 0, 1, 1);

        clearBtn = new QPushButton(centralWidget);
        clearBtn->setObjectName("clearBtn");

        gridLayout->addWidget(clearBtn, 7, 1, 1, 1);

        clearAllBtn = new QPushButton(centralWidget);
        clearAllBtn->setObjectName("clearAllBtn");

        gridLayout->addWidget(clearAllBtn, 7, 2, 1, 1);

        powBtn = new QPushButton(centralWidget);
        powBtn->setObjectName("powBtn");

        gridLayout->addWidget(powBtn, 7, 3, 1, 1);

        equalBtn = new QPushButton(centralWidget);
        equalBtn->setObjectName("equalBtn");

        gridLayout->addWidget(equalBtn, 7, 4, 1, 1);

        sinBtn = new QPushButton(centralWidget);
        sinBtn->setObjectName("sinBtn");

        gridLayout->addWidget(sinBtn, 8, 0, 1, 1);

        leftBracketBtn = new QPushButton(centralWidget);
        leftBracketBtn->setObjectName("leftBracketBtn");

        gridLayout->addWidget(leftBracketBtn, 8, 1, 1, 1);

        rightBracketBtn = new QPushButton(centralWidget);
        rightBracketBtn->setObjectName("rightBracketBtn");

        gridLayout->addWidget(rightBracketBtn, 8, 2, 1, 1);

        signBtn = new QPushButton(centralWidget);
        signBtn->setObjectName("signBtn");

        gridLayout->addWidget(signBtn, 8, 3, 1, 1);

        addBtn = new QPushButton(centralWidget);
        addBtn->setObjectName("addBtn");

        gridLayout->addWidget(addBtn, 8, 4, 1, 1);

        cosBtn = new QPushButton(centralWidget);
        cosBtn->setObjectName("cosBtn");

        gridLayout->addWidget(cosBtn, 9, 0, 1, 1);

        digitBtn1 = new QPushButton(centralWidget);
        digitBtn1->setObjectName("digitBtn1");

        gridLayout->addWidget(digitBtn1, 9, 1, 1, 1);

        digitBtn2 = new QPushButton(centralWidget);
        digitBtn2->setObjectName("digitBtn2");

        gridLayout->addWidget(digitBtn2, 9, 2, 1, 1);

        digitBtn3 = new QPushButton(centralWidget);
        digitBtn3->setObjectName("digitBtn3");

        gridLayout->addWidget(digitBtn3, 9, 3, 1, 1);

        subtractionBtn = new QPushButton(centralWidget);
        subtractionBtn->setObjectName("subtractionBtn");

        gridLayout->addWidget(subtractionBtn, 9, 4, 1, 1);

        tanBtn = new QPushButton(centralWidget);
        tanBtn->setObjectName("tanBtn");

        gridLayout->addWidget(tanBtn, 10, 0, 1, 1);

        digitBtn4 = new QPushButton(centralWidget);
        digitBtn4->setObjectName("digitBtn4");

        gridLayout->addWidget(digitBtn4, 10, 1, 1, 1);

        digitBtn5 = new QPushButton(centralWidget);
        digitBtn5->setObjectName("digitBtn5");

        gridLayout->addWidget(digitBtn5, 10, 2, 1, 1);

        digitBtn6 = new QPushButton(centralWidget);
        digitBtn6->setObjectName("digitBtn6");

        gridLayout->addWidget(digitBtn6, 10, 3, 1, 1);

        multiplicationBtn = new QPushButton(centralWidget);
        multiplicationBtn->setObjectName("multiplicationBtn");

        gridLayout->addWidget(multiplicationBtn, 10, 4, 1, 1);

        lnBtn = new QPushButton(centralWidget);
        lnBtn->setObjectName("lnBtn");

        gridLayout->addWidget(lnBtn, 11, 0, 1, 1);

        digitBtn7 = new QPushButton(centralWidget);
        digitBtn7->setObjectName("digitBtn7");

        gridLayout->addWidget(digitBtn7, 11, 1, 1, 1);

        digitBtn8 = new QPushButton(centralWidget);
        digitBtn8->setObjectName("digitBtn8");

        gridLayout->addWidget(digitBtn8, 11, 2, 1, 1);

        digitBtn9 = new QPushButton(centralWidget);
        digitBtn9->setObjectName("digitBtn9");

        gridLayout->addWidget(digitBtn9, 11, 3, 1, 1);

        divisionBtn = new QPushButton(centralWidget);
        divisionBtn->setObjectName("divisionBtn");

        gridLayout->addWidget(divisionBtn, 11, 4, 1, 1);

        lgBtn = new QPushButton(centralWidget);
        lgBtn->setObjectName("lgBtn");

        gridLayout->addWidget(lgBtn, 12, 0, 1, 1);

        pointBtn = new QPushButton(centralWidget);
        pointBtn->setObjectName("pointBtn");

        gridLayout->addWidget(pointBtn, 12, 1, 1, 1);

        digitBtn0 = new QPushButton(centralWidget);
        digitBtn0->setObjectName("digitBtn0");

        gridLayout->addWidget(digitBtn0, 12, 2, 1, 1);

        levelBtn = new QPushButton(centralWidget);
        levelBtn->setObjectName("levelBtn");

        gridLayout->addWidget(levelBtn, 12, 3, 1, 1);

        genhaoBtn = new QPushButton(centralWidget);
        genhaoBtn->setObjectName("genhaoBtn");

        gridLayout->addWidget(genhaoBtn, 12, 4, 1, 1);

        le_2 = new QLineEdit(centralWidget);
        le_2->setObjectName("le_2");

        gridLayout->addWidget(le_2, 3, 7, 1, 2);

        le_cin = new QLineEdit(centralWidget);
        le_cin->setObjectName("le_cin");

        gridLayout->addWidget(le_cin, 2, 5, 1, 2);

        le_8 = new QLineEdit(centralWidget);
        le_8->setObjectName("le_8");

        gridLayout->addWidget(le_8, 4, 7, 1, 2);

        le_10 = new QLineEdit(centralWidget);
        le_10->setObjectName("le_10");

        gridLayout->addWidget(le_10, 5, 7, 1, 2);

        le_16 = new QLineEdit(centralWidget);
        le_16->setObjectName("le_16");

        gridLayout->addWidget(le_16, 6, 7, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 566, 17));
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
        menu->addAction(action_2);
        menu->addAction(action_3);
        menu->addAction(action_4);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\350\256\260\345\275\225", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\347\247\221\345\255\246\350\256\241\347\256\227\345\231\250", nullptr));
        radio_2->setText(QCoreApplication::translate("MainWindow", "2\350\277\233\345\210\266", nullptr));
        radio_8->setText(QCoreApplication::translate("MainWindow", "8\350\277\233\345\210\266", nullptr));
        radio_10->setText(QCoreApplication::translate("MainWindow", "10\350\277\233\345\210\266", nullptr));
        radio_16->setText(QCoreApplication::translate("MainWindow", "16\350\277\233\345\210\266", nullptr));
        btn_transition->setText(QCoreApplication::translate("MainWindow", "\350\275\254\346\215\242", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\272\214\350\277\233\345\210\266", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\205\253\350\277\233\345\210\266", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\215\201\350\277\233\345\210\266", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266", nullptr));
        percentBtn->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        clearBtn->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        clearAllBtn->setText(QCoreApplication::translate("MainWindow", "ClearAll", nullptr));
        powBtn->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        equalBtn->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        sinBtn->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        leftBracketBtn->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        rightBracketBtn->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        signBtn->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        addBtn->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        cosBtn->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        digitBtn1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        digitBtn2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        digitBtn3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        subtractionBtn->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        tanBtn->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        digitBtn4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        digitBtn5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        digitBtn6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        multiplicationBtn->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        lnBtn->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        digitBtn7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        digitBtn8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        digitBtn9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        divisionBtn->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        lgBtn->setText(QCoreApplication::translate("MainWindow", "lg", nullptr));
        pointBtn->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        digitBtn0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        levelBtn->setText(QCoreApplication::translate("MainWindow", "!", nullptr));
        genhaoBtn->setText(QCoreApplication::translate("MainWindow", "root", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
