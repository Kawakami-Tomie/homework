#include "widget.h"
#include "ui_widget.h"

void Widget::paintEvent(QPaintEvent *event)
{
      QPainter painter(this);   // 创建一个本窗口(this) 的画家对象
 //   painter.drawLine(QPoint(0, 0), QPoint(100, 100));
 //     painter.drawPixmap(x,50,80,80,QPixmap("../sheep.jpg"));

      //画圆
//      painter.drawEllipse(QPoint(100,100),50,50);

//      //画矩形
//      painter.drawRect(QRect(20,20,50,50));

//      //画文字
//      painter.drawText(QRect(150,100,400,400),"在矩形框位置中显示文字");

      QPen pen(Qt::red, 5, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);
      painter.setPen(pen);
      QRectF rect(70.0, 40.0, 80.0, 60.0);  //矩形
      int startAngle = 30 * 16;
      int spanAngle = 120 * 16;
      painter.drawArc(rect, startAngle, spanAngle);   //圆弧

      QBrush brush(QColor(0, 0, 255), Qt::Dense4Pattern);
      painter.setBrush(brush);
      painter.drawEllipse(220, 20, 50, 50); // 画圆
      static const QPointF points[4] = {
              QPointF(270.0, 80.0),
              QPointF(290.0, 10.0),
              QPointF(350.0, 30.0),
              QPointF(390.0, 70.0)
      };

}

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
    x+=50;
    if(x>width()) x=10;
    update();
}
