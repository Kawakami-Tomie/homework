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


BoardWidget::BoardWidget(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(WIDGET_SIZE);
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

}


