/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *clearBtn;
    QPushButton *clearAllBtn;
    QPushButton *equalBtn;
    QPushButton *digitBtn1;
    QPushButton *digitBtn2;
    QPushButton *digitBtn3;
    QPushButton *addBtn;
    QPushButton *digitBtn4;
    QPushButton *digitBtn5;
    QPushButton *digitBtn6;
    QPushButton *subtractionBtn;
    QPushButton *digitBtn7;
    QPushButton *digitBtn8;
    QPushButton *digitBtn9;
    QPushButton *multiplicationBnt;
    QPushButton *pointBtn;
    QPushButton *digitBtn0;
    QPushButton *signBtn;
    QPushButton *divisionBtn;
    QPushButton *levelBtn;
    QPushButton *tenPowerBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 4);

        clearBtn = new QPushButton(Widget);
        clearBtn->setObjectName(QStringLiteral("clearBtn"));

        gridLayout->addWidget(clearBtn, 1, 0, 1, 1);

        clearAllBtn = new QPushButton(Widget);
        clearAllBtn->setObjectName(QStringLiteral("clearAllBtn"));

        gridLayout->addWidget(clearAllBtn, 1, 1, 1, 1);

        equalBtn = new QPushButton(Widget);
        equalBtn->setObjectName(QStringLiteral("equalBtn"));

        gridLayout->addWidget(equalBtn, 1, 2, 1, 2);

        digitBtn1 = new QPushButton(Widget);
        digitBtn1->setObjectName(QStringLiteral("digitBtn1"));

        gridLayout->addWidget(digitBtn1, 2, 0, 1, 1);

        digitBtn2 = new QPushButton(Widget);
        digitBtn2->setObjectName(QStringLiteral("digitBtn2"));

        gridLayout->addWidget(digitBtn2, 2, 1, 1, 1);

        digitBtn3 = new QPushButton(Widget);
        digitBtn3->setObjectName(QStringLiteral("digitBtn3"));

        gridLayout->addWidget(digitBtn3, 2, 2, 1, 1);

        addBtn = new QPushButton(Widget);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        gridLayout->addWidget(addBtn, 2, 3, 1, 1);

        digitBtn4 = new QPushButton(Widget);
        digitBtn4->setObjectName(QStringLiteral("digitBtn4"));

        gridLayout->addWidget(digitBtn4, 3, 0, 1, 1);

        digitBtn5 = new QPushButton(Widget);
        digitBtn5->setObjectName(QStringLiteral("digitBtn5"));

        gridLayout->addWidget(digitBtn5, 3, 1, 1, 1);

        digitBtn6 = new QPushButton(Widget);
        digitBtn6->setObjectName(QStringLiteral("digitBtn6"));

        gridLayout->addWidget(digitBtn6, 3, 2, 1, 1);

        subtractionBtn = new QPushButton(Widget);
        subtractionBtn->setObjectName(QStringLiteral("subtractionBtn"));

        gridLayout->addWidget(subtractionBtn, 3, 3, 1, 1);

        digitBtn7 = new QPushButton(Widget);
        digitBtn7->setObjectName(QStringLiteral("digitBtn7"));

        gridLayout->addWidget(digitBtn7, 4, 0, 1, 1);

        digitBtn8 = new QPushButton(Widget);
        digitBtn8->setObjectName(QStringLiteral("digitBtn8"));

        gridLayout->addWidget(digitBtn8, 4, 1, 1, 1);

        digitBtn9 = new QPushButton(Widget);
        digitBtn9->setObjectName(QStringLiteral("digitBtn9"));

        gridLayout->addWidget(digitBtn9, 4, 2, 1, 1);

        multiplicationBnt = new QPushButton(Widget);
        multiplicationBnt->setObjectName(QStringLiteral("multiplicationBnt"));

        gridLayout->addWidget(multiplicationBnt, 4, 3, 1, 1);

        pointBtn = new QPushButton(Widget);
        pointBtn->setObjectName(QStringLiteral("pointBtn"));

        gridLayout->addWidget(pointBtn, 5, 0, 1, 1);

        digitBtn0 = new QPushButton(Widget);
        digitBtn0->setObjectName(QStringLiteral("digitBtn0"));

        gridLayout->addWidget(digitBtn0, 5, 1, 1, 1);

        signBtn = new QPushButton(Widget);
        signBtn->setObjectName(QStringLiteral("signBtn"));

        gridLayout->addWidget(signBtn, 5, 2, 1, 1);

        divisionBtn = new QPushButton(Widget);
        divisionBtn->setObjectName(QStringLiteral("divisionBtn"));

        gridLayout->addWidget(divisionBtn, 5, 3, 1, 1);

        levelBtn = new QPushButton(Widget);
        levelBtn->setObjectName(QStringLiteral("levelBtn"));

        gridLayout->addWidget(levelBtn, 6, 0, 1, 2);

        tenPowerBtn = new QPushButton(Widget);
        tenPowerBtn->setObjectName(QStringLiteral("tenPowerBtn"));

        gridLayout->addWidget(tenPowerBtn, 6, 2, 1, 2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        clearBtn->setText(QApplication::translate("Widget", "Clear", Q_NULLPTR));
        clearAllBtn->setText(QApplication::translate("Widget", "ClearAll", Q_NULLPTR));
        equalBtn->setText(QApplication::translate("Widget", "=", Q_NULLPTR));
        digitBtn1->setText(QApplication::translate("Widget", "1", Q_NULLPTR));
        digitBtn2->setText(QApplication::translate("Widget", "2", Q_NULLPTR));
        digitBtn3->setText(QApplication::translate("Widget", "3", Q_NULLPTR));
        addBtn->setText(QApplication::translate("Widget", "+", Q_NULLPTR));
        digitBtn4->setText(QApplication::translate("Widget", "4", Q_NULLPTR));
        digitBtn5->setText(QApplication::translate("Widget", "5", Q_NULLPTR));
        digitBtn6->setText(QApplication::translate("Widget", "6", Q_NULLPTR));
        subtractionBtn->setText(QApplication::translate("Widget", "-", Q_NULLPTR));
        digitBtn7->setText(QApplication::translate("Widget", "7", Q_NULLPTR));
        digitBtn8->setText(QApplication::translate("Widget", "8", Q_NULLPTR));
        digitBtn9->setText(QApplication::translate("Widget", "9", Q_NULLPTR));
        multiplicationBnt->setText(QApplication::translate("Widget", "*", Q_NULLPTR));
        pointBtn->setText(QApplication::translate("Widget", ".", Q_NULLPTR));
        digitBtn0->setText(QApplication::translate("Widget", "0", Q_NULLPTR));
        signBtn->setText(QApplication::translate("Widget", "+/-", Q_NULLPTR));
        divisionBtn->setText(QApplication::translate("Widget", "/", Q_NULLPTR));
        levelBtn->setText(QApplication::translate("Widget", "!", Q_NULLPTR));
        tenPowerBtn->setText(QApplication::translate("Widget", "^10", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
