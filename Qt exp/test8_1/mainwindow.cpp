#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTextDocument>
#include<QTextBlock>
#include<QTextFrame>
#include<QClipboard>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextDocument *document = ui->textEdit->document(); //获取编辑器中的文档对象
        QTextFrame *rootFrame = document->rootFrame(); //获取文档根框架
        QTextFrameFormat format; //创建框架格式
        format.setBorderBrush(Qt::red);   //设置框架的边界颜色为红色
        format.setBorder(3);  //设置框架的边界宽度为3
        rootFrame->setFrameFormat(format);  //设置根框架使用框架格式
        //在根框架中添加一个子框架
       QTextFrameFormat frameFormat; //创建子框架格式
        frameFormat.setBackground(Qt::lightGray); //设置背景颜色为灰色
        frameFormat.setMargin(10); //设置边距
        frameFormat.setPadding(5); //设置填衬
        frameFormat.setBorder(2);
        frameFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Dotted);//设置边框样式
        QTextCursor cursor = ui->textEdit->textCursor(); //获取光标
        cursor.insertFrame(frameFormat); //在光标处插入子框架
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    QTextDocument *document = ui->textEdit->document();
        QTextBlock block = document->firstBlock();
        for(int i = 0; i < document->blockCount(); i++)
        {
            qDebug() << tr("文本块%1, 文本块首行行号为:%2，长度为:%3，内容为:%4")
                        .arg(i).arg(block.firstLineNumber()).arg(block.length()).arg(block.text());
            block = block.next();
        }
//    //获取系统剪切板内容
//    QClipboard *board = QApplication::clipboard();
//    QString text = board->text();
//    ui->textEdit->append(text);
//    //设置滚动条自动向下滑落
//    ui->textEdit->moveCursor(QTextCursor::End);
}
