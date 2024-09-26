#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QStack>
#include <QPoint>
#include <QSet>

typedef int (*Board)[15];

class BoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BoardWidget(QWidget *parent = nullptr);

    //设置棋盘控件接受的下棋方，在ai模式中只接受白色方，双人模式中都接受
    void setReceivePlayers(const QSet<int> &value);
    //获取棋盘信息
    Board getBoard();

protected:
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    //初始化棋盘控件
    void initBoard();
    //切换下一位下棋者
    void switchNextPlayer();
    //检查是否有获胜方，或者平局
    void checkWinner();
    //判断从(x, y)处开始，是否有五个同色棋子在一条线上
    bool isFivePieceFrom(int x, int y);
    //判断从(x, y)处开始，向下是否有五个同色棋子
    bool isVFivePieceFrom(int x, int y);
    //判断从(x, y)处开始，向下是否有五个同色棋子
    bool isHFivePieceFrom(int x, int y);
    //判断从(x, y)处开始，右上方向是否有五个同色棋子
    bool isFSFivePieceFrom(int x, int y);
    //判断(x, y)处开始， 右下方向是否有五个同色棋子
    bool isBSFivePieceFrom(int x, int y);

signals:
    void gameOver(int winner);
    void turnNextPlayer(int player);

public slots:
    //清除棋盘信息，开始新游戏
    void newGame();
    //落子
    void downPiece(int x, int y);
    void undo(int steps);	//悔棋

public:
    static const QSize WIDGET_SIZE;         //棋盘控件大小
    static const QSize CELL_SIZE;           //棋盘单元格大小
    static const QPoint START_POS;          //棋盘单元格开始位置
    static const QPoint ROW_NUM_START;      //行标号开始位置
    static const QPoint CLU_NUM_START;      //列标号开始位置
    static const int BOARD_WIDTH = 15;      //棋盘列数
    static const int BOARD_HEIGHT = 15;     //棋盘行数
    static const int NO_PIECE = 0;          //棋子标志，表示无子
    static const int WHITE_PIECE = 1;       //棋子标志, 表示白子
    static const int BLACK_PIECE = 2;       //棋子标志，表示黑子
    static const bool WHITE_PLAYER = true;  //棋手标志， 表示白方
    static const bool BLACK_PLAYER = false; //棋手标志， 表示黑方

    void setTrackPos(const QPoint &value);  //设置当前鼠标所在棋盘中的位置

private:
    bool endGame;                               //游戏是否结束标志
    int board[BOARD_WIDTH][BOARD_HEIGHT];       //棋盘信息
    int nextPlayer;                             //表示下一位棋手
    QPoint trackPos;                            //记录鼠标在棋盘中的位置
    QVector<QPoint> winPoses;                   //获胜的五子位置
    QSet<int> receivePlayers;                   //棋盘接受点击下棋的棋手
    QStack<QPoint> dropedPieces;                //每一步落子位置
};

#endif // BOARDWIDGET_H
