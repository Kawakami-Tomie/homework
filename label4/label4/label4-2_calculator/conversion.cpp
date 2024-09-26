#include "conversion.h"
#include "ui_conversion.h"
#include<QString>
#include<QMainWindow>
#include"mainwindow.h"
#include<QDebug>
#include<QMessageBox>

conversion::conversion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::conversion)
{
    ui->setupUi(this);
}

conversion::~conversion()
{
    delete ui;
}

void conversion::on_action_triggered()
{
    emit goback();
}

void conversion::on_convert10_clicked() //十进制转
{
    QString text=ui->dec->text();
    int value=text.toInt(); //toInt默认为十进制

    QString bin=text.setNum(value,2); //二进制
    ui->bin->setText(bin);

    QString hex=text.setNum(value,16); //十六进制
    ui->hex->setText(QString("0x%1").arg(hex));

    QString oct=text.setNum(value,8); //八进制
    ui->oct->setText(oct);
}



void conversion::on_convert2_clicked()
{
    QString text=ui->bin->text();
    bool ok;
    int value=text.toInt(&ok,2); //以二进制读入，读取成功ok=true
    qDebug()<<"ok="<<ok;

    if(ok)
    {
        QString dec=QString::number(value,10); //十进制
        ui->dec->setText(dec);

        QString hex=QString::number(value,16).toUpper(); //十六进制
        ui->hex->setText(QString("0x%1").arg(hex));

        QString oct=QString::number(value,8); //八进制
        ui->oct->setText(oct);
    }
    else
        QMessageBox::warning(this,"运算错误","输入不合法");
}


void conversion::on_convert16_clicked()
{
    QString text=ui->hex->text();
    bool ok;
    int value=text.toInt(&ok,16); //以十六进制读入，读取成功ok=true
    qDebug()<<"ok="<<ok;

    if(ok)
    {
        QString dec=QString::number(value,10); //十进制
        ui->dec->setText(dec);

        QString bin=QString::number(value,2).toUpper(); //十六进制
        ui->bin->setText(bin);

        QString oct=QString::number(value,8); //八进制
        ui->oct->setText(oct);
    }
    else
        QMessageBox::warning(this,"运算错误","输入不合法");
}

void conversion::on_convert8_clicked()
{
    QString text=ui->oct->text();
    bool ok;
    int value=text.toInt(&ok,8); //以八进制读入，读取成功ok=true
    qDebug()<<"ok="<<ok;

    if(ok)
    {
        QString dec=QString::number(value,10); //十进制
        ui->dec->setText(dec);

        QString hex=QString::number(value,16).toUpper(); //十六进制
        ui->hex->setText(QString("0x%1").arg(hex));

        QString bin=QString::number(value,2); //八进制
        ui->bin->setText(bin);
    }
    else
        QMessageBox::warning(this,"运算错误","输入不合法");
}
