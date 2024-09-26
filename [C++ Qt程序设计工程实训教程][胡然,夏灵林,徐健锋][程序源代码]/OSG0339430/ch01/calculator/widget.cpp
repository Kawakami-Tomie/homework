#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    int num1 = ui->num1->value();
    int num2 = ui->num2->value();
    ui->sum->setText(QString::number(num1 + num2));
}
