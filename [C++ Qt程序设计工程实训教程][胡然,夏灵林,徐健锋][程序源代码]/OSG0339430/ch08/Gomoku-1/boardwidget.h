#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QVector>
#include <QPoint>

class BoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BoardWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);

public:
    static const QSize WIDGET_SIZE;      //棋盘控件大小
    static const QSize CELL_SIZE;        //棋盘单元格大小
    static const QPoint START_POS;       //棋盘单元格绘制开始位置
    static const QPoint ROW_NUM_START;   //棋盘行标号开始位置
    static const QPoint CLU_NUM_START;   //棋盘列标号开始位置
    static const int BOARD_WIDTH = 15;   //棋盘列数
    static const int BOARD_HEIGHT = 15;  //棋盘行数
};

#endif // BOARDWIDGET_H
