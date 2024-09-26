#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButton_4_clicked()
{
    a += "1"; // 将 '1' 添加到字符串 'a'
    ui->lineEdit->setText(a); // 将字符串 'a' 的内容设置为文本框的文本
}

void Widget::on_pushButton_5_clicked()
{
    a += "2"; // 将 '2' 添加到字符串 'a'
    ui->lineEdit->setText(a); // 将字符串 'a' 的内容设置为文本框的文本

}

void Widget::on_pushButton_6_clicked()
{
    a += "3";
    ui->lineEdit->setText(a);

}

void Widget::on_pushButton_8_clicked()
{
    a += "4";
    ui->lineEdit->setText(a);
}

void Widget::on_pushButton_9_clicked()
{
    a += "5";
    ui->lineEdit->setText(a);
}

void Widget::on_pushButton_10_clicked()
{
    a += "6";
    ui->lineEdit->setText(a);
}

void Widget::on_pushButton_12_clicked()
{
    a += "7";
    ui->lineEdit->setText(a);
}

void Widget::on_pushButton_13_clicked()
{
    a += "8";
    ui->lineEdit->setText(a);
}

void Widget::on_pushButton_14_clicked()
{
    a += "9";
    ui->lineEdit->setText(a);
}


void Widget::on_pushButton_17_clicked()
{
    a += "0";
    ui->lineEdit->setText(a);
}

void Widget::on_pushButton_7_clicked()
{

    b.insert(0,a); // 将字符串a插入到字符串b的首位
    a.clear(); // 清空字符串a
    b.insert(1,"+"); // 在字符串b的第1个位置插入"+"符号
    ui->lineEdit->setText("+"); // 将字符串a的内容设置为文本框的文本

}

void Widget::on_pushButton_11_clicked()
{
        b.insert(0,a); // 将字符串a插入到字符串b的首位
        a.clear(); // 清空字符串a
        b.insert(1,"-"); // 在字符串b的第1个位置插入"-"符号
        ui->lineEdit->setText("-"); // 将字符串a的内容设置为文本框的文本
}


void Widget::on_pushButton_15_clicked()
{
    b.insert(0,a); // 将字符串a插入到字符串b的首位
    a.clear(); // 清空字符串a
    b.insert(1,"*"); // 在字符串b的第1个位置插入"*"符号
    ui->lineEdit->setText("*"); // 将字符串a的内容设置为文本框的文本

}

void Widget::on_pushButton_19_clicked()
{
        b.insert(0,a); // 将字符串a插入到字符串b的首位
        a.clear(); // 清空字符串a
        b.insert(1,"/"); // 在字符串b的第1个位置插入"/"符号
        ui->lineEdit->setText("/"); // 将字符串a的内容设置为文本框的文本
}

void Widget::on_pushButton_2_clicked()
{
       a.clear(); // 清空字符串a
       b.clear(); // 清空字符串b
       ui->lineEdit->setText("0"); // 将文本框的文本设置为"0"

}

void Widget::on_pushButton_3_clicked()
{
    if (!a.isEmpty() && !b.isEmpty()) {
            b.insert(2, a); // 在字符串b的第2个位置插入字符串a
            float v3;
            if (b.at(1) == "+") { // 判断字符串b的第1个元素是否为"+"
                v3 = QString(b.at(0)).toFloat() + QString(b.at(2)).toFloat(); // 将字符串b的第0个和第2个元素转换为浮点数，并进行加法运算
                ui->lineEdit->setText(QString::number(v3)); // 将结果转换为字符串，并将其设置为文本框的文本
            } else if (b.at(1) == "-") { // 判断字符串b的第1个元素是否为"-"
                v3 = QString(b.at(0)).toFloat() - QString(b.at(2)).toFloat(); // 将字符串b的第0个和第2个元素转换为浮点数，并进行减法运算
                ui->lineEdit->setText(QString::number(v3)); // 将结果转换为字符串，并将其设置为文本框的文本
            } else if (b.at(1) == "*") { // 判断字符串b的第1个元素是否为"*"
                v3 = QString(b.at(0)).toFloat() * QString(b.at(2)).toFloat(); // 将字符串b的第0个和第2个元素转换为整数，并进行乘法运算
                ui->lineEdit->setText(QString::number(v3)); // 将结果转换为字符串，并将其设置为文本框的文本
            } else if (b.at(1) == "/") { // 判断字符串b的第1个元素是否为"/"
                if(b.at(2)=="0"){
                    ui->lineEdit->setText("输入不合法！");
                }
                else{
                v3 = QString(b.at(0)).toFloat() / QString(b.at(2)).toFloat(); // 将字符串b的第0个和第2个元素转换为整数，并进行除法运算
                ui->lineEdit->setText(QString::number(v3)); // 将结果转换为字符串，并将其设置为文本框的文本
                }
            }

            // 清空a和b，同时将结果保存到a，以便后续计算
            a = QString::number(v3);
            b.clear();
        }
        else {
            b.insert(0, a); // 将字符串a插入到字符串b的首位
            a.clear(); // 清空字符串a
        }

}

void Widget::on_pushButton_16_clicked()
{
    a += ".";
    ui->lineEdit->setText(a);
}

void Widget::on_pushButton_clicked()
{
//    a += "1";
// //   a.chop(1);
//    ui->lineEdit->setText(a);
    a += ".";
    ui->lineEdit->setText(a);
}
