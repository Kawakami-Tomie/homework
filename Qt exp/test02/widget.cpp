#include "widget.h"
#include "ui_widget.h"
#include "QDebug"
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
    ui->sum->setText(QString::number(ui->num1->text().toInt()+ui->num2->text().toInt()));
}
