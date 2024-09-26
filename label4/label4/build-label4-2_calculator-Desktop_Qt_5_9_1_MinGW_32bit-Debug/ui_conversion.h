/********************************************************************************
** Form generated from reading UI file 'conversion.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERSION_H
#define UI_CONVERSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            conversion->setObjectName(QStringLiteral("conversion"));
        conversion->resize(329, 165);
        action = new QAction(conversion);
        action->setObjectName(QStringLiteral("action"));
        Convert = new QWidget(conversion);
        Convert->setObjectName(QStringLiteral("Convert"));
        layoutWidget = new QWidget(Convert);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 306, 110));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        dec = new QLineEdit(layoutWidget);
        dec->setObjectName(QStringLiteral("dec"));

        verticalLayout_2->addWidget(dec);

        bin = new QLineEdit(layoutWidget);
        bin->setObjectName(QStringLiteral("bin"));

        verticalLayout_2->addWidget(bin);

        hex = new QLineEdit(layoutWidget);
        hex->setObjectName(QStringLiteral("hex"));

        verticalLayout_2->addWidget(hex);

        oct = new QLineEdit(layoutWidget);
        oct->setObjectName(QStringLiteral("oct"));

        verticalLayout_2->addWidget(oct);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        convert10 = new QPushButton(layoutWidget);
        convert10->setObjectName(QStringLiteral("convert10"));

        verticalLayout_3->addWidget(convert10);

        convert2 = new QPushButton(layoutWidget);
        convert2->setObjectName(QStringLiteral("convert2"));

        verticalLayout_3->addWidget(convert2);

        convert16 = new QPushButton(layoutWidget);
        convert16->setObjectName(QStringLiteral("convert16"));

        verticalLayout_3->addWidget(convert16);

        convert8 = new QPushButton(layoutWidget);
        convert8->setObjectName(QStringLiteral("convert8"));

        verticalLayout_3->addWidget(convert8);


        horizontalLayout_2->addLayout(verticalLayout_3);

        conversion->setCentralWidget(Convert);
        menubar = new QMenuBar(conversion);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 329, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        conversion->setMenuBar(menubar);
        statusbar = new QStatusBar(conversion);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        conversion->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);

        retranslateUi(conversion);

        QMetaObject::connectSlotsByName(conversion);
    } // setupUi

    void retranslateUi(QMainWindow *conversion)
    {
        conversion->setWindowTitle(QApplication::translate("conversion", "convert", Q_NULLPTR));
        action->setText(QApplication::translate("conversion", "\350\256\241\347\256\227\345\231\250", Q_NULLPTR));
        label->setText(QApplication::translate("conversion", "\345\215\201\350\277\233\345\210\266\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("conversion", "\344\272\214\350\277\233\345\210\266\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("conversion", "\345\215\201\345\205\255\350\277\233\345\210\266\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("conversion", "\345\205\253\350\277\233\345\210\266\357\274\232", Q_NULLPTR));
        convert10->setText(QApplication::translate("conversion", "10convert", Q_NULLPTR));
        convert2->setText(QApplication::translate("conversion", "2convert", Q_NULLPTR));
        convert16->setText(QApplication::translate("conversion", "16convert", Q_NULLPTR));
        convert8->setText(QApplication::translate("conversion", "8convert", Q_NULLPTR));
        menu->setTitle(QApplication::translate("conversion", "\350\217\234\345\215\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class conversion: public Ui_conversion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERSION_H
