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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(548, 372);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 60, 454, 225));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(16);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 3);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(12);
        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_2->addWidget(pushButton_4, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout_2->addWidget(pushButton_5, 0, 1, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout_2->addWidget(pushButton_6, 0, 2, 1, 1);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout_2->addWidget(pushButton_7, 0, 3, 1, 1);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout_2->addWidget(pushButton_8, 1, 0, 1, 1);

        pushButton_9 = new QPushButton(layoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout_2->addWidget(pushButton_9, 1, 1, 1, 1);

        pushButton_10 = new QPushButton(layoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        gridLayout_2->addWidget(pushButton_10, 1, 2, 1, 1);

        pushButton_11 = new QPushButton(layoutWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        gridLayout_2->addWidget(pushButton_11, 1, 3, 1, 1);

        pushButton_12 = new QPushButton(layoutWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        gridLayout_2->addWidget(pushButton_12, 2, 0, 1, 1);

        pushButton_13 = new QPushButton(layoutWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        gridLayout_2->addWidget(pushButton_13, 2, 1, 1, 1);

        pushButton_14 = new QPushButton(layoutWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));

        gridLayout_2->addWidget(pushButton_14, 2, 2, 1, 1);

        pushButton_15 = new QPushButton(layoutWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));

        gridLayout_2->addWidget(pushButton_15, 2, 3, 1, 1);

        pushButton_16 = new QPushButton(layoutWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));

        gridLayout_2->addWidget(pushButton_16, 3, 0, 1, 1);

        pushButton_17 = new QPushButton(layoutWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));

        gridLayout_2->addWidget(pushButton_17, 3, 1, 1, 1);

        pushButton_18 = new QPushButton(layoutWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));

        gridLayout_2->addWidget(pushButton_18, 3, 2, 1, 1);

        pushButton_19 = new QPushButton(layoutWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));

        gridLayout_2->addWidget(pushButton_19, 3, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "Clear", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "ClearAll", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Widget", "=", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Widget", "1", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Widget", "2", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Widget", "3", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Widget", "+", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("Widget", "4", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("Widget", "5", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("Widget", "6", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("Widget", "-", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("Widget", "7", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("Widget", "8", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("Widget", "9", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("Widget", "*", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("Widget", ".", Q_NULLPTR));
        pushButton_17->setText(QApplication::translate("Widget", "0", Q_NULLPTR));
        pushButton_18->setText(QApplication::translate("Widget", "+/-", Q_NULLPTR));
        pushButton_19->setText(QApplication::translate("Widget", "/", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
