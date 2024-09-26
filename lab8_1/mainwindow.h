#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QInputDialog>
#include<QColorDialog>
#include<QComboBox>
#include<QPainter>
#include <QDebug>
#include <QImage>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_line_triggered();

    void on_color_triggered();

    void on_cuxi_triggered();

    void on_style_triggered();

    void on_circle_triggered();

    void on_rect_triggered();

    void on_bgcolor_triggered();

    void on_clear_triggered();

    void on_shan_triggered();

private:
    Ui::MainWindow *ui;
    QPen pen; //存储画笔
    int x1, y1, x2, y2;
    int R,xr,yr,chang,kuan;
    int x, y, r;
    int x111, y111, x222, y222;
    int X,Y,W,H,A,Alen;    QPoint point1,point2,point3,point4; //存储坐标点
    QColor color,colorb;  //存储选择的颜色
    bool clear;
    int penWidth = 1;
    Qt::PenStyle penStyle = Qt::SolidLine;
    QColor brushColor = Qt::white;//背景颜色


protected:
    void paintEvent(QPaintEvent *event); //重写绘图函数
    void setBackgroundColor(const QString &colorCode);
};

#endif // MAINWINDOW_H
