/********************************************************************************
** Form generated from reading UI file 'conversion.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERSION_H
#define UI_CONVERSION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_conversion
{
public:
    QAction *action;
    QWidget *Convert;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *dec;
    QLineEdit *bin;
    QLineEdit *hex;
    QLineEdit *oct;
    QVBoxLayout *verticalLayout_3;
    QPushButton *convert10;
    QPushButton *convert2;
    QPushButton *convert16;
    QPushButton *convert8;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *conversion)
    {
        if (conversion->objectName().isEmpty())
            conversion->setObjectName("conversion");
        conversion->resize(329, 165);
        action = new QAction(conversion);
        action->setObjectName("action");
        Convert = new QWidget(conversion);
        Convert->setObjectName("Convert");
        layoutWidget = new QWidget(Convert);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(9, 9, 306, 110));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        dec = new QLineEdit(layoutWidget);
        dec->setObjectName("dec");

        verticalLayout_2->addWidget(dec);

        bin = new QLineEdit(layoutWidget);
        bin->setObjectName("bin");

        verticalLayout_2->addWidget(bin);

        hex = new QLineEdit(layoutWidget);
        hex->setObjectName("hex");

        verticalLayout_2->addWidget(hex);

        oct = new QLineEdit(layoutWidget);
        oct->setObjectName("oct");

        verticalLayout_2->addWidget(oct);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        convert10 = new QPushButton(layoutWidget);
        convert10->setObjectName("convert10");

        verticalLayout_3->addWidget(convert10);

        convert2 = new QPushButton(layoutWidget);
        convert2->setObjectName("convert2");

        verticalLayout_3->addWidget(convert2);

        convert16 = new QPushButton(layoutWidget);
        convert16->setObjectName("convert16");

        verticalLayout_3->addWidget(convert16);

        convert8 = new QPushButton(layoutWidget);
        convert8->setObjectName("convert8");

        verticalLayout_3->addWidget(convert8);


        horizontalLayout_2->addLayout(verticalLayout_3);

        conversion->setCentralWidget(Convert);
        menubar = new QMenuBar(conversion);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 329, 21));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        conversion->setMenuBar(menubar);
        statusbar = new QStatusBar(conversion);
        statusbar->setObjectName("statusbar");
        conversion->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);

        retranslateUi(conversion);

        QMetaObject::connectSlotsByName(conversion);
    } // setupUi

    void retranslateUi(QMainWindow *conversion)
    {
        conversion->setWindowTitle(QCoreApplication::translate("conversion", "convert", nullptr));
        action->setText(QCoreApplication::translate("conversion", "\350\256\241\347\256\227\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("conversion", "\345\215\201\350\277\233\345\210\266\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("conversion", "\344\272\214\350\277\233\345\210\266\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("conversion", "\345\215\201\345\205\255\350\277\233\345\210\266\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("conversion", "\345\205\253\350\277\233\345\210\266\357\274\232", nullptr));
        convert10->setText(QCoreApplication::translate("conversion", "10convert", nullptr));
        convert2->setText(QCoreApplication::translate("conversion", "2convert", nullptr));
        convert16->setText(QCoreApplication::translate("conversion", "16convert", nullptr));
        convert8->setText(QCoreApplication::translate("conversion", "8convert", nullptr));
        menu->setTitle(QCoreApplication::translate("conversion", "\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class conversion: public Ui_conversion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERSION_H
