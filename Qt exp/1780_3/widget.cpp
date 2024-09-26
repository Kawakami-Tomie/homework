#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>
#include<QString>



Widget::Widget(QWidget *parent) :
    QWidget(parent),
   /* ui(new Ui::Widget)
  {
    ui->setupUi(this);
    //ui->lineEdit->setText("0");

    result=0.0;
    waitForOperand=true;

    connectSlots();
    setShortcutKeys();*/

   ui(new Ui::Widget)
    {

       initUi();
       result=0.0;
       waitForOperand=true;
       connectSlots();
       setShortcutKeys();
    }


Widget::~Widget() {
    delete ui;
  }
bool Widget::calculate(double operand,QString pendingOperator)
{
    if(pendingOperator=="+")
    {
        result+=operand;
    }
    else if(pendingOperator=="-")
    {
        result-=operand;
    }
    else if(pendingOperator=="*")
    {
        result*=operand;
    }
    else if(pendingOperator=="!")
    {
        double level;
        level=operand;
        if(operand==0){
            result=1;
        }
        else
        {
        for(int i=level;i>2;i--)
        {
            result=result*(i-1);
        }

        }

    }
    else if(pendingOperator=="^10")
    {

        for(int i=1;i<10;i++)
        {
            result*=operand;
        }

    }
    else if(pendingOperator=="/")
    {
        if(operand==0.0)
        return false;
        result/=operand;
    }
    return true;

}
void Widget::abortOperation()
{
    result=0.0;
    pendingOperator.clear();
    ui->lineEdit->setText("0");
    waitForOperand=true;
    QMessageBox::warning(this,"运算错误","除数不能为零");
}
void Widget::connectSlots()
{
    QPushButton *digitBtns[10] = {
    ui->digitBtn0, ui->digitBtn1,ui->digitBtn2,ui->digitBtn3,
    ui->digitBtn4,ui->digitBtn5,ui->digitBtn6,ui->digitBtn7,
    ui->digitBtn8, ui->digitBtn9
    } ;
    for (auto btn : digitBtns)
    connect (btn, &QPushButton:: clicked, this, &Widget::digitClicked);
    QPushButton *operatorBtns[6] ={
    ui->addBtn, ui->subtractionBtn, ui->multiplicationBnt, ui->divisionBtn,
    ui->levelBtn,ui->tenPowerBtn
    };
    for (auto btn : operatorBtns)
    connect(btn, &QPushButton::clicked, this, &Widget::operatorClicked);
}
void Widget::digitClicked()
{

    QPushButton *digitBtn = static_cast<QPushButton*>(sender());
    QString value = digitBtn->text();
    if(ui->lineEdit->text () == "0" && value == "O")
    return;
    if (waitForOperand)
    {
    ui->lineEdit->setText (value);
    waitForOperand = false;
    }
    else
    {
    ui->lineEdit->setText(ui->lineEdit->text() + value);
    }
 }


    void Widget::on_clearBtn_clicked()
    {
    //将当前显示的数归零
    ui->lineEdit->setText ("0");
    waitForOperand = true;
    }


    void Widget::on_clearAllBtn_clicked ()
    {
    //将当前显示的数据归零，并将之前保存的数据运算清除
        ui->lineEdit->setText ("0");
        waitForOperand = true;
        result = 0.0;
        pendingOperator.clear();
    }


    void Widget::on_equalBtn_clicked()
    {
    double operand = ui->lineEdit->text().toDouble();
    if (pendingOperator.isEmpty ())
       return;
    if (!calculate (operand, pendingOperator))
    {
        abortOperation();
        return;
    }
    ui->lineEdit->setText(QString::number(result));
    pendingOperator.clear();
    result = 0.0;
    waitForOperand = true;
    }


    void Widget::on_signBtn_clicked ()
    {
    QString text = ui->lineEdit->text () ;
    double value = text.toDouble () ;
    if(value > 0)
    {
    text.prepend ('-');
    }
    else if(value < 0)
    {
    text.remove (0, 1);
    }
    ui->lineEdit->setText (text);
    }

    void Widget::operatorClicked ()
    {
    QPushButton *clickedBtn = qobject_cast<QPushButton *> (sender ()) ;
    QString clickedOperator = clickedBtn->text() ;
    double operand = ui->lineEdit->text().toDouble ();
    if (!pendingOperator.isEmpty ()&& !waitForOperand )
    {
    if (!calculate (operand, pendingOperator))
    {
    abortOperation () ;
    return;
    }

    ui->lineEdit->setText (QString::number (result));
    }
    else
    {
    result = operand;
    }
    pendingOperator = clickedOperator;
    waitForOperand=true;
    }

    void Widget::on_pointBtn_clicked()
    {
    if(waitForOperand)
        ui->lineEdit->setText("0");
    if(!ui->lineEdit->text().contains('.'))
        ui->lineEdit->setText(ui->lineEdit->text()+".");
    waitForOperand=false;
    }

void Widget::setShortcutKeys()
{
    Qt::Key key[20]={
        Qt::Key_0, Qt::Key_1, Qt::Key_2, Qt::Key_3,
        Qt::Key_4, Qt::Key_5, Qt::Key_6, Qt::Key_7,
        Qt::Key_8, Qt::Key_9,
        Qt::Key_Plus, Qt::Key_Minus, Qt::Key_Asterisk, Qt::Key_Slash,
        Qt::Key_E, Qt::Key_Period, Qt::Key_Backspace, Qt::Key_M,
        Qt::Key_Q, Qt::Key_T
    };

    QPushButton *btn[20]={
        ui->digitBtn0, ui->digitBtn1,ui->digitBtn2,ui->digitBtn3,
        ui->digitBtn4,ui->digitBtn5,ui->digitBtn6,ui->digitBtn7,
        ui->digitBtn8, ui->digitBtn9,
        ui->addBtn, ui->subtractionBtn, ui->multiplicationBnt, ui->divisionBtn,
        ui->equalBtn,ui->pointBtn,ui->clearBtn,ui->signBtn,
        ui->levelBtn,ui->tenPowerBtn
        };
   for(int i=0;i<20;i++)
       btn[i]->setShortcut(QKeySequence(key[i]));
    ui->clearAllBtn->setShortcut(QKeySequence("Ctrl+Backspace"));

}

void Widget::initUi()
{
    ui->setupUi(this);
    ui->lineEdit->setText("0"); // 假设您有一个lineEdit用于显示结果
    ui->lineEdit->setReadOnly(true); // 设置lineEdit为只读
    setShortcutKeys();




}
