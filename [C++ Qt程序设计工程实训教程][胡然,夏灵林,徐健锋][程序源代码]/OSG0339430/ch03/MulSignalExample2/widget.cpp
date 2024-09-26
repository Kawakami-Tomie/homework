#include "widget.h"
#include "ui_widget.h"
//#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lineEdit->setText("");//清除lineedit数据。
    ui->lineEdit->setReadOnly(true);//设置lineedit只读，不能输入。
    connectSlots();
}
Widget::~Widget()
{
    delete ui;
}

void Widget::connectSlots()
{
    QPushButton *digitBtns[10] = {
        ui->digitBtn0, ui->digitBtn1, ui->digitBtn2, ui->digitBtn3,
        ui->digitBtn4, ui->digitBtn5, ui->digitBtn6, ui->digitBtn7,
        ui->digitBtn8, ui->digitBtn9
    };
    for (auto btn : digitBtns)
        //10个数字按钮，每个按钮是一个信号，都连接到同一个槽函数digitClicked
        connect(btn, &QPushButton::clicked, this, &Widget::digitClicked);
}

void Widget::digitClicked()
{
    //通过sender()函数判断是哪个按钮发出的信号
    QPushButton *digitBtn = static_cast<QPushButton*>(sender());
    QString value = digitBtn->text();

    //qDebug()<<value; //打印
    ui->lineEdit->setText(ui->lineEdit->text() + value);
}

void Widget::on_pointBtn_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ".");
}

void Widget::on_clearBtn_clicked()
{
    //清除lineedit数据。
    ui->lineEdit->setText("");
}
