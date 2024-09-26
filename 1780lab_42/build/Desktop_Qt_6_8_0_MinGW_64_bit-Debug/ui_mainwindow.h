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
#include <QtWidgets/QFormLayout>
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QWidget *centralwidget;
    QPushButton *digitBtn8;
    QPushButton *pointBtn;
    QPushButton *tanBtn;
    QPushButton *subtractionBtn;
    QPushButton *digitBtn5;
    QPushButton *lnBtn;
    QTextEdit *textEdit;
    QPushButton *divisionBtn;
    QPushButton *addBtn;
    QPushButton *rightBracketBtn;
    QPushButton *digitBtn0;
    QPushButton *multiplicationBtn;
    QPushButton *lgBtn;
    QPushButton *equalBtn;
    QPushButton *digitBtn3;
    QPushButton *digitBtn4;
    QPushButton *percentBtn;
    QPushButton *powBtn;
    QPushButton *genhaoBtn;
    QPushButton *digitBtn6;
    QPushButton *leftBracketBtn;
    QPushButton *digitBtn7;
    QPushButton *levelBtn;
    QPushButton *clearBtn;
    QPushButton *digitBtn9;
    QPushButton *digitBtn2;
    QPushButton *signBtn;
    QPushButton *digitBtn1;
    QPushButton *sinBtn;
    QPushButton *cosBtn;
    QPushButton *clearAllBtn;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *le_2;
    QLabel *label_2;
    QLineEdit *le_8;
    QLabel *label_3;
    QLineEdit *le_10;
    QLabel *label_4;
    QLineEdit *le_16;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QRadioButton *radio_2;
    QRadioButton *radio_8;
    QRadioButton *radio_10;
    QRadioButton *radio_16;
    QLineEdit *le_cin;
    QPushButton *btn_transition;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(626, 536);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        action_3 = new QAction(MainWindow);
        action_3->setObjectName("action_3");
        action_4 = new QAction(MainWindow);
        action_4->setObjectName("action_4");
        action_4->setCheckable(true);
        action_5 = new QAction(MainWindow);
        action_5->setObjectName("action_5");
        action_5->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        digitBtn8 = new QPushButton(centralwidget);
        digitBtn8->setObjectName("digitBtn8");
        digitBtn8->setGeometry(QRect(179, 375, 80, 28));
        pointBtn = new QPushButton(centralwidget);
        pointBtn->setObjectName("pointBtn");
        pointBtn->setGeometry(QRect(93, 409, 80, 28));
        tanBtn = new QPushButton(centralwidget);
        tanBtn->setObjectName("tanBtn");
        tanBtn->setGeometry(QRect(7, 341, 80, 28));
        subtractionBtn = new QPushButton(centralwidget);
        subtractionBtn->setObjectName("subtractionBtn");
        subtractionBtn->setGeometry(QRect(351, 307, 80, 28));
        digitBtn5 = new QPushButton(centralwidget);
        digitBtn5->setObjectName("digitBtn5");
        digitBtn5->setGeometry(QRect(179, 341, 80, 28));
        lnBtn = new QPushButton(centralwidget);
        lnBtn->setObjectName("lnBtn");
        lnBtn->setGeometry(QRect(7, 375, 80, 28));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(7, 11, 441, 222));
        textEdit->setMinimumSize(QSize(200, 0));
        QFont font;
        font.setPointSize(11);
        textEdit->setFont(font);
        divisionBtn = new QPushButton(centralwidget);
        divisionBtn->setObjectName("divisionBtn");
        divisionBtn->setGeometry(QRect(351, 375, 80, 28));
        addBtn = new QPushButton(centralwidget);
        addBtn->setObjectName("addBtn");
        addBtn->setGeometry(QRect(351, 273, 80, 28));
        rightBracketBtn = new QPushButton(centralwidget);
        rightBracketBtn->setObjectName("rightBracketBtn");
        rightBracketBtn->setGeometry(QRect(179, 273, 80, 28));
        digitBtn0 = new QPushButton(centralwidget);
        digitBtn0->setObjectName("digitBtn0");
        digitBtn0->setGeometry(QRect(179, 409, 80, 28));
        multiplicationBtn = new QPushButton(centralwidget);
        multiplicationBtn->setObjectName("multiplicationBtn");
        multiplicationBtn->setGeometry(QRect(351, 341, 80, 28));
        lgBtn = new QPushButton(centralwidget);
        lgBtn->setObjectName("lgBtn");
        lgBtn->setGeometry(QRect(7, 409, 80, 28));
        equalBtn = new QPushButton(centralwidget);
        equalBtn->setObjectName("equalBtn");
        equalBtn->setGeometry(QRect(351, 239, 80, 28));
        digitBtn3 = new QPushButton(centralwidget);
        digitBtn3->setObjectName("digitBtn3");
        digitBtn3->setGeometry(QRect(265, 307, 80, 28));
        digitBtn4 = new QPushButton(centralwidget);
        digitBtn4->setObjectName("digitBtn4");
        digitBtn4->setGeometry(QRect(93, 341, 80, 28));
        percentBtn = new QPushButton(centralwidget);
        percentBtn->setObjectName("percentBtn");
        percentBtn->setGeometry(QRect(7, 239, 80, 28));
        powBtn = new QPushButton(centralwidget);
        powBtn->setObjectName("powBtn");
        powBtn->setGeometry(QRect(265, 239, 80, 28));
        genhaoBtn = new QPushButton(centralwidget);
        genhaoBtn->setObjectName("genhaoBtn");
        genhaoBtn->setGeometry(QRect(351, 409, 80, 28));
        digitBtn6 = new QPushButton(centralwidget);
        digitBtn6->setObjectName("digitBtn6");
        digitBtn6->setGeometry(QRect(265, 341, 80, 28));
        leftBracketBtn = new QPushButton(centralwidget);
        leftBracketBtn->setObjectName("leftBracketBtn");
        leftBracketBtn->setGeometry(QRect(93, 273, 80, 28));
        digitBtn7 = new QPushButton(centralwidget);
        digitBtn7->setObjectName("digitBtn7");
        digitBtn7->setGeometry(QRect(93, 375, 80, 28));
        levelBtn = new QPushButton(centralwidget);
        levelBtn->setObjectName("levelBtn");
        levelBtn->setGeometry(QRect(265, 409, 80, 28));
        clearBtn = new QPushButton(centralwidget);
        clearBtn->setObjectName("clearBtn");
        clearBtn->setGeometry(QRect(93, 239, 80, 28));
        digitBtn9 = new QPushButton(centralwidget);
        digitBtn9->setObjectName("digitBtn9");
        digitBtn9->setGeometry(QRect(265, 375, 80, 28));
        digitBtn2 = new QPushButton(centralwidget);
        digitBtn2->setObjectName("digitBtn2");
        digitBtn2->setGeometry(QRect(179, 307, 80, 28));
        signBtn = new QPushButton(centralwidget);
        signBtn->setObjectName("signBtn");
        signBtn->setGeometry(QRect(265, 273, 80, 28));
        digitBtn1 = new QPushButton(centralwidget);
        digitBtn1->setObjectName("digitBtn1");
        digitBtn1->setGeometry(QRect(93, 307, 80, 28));
        sinBtn = new QPushButton(centralwidget);
        sinBtn->setObjectName("sinBtn");
        sinBtn->setGeometry(QRect(7, 273, 80, 28));
        cosBtn = new QPushButton(centralwidget);
        cosBtn->setObjectName("cosBtn");
        cosBtn->setGeometry(QRect(7, 307, 80, 28));
        clearAllBtn = new QPushButton(centralwidget);
        clearAllBtn->setObjectName("clearAllBtn");
        clearAllBtn->setGeometry(QRect(179, 239, 80, 28));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(460, 240, 141, 181));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName("formLayout");
        formLayout->setVerticalSpacing(14);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        le_2 = new QLineEdit(widget);
        le_2->setObjectName("le_2");

        formLayout->setWidget(0, QFormLayout::FieldRole, le_2);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        le_8 = new QLineEdit(widget);
        le_8->setObjectName("le_8");

        formLayout->setWidget(1, QFormLayout::FieldRole, le_8);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        le_10 = new QLineEdit(widget);
        le_10->setObjectName("le_10");

        formLayout->setWidget(2, QFormLayout::FieldRole, le_10);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        le_16 = new QLineEdit(widget);
        le_16->setObjectName("le_16");

        formLayout->setWidget(3, QFormLayout::FieldRole, le_16);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(490, 10, 111, 192));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radio_2 = new QRadioButton(widget1);
        radio_2->setObjectName("radio_2");
        radio_2->setCheckable(true);
        radio_2->setChecked(false);

        verticalLayout->addWidget(radio_2);

        radio_8 = new QRadioButton(widget1);
        radio_8->setObjectName("radio_8");

        verticalLayout->addWidget(radio_8);

        radio_10 = new QRadioButton(widget1);
        radio_10->setObjectName("radio_10");

        verticalLayout->addWidget(radio_10);

        radio_16 = new QRadioButton(widget1);
        radio_16->setObjectName("radio_16");

        verticalLayout->addWidget(radio_16);

        le_cin = new QLineEdit(widget1);
        le_cin->setObjectName("le_cin");

        verticalLayout->addWidget(le_cin);

        btn_transition = new QPushButton(widget1);
        btn_transition->setObjectName("btn_transition");

        verticalLayout->addWidget(btn_transition);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 626, 24));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addAction(action_3);
        menu->addAction(action_4);
        menu->addAction(action_5);
        menu->addSeparator();
        toolBar->addAction(action);
        toolBar->addAction(action_2);
        toolBar->addAction(action_3);
        toolBar->addAction(action_4);
        toolBar->addAction(action_5);

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
        action_5->setText(QCoreApplication::translate("MainWindow", "\347\250\213\345\272\217\345\221\230", nullptr));
        digitBtn8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pointBtn->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        tanBtn->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        subtractionBtn->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        digitBtn5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        lnBtn->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        divisionBtn->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        addBtn->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        rightBracketBtn->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        digitBtn0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        multiplicationBtn->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        lgBtn->setText(QCoreApplication::translate("MainWindow", "lg", nullptr));
        equalBtn->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        digitBtn3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        digitBtn4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        percentBtn->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        powBtn->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        genhaoBtn->setText(QCoreApplication::translate("MainWindow", "root", nullptr));
        digitBtn6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        leftBracketBtn->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        digitBtn7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        levelBtn->setText(QCoreApplication::translate("MainWindow", "!", nullptr));
        clearBtn->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        digitBtn9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        digitBtn2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        signBtn->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        digitBtn1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        sinBtn->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        cosBtn->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        clearAllBtn->setText(QCoreApplication::translate("MainWindow", "ClearAll", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Bin", nullptr));
        le_2->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Oct", nullptr));
        le_8->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Dec", nullptr));
        le_10->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Hex", nullptr));
        le_16->setText(QString());
        radio_2->setText(QCoreApplication::translate("MainWindow", "Bin", nullptr));
        radio_8->setText(QCoreApplication::translate("MainWindow", "Oct", nullptr));
        radio_10->setText(QCoreApplication::translate("MainWindow", "Dec", nullptr));
        radio_16->setText(QCoreApplication::translate("MainWindow", "Hex", nullptr));
        btn_transition->setText(QCoreApplication::translate("MainWindow", "\350\275\254\346\215\242", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\350\217\234\345\215\225", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
