#include "gomokuai.h"
#include <QDebug>
#include <cmath>

const int GomokuAi::CHESS_VALUES[9] = {0, 50, 100, 200, 500, 650, 2500, 10000, 30000};
const int GomokuAi::MIN_VALUE;
const int GomokuAi::AI_PLAYER;

GomokuAi::GomokuAi(QObject *parent) : QObject(parent)
{
}

QVector<QPoint> GomokuAi::getAllDropPos()
{
    QVector<QPoint> allPos;
    for (int i = 0; i < BoardWidget::BOARD_WIDTH; i++)
    {
        for (int j = 0; j < BoardWidget::BOARD_HEIGHT; j++)
        {
            if (board[i][j] == BoardWidget::NO_PIECE)
            {
                allPos.push_back(QPoint(i, j));
            }
        }
    }
    return allPos;
}

int GomokuAi::getPieceScore(int x, int y, int player)
{
    int value = 0;
    int piece = (player == BoardWidget::WHITE_PLAYER) ? BoardWidget::WHITE_PIECE : BoardWidget::BLACK_PIECE;
    for (int i = 0; i < 8; i++)
    {
        int t = getChessType(x, y, i, piece);
        value += CHESS_VALUES[t];
    }
    value += getPosValue(x, y);
    return value;
}

int GomokuAi::getPosValue(int x, int y)
{
    int valuex =BoardWidget::BOARD_WIDTH - std::abs(x - BoardWidget::BOARD_WIDTH / 2);
    int valuey =BoardWidget::BOARD_HEIGHT - std::abs(y - BoardWidget::BOARD_HEIGHT / 2);
    return valuex + valuey;
}

int GomokuAi::getChessType(int x, int y, int dire, int piece)
{
    int chessType = 0;
    int end = BoardWidget::NO_PIECE;
    int num = getLinePieceNum(x, y, dire, piece, end);
    if (num == 5)
    {
        chessType = 8;
    }
    else if (num == 4 && end == BoardWidget::NO_PIECE)
    {
        chessType = 7;
    }
    else if (num == 4 && end != BoardWidget::NO_PIECE)
    {
        chessType = 6;
    }
    else if (num == 3 && end == BoardWidget::NO_PIECE)
    {
        chessType = 5;
    }
    else if (num == 3 && end != BoardWidget::NO_PIECE)
    {
        chessType = 4;
    }
    else if (num == 2 && end == BoardWidget::NO_PIECE)
    {
        chessType = 3;
    }
    else if (num == 2 && end != BoardWidget::NO_PIECE)
    {
        chessType = 2;
    }
    else if (num == 1 && end == BoardWidget::NO_PIECE)
    {
        chessType = 1;
    }
    else
    {
        chessType = 0;
    }
    return chessType;
}

int GomokuAi::getLinePieceNum(int x, int y, int dire, int pieceColo, int &pieceEnd)
{
    int offset[8][2] = {{1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}};
    int num = 0;
    x += offset[dire][0];
    y += offset[dire][1];
    if (isBeyond(x, y) || board[x][y] != pieceColo)
    {
        return 0;
    }
    int pieceStart = board[x][y];
    while (!isBeyond(x, y) && board[x][y] == pieceStart)
    {
        x += offset[dire][0];
        y += offset[dire][1];
        num++;
    }
    pieceEnd = board[x][y];	//终止处的棋子
    return num;
}

bool GomokuAi::isBeyond(int x, int y)
{
    return x < 0 || x >= BoardWidget::BOARD_WIDTH || y < 0 || y >= BoardWidget::BOARD_HEIGHT;
}

QPoint GomokuAi::searchAGoodPos(Board nBoard)
{
    memcpy(board, nBoard, sizeof(board));
    int bestScore = MIN_VALUE;
    for (QPoint pos : getAllDropPos())
    {
        int value = getPieceScore(pos.x(), pos.y(), AI_PLAYER);
        int oppoValue = getPieceScore(pos.x(), pos.y(), !AI_PLAYER);
        int totalValue = std::max(value, oppoValue * 4 / 5);
        if (totalValue > bestScore)
        {
            bestScore = totalValue;
            bestPos = pos;
        }
    }
    return bestPos;
}
