#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::jointNum(QString str, int &i)//分割，提取操作数
{
    QString temp;
     ui->le_show->clear();
    double result;
    //138×16-5
    while(str[i]>='0'&&str[i]<='9') //处理小数点之前的部分
    {
        temp += str[i++];
    }
    if(str[i]=='.')//处理小数点之后的部分
    {
        i++;
        temp+='.';
        while(str[i]>='0'&&str[i]<='9') //处理小数点之前的部分
            temp += str[i++];
    }
    result = temp.toDouble();
    return result;
}

int MainWindow::in_priority(char ch)
{
    int in;
    switch(ch)
    {
    case '=':in = 0;break;
    case '+':in = 3;break;
    case '-':in = 3;break;
    case '*':in = 5;break;
    case '/':in = 5;break;
    case '!':in = 7;break;
    case '^':in = 9;break;
    case '(':in = 1;break;
    case ')':in = 10;break;
    }
    return in;
}
int MainWindow::out_priority(char ch)
{
    int out;
    switch(ch)
    {
    case '=':out = 0;break;
    case '+':out = 2;break;
    case '-':out = 2;break;
    case '*':out = 4;break;
    case '/':out = 4;break;
    case '！':out = 6;break;
    case '^':out = 8;break;
    case '(':out = 10;break;
    case ')':out = 1;break;
    }
    return out;
}

int MainWindow::compare_priority(int in, int out)
{
    if(in<out)
        return -1;
    else if(in==out)
        return 0;
    else
        return 1;
}

double MainWindow::calcualate_num(double num1, double num2, char oper)
{
    switch(oper)
    {
    case '+':return num2+num1;
    case '-':return num2-num1;
    case '*':return num2*num1;
    case '/':
    {
        if(num1 == 0)
        {
            QMessageBox::warning(this,"错误","除数为0!!!");
            return 0;
        }

        return num2/num1;
    }
    case '!':
    {
        return !num1;
    }
     case '^':
        double num3 = num2;
        qDebug() << "My num3 a is:" << num3;
        for(int i=1;i<num1;i++)
        {
            num2=num2*num3;
            qDebug() << "My num2 a is:" << num2;
        }
        qDebug() << "My num1 a is:" << num1;

        return num2;

    }
}
//键盘响应事件
void MainWindow::keyPressEvent(QKeyEvent *event)
{
   infix = ui->le_show->text();
   switch (event->key()) {
   case 0x30:infix+="0";btn_highlight(ui->btn_0);break;
   case 0x31:infix+="1";btn_highlight(ui->btn_1);break;
   case 0x32:infix+="2";btn_highlight(ui->btn_2);break;
   case 0x33:infix+="3";btn_highlight(ui->btn_3);break;
   case 0x34:infix+="4";btn_highlight(ui->btn_4);break;
   case 0x35:infix+="5";btn_highlight(ui->btn_5);break;
   case 0x36:infix+="6";btn_highlight(ui->btn_6);break;
   case 0x37:infix+="7";btn_highlight(ui->btn_7);break;
   case 0x38:infix+="8";btn_highlight(ui->btn_8);break;
   case 0x39:infix+="9";btn_highlight(ui->btn_9);break;
   case 0x2b:infix+="+";btn_highlight(ui->btn_add);break;
   case 0x2d:infix+="-";btn_highlight(ui->btn_sub);break;
   case 0x2a:infix+="*";btn_highlight(ui->btn_multiply);break;
   case 0x2f:infix+="/";btn_highlight(ui->btn_divide);break;
   case 0x28:infix+="(";btn_highlight(ui->btn_left);break;
   case 0x29:infix+=")"; btn_highlight(ui->btn_right);break;
   case 0x2e:infix+="."; btn_highlight(ui->btn_point);break;
   case 0x01000003:on_btn_back_clicked();btn_highlight(ui->btn_back);break; //退格
   case 0x01000004:on_btn_equal_clicked();btn_highlight(ui->btn_equal);break; //等于
   case 0x01000005:on_btn_equal_clicked();btn_highlight(ui->btn_equal);break; //等于
   }

   ui->le_show->setText(infix);
}
//键盘释放事件
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case 0x30:btn_release(ui->btn_0);break;
    case 0x31:btn_release(ui->btn_1);break;
    case 0x32:btn_release(ui->btn_2);break;
    case 0x33:btn_release(ui->btn_3);break;
    case 0x34:btn_release(ui->btn_4);break;
    case 0x35:btn_release(ui->btn_5);break;
    case 0x36:btn_release(ui->btn_6);break;
    case 0x37:btn_release(ui->btn_7);break;
    case 0x38:btn_release(ui->btn_8);break;
    case 0x39:btn_release(ui->btn_9);break;
    case 0x2b:btn_release(ui->btn_add);break;
    case 0x2d:btn_release(ui->btn_sub);break;
    case 0x2a:btn_release(ui->btn_multiply);break;
    case 0x2f:btn_release(ui->btn_divide);break;
    case 0x28:btn_release(ui->btn_left);break;
    case 0x29: btn_release(ui->btn_right);break;
    case 0x2e: btn_release(ui->btn_point);break;
    case 0x01000003:btn_release(ui->btn_back);break; //退格
    case 0x01000004:btn_release(ui->btn_equal);break; //等于
    case 0x01000005:btn_release(ui->btn_equal);break; //等于
    }
}
void MainWindow::btn_highlight(QPushButton *btn) //按下效果
{
    btn->setStyleSheet("QPushButton{background-color: rgb(200, 200, 200);}");
}
void MainWindow::btn_release(QPushButton *btn) //释放效果
{
    btn->setStyleSheet("QPushButton{background-color: rgb(240, 240, 240);}");
}
void MainWindow::de_weight(QVector<QString> &vec) //去重
{
    for(int i = 0;i<vec.size();i++)
    {
        for(int j = i+1;j<vec.size();j++)
        {
            if(vec.at(j) == vec.at(i))
                vec.removeAt(j);
        }
    }
}

void MainWindow::on_btn_back_clicked()
{
    infix.remove(infix.length()-1,1);
    ui->le_show->setText(infix);
}

void MainWindow::on_btn_clear_clicked()
{
    ui->le_show->clear();
    infix.clear();
    infix_copy.clear();
}

void MainWindow::on_btn_left_clicked()
{
    infix += "(";
    ui->le_show->setText(infix);
}

void MainWindow::on_btn_right_clicked()
{
    infix += ")";
    ui->le_show->setText(infix);
}

void MainWindow::on_btn_mul_clicked()
{
    infix += "^";
    ui->le_show->setText(infix);
}

void MainWindow::on_btn_equal_clicked()
{
    //   ui->text_history->clear();

       optr.clear();//运算符
       opnd.clear();//操作数
       infix = ui->le_show->text(); //获取表达式
       if(infix[0]=="-")
           infix = "0" + infix;
       if(infix.isEmpty())
           return;
       optr.push('='); //=置于栈底，级别最低
       int i = 0;
       double num,a,b;
       char item,ch;
       while(!optr.empty())
       {
           if(infix[i]=="0"||infix[i]=="1"||infix[i]=="2"||infix[i]=="3"||infix[i]=="4"||infix[i]=="5"||
               infix[i]=="6"||infix[i]=="7"||infix[i]=="8"||infix[i]=="9"||infix[i]==".") //数字字符或者.，则拼接并入栈
           {
               num = jointNum(infix,i);
               opnd.push(num);  //数字入栈
           }
           else //操作符
           { //12+13
                item = optr.top();
               switch(compare_priority(in_priority(item),out_priority(infix[i].toLatin1())))//比较运算符优先级,toLatin1:QChar->char
               {
                  case -1:
               {
                   optr.push(infix[i].toLatin1());//infix[i]优先级高，入栈
                                   i++;  //指向下一个字符
               }
                   break;
                  case 0:
               {
                   item = optr.pop(); //删除括号或者=
                   if(item!='=')
                       i++;  //指向下一个字符
               }
                   break;
                  case 1:
               {
                   ch = optr.pop(); //infix[i]级别低，弹出一个运算符并弹出两个操作数进行运算后再压栈
                   a = opnd.pop();
                   b = opnd.pop();
                   opnd.push(calcualate_num(a,b,ch)); //运算后结果入栈
                   qDebug() << "My double a is:" << a;
                   qDebug() << "My double b is:" << b;
               }
               }

           }
       }
       num = opnd.pop();
       if(!opnd.empty())
        qDebug()<<"error";
       QString temp = infix + "="+ QString::number(num);
       history_infix.push_back(temp);
       de_weight(history_infix);//去重
   //    for(int i = 0;i<history_infix.size();i++)
   //    {
   //        ui->text_history->append(history_infix.at(i));
   //    }
   //    ui->le_show->setText(QString::number(num));
       infix_copy = infix + "="+ QString::number(num);
       ui->le_show->setText(infix_copy);
       infix = QString::number(num);
}

void MainWindow::on_btn_sub_clicked()
{
    infix += "-";
    ui->le_show->setText(infix);
}

void MainWindow::on_btn_multiply_clicked()
{
    infix += "*";
    ui->le_show->setText(infix);
}

void MainWindow::on_btn_1_clicked()
{
    infix += "1";
    ui->le_show->setText(infix);
}

void MainWindow::on_btn_2_clicked()
{
    infix += "2";
    ui->le_show->setText(infix);
}

void MainWindow::on_btn_3_clicked()
{
    infix += "3";
    ui->le_show->setText(infix);
}

void MainWindow::on_btn_5_clicked()
{
    infix += "5";
    ui->le_show->setText(infix);
}

void MainWindow::on_btn_6_clicked()
{
    infix += "6";
    ui->le_show->setText(infix);
}

void MainWindow::on_btn_7_clicked()
{
    infix += "7";
    ui->le_show->setText(infix);
}

void MainWindow::on_btn_8_clicked()
{
    infix += "8";
    ui->le_show->setText(infix);
}

void MainWindow::on_btn_9_clicked()
{
    infix += "9";
    ui->le_show->setText(infix);
}

void MainWindow::on_btn_point_clicked()
{
    infix += ".";
    ui->le_show->setText(infix);
}

void MainWindow::on_btn_0_clicked()
{
    infix += "0";
    ui->le_show->setText(infix);
}

void MainWindow::on_btn_4_clicked()
{
    infix += "4";
    ui->le_show->setText(infix);
}

void MainWindow::on_btn_add_clicked()
{
    infix += "+";
    ui->le_show->setText(infix);
}

void MainWindow::on_btn_divide_clicked()
{
    infix += "/";
    ui->le_show->setText(infix);
}

void MainWindow::on_action_V_triggered()
{
    QClipboard *board = QApplication::clipboard();
    QString text = board->text();
    infix += text;
    ui->le_show->setText(infix);
}

//2.5*(6+1.2)^2
//2.67/0

void MainWindow::on_btn_qufan_clicked()
{
    infix += "!";
    ui->le_show->setText(infix);
}
