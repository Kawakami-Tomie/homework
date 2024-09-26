#include "boardwidget.h"
#include "ChooseColorDialog.h"
#include <QPainter>
#include <QMouseEvent>
#include<QInputDialog>

/*类静态数据成员定义*/
const QSize BoardWidget::WIDGET_SIZE(430, 430);
const QSize BoardWidget::CELL_SIZE(25, 25);
const QPoint BoardWidget::START_POS(40, 40);
const QPoint BoardWidget::ROW_NUM_START(15, 45);
const QPoint BoardWidget::CLU_NUM_START(39, 25);
const int BoardWidget::BOARD_WIDTH;
const int BoardWidget::BOARD_HEIGHT;
const int BoardWidget::NO_PIECE;
const int BoardWidget::WHITE_PIECE;
const int BoardWidget::BLACK_PIECE;
const bool BoardWidget::WHITE_PLAYER;
const bool BoardWidget::BLACK_PLAYER;


BoardWidget::BoardWidget(QWidget *parent) :
    QWidget(parent),
    trackPos(28, 28)
{
    setFixedSize(WIDGET_SIZE);
    setMouseTracking(true);

    initBoard();

}

void BoardWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(0, 0, width(), height(), Qt::gray);	//背景颜色

    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        painter.drawText(CLU_NUM_START + QPoint(i * CELL_SIZE.width(), 0),
                         QString::number(i + 1));
    }
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        painter.drawText(ROW_NUM_START + QPoint(0, i * CELL_SIZE.height()),
                         QString::number(i + 1));
    }

    for (int i = 0; i < BOARD_WIDTH - 1; i++)	//绘制棋盘格子
    {
        for (int j = 0; j < BOARD_HEIGHT - 1; j++)
        {
            painter.drawRect(QRect(START_POS + QPoint(i * CELL_SIZE.width(),
                        j * CELL_SIZE.height()), CELL_SIZE));
        }
    }

    painter.setPen(Qt::red);//落子提示
    QPoint poses[12] = {
        trackPos + QPoint(0, 8),
        trackPos,
        trackPos + QPoint(8, 0),
        trackPos + QPoint(17, 0),
        trackPos + QPoint(25, 0),
        trackPos + QPoint(25, 8),
        trackPos + QPoint(25, 17),
        trackPos + QPoint(25, 25),
        trackPos + QPoint(17, 25),
        trackPos + QPoint(8, 25),
        trackPos + QPoint(0, 25),
        trackPos + QPoint(0, 17)
    };
    painter.drawPolyline(poses, 3);
    painter.drawPolyline(poses + 3, 3);
    painter.drawPolyline(poses + 6, 3);
    painter.drawPolyline(poses + 9, 3);

    painter.setPen(Qt::NoPen);
    for (int i = 0; i < BOARD_WIDTH; i++)	//绘制棋子
    {
        for (int j = 0; j < BOARD_HEIGHT; j++)
        {
            if (board[i][j] != NO_PIECE)
            {
                QColor color = (board[i][j] == WHITE_PIECE) ? Qt::white : Qt::black;
                painter.setBrush(QBrush(color));
                painter.drawEllipse(START_POS.x() - CELL_SIZE.width()/2 + i*CELL_SIZE.width(),
                                    START_POS.y() - CELL_SIZE.height()/2 + j*CELL_SIZE.height(),
                                    CELL_SIZE.width(), CELL_SIZE.height());
            }
        }
    }

    painter.setPen(Qt::red);//标记lastpos落子位置
    if (lastPos.x() != -1)
    {
        QPoint drawPos = START_POS + QPoint(lastPos.x() * CELL_SIZE.width(), lastPos.y() * CELL_SIZE.height());
        painter.drawLine(drawPos + QPoint(0, 5), drawPos + QPoint(0, -5));
        painter.drawLine(drawPos + QPoint(5, 0), drawPos + QPoint(-5, 0));
    }

    for (QPoint pos : winPoses)//绘制连成5颗的棋子
    {
        QPoint drawPos = START_POS + QPoint(pos.x() * CELL_SIZE.width(), pos.y() * CELL_SIZE.height());
        painter.drawLine(drawPos + QPoint(0, 5), drawPos + QPoint(0, -5));
        painter.drawLine(drawPos + QPoint(5, 0), drawPos + QPoint(-5, 0));
    }
}

void BoardWidget::mouseReleaseEvent(QMouseEvent *event)//单击鼠标
{
    if (!endGame)
    {
        QPoint pos = event->pos() - START_POS;
        int x = pos.x();
        int y = pos.y();
        int pieceX = x / CELL_SIZE.width();
        int pieceY = y / CELL_SIZE.height();
        int offsetX = x % CELL_SIZE.width();
        int offsetY = y % CELL_SIZE.height();
        if (offsetX > CELL_SIZE.width() / 2)
        {
            pieceX++;
        }
        if (offsetY > CELL_SIZE.height() / 2)
        {
            pieceY++;
        }
        downPiece(pieceX, pieceY);
    }
}

void BoardWidget::mouseMoveEvent(QMouseEvent *event)//标记鼠标位置 获取当前坐标
{
    QPoint pos = event->pos() - START_POS + QPoint(CELL_SIZE.width()/2, CELL_SIZE.height()/2);
    int x = pos.x();
    int y = pos.y();
    //超过范围
    if (x < 0 || x >= CELL_SIZE.width() * BOARD_WIDTH ||
            y < 0 || y >= CELL_SIZE.height() * BOARD_HEIGHT)
    {
        return;
    }
    int offsetX = x % CELL_SIZE.width();
    int offsetY = y % CELL_SIZE.height();
    setTrackPos(QPoint(x - offsetX, y - offsetY) + START_POS - QPoint(CELL_SIZE.width()/2, CELL_SIZE.height()/2));
}

void BoardWidget::initBoard()//重新初始化
{
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        for (int j = 0; j < BOARD_HEIGHT; j++)
        {
            board[i][j] = NO_PIECE;//清除所有棋子
        }
    }
    lastPos = QPoint(-1, -1);
    endGame = false;
    winPoses.clear();

    ChooseColorDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        ChooseColorDialog::Color chosenColor = dialog.getChosenColor();
        if (chosenColor == ChooseColorDialog::WHITE)
        {
            nextPlayer = WHITE_PLAYER;
        }
        else  nextPlayer = BLACK_PLAYER;

    } else {
        nextPlayer = BLACK_PLAYER;
    }


}

void BoardWidget::undo()//悔棋，回到上一颗棋子
{
    if (!endGame)
    {
        QPoint pos = lastPos;
        board[pos.x()][pos.y()] = NO_PIECE;

        update();
        nextPlayer = !nextPlayer;
    }
}

void BoardWidget::downPiece(int x, int y)
{
    //判断此处无棋和颜色
    if (x >= 0 && x < BOARD_WIDTH && y >= 0 && y < BOARD_HEIGHT && board[x][y] == NO_PIECE)
    {
        board[x][y] = (nextPlayer == WHITE_PLAYER) ? WHITE_PIECE : BLACK_PIECE;
        nextPlayer = !nextPlayer;
        lastPos = QPoint(x, y);
        checkWinner();
        update();
    }
}

void BoardWidget::checkWinner()
{
    bool fullPieces = true;
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        for (int j = 0; j < BOARD_HEIGHT; j++)
        {
            if (board[i][j] == NO_PIECE)//有一个空格就会返回flase
            {
                fullPieces = false;
            }
            if (board[i][j] != NO_PIECE && isFivePieceFrom(i, j))//有空格，查找是否连成5格
            {
                bool winner = (board[i][j] == WHITE_PIECE) ? WHITE_PLAYER : BLACK_PLAYER;
                endGame = true;
                emit gameOver(winner);//出发结束信号
            }
        }
    }
    if (fullPieces)
    {
        endGame = true;
        emit gameOver(2);   //代表和棋
    }
}

bool BoardWidget::isFivePieceFrom(int x, int y)//判断5颗棋子相连
{
    return isVFivePieceFrom(x, y) || isHFivePieceFrom(x, y) || isFSFivePieceFrom(x, y) || isBSFivePieceFrom(x, y);
}

bool BoardWidget::isVFivePieceFrom(int x, int y)//垂直
{
    int piece = board[x][y];
    for (int i = 1; i < 5; i++)
    {
        if (y + i >= BOARD_HEIGHT || board[x][y + i] != piece)
        {
            return false;
        }
    }
    winPoses.clear();
    for (int i = 0; i < 5; i++)
    {
        winPoses.append(QPoint(x, y + i));
    }
    return true;
}

bool BoardWidget::isHFivePieceFrom(int x, int y)//水平
{
    int piece = board[x][y];
    for (int i = 1; i < 5; i++)
    {
        if (x + i >= BOARD_WIDTH || board[x + i][y] != piece)
        {
            return false;
        }
    }
    winPoses.clear();
    for (int i = 0; i < 5; i++)
    {
        winPoses.append(QPoint(x + i, y));
    }
    return true;
}

bool BoardWidget::isFSFivePieceFrom(int x, int y)
{
    int piece = board[x][y];
    for (int i = 1; i < 5; i++)
    {
        if (x + i >= BOARD_WIDTH || y - i < 0 || board[x + i][y - i] != piece)
        {
            return false;
        }
    }
    winPoses.clear();
    for (int i = 0; i < 5; i++)
    {
        winPoses.append(QPoint(x + i, y - i));
    }
    return true;
}

bool BoardWidget::isBSFivePieceFrom(int x, int y)
{
    int piece = board[x][y];
    for (int i = 1; i < 5; i++)
    {
        if (x + i >= BOARD_WIDTH || y + i >= BOARD_HEIGHT || board[x + i][y + i] != piece)
        {
            return false;
        }
    }
    winPoses.clear();
    for (int i = 0; i < 5; i++)
    {
        winPoses.append(QPoint(x + i, y + i));
    }
    return true;
}

void BoardWidget::setTrackPos(const QPoint &value)
{
    trackPos = value;
    update();
}

