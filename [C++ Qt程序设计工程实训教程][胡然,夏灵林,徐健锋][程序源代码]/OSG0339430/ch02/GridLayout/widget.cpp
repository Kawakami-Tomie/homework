#include "widget.h"
#include "ui_widget.h"
#include <QGridLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QGridLayout *gLayout = new QGridLayout();
    gLayout->addWidget(ui->nameLabel, 0, 0);
    gLayout->addWidget(ui->nameLineEdit, 0, 1, 1, 2);
    gLayout->addWidget(ui->idLabel, 1, 0);
    gLayout->addWidget(ui->idLineEdit, 1, 1, 1, 2);
    gLayout->addWidget(ui->passwordLabel, 2, 0);
    gLayout->addWidget(ui->passwordLineEdit, 2, 1, 1, 2);
    gLayout->addWidget(ui->rePasswordLabel, 3, 0);
    gLayout->addWidget(ui->rePasswordLineEdit, 3, 1, 1, 2);
    gLayout->addWidget(ui->okBtn, 4, 1);
    gLayout->addWidget(ui->cancelBtn, 4, 2);

    setLayout(gLayout);
}

Widget::~Widget()
{
    delete ui;
}
