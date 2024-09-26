/********************************************************************************
** Form generated from reading UI file 'chrngxu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHRNGXU_H
#define UI_CHRNGXU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QRadioButton *radio_8;
    QLineEdit *le_10;
    QRadioButton *radio_10;
    QLabel *label_3;
    QLineEdit *le_8;
    QLineEdit *le_16;
    QLabel *label;
    QRadioButton *radio_16;
    QLabel *label_2;
    QLineEdit *le_cin;
    QRadioButton *radio_2;
    QLabel *label_4;
    QPushButton *btn_transition;
    QLineEdit *le_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(197, 221);
        radio_8 = new QRadioButton(Dialog);
        radio_8->setObjectName("radio_8");
        radio_8->setGeometry(QRect(90, 7, 86, 21));
        le_10 = new QLineEdit(Dialog);
        le_10->setObjectName("le_10");
        le_10->setGeometry(QRect(90, 148, 86, 23));
        radio_10 = new QRadioButton(Dialog);
        radio_10->setObjectName("radio_10");
        radio_10->setGeometry(QRect(21, 34, 63, 21));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(21, 148, 48, 23));
        le_8 = new QLineEdit(Dialog);
        le_8->setObjectName("le_8");
        le_8->setGeometry(QRect(90, 119, 86, 23));
        le_16 = new QLineEdit(Dialog);
        le_16->setObjectName("le_16");
        le_16->setGeometry(QRect(90, 177, 86, 23));
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(21, 90, 48, 23));
        radio_16 = new QRadioButton(Dialog);
        radio_16->setObjectName("radio_16");
        radio_16->setGeometry(QRect(90, 34, 86, 21));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(21, 119, 48, 23));
        le_cin = new QLineEdit(Dialog);
        le_cin->setObjectName("le_cin");
        le_cin->setGeometry(QRect(21, 61, 63, 23));
        radio_2 = new QRadioButton(Dialog);
        radio_2->setObjectName("radio_2");
        radio_2->setGeometry(QRect(21, 7, 63, 21));
        radio_2->setCheckable(true);
        radio_2->setChecked(false);
        label_4 = new QLabel(Dialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(21, 177, 48, 23));
        btn_transition = new QPushButton(Dialog);
        btn_transition->setObjectName("btn_transition");
        btn_transition->setGeometry(QRect(96, 61, 80, 23));
        le_2 = new QLineEdit(Dialog);
        le_2->setObjectName("le_2");
        le_2->setGeometry(QRect(90, 90, 86, 23));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        radio_8->setText(QCoreApplication::translate("Dialog", "8\350\277\233\345\210\266", nullptr));
        radio_10->setText(QCoreApplication::translate("Dialog", "10\350\277\233\345\210\266", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "\345\215\201\350\277\233\345\210\266", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\344\272\214\350\277\233\345\210\266", nullptr));
        radio_16->setText(QCoreApplication::translate("Dialog", "16\350\277\233\345\210\266", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "\345\205\253\350\277\233\345\210\266", nullptr));
        radio_2->setText(QCoreApplication::translate("Dialog", "2\350\277\233\345\210\266", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "\345\215\201\345\205\255\350\277\233\345\210\266", nullptr));
        btn_transition->setText(QCoreApplication::translate("Dialog", "\350\275\254\346\215\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHRNGXU_H
