#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    qDebug() << "before call setupUi" << endl;
    ui->setupUi(this);
    qDebug() << "after call setupUI" << endl;
}

Widget::~Widget()
{
    qDebug() << "destory the widget";
    delete ui;
}
