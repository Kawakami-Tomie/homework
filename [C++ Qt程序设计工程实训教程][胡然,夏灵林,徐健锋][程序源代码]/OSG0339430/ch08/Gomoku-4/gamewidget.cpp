#include "gamewidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPushButton>

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("五子棋");
    boardWidget = new BoardWidget(this);

    connect(boardWidget, &BoardWidget::gameOver, this, &GameWidget::showWinner);
}

GameWidget::~GameWidget()
{

}

void GameWidget::showWinner(int winner)
{
    if (winner != 2)
    {
        QString playerName = (winner == BoardWidget::WHITE_PLAYER) ? "白方" : "黑方";
        QMessageBox::information(this, "游戏结束", tr("恭喜%1获胜！！").arg(playerName), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, "游戏结束", "和棋！", QMessageBox::Ok);
    }
}
