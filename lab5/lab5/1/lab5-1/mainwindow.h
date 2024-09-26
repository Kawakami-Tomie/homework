#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include<QPixmap>
#include <QMouseEvent>
#include <QVector>
#include <QTextEdit>
#include <QPen>
#include <QBrush>

namespace Ui {
class MainWindow;
}
class DrawArea;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QVector<QVector<QPoint> > _lines;//线条集合(一条线条可包含多个线段)
    QVector<QRect> _rects;//矩形集合
    QVector<QRect> _ellipse;//椭圆集合
    QVector<QRect> _circle;//圆集合
    QVector<QRect>  _line;//直线集合
    QVector<QString>  _text;//文字集合
    QVector<QPoint>  _tpoint;//文字位置集合
    QVector<int>  _shape;//图形类型集合，用于撤回功能
    QPoint _begin;//鼠标按下坐标、用于最后一个图形移动
    QPen _pen;//画笔。绘制图形边线，由颜色、宽度、线风格等参数组成
    QBrush _brush;//画刷。填充几何图形的调色板，由颜色和填充风格组成
    QColor BackGround=Qt::white;//背景颜色

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);//重写鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *e);//重写鼠标释放事件
    void mouseMoveEvent(QMouseEvent *);//重写鼠标移动事件
//    void keyPressEvent(QKeyEvent *e); //重写按键事件

private:
    int _lpress;//左键按下标志
    int _drawType;//描绘类型
    int _drag;//拖拽标志
    int _openflag;//打开图片
    QPen pen[20];
    int opre_num;
    int pen_num[20];
    QPixmap _pixmap;//画布图片
    QTextEdit *_tEdit;//文本输入框
    QPoint p1,p2;//坐标点
    QPoint yuanxin;//圆心
    int r;
    int last_width,last_height;
    Ui::MainWindow *ui;

private slots:
    void on_actionLine_triggered();
    void on_actionCircle_triggered();
    void on_actionRet_triggered();
    void on_actionclear_triggered();
    void on_actionellipse_triggered();
    void on_actionline_triggered();
    void on_actiontext_triggered();
    void on_actionPenColor_triggered();
    void on_actionPenW_triggered();
    void on_actionPenSty_triggered();
    void on_actionBackGroundColor_triggered();
};

#endif // MAINWINDOW_H
