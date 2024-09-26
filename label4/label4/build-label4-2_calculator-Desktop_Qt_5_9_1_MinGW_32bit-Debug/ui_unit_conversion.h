/********************************************************************************
** Form generated from reading UI file 'unit_conversion.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNIT_CONVERSION_H
#define UI_UNIT_CONVERSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_unit_conversion
{
public:
    QLineEdit *lineEdit;
    QLabel *bin;
    QLabel *hex;
    QLabel *oct;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *unit_conversion)
    {
        if (unit_conversion->objectName().isEmpty())
            unit_conversion->setObjectName(QStringLiteral("unit_conversion"));
        unit_conversion->resize(400, 300);
        lineEdit = new QLineEdit(unit_conversion);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(160, 50, 108, 22));
        bin = new QLabel(unit_conversion);
        bin->setObjectName(QStringLiteral("bin"));
        bin->setGeometry(QRect(160, 80, 54, 16));
        hex = new QLabel(unit_conversion);
        hex->setObjectName(QStringLiteral("hex"));
        hex->setGeometry(QRect(160, 100, 54, 16));
        oct = new QLabel(unit_conversion);
        oct->setObjectName(QStringLiteral("oct"));
        oct->setGeometry(QRect(160, 120, 54, 16));
        widget = new QWidget(unit_conversion);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 50, 98, 86));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);


        retranslateUi(unit_conversion);

        QMetaObject::connectSlotsByName(unit_conversion);
    } // setupUi

    void retranslateUi(QDialog *unit_conversion)
    {
        unit_conversion->setWindowTitle(QApplication::translate("unit_conversion", "Dialog", Q_NULLPTR));
        bin->setText(QApplication::translate("unit_conversion", "TextLabel", Q_NULLPTR));
        hex->setText(QApplication::translate("unit_conversion", "TextLabel", Q_NULLPTR));
        oct->setText(QApplication::translate("unit_conversion", "TextLabel", Q_NULLPTR));
        label->setText(QApplication::translate("unit_conversion", "\350\257\267\350\276\223\345\205\24510\350\277\233\345\210\266\346\225\260\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("unit_conversion", "\350\275\254\346\215\242\344\270\272\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("unit_conversion", "\344\272\214\350\277\233\345\210\266\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("unit_conversion", "\345\215\201\345\205\255\350\277\233\345\210\266\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("unit_conversion", "\345\205\253\350\277\233\345\210\266\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class unit_conversion: public Ui_unit_conversion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNIT_CONVERSION_H
