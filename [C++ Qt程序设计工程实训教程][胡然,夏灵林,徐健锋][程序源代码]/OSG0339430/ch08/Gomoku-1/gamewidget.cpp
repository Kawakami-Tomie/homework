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
}

GameWidget::~GameWidget()
{

}
