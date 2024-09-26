#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include<QDebug>
#include<QMenuBar>
#include<QToolButton>
#include<QStatusBar>
#include<QLabel>
#include<QPushButton>
#include <QToolButton>
#include <QSpinBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
