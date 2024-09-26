#include "gamewidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPushButton>

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("五子棋_1780");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    boardWidget = new BoardWidget(this);

    QHBoxLayout *hLayout = new QHBoxLayout();
    QPushButton *newGame = new QPushButton("重新开始");
    QPushButton *undo = new QPushButton("悔棋");
    hLayout->addWidget(newGame);
    hLayout->addWidget(undo);
    hLayout->addStretch();

    mainLayout->addLayout(hLayout);
    mainLayout->addWidget(boardWidget);

    connect(newGame, &QPushButton::clicked, boardWidget, &BoardWidget::initBoard);
    connect(undo, &QPushButton::clicked, boardWidget, &BoardWidget::undo);
    connect(boardWidget, &BoardWidget::gameOver, this, &GameWidget::showWinner);
}

GameWidget::~GameWidget()
{

}

void GameWidget::showWinner(int winner)//gameover传入信号
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
