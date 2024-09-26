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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLineEdit *num1;
    QLineEdit *num2;
    QLineEdit *sum;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(530, 413);
        num1 = new QLineEdit(Widget);
        num1->setObjectName(QStringLiteral("num1"));
        num1->setGeometry(QRect(30, 160, 113, 21));
        num2 = new QLineEdit(Widget);
        num2->setObjectName(QStringLiteral("num2"));
        num2->setGeometry(QRect(180, 160, 113, 21));
        sum = new QLineEdit(Widget);
        sum->setObjectName(QStringLiteral("sum"));
        sum->setGeometry(QRect(400, 160, 113, 21));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 160, 72, 15));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(24);
        label->setFont(font);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(330, 160, 41, 28));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Arabic"));
        font1.setPointSize(18);
        pushButton->setFont(font1);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "test02_ui", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "+", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "=", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
