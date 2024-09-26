#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextFrame>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置根框架格式
    QTextDocument *document = ui->textEdit->document();
    QTextFrame *rootFrame = document->rootFrame();
    QTextFrameFormat format;
    format.setBorderBrush(Qt::red);
    format.setBorder(3);
    rootFrame->setFrameFormat(format);

    //在根框架中添加一个子框架
    QTextFrameFormat frameFormat;
    frameFormat.setBackground(Qt::lightGray);
    frameFormat.setMargin(10);
    frameFormat.setPadding(5);
    frameFormat.setBorder(2);
    frameFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Dotted);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertFrame(frameFormat);

    findDialog = new QDialog(this);
    lineEdit = new QLineEdit(findDialog);
    QPushButton *btn = new QPushButton(findDialog);
    btn->setText("查找下一个");
    connect(btn, &QPushButton::clicked, this, &MainWindow::findNext);
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(lineEdit);
    layout->addWidget(btn);
    findDialog->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::findNext()
{
    QString str = lineEdit->text();
    bool isFind = ui->textEdit->find(str, QTextDocument::FindBackward);
    if (isFind)
    {
        qDebug() << tr("行号：%1， 列号：%2")
                    .arg(ui->textEdit->textCursor().blockNumber())
                    .arg(ui->textEdit->textCursor().columnNumber());
    }
}

void MainWindow::on_action_triggered()	//遍历文本块
{
    QTextDocument *document = ui->textEdit->document();
    QTextBlock block = document->firstBlock();
    for(int i = 0; i < document->blockCount(); i++)
    {
        qDebug() << tr("文本块%1, 文本块首行行号为:%2，长度为:%3，内容为:")
                    .arg(i).arg(block.firstLineNumber()).arg(block.length())
                 << block.text();
        block = block.next();
    }
}

void MainWindow::on_action_textTable_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTableFormat format;
    format.setCellSpacing(2);
    format.setCellPadding(10);
    cursor.insertTable(2, 2, format);
}

void MainWindow::on_action_textList_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextListFormat format;
    format.setStyle(QTextListFormat::ListDecimal);
    cursor.insertList(format);
}

void MainWindow::on_action_textImage_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextImageFormat format;
    format.setName("../qt.jpg");
    cursor.insertImage(format);
}

void MainWindow::on_action_find_triggered()
{
    findDialog->show();
}
