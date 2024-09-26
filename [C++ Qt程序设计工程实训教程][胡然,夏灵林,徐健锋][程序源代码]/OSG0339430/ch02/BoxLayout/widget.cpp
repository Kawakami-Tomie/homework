#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(ui->button7, 0, Qt::AlignTop);
    hLayout->addWidget(ui->button8);
    hLayout->addWidget(ui->button9, 0, Qt::AlignBottom);

    ui->widget3->setLayout(hLayout);
}

Widget::~Widget()
{
    delete ui;
}
