#include "widget.h"
#include "ui_widget.h"
#include <QFormLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QFormLayout *fLayout = new QFormLayout();
    fLayout->addRow(ui->nameLabel, ui->nameLineEdit);
    fLayout->addRow(ui->ageLabel, ui->ageSpinBox);
    fLayout->addRow(ui->adressLabel, ui->adressLineEdit);
    fLayout->addRow(ui->tasteLabel, ui->tasteLineEdit);

    setLayout(fLayout);
}

Widget::~Widget()
{
    delete ui;
}
