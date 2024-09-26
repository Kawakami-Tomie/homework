#include "gamewidget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QFileDialog>
#include <QLabel>
#include <QDebug>

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent)
{
    ai = new GomokuAi(this);
    isGameWithAi = false;
    initWidget();

    switchHumanGame();
}

GameWidget::~GameWidget()
{

}

void GameWidget::initWidget()
{

    setWindowTitle("五子棋");

    //创建水平布局作为总布局
    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    //棋盘控件
    boardWidget = new BoardWidget(this);
    mainLayout->addWidget(boardWidget);

    //创建垂直布局作为界面右边标签和菜单的子布局
    QVBoxLayout *vLayout = new QVBoxLayout();
    playerLabel = new QLabel("轮到白方落子", this);
    playerLabel->setFont(QFont("微软雅黑", 25));
    vLayout->addWidget(playerLabel);
    vLayout->addStretch();

    winLabel = new QLabel(this);
    winLabel->setFont(QFont("微软雅黑", 20));
    vLayout->addWidget(winLabel);
    vLayout->addStretch();          //添加一个伸缩因子

    //创建栅格布局作为菜单按钮的布局
    QGridLayout *gLayout = new QGridLayout();
    newGameBtn = new QPushButton("新游戏");
    humanGameBtn = new QPushButton("双人游戏");
    aiGameBtn = new QPushButton("人机对战");
    undoBtn = new QPushButton("悔棋");
    gLayout->addWidget(newGameBtn, 0, 0);
    gLayout->addWidget(humanGameBtn, 0, 1);
    gLayout->addWidget(aiGameBtn, 0, 2);
    gLayout->addWidget(undoBtn, 0, 3);

    vLayout->addLayout(gLayout);
    mainLayout->addLayout(vLayout);

    connect(boardWidget, &BoardWidget::gameOver, this, &GameWidget::showWinner);
    connect(boardWidget, &BoardWidget::turnNextPlayer, this, &GameWidget::switchPlayerLabel, Qt::QueuedConnection);
    connect(boardWidget, &BoardWidget::turnNextPlayer, this, &GameWidget::nextDropPiece, Qt::QueuedConnection);
    connect(newGameBtn, &QPushButton::clicked, this, &GameWidget::newGame);
    connect(humanGameBtn, &QPushButton::clicked, this, &GameWidget::switchHumanGame);
    connect(aiGameBtn, &QPushButton::clicked, this, &GameWidget::switchAiGame);
    connect(undoBtn, &QPushButton::clicked, this, &GameWidget::undo);
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

void GameWidget::switchPlayerLabel(bool player)
{
    QString playerName = (player == BoardWidget::WHITE_PLAYER) ? "白方" : "黑方";
    QString labelText = tr("轮到%1落子").arg(playerName);
    playerLabel->setText(labelText);
}

void GameWidget::switchHumanGame()
{
    humanGameBtn->setEnabled(false);
    aiGameBtn->setEnabled(true);
    QSet<int> receivePlayers;
    receivePlayers << BoardWidget::WHITE_PLAYER << BoardWidget::BLACK_PLAYER;
    boardWidget->setReceivePlayers(receivePlayers);
    isGameWithAi = false;
    boardWidget->newGame();
}

void GameWidget::switchAiGame()
{
    aiGameBtn->setEnabled(false);
    humanGameBtn->setEnabled(true);
    QSet<int> receivePlayers;
    receivePlayers << BoardWidget::WHITE_PLAYER;
    boardWidget->setReceivePlayers(receivePlayers);
    isGameWithAi = true;
    boardWidget->newGame();
}

void GameWidget::nextDropPiece(bool player)
{
    if (isGameWithAi && player == GomokuAi::AI_PLAYER)
    {
        QPoint pos = ai->searchAGoodPos(boardWidget->getBoard());
        boardWidget->downPiece(pos.x(), pos.y());
    }
}

void GameWidget::undo()
{
    if (isGameWithAi)
    {
        boardWidget->undo(2);
    }
    else
    {
        boardWidget->undo(1);
    }
}

void GameWidget::newGame()
{
    winLabel->setText("");
    boardWidget->newGame();
}
