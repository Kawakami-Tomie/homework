#ifndef GOMOKUAI_H
#define GOMOKUAI_H

#include <QObject>
#include "boardwidget.h"

class GomokuAi : public QObject
{
    Q_OBJECT
public:
    explicit GomokuAi(QObject *parent = nullptr);

private:
    //返回棋盘上所有空的位置
    QVector<QPoint> getAllDropPos();
    //返回该位置的相对于player的分数
    int getPieceScore(int x, int y, int player);
    //返回该位置的分数，越靠近中间分数越大
    int getPosValue(int x, int y);
    //返回该位置dire方向上的棋型
    int getChessType(int x, int y, int dire, int pieceColor);	//返回此处棋型
    //获取该位置该方向上pieceColor颜色的连续棋子数， pieceEnd为结束位置棋子
    int getLinePieceNum(int x, int y, int dire, int pieceColor, int &pieceEnd);
    bool isBeyond(int x, int y);

signals:

public slots:
    QPoint searchAGoodPos(Board nBoard);
public:
    static const int CHESS_VALUES[9];
    static const int MIN_VALUE = -2000000;
    static const int AI_PLAYER = BoardWidget::BLACK_PLAYER;

private:
    int board[BoardWidget::BOARD_WIDTH][BoardWidget::BOARD_HEIGHT];
    QPoint bestPos;
};

#endif // GOMOKUAI_H
