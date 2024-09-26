/********************************************************************************
** Form generated from reading UI file 'chengxu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHENGXU_H
#define UI_CHENGXU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_chengxu
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

    void setupUi(QDialog *chengxu)
    {
        if (chengxu->objectName().isEmpty())
            chengxu->setObjectName("chengxu");
        chengxu->resize(197, 220);
        radio_8 = new QRadioButton(chengxu);
        radio_8->setObjectName("radio_8");
        radio_8->setGeometry(QRect(90, 7, 86, 21));
        le_10 = new QLineEdit(chengxu);
        le_10->setObjectName("le_10");
        le_10->setGeometry(QRect(90, 148, 86, 23));
        radio_10 = new QRadioButton(chengxu);
        radio_10->setObjectName("radio_10");
        radio_10->setGeometry(QRect(21, 34, 63, 21));
        label_3 = new QLabel(chengxu);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(21, 148, 48, 23));
        le_8 = new QLineEdit(chengxu);
        le_8->setObjectName("le_8");
        le_8->setGeometry(QRect(90, 119, 86, 23));
        le_16 = new QLineEdit(chengxu);
        le_16->setObjectName("le_16");
        le_16->setGeometry(QRect(90, 177, 86, 23));
        label = new QLabel(chengxu);
        label->setObjectName("label");
        label->setGeometry(QRect(21, 90, 48, 23));
        radio_16 = new QRadioButton(chengxu);
        radio_16->setObjectName("radio_16");
        radio_16->setGeometry(QRect(90, 34, 86, 21));
        label_2 = new QLabel(chengxu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(21, 119, 48, 23));
        le_cin = new QLineEdit(chengxu);
        le_cin->setObjectName("le_cin");
        le_cin->setGeometry(QRect(21, 61, 63, 23));
        radio_2 = new QRadioButton(chengxu);
        radio_2->setObjectName("radio_2");
        radio_2->setGeometry(QRect(21, 7, 63, 21));
        radio_2->setCheckable(true);
        radio_2->setChecked(false);
        label_4 = new QLabel(chengxu);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(21, 177, 48, 23));
        btn_transition = new QPushButton(chengxu);
        btn_transition->setObjectName("btn_transition");
        btn_transition->setGeometry(QRect(96, 61, 80, 23));
        le_2 = new QLineEdit(chengxu);
        le_2->setObjectName("le_2");
        le_2->setGeometry(QRect(90, 90, 86, 23));

        retranslateUi(chengxu);

        QMetaObject::connectSlotsByName(chengxu);
    } // setupUi

    void retranslateUi(QDialog *chengxu)
    {
        chengxu->setWindowTitle(QCoreApplication::translate("chengxu", "Dialog", nullptr));
        radio_8->setText(QCoreApplication::translate("chengxu", "8\350\277\233\345\210\266", nullptr));
        radio_10->setText(QCoreApplication::translate("chengxu", "10\350\277\233\345\210\266", nullptr));
        label_3->setText(QCoreApplication::translate("chengxu", "\345\215\201\350\277\233\345\210\266", nullptr));
        label->setText(QCoreApplication::translate("chengxu", "\344\272\214\350\277\233\345\210\266", nullptr));
        radio_16->setText(QCoreApplication::translate("chengxu", "16\350\277\233\345\210\266", nullptr));
        label_2->setText(QCoreApplication::translate("chengxu", "\345\205\253\350\277\233\345\210\266", nullptr));
        radio_2->setText(QCoreApplication::translate("chengxu", "2\350\277\233\345\210\266", nullptr));
        label_4->setText(QCoreApplication::translate("chengxu", "\345\215\201\345\205\255\350\277\233\345\210\266", nullptr));
        btn_transition->setText(QCoreApplication::translate("chengxu", "\350\275\254\346\215\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chengxu: public Ui_chengxu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHENGXU_H
