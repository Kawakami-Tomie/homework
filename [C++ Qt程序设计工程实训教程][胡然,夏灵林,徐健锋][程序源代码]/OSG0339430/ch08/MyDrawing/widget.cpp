#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

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

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawLine(QPoint(0, 0), QPoint(100, 100));

    QPen pen(Qt::green, 5, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);
    QRectF rect(70.0, 40.0, 80.0, 60.0);
    int startAngle = 30 * 16;
    int spanAngle = 120 * 16;
    painter.drawArc(rect, startAngle, spanAngle);

    pen.setWidth(1);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    painter.drawRect(160, 20, 50, 40);
    QBrush brush(QColor(0, 0, 255), Qt::Dense4Pattern);
    painter.setBrush(brush);
    painter.drawEllipse(220, 20, 50, 50);

    static const QPointF points[4] = {
        QPointF(270.0, 80.0),
        QPointF(290.0, 10.0),
        QPointF(350.0, 30.0),
        QPointF(390.0, 70.0)
    };
    painter.drawPolygon(points, 4);

    painter.fillRect(QRect(10, 100, 150, 20), QBrush(Qt::darkYellow));
    painter.eraseRect(QRect(50, 0, 50, 120));
}
