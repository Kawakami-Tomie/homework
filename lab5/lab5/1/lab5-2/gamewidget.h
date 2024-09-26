#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "boardwidget.h"

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    GameWidget(QWidget *parent = 0);
    ~GameWidget();

private:
    void showWinner(int winner);
    //悔棋
    void undo();

private:
    BoardWidget *boardWidget;
    QPushButton *undoBtn;       //悔棋按钮
    QPushButton *cancelBtn;
};

#endif // GAMEWIDGET_H
