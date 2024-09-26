#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "boardwidget.h"
#include "gomokuai.h"

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    GameWidget(QWidget *parent = 0);
    ~GameWidget();

private:
    //初始化游戏窗口界面
    void initWidget();
    //显示获胜者
    void showWinner(int winner);
    //切换playerLabel标签显示内容
    void switchPlayerLabel(bool player);
    //切换至双人对战模式
    void switchHumanGame();
    //切换到Ai对战模式
    void switchAiGame();
    //接受下棋信号，如果为ai模式且轮到ai时，搜索最佳位置下棋
    void nextDropPiece(bool player);
    //悔棋
    void undo();
    //新游戏;
    void newGame();

private:
    GomokuAi *ai;               //ai 对象指针
    bool isGameWithAi;          //是否为ai对战模式

    BoardWidget *boardWidget;   //棋盘控件
    QLabel *playerLabel;        //用于提示下一步轮哪一方
    QLabel *winLabel;           //提示获胜的标签
    QPushButton *newGameBtn;    //新游戏按钮
    QPushButton *humanGameBtn;  //双人游戏按钮
    QPushButton *aiGameBtn;     //ai对战按钮
    QPushButton *undoBtn;       //悔棋按钮
};

#endif // GAMEWIDGET_H
