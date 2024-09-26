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
    void mouseReleaseEvent(QMouseEvent *event);

private:
    void downPiece(int x, int y);

public slots:
    void initBoard();

public:
    static const QSize WIDGET_SIZE;             //棋盘控件大小
    static const QSize CELL_SIZE;               //棋盘单元格大小
    static const QPoint START_POS;              //棋盘单元格绘制开始位置
    static const QPoint ROW_NUM_START;          //棋盘行标号开始位置
    static const QPoint CLU_NUM_START;          //棋盘列标号绘制开始位置
    static const int BOARD_WIDTH = 15;          //棋盘列数
    static const int BOARD_HEIGHT = 15;         //棋盘行数
    static const int NO_PIECE = 0;              //棋子标志， 无子
    static const int WHITE_PIECE = 1;           //棋子标志， 白子
    static const int BLACK_PIECE = 2;           //棋子标志，黑子
    static const bool WHITE_PLAYER = true;      //棋手标志，白方
    static const bool BLACK_PLAYER = false;     //棋手标志，黑方


private:
    int board[BOARD_WIDTH][BOARD_HEIGHT];       //棋盘数据
    int nextPlayer;                             //下一手棋手
};

#endif // BOARDWIDGET_H
