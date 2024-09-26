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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QRadioButton *gentleman;
    QRadioButton *radioButton_2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QSpinBox *age;
    QLabel *label_3;
    QSpinBox *height;
    QLabel *label_4;
    QSpinBox *weight;
    QPushButton *caculate;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLabel *result;
    QLabel *textres;
    QListWidget *listWidget;
    QPushButton *clearHistoryButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(358, 573);
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 130, 21));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        gentleman = new QRadioButton(widget);
        gentleman->setObjectName(QStringLiteral("gentleman"));

        horizontalLayout_2->addWidget(gentleman);

        radioButton_2 = new QRadioButton(widget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout_2->addWidget(radioButton_2);

        widget1 = new QWidget(Widget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(20, 50, 311, 501));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        age = new QSpinBox(widget1);
        age->setObjectName(QStringLiteral("age"));
        age->setMaximum(120);
        age->setValue(19);

        verticalLayout_2->addWidget(age);

        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        height = new QSpinBox(widget1);
        height->setObjectName(QStringLiteral("height"));
        height->setMaximum(300);
        height->setValue(160);

        verticalLayout_2->addWidget(height);

        label_4 = new QLabel(widget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        weight = new QSpinBox(widget1);
        weight->setObjectName(QStringLiteral("weight"));
        weight->setMaximum(200);
        weight->setValue(110);

        verticalLayout_2->addWidget(weight);

        caculate = new QPushButton(widget1);
        caculate->setObjectName(QStringLiteral("caculate"));

        verticalLayout_2->addWidget(caculate);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(widget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setLineWidth(20);

        horizontalLayout->addWidget(label_5);

        result = new QLabel(widget1);
        result->setObjectName(QStringLiteral("result"));

        horizontalLayout->addWidget(result);


        verticalLayout->addLayout(horizontalLayout);

        textres = new QLabel(widget1);
        textres->setObjectName(QStringLiteral("textres"));

        verticalLayout->addWidget(textres);


        verticalLayout_2->addLayout(verticalLayout);

        listWidget = new QListWidget(widget1);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        clearHistoryButton = new QPushButton(widget1);
        clearHistoryButton->setObjectName(QStringLiteral("clearHistoryButton"));

        verticalLayout_2->addWidget(clearHistoryButton);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\346\200\247\345\210\253", Q_NULLPTR));
        gentleman->setText(QApplication::translate("Widget", "\347\224\267", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("Widget", "\345\245\263", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\345\271\264\351\276\204\357\274\210\345\262\201\357\274\211", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "\350\272\253\351\253\230\357\274\210\345\216\230\347\261\263\357\274\211", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "\344\275\223\351\207\215\357\274\210\345\205\254\346\226\244\357\274\211", Q_NULLPTR));
        caculate->setText(QApplication::translate("Widget", "\350\256\241\347\256\227BMI\346\214\207\346\225\260", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "BMI\357\274\232", Q_NULLPTR));
        result->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        textres->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        clearHistoryButton->setText(QApplication::translate("Widget", "\346\270\205\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
