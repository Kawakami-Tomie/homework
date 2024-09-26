#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}


void Widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up)
    {
        ui->label->move(ui->label->pos() + QPoint(0, -20));
    }
    else if (event->key() == Qt::Key_Down)
    {
        ui->label->move(ui->label->pos() + QPoint(0, 20));
    }
    else if (event->key() == Qt::Key_Left)
    {
        ui->label->move(ui->label->pos() + QPoint(-20, 0));
    }
    else if (event->key() == Qt::Key_Right)
    {
        ui->label->move(ui->label->pos() + QPoint(20, 0));
    }
}
void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up)
    {
        ui->label->move(ui->label->pos() + QPoint(0, 20));
    }
    else if (event->key() == Qt::Key_Down)
    {
        ui->label->move(ui->label->pos() + QPoint(0, -20));
    }
    else if (event->key() == Qt::Key_Left)
    {
        ui->label->move(ui->label->pos() + QPoint(20, 0));
    }
    else if (event->key() == Qt::Key_Right)
    {
        ui->label->move(ui->label->pos() + QPoint(-20, 0));
    }
}



Widget::~Widget()
{
    delete ui;
}
