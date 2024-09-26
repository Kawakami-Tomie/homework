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
    void mouseMoveEvent(QMouseEvent *event);

private:
    void downPiece(int x, int y);
    void checkWinner();
    bool isFivePieceFrom(int x, int y);		//判断从(x, y)处开始，是否有五个同色棋子在一条线上
    bool isVFivePieceFrom(int x, int y);	//判断从(x, y)处开始，向下是否有五个同色棋子
    bool isHFivePieceFrom(int x, int y); 	//判断从(x, y)处开始，向右是否有五个同色棋子
    bool isFSFivePieceFrom(int x, int y);	//判断从(x, y)处开始，右上方向是否有五个同色棋子
    bool isBSFivePieceFrom(int x, int y);	//判断(x, y)处开始， 右下方向是否有五个同色棋子
    void setTrackPos(const QPoint &value);

signals:
    //游戏结束信号 winner为获胜者
    void gameOver(int winner);

public slots:
    void initBoard();
    void undo();

public:
    static const QSize WIDGET_SIZE;             //棋盘控件大小
    static const QSize CELL_SIZE;               //棋盘单元格大小
    static const QPoint START_POS;              //棋盘单元格绘制时的起始位置
    static const QPoint ROW_NUM_START;          //棋盘行标号的起始位置
    static const QPoint CLU_NUM_START;          //棋盘列标号的起始位置
    static const int BOARD_WIDTH = 15;          //棋盘列数
    static const int BOARD_HEIGHT = 15;         //棋盘行数
    static const int NO_PIECE = 0;              //棋子标志，表示无子
    static const int WHITE_PIECE = 1;           //棋子标志，表示白子
    static const int BLACK_PIECE = 2;           //棋子标志，表示黑子
    static const bool WHITE_PLAYER = true;      //棋手标志，表示白方
    static const bool BLACK_PLAYER = false;     //棋手标志，表示黑方


private:
    bool endGame;                               //游戏结束标志
    int board[BOARD_WIDTH][BOARD_HEIGHT];       //棋盘数据
    int nextPlayer;                             //表示下一位棋手
    QPoint lastPos;                             //上一步棋子位置
    QPoint trackPos;                            //鼠标在棋盘上的位置
    QVector<QPoint> winPoses;                   //获胜的五个棋子所在位置
};

#endif // BOARDWIDGET_H
