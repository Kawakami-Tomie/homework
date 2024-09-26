#include "boardwidget.h"
#include <QPainter>
#include <QMouseEvent>

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
    QWidget(parent)
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
            painter.drawRect(QRect(START_POS + QPoint(i * CELL_SIZE.width(), j * CELL_SIZE.height()),
                                   CELL_SIZE));
        }
    }

    painter.setPen(Qt::red);
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
}

void BoardWidget::mouseReleaseEvent(QMouseEvent *event)
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

void BoardWidget::mouseMoveEvent(QMouseEvent *event)
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

void BoardWidget::initBoard()
{
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        for (int j = 0; j < BOARD_HEIGHT; j++)
        {
            board[i][j] = NO_PIECE;
        }
    }
    trackPos = QPoint(28, 28);
    endGame = false;
    nextPlayer = BLACK_PLAYER;
}

void BoardWidget::downPiece(int x, int y)
{
    if (x >= 0 && x < BOARD_WIDTH && y >= 0 && y < BOARD_HEIGHT && board[x][y] == NO_PIECE)
    {
        board[x][y] = (nextPlayer == WHITE_PLAYER) ? WHITE_PIECE : BLACK_PIECE;
        nextPlayer = !nextPlayer;
        update();
    }
}


void BoardWidget::setTrackPos(const QPoint &value)
{
    trackPos = value;
    update();
}

