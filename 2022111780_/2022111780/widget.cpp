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

//void Widget::on_caculate_clicked()
//{

//}

#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QColorDialog>
#include<QFontDialog>
#include<QInputDialog>
#include<QMessageBox>
#include<QProgressDialog>
#include<QErrorMessage>
#include<QDateTime>


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


void Widget::on_clearHistoryButton_clicked()
{
    ui->listWidget->clear(); // 清除历史记录
}

void Widget::on_caculate_clicked()
{
    int weight = ui->weight->value();
    int height = ui->height->value(); // 注意：这里假设身高是以厘米为单位的
    if(height==0)QMessageBox::warning(this, "错误", "身高不能为0。", QMessageBox::Abort);
    int age    = ui->age->value();
    if(age<17)QMessageBox::information(this, "提醒", "BMI分类不适用于青少年", QMessageBox::Ok);
    double heightInMeters = height / 100.0; // 转换为米
    bmi = weight / (heightInMeters * heightInMeters);
    QString result = QString::number(bmi, 'f', 2); // 保留两位小数
    QDateTime dt = QDateTime::currentDateTime();
    QString dt_str = dt.toString();

    ui->result->setText(result);
    if(bmi<=18.5){ui->textres->setText("您的体质偏瘦!");}
    else if(bmi>18.5&&bmi<=24){ui->textres->setText("您的体质正常。"); }
    else if(bmi>24&&bmi<=27){ui->textres->setText("您的体质微胖。");}
    else if(bmi>27&&bmi<=30){ui->textres->setText("您的体质中度肥胖！");}
    else if(bmi>30){ui->textres->setText("您的体质肥胖！");}

    // 将结果添加到历史记录中
    QListWidgetItem *newItem = new QListWidgetItem(QString(dt_str+"   BMI: %1").arg(result));
    ui->listWidget->addItem(newItem);
    newItem->setForeground(Qt::red);//最新的结果显示为红色

    for (int i = 0; i < ui->listWidget->count() - 1; ++i) {
        QListWidgetItem *item = ui->listWidget->item(i);
        if (item) {
            item->setForeground(Qt::black);
        }
    }

}
