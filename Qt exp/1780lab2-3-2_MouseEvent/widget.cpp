#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setMouseTracking(true);
}


void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        ui->motionLabel->setText("left button press");
    }
    else
    {
        ui->motionLabel->setText("right button press");
    }
}



void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint pos = event->globalPos();
    ui->posLabel->setText(QString("(%1,%2)").arg(pos.rx()).arg(pos.ry()));
}




void Widget::wheelEvent(QWheelEvent *event)
{
    if (event->delta() > 0)
    {
        ui->motionLabel->setText("wheel up roll");
    }
    else
    {
        ui->motionLabel->setText("wheel down roll");
    }
}

Widget::~Widget()
{
    delete ui;
}
