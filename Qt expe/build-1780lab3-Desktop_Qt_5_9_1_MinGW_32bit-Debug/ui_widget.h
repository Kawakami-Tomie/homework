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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *le_show;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_back;
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
    QPushButton *pushButton_19;
    QPushButton *btn_divide;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(479, 362);
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 40, 429, 271));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        le_show = new QLineEdit(widget);
        le_show->setObjectName(QStringLiteral("le_show"));

        verticalLayout_2->addWidget(le_show);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(25);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_back = new QPushButton(widget);
        btn_back->setObjectName(QStringLiteral("btn_back"));

        horizontalLayout->addWidget(btn_back);

        btn_clear = new QPushButton(widget);
        btn_clear->setObjectName(QStringLiteral("btn_clear"));

        horizontalLayout->addWidget(btn_clear);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(17);
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

        pushButton_19 = new QPushButton(widget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));

        gridLayout->addWidget(pushButton_19, 4, 2, 1, 1);

        btn_divide = new QPushButton(widget);
        btn_divide->setObjectName(QStringLiteral("btn_divide"));

        gridLayout->addWidget(btn_divide, 4, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(verticalLayout);

        btn_left->raise();
        btn_right->raise();
        btn_mul->raise();
        btn_equal->raise();
        btn_1->raise();
        btn_2->raise();
        btn_3->raise();
        btn_add->raise();
        btn_4->raise();
        btn_5->raise();
        btn_6->raise();
        btn_sub->raise();
        btn_7->raise();
        btn_8->raise();
        btn_9->raise();
        btn_multiply->raise();
        btn_point->raise();
        btn_0->raise();
        pushButton_19->raise();
        btn_divide->raise();
        btn_back->raise();
        btn_clear->raise();
        le_show->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        btn_back->setText(QApplication::translate("Widget", "Clear", Q_NULLPTR));
        btn_clear->setText(QApplication::translate("Widget", "Clear All", Q_NULLPTR));
        btn_left->setText(QApplication::translate("Widget", "(", Q_NULLPTR));
        btn_right->setText(QApplication::translate("Widget", ")", Q_NULLPTR));
        btn_mul->setText(QApplication::translate("Widget", "^", Q_NULLPTR));
        btn_equal->setText(QApplication::translate("Widget", "=", Q_NULLPTR));
        btn_1->setText(QApplication::translate("Widget", "1", Q_NULLPTR));
        btn_2->setText(QApplication::translate("Widget", "2", Q_NULLPTR));
        btn_3->setText(QApplication::translate("Widget", "3", Q_NULLPTR));
        btn_add->setText(QApplication::translate("Widget", "+", Q_NULLPTR));
        btn_4->setText(QApplication::translate("Widget", "4", Q_NULLPTR));
        btn_5->setText(QApplication::translate("Widget", "5", Q_NULLPTR));
        btn_6->setText(QApplication::translate("Widget", "6", Q_NULLPTR));
        btn_sub->setText(QApplication::translate("Widget", "-", Q_NULLPTR));
        btn_7->setText(QApplication::translate("Widget", "7", Q_NULLPTR));
        btn_8->setText(QApplication::translate("Widget", "8", Q_NULLPTR));
        btn_9->setText(QApplication::translate("Widget", "9", Q_NULLPTR));
        btn_multiply->setText(QApplication::translate("Widget", "*", Q_NULLPTR));
        btn_point->setText(QApplication::translate("Widget", ".", Q_NULLPTR));
        btn_0->setText(QApplication::translate("Widget", "0", Q_NULLPTR));
        pushButton_19->setText(QApplication::translate("Widget", "+/_", Q_NULLPTR));
        btn_divide->setText(QApplication::translate("Widget", "/", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
