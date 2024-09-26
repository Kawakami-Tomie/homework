#include "widget.h"
#include "ui_widget.h"
#include <QDialog>
#include<QDebug>
#include<QFileDialog>
#include<QColorDialog>
#include<QFontDialog>
#include<QInputDialog>
#include<QMessageBox>
#include<QProgressDialog>
#include<QErrorMessage>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QDialog*dlg=new QDialog(this);
 //   dlg->setModal(true);//模态对话框
    dlg->show();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
        QString curPath=QDir::currentPath();  //获取当前程序的路径
        QString filter="文本文件(*.txt);;图片文件(*.jpg *.gif);;所有文件(*.*)";  //文件类型过滤器
        QString  fileName=QFileDialog::getOpenFileName(this, "选择文件",curPath,filter);
        if (fileName.isEmpty())   return;
        ui->plainTextEdit->appendPlainText(fileName); //追加文本
        qDebug()<<fileName;

}

void Widget::on_pushButton_2_clicked()
{
    QPalette pal=ui->plainTextEdit->palette(); //获取当前文本框的现有 palette
    QColor iniColor=pal.color(QPalette::Text); //现有的文字颜色
    QColor color=QColorDialog::getColor(iniColor,this,"选择颜色");
    if (!color.isValid())   return;
    pal.setColor(QPalette::Text,color); //palette对文本主题设置了选择的颜色
     qDebug()<<color;
    pal.setColor(QPalette::Base,Qt::lightGray); //palette对背景主题设置了浅灰色
    ui->plainTextEdit->setPalette(pal); //设置调色板的颜色
}

void Widget::on_pushButton_4_clicked()
{
    bool ok=false;
    QString str = QInputDialog::getText(this, "输入文字对话框", "请输入用户名：", QLineEdit::Normal, "admin", &ok);
    if (!ok)  return;
    ui->plainTextEdit->appendPlainText(str);
     qDebug()<<str;

//    bool ok=false;
//     int intNum = QInputDialog::getInt(this, "整数输入对话框", "请输入-1000到1000之间的数值", 100, -1000, 1000, 10, &ok);
//     if (!ok)  return;
//     ui->plainTextEdit->appendPlainText(QString::number(intNum));
}

void Widget::on_pushButton_5_clicked()
{
//    int ret1 = QMessageBox::question(this, "问题对话框", "你了解Qt吗？", QMessageBox::Yes, QMessageBox::No);
//    QString str;
//    if (ret1 == QMessageBox::Yes)
//          str="了解";
//    else str="不了解";
//    ui->plainTextEdit->appendPlainText(str);
    QMessageBox::information(this, "提示对话框", "这是Qt书籍！", QMessageBox::Ok);

    QMessageBox::warning(this, "警告对话框", "不能提前结束！", QMessageBox::Abort);

    QMessageBox::critical(this, "严重错误对话框", "发现一个严重错误！现在要关闭所有文件！", QMessageBox::YesAll);

    QMessageBox::about(this, "关于对话框", "Qt对话框实例");

}

void Widget::on_pushButton_6_clicked()
{
//    bool ok=false;
//        QStringList items;
//        items << "优秀" << "良好" << "及格";
//        QString item = QInputDialog::getItem(this, "条目输入对话框", "请选择或输入一个条目", items, 0, true, &ok);
//        //为false的时候不能自己输入
//        if (!ok)  return;
//        ui->plainTextEdit->appendPlainText(item);
    QProgressDialog dialog("文件复制进度", "取消", 0, 50000, this);
          dialog.setWindowTitle("进度对话框");
          dialog.show();
          for (int i = 0; i < 100000; i++)
          {
              dialog.setValue(i);
              QCoreApplication::processEvents();
              if (dialog.wasCanceled())
              {
                  break;
              }
          }

}

void Widget::on_pushButton_3_clicked()
{
    QFont iniFont=ui->plainTextEdit->font(); //获取文本框的字体
    bool ok=false;
    QFont font=QFontDialog::getFont(&ok,iniFont,this,"选择字体"); //选择字体
    if (!ok)  return;
    ui->plainTextEdit->setFont(font); //选择有效
     qDebug()<<font;
}
