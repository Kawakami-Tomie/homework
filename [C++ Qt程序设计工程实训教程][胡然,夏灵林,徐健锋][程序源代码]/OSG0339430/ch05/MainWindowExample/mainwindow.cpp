#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QToolButton>
#include <QSpinBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //向工具栏中手动添加部件
    QToolButton *toolBtn = new QToolButton(this);
    toolBtn->setText("颜色");
    QMenu *colorMenu = new QMenu(this);
    colorMenu->addAction(tr("红色"));
    colorMenu->addAction(tr("绿色"));
    toolBtn->setMenu(colorMenu);
    toolBtn->setPopupMode(QToolButton::MenuButtonPopup);
    ui->mainToolBar->addWidget(toolBtn);
    QSpinBox *spinBox = new QSpinBox(this);
    ui->mainToolBar->addWidget(spinBox);

    //向状态栏中添加两个label用来显示永久信息和临时信息。
    QLabel *normal = new QLabel("正常信息", this);
    QLabel *permanent = new QLabel( "永久信息" ,this);

    ui->statusBar->addWidget(normal);
    ui->statusBar->addPermanentWidget(permanent);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_N_triggered()
{
    qDebug() << "新建 Action triggered" << endl;
    ui->statusBar->showMessage("新建 Action triggered", 2000);
}

void MainWindow::on_action_O_triggered()
{
    qDebug() << "打开 Action triggered" << endl;
    ui->statusBar->showMessage("打开 Action triggered", 2000);
}
