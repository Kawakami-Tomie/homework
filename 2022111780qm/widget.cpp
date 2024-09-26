//#include "widget.h"
//#include "ui_widget.h"

//Widget::Widget(QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::Widget)
//{
//    ui->setupUi(this);
//}

//Widget::~Widget()
//{
//    delete ui;
//}

//void Widget::timerEvent(QTimerEvent *event){
//    ui->lineEdit->setText(QString(timer_id));

//}

//void Widget::on_begin_clicked()
//{
//    timer_id = startTimer(100);

//}

//void Widget::on_pushButton_3_clicked()
//{
//    killTimer(timer_id);
//}

//void Widget::on_record_clicked()
//{
//    int n = ui->listWidget->count(); // 获取列表中记录的个数
//    ui->listWidget->item(n-1)->setForeground(Qt::red); // 将最后一个记录设置为红色
//}

#include "widget.h"
#include "ui_widget.h"
#include <QTimerEvent>
#include <QTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    timer_id(0),  // 初始化定时器ID为0
    elapsedTime(0)  // 初始化经过的时间为0
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event){
    if (event->timerId() == timer_id) {
        elapsedTime += 100;  // 每次增加100毫秒
        int secs = elapsedTime / 1000;
        int msecs = elapsedTime % 1000;
        ui->lineEdit->setText(QString("%1.%2").arg(secs, 2, 10, QChar('0')).arg(msecs/10, 2, 10, QChar('0')));
    }
}

void Widget::on_begin_clicked()
{
    if (timer_id == 0) {  // 确保没有正在运行的定时器
        elapsedTime = 0;  // 重置时间
        timer_id = startTimer(100);  // 设置定时器为每100毫秒触发一次
    }
}

void Widget::on_pushButton_3_clicked()
{
    killTimer(timer_id);
    timer_id = 0;  // 将定时器ID重置为0
}

//void Widget::on_record_clicked()
//{
//    if (ui->listWidget->count() > 0) {
//        int n = ui->listWidget->count(); // 获取列表中记录的个数
//        QListWidgetItem *item = ui->listWidget->item(n-1);
//        if (item) {
//            item->setForeground(Qt::red); // 将最后一个记录设置为红色
//        }
//    }
//}

void Widget::on_record_clicked()
{
    // 格式化当前时间
    int secs = elapsedTime / 1000;
    int msecs = (elapsedTime % 1000) / 10;  // 转换为10毫秒的倍数，以便显示三位小数
    int mins = secs / 60;
    secs %= 60;
    QString currentTime = QString("%1:%2.%3").arg(mins, 2, 10, QChar('0')).arg(secs, 2, 10, QChar('0')).arg(msecs, 3, 10, QChar('0'));

    // 创建一个新的QListWidgetItem，并设置其文本
    QListWidgetItem *newItem = new QListWidgetItem(currentTime);

    // 将新项添加到QListWidget中
    ui->listWidget->addItem(newItem);

    // 将新添加的记录项设置为红色
    newItem->setForeground(Qt::red);

//    ui->step->setText(QString(count()));
    // 示例：将除了最后一项之外的所有项设置为默认颜色（如果需要的话）
    for (int i = 0; i < ui->listWidget->count() - 1; ++i) {
        QListWidgetItem *item = ui->listWidget->item(i);
        if (item) {
            item->setForeground(Qt::black); // 假设默认颜色是黑色
        }
    }
}
