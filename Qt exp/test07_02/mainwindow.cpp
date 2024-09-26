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

    QLabel *label=new QLabel("正常信息1",this);
    ui->statusBar->addWidget(label); //添加正常信息
    ui->statusBar->addWidget(new QLabel("正常信息2",this));
    ui->statusBar->addPermanentWidget(new QLabel("永久信息",this));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_N_triggered()
{

}
