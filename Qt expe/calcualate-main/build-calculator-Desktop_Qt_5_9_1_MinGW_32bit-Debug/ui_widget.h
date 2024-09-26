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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_4;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *le_show;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QTextEdit *text_history;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QPushButton *btn_0;
    QPushButton *btn_2;
    QPushButton *btn_right;
    QPushButton *btn_clear;
    QPushButton *btn_multiply;
    QPushButton *btn_6;
    QPushButton *btn_5;
    QPushButton *btn_8;
    QPushButton *btn_4;
    QPushButton *btn_9;
    QPushButton *btn_left;
    QPushButton *btn_7;
    QPushButton *btn_1;
    QPushButton *btn_back;
    QPushButton *btn_sub;
    QPushButton *btn_point;
    QPushButton *btn_divide;
    QPushButton *btn_3;
    QPushButton *btn_add;
    QPushButton *btn_equal;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1027, 542);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/calcualate.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        Widget->setStyleSheet(QLatin1String("QPushButton{background-color: rgb(240, 240, 240)}\n"
"QPushButton:hover{background-color: rgb(230, 230, 230)}\n"
"QPushButton:pressed{background-color: rgb(200, 200, 200)}"));
        gridLayout_4 = new QGridLayout(Widget);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 100));
        widget->setMaximumSize(QSize(16777215, 100));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        le_show = new QLineEdit(widget);
        le_show->setObjectName(QStringLiteral("le_show"));
        le_show->setMinimumSize(QSize(0, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\247\232\344\275\223"));
        font.setPointSize(35);
        le_show->setFont(font);
        le_show->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        le_show->setReadOnly(true);

        gridLayout->addWidget(le_show, 0, 0, 1, 1);


        gridLayout_4->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(Widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMaximumSize(QSize(300, 16777215));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        text_history = new QTextEdit(widget_2);
        text_history->setObjectName(QStringLiteral("text_history"));
        text_history->setMinimumSize(QSize(0, 0));
        text_history->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\247\232\344\275\223"));
        font1.setPointSize(16);
        text_history->setFont(font1);
        text_history->setReadOnly(true);

        gridLayout_3->addWidget(text_history, 1, 0, 1, 1);

        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setStyleSheet(QStringLiteral("background-color: rgb(218, 218, 218);"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);


        gridLayout_4->addWidget(widget_2, 0, 1, 2, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btn_0 = new QPushButton(Widget);
        btn_0->setObjectName(QStringLiteral("btn_0"));
        btn_0->setMinimumSize(QSize(0, 80));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(26);
        btn_0->setFont(font3);

        gridLayout_2->addWidget(btn_0, 4, 0, 1, 1);

        btn_2 = new QPushButton(Widget);
        btn_2->setObjectName(QStringLiteral("btn_2"));
        btn_2->setMinimumSize(QSize(0, 80));
        btn_2->setFont(font3);

        gridLayout_2->addWidget(btn_2, 3, 1, 1, 1);

        btn_right = new QPushButton(Widget);
        btn_right->setObjectName(QStringLiteral("btn_right"));
        btn_right->setMinimumSize(QSize(0, 80));
        btn_right->setFont(font3);

        gridLayout_2->addWidget(btn_right, 0, 1, 1, 1);

        btn_clear = new QPushButton(Widget);
        btn_clear->setObjectName(QStringLiteral("btn_clear"));
        btn_clear->setMinimumSize(QSize(93, 80));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(17);
        btn_clear->setFont(font4);

        gridLayout_2->addWidget(btn_clear, 0, 2, 1, 1);

        btn_multiply = new QPushButton(Widget);
        btn_multiply->setObjectName(QStringLiteral("btn_multiply"));
        btn_multiply->setMinimumSize(QSize(0, 80));
        btn_multiply->setFont(font3);

        gridLayout_2->addWidget(btn_multiply, 2, 3, 1, 1);

        btn_6 = new QPushButton(Widget);
        btn_6->setObjectName(QStringLiteral("btn_6"));
        btn_6->setMinimumSize(QSize(0, 80));
        btn_6->setFont(font3);

        gridLayout_2->addWidget(btn_6, 2, 2, 1, 1);

        btn_5 = new QPushButton(Widget);
        btn_5->setObjectName(QStringLiteral("btn_5"));
        btn_5->setMinimumSize(QSize(0, 80));
        btn_5->setFont(font3);

        gridLayout_2->addWidget(btn_5, 2, 1, 1, 1);

        btn_8 = new QPushButton(Widget);
        btn_8->setObjectName(QStringLiteral("btn_8"));
        btn_8->setMinimumSize(QSize(0, 80));
        btn_8->setFont(font3);

        gridLayout_2->addWidget(btn_8, 1, 1, 1, 1);

        btn_4 = new QPushButton(Widget);
        btn_4->setObjectName(QStringLiteral("btn_4"));
        btn_4->setMinimumSize(QSize(0, 80));
        btn_4->setFont(font3);

        gridLayout_2->addWidget(btn_4, 2, 0, 1, 1);

        btn_9 = new QPushButton(Widget);
        btn_9->setObjectName(QStringLiteral("btn_9"));
        btn_9->setMinimumSize(QSize(0, 80));
        btn_9->setFont(font3);

        gridLayout_2->addWidget(btn_9, 1, 2, 1, 1);

        btn_left = new QPushButton(Widget);
        btn_left->setObjectName(QStringLiteral("btn_left"));
        btn_left->setMinimumSize(QSize(0, 80));
        btn_left->setFont(font3);

        gridLayout_2->addWidget(btn_left, 0, 0, 1, 1);

        btn_7 = new QPushButton(Widget);
        btn_7->setObjectName(QStringLiteral("btn_7"));
        btn_7->setMinimumSize(QSize(0, 80));
        btn_7->setFont(font3);

        gridLayout_2->addWidget(btn_7, 1, 0, 1, 1);

        btn_1 = new QPushButton(Widget);
        btn_1->setObjectName(QStringLiteral("btn_1"));
        btn_1->setMinimumSize(QSize(0, 80));
        btn_1->setFont(font3);

        gridLayout_2->addWidget(btn_1, 3, 0, 1, 1);

        btn_back = new QPushButton(Widget);
        btn_back->setObjectName(QStringLiteral("btn_back"));
        btn_back->setMinimumSize(QSize(93, 80));
        btn_back->setFont(font4);

        gridLayout_2->addWidget(btn_back, 0, 3, 1, 1);

        btn_sub = new QPushButton(Widget);
        btn_sub->setObjectName(QStringLiteral("btn_sub"));
        btn_sub->setMinimumSize(QSize(0, 80));
        btn_sub->setFont(font3);

        gridLayout_2->addWidget(btn_sub, 3, 3, 1, 1);

        btn_point = new QPushButton(Widget);
        btn_point->setObjectName(QStringLiteral("btn_point"));
        btn_point->setMinimumSize(QSize(0, 80));
        btn_point->setFont(font3);

        gridLayout_2->addWidget(btn_point, 4, 1, 1, 1);

        btn_divide = new QPushButton(Widget);
        btn_divide->setObjectName(QStringLiteral("btn_divide"));
        btn_divide->setMinimumSize(QSize(0, 80));
        btn_divide->setFont(font3);

        gridLayout_2->addWidget(btn_divide, 1, 3, 1, 1);

        btn_3 = new QPushButton(Widget);
        btn_3->setObjectName(QStringLiteral("btn_3"));
        btn_3->setMinimumSize(QSize(0, 80));
        btn_3->setFont(font3);

        gridLayout_2->addWidget(btn_3, 3, 2, 1, 1);

        btn_add = new QPushButton(Widget);
        btn_add->setObjectName(QStringLiteral("btn_add"));
        btn_add->setMinimumSize(QSize(0, 80));
        btn_add->setFont(font3);

        gridLayout_2->addWidget(btn_add, 4, 2, 1, 1);

        btn_equal = new QPushButton(Widget);
        btn_equal->setObjectName(QStringLiteral("btn_equal"));
        btn_equal->setMinimumSize(QSize(0, 80));
        btn_equal->setFont(font3);

        gridLayout_2->addWidget(btn_equal, 4, 3, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 1, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        le_show->setText(QString());
        label->setText(QApplication::translate("Widget", "\345\216\206\345\217\262\350\256\260\345\275\225", Q_NULLPTR));
        btn_0->setText(QApplication::translate("Widget", "0", Q_NULLPTR));
        btn_2->setText(QApplication::translate("Widget", "2", Q_NULLPTR));
        btn_right->setText(QApplication::translate("Widget", "\357\274\211", Q_NULLPTR));
        btn_clear->setText(QApplication::translate("Widget", "\346\270\205\347\251\272", Q_NULLPTR));
        btn_multiply->setText(QApplication::translate("Widget", "*", Q_NULLPTR));
        btn_6->setText(QApplication::translate("Widget", "6", Q_NULLPTR));
        btn_5->setText(QApplication::translate("Widget", "5", Q_NULLPTR));
        btn_8->setText(QApplication::translate("Widget", "8", Q_NULLPTR));
        btn_4->setText(QApplication::translate("Widget", "4", Q_NULLPTR));
        btn_9->setText(QApplication::translate("Widget", "9", Q_NULLPTR));
        btn_left->setText(QApplication::translate("Widget", "\357\274\210", Q_NULLPTR));
        btn_7->setText(QApplication::translate("Widget", "7", Q_NULLPTR));
        btn_1->setText(QApplication::translate("Widget", "1", Q_NULLPTR));
        btn_back->setText(QApplication::translate("Widget", "\351\200\200\346\240\274", Q_NULLPTR));
        btn_sub->setText(QApplication::translate("Widget", "-", Q_NULLPTR));
        btn_point->setText(QApplication::translate("Widget", ".", Q_NULLPTR));
        btn_divide->setText(QApplication::translate("Widget", "/", Q_NULLPTR));
        btn_3->setText(QApplication::translate("Widget", "3", Q_NULLPTR));
        btn_add->setText(QApplication::translate("Widget", "+", Q_NULLPTR));
        btn_equal->setText(QApplication::translate("Widget", "=", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
