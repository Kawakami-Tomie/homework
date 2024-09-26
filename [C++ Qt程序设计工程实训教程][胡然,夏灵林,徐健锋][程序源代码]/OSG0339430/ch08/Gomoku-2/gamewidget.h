#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "boardwidget.h"

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    GameWidget(QWidget *parent = 0);
    ~GameWidget();

private:
    BoardWidget *boardWidget;
};

#endif // GAMEWIDGET_H
