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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *step;
    QListWidget *listWidget;
    QLineEdit *lineEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *begin;
    QPushButton *record;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(382, 396);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 241, 16));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 360, 72, 15));
        step = new QLabel(Widget);
        step->setObjectName(QStringLiteral("step"));
        step->setGeometry(QRect(330, 360, 72, 15));
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 180, 341, 171));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 40, 331, 81));
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 140, 341, 30));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        begin = new QPushButton(widget);
        begin->setObjectName(QStringLiteral("begin"));

        horizontalLayout->addWidget(begin);

        record = new QPushButton(widget);
        record->setObjectName(QStringLiteral("record"));

        horizontalLayout->addWidget(record);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "2022111780 \347\216\213\344\271\231\346\226\257 \347\224\265\345\255\2201\347\217\255", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\350\256\260\345\275\225\344\270\252\346\225\260\357\274\232", Q_NULLPTR));
        step->setText(QApplication::translate("Widget", "0", Q_NULLPTR));
        begin->setText(QApplication::translate("Widget", "\345\274\200\345\247\213", Q_NULLPTR));
        record->setText(QApplication::translate("Widget", "\350\256\260\345\275\225", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Widget", "\345\201\234\346\255\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
