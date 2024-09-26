#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QComboBox>
#include<QPainter>
#include <QDebug>
#include <QImage>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT


public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_caculate_clicked();

    void on_clearHistoryButton_clicked();

private:
    Ui::Widget *ui;
    QPen pen; //存储画笔
    QPoint point1,point2; //存储坐标点
    QColor color;  //存储选择的颜色
    double bmi;

protected:

     void paintEvent(QPaintEvent *event) override {
            QPainter painter(this);
            QPen pen;
            pen.setWidth(8);

            point1 = QPoint(15, 560);
            point2 = QPoint(335, 560);

            if (bmi <= 18.5) {
                pen.setColor(QColor(0, 0, 255)); // 蓝色
            } else if (bmi > 18.5 && bmi <= 24) {
                pen.setColor(QColor(0, 255, 0)); // 绿色
            } else if (bmi > 24 && bmi <= 27) {
                pen.setColor(QColor(255, 255, 0)); // 黄色
            } else if (bmi > 27 && bmi <= 30) {
                pen.setColor(QColor(255, 0, 0)); // 红色
            } else if (bmi > 30) {
                pen.setColor(QColor(255, 0, 255)); // 紫色
            }

            painter.setPen(pen);
            painter.drawLine(point1, point2);
        }
};

#endif // WIDGET_H
