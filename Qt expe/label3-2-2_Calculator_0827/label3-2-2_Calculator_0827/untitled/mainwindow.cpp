#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include<QPushButton>
#include<map>
#include<stack>
#include<cmath>
#include<QtMath>
#include<QChar>
#include<QClipboard>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    waitForOperand=true;
    //构造函数自动调用
    connectSlots();
    setShortcutKeys();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isInt(QString str)
{
    bool isInt;
    str.toInt(&isInt);
    return isInt;
}

void MainWindow::abortOpreration()
{
    ui->lineEdit->setText("0");
    waitForOperand=true;
    QMessageBox::warning(this,"运算错误","除数不能为0");
}

void MainWindow::connectSlots()
{
    //都是数字信号，用范围for语句整体传信号
    QPushButton *digitBtns[10]={
      ui->digitBtn0,ui->digitBtn1,ui->digitBtn2,ui->digitBtn3,
      ui->digitBtn4,ui->digitBtn5,ui->digitBtn6,ui->digitBtn7,
      ui->digitBtn8,ui->digitBtn9
    };
   for(auto btn:digitBtns)
        connect(btn,&QPushButton::clicked,this,&MainWindow::digitClicked);

   QPushButton *operatorBtns[7]={
       ui->addBtn,ui->substactionBtn,ui->multiplicationBtn,ui->divisionBtn,
       ui->leftBracketBtn,ui->rightBracketBtn,ui->powBtn
   };
   for(auto btn: operatorBtns)
       connect(btn,&QPushButton::clicked,this,&MainWindow::operatorClicked);
}

void MainWindow::on_clearBtn_clicked()
{
    QString str=ui->lineEdit->text();
    if(str!="0")
    {
        ui->lineEdit->setText(str.left(str.count()-1));
    }
}

//槽的实现
void MainWindow::digitClicked()
{
    //多个信号对应一个槽函数
    QPushButton *digitBtn=static_cast<QPushButton*>(sender());//确认传信号对象
    QString value=digitBtn->text();//保存按钮数字
    if(ui->lineEdit->text()=="0"&&value=="0")
        return;
    if(waitForOperand)//保存多位数字
    {
        ui->lineEdit->setText(value);
        waitForOperand=false;
    }
    else
    {
        ui->lineEdit->setText(ui->lineEdit->text()+value);
    }
}

void MainWindow::on_ClearAllBtn_clicked()
{
    //将当前数据清零，并将之前保留数据运算清除
    ui->lineEdit->setText("0");
    //等待只有开始新式为true
    waitForOperand=true;
//    result=0.0;
//    pendingOperator.clear();
}

void MainWindow::on_equalBtn_clicked()
{
    double result=0.0;
    try
    {
        result=compute(inToPost(ui->lineEdit->text()));
    }
    catch(const char *er)
    {
        error=er;
        abortOpreration();
        return;
    }
    ui->lineEdit->setText(ui->lineEdit->text()+"="+QString::number(result));
    waitForOperand=true;
}

void MainWindow::on_signBtn_clicked()
{
    QString text=ui->lineEdit->text();
    QChar sign=text[text.size()-1];
    if(sign=='-')
    {
        text.remove(text.size()-1,1);
    }
    else
    {
        text.append('-');
    }
    ui->lineEdit->setText(text);
}

void MainWindow::operatorClicked()
{
    //多个信号一个槽函数
    QPushButton *clickedBtn=qobject_cast<QPushButton *>(sender());
    QString clickedOperator=clickedBtn->text();
    //double operand=ui->lineEdit->text().toDouble();
    if(waitForOperand)
    {
       if(clickedOperator=='(')
       {
           ui->lineEdit->setText(clickedOperator);
           waitForOperand=false;
       }
       else
       {
           ui->lineEdit->setText('0'+clickedOperator);
           waitForOperand=false;
       }
    }
    else
        ui->lineEdit->setText(ui->lineEdit->text()+clickedOperator);
}


void MainWindow::on_pointBtn_clicked()
{
    if(waitForOperand)
        ui->lineEdit->setText("0");
    ui->lineEdit->setText(ui->lineEdit->text()+".");
    waitForOperand=false;
}


//设置键盘快捷键
void MainWindow::setShortcutKeys()
{
    Qt::Key key[25]={
        Qt::Key_0, Qt::Key_1, Qt::Key_2, Qt::Key_3, Qt::Key_4,
        Qt::Key_5, Qt::Key_6, Qt::Key_7, Qt::Key_8, Qt::Key_9,
        Qt::Key_Plus, Qt::Key_Minus, Qt::Key_Asterisk, Qt::Key_Slash,
        Qt::Key_Return, Qt::Key_Period, Qt::Key_Backspace, Qt::Key_M,
        Qt::Key_ParenLeft, Qt::Key_ParenRight, Qt::Key_AsciiCircum,
        Qt::Key_L, Qt::Key_S, Qt::Key_C, Qt::Key_Exclam
    };

    QPushButton *btn[25]={
        ui->digitBtn0, ui->digitBtn1, ui->digitBtn2, ui->digitBtn3, ui->digitBtn4,
        ui->digitBtn5, ui->digitBtn6, ui->digitBtn7, ui->digitBtn8, ui->digitBtn9,
        ui->addBtn, ui->substactionBtn, ui->multiplicationBtn, ui->divisionBtn,
        ui->equalBtn, ui->pointBtn, ui->clearBtn, ui->signBtn,
        ui->leftBracketBtn, ui->rightBracketBtn, ui->powBtn,
        ui->lnBtn, ui->sinBtn, ui->cosBtn, ui->facBtn
    };

    //键盘事件响应，触发控件信号合起来
    for(int i=0;i<24;i++)
        btn[i]->setShortcut(QKeySequence(key[i]));
    ui->ClearAllBtn->setShortcut(QKeySequence("Ctrl+Backspace"));
}

QString MainWindow::inToPost(QString infix) throw(const char*)//逆波兰式
{
    std::stack<char> stack;
    char current=0; //读入的字符
    QString postfix;//后缀表达式
    std::map<char,int> priority;//运算符号优先级表
    priority['+']=0;
    priority['-']=0;
    priority['*']=1;
    priority['/']=1;
    priority['^']=2;
    priority['l']=3;
    priority['s']=3;
    priority['c']=3;
    priority['!']=3;

    for(int i=0;i<infix.length();++i)   //遍历中缀表达式
    {
        current=infix[i].toLatin1();    //ascii

        if(isdigit(current))    //数字直接加进表达式
        {
            postfix.push_back(current);
            continue;
        }

        switch(current)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            if(infix[i-1]!=')'&&infix[i-1]!='!'&&infix[i-1]!='i') //判断是数字，加#，标识数字输完
            {
                if(infix[i-1].isDigit())
                    postfix.push_back('#');
                else
                    throw "expression is illegality";
            }
            if(!stack.empty())  //判断运算符优先级
            {
                char tempTop=stack.top();   //栈顶符号
                while(tempTop!='('&&priority[current]<=priority[tempTop])   //优先级高就出栈
                {
                    stack.pop();
                    postfix.push_back(tempTop);
                    if(stack.empty())
                       break;
                    tempTop=stack.top();
                }

            }
            stack.push(current); //当前符号入栈
            break;
        case '.':
            postfix.push_back(current);
            break;
        case '%':
            postfix.push_back(current);
            break;
        case '(':
            stack.push(current);
            break;
        case ')':   //右括号说明前方数字输入完成
            if(infix[i-1].isDigit())
                postfix.push_back('#');
            char tempTop;
            tempTop=stack.top();
            while(tempTop!='(') //直到遇到左括号停止，括号里优先级高，出栈
            {
                stack.pop();
                postfix.push_back(tempTop);
                if(!stack.empty()){
                tempTop=stack.top();
                }
            }
            stack.pop();
            break;
        case 'l':
            if(i-1<0)
            {
                stack.push(current);
                i=i+1;
            }
            else
            {
                if(infix[i-1]!=')'&&!infix[i-1].isDigit())
                {
                    if(!stack.empty())
                    {
                        char tempTop=stack.top();
                        while(tempTop!='('&&priority[current]<=priority[tempTop])
                        {
                            stack.pop();
                            postfix.push_back(tempTop);
                            if(stack.empty())
                                break;
                            tempTop=stack.top();
                        }
                    }
                    stack.push(current);
                    i=i+1;
                }
            }
            break;
        case 's':
            if(i-1<0)
            {
                stack.push(current);
                i=i+2;
            }
            else
            {
                if(infix[i-1]!=')'&&!infix[i-1].isDigit())
                {
                    if(!stack.empty())
                    {
                        char tempTop=stack.top();
                        while(tempTop!='('&&priority[current]<=priority[tempTop])
                        {
                            stack.pop();
                            postfix.push_back(tempTop);
                            if(stack.empty())
                                break;
                            tempTop=stack.top();
                        }
                    }
                    stack.push(current);
                    i=i+2;
                }
                else
                  throw "expression is illegality";
            }
            break;
        case 'c':
            if(i-1<0)
            {
                stack.push(current);
                i=i+2;
            }
            else
            {
                if(infix[i-1]!=')'&&!infix[i-1].isDigit())
                {
                    if(!stack.empty())
                    {
                        char tempTop=stack.top();
                        while(tempTop!='('&&priority[current]<=priority[tempTop])
                        {
                            stack.pop();
                            postfix.push_back(tempTop);
                            if(stack.empty())
                                break;
                            tempTop=stack.top();
                        }
                    }
                    stack.push(current);
                    i=i+2;
                }
            }
            break;
        case '!':
            if(infix[i-1].isDigit())
                postfix.push_back('#');
            if(!stack.empty())
            {
                char tempTop=stack.top();
                while(tempTop!='('&&priority[current]<=priority[tempTop])   //优先级高就出栈
                {
                    stack.pop();
                    postfix.push_back(tempTop);
                    if(stack.empty())
                        break;
                    tempTop=stack.top();
                }
            }
            stack.push(current);
            break;
        case 'p':
           postfix.push_back(current);
           i=i+1;
           break;
        default:
            throw "expression has illegality character";
            break;
        }
    }
    if(infix[infix.size()-1]!=')')
    {
        if(infix[infix.size()-1].isDigit())
            postfix.push_back('#');
        else if(infix[infix.size()-1]!='!'&&infix[infix.size()-1]!='i')
            throw "expession is illegality";
    }
    while(!stack.empty())
    {
        char tempOut=stack.top();
        stack.pop();
        postfix.push_back(tempOut);
    }
    return postfix;
}

double MainWindow::compute(QString s) throw(const char*)
{
    std::stack<double> stack;
    QString str;
    QString s1;
    double curr;    //目前算的值

    double temNum1; //存储两数进行计算
    double temNum2;
    for(auto i=s.begin();i!=s.end();i++)
    {
        if((*i).isDigit())
        {
            str.push_back(*i);
            continue;
        }
        switch((*i).toLatin1())
        {
        case '+':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(temNum1+temNum2);
            break;
        case '-':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(temNum2-temNum1);
            break;
        case '*':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(temNum1*temNum2);
            break;
        case '/':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(temNum2/temNum1);
            break;
        case '^':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(pow(temNum2,temNum1));
            break;
        case '.':
            str.push_back(*i);
            break;
        case '#':
            curr=str.toDouble();
            str.clear();
            stack.push(curr);
            break;
        case '%':
            curr=stack.top();
            stack.pop();
            curr*=0.01;
            stack.push(curr);
            break;
        case 'l':
            curr=stack.top();
            stack.pop();
            curr=qLn(curr);
            stack.push(curr);
            break;
        case 's':
            curr=stack.top();
            stack.pop();
            curr=qSin(curr);
            stack.push(curr);
            break;
        case 'c':
            curr=stack.top();
            stack.pop();
            curr=qCos(curr);
            stack.push(curr);
            break;
        case '!':
            int t;
            curr=stack.top();
            s1=QString::number(curr);
            if(isInt(s1))
            {
                t=curr;
                curr=1;
                stack.pop();
                while(t>0)
                {
                    curr*=t;
                    t=t-1;
                }
                stack.push(curr);
            }
            else
                throw "expression has illegality character";
            break;
        case 'p':
            curr=acos(-1);
            stack.push(curr);
            break;
        default:
            throw "expression has illegality character";
            break;
        }
    }
    curr=stack.top();
    return curr;
}



void MainWindow::on_lnBtn_clicked()
{
    QString ln=ui->lnBtn->text();
    if(waitForOperand)
    {
        ui->lineEdit->setText(ln+'(');
        waitForOperand=false;
    }
    else
        ui->lineEdit->setText(ui->lineEdit->text()+ln+'(');
}


void MainWindow::on_action_triggered()
{
    QClipboard *board=QApplication::clipboard();
    QString text=board->text();
    ui->lineEdit->setText(text);
    waitForOperand=false;
}

void MainWindow::on_sinBtn_clicked()
{
    QString sin=ui->sinBtn->text();
    if(waitForOperand)
    {
        ui->lineEdit->setText(sin+'(');
        waitForOperand=false;
    }
    else
        ui->lineEdit->setText(ui->lineEdit->text()+sin+'(');
}

void MainWindow::on_cosBtn_clicked()
{
    QString cos=ui->cosBtn->text();
    if(waitForOperand)
    {
        ui->lineEdit->setText(cos+'(');
        waitForOperand=false;
    }
    else
        ui->lineEdit->setText(ui->lineEdit->text()+cos+'(');
}

void MainWindow::on_facBtn_clicked()
{
    if(!waitForOperand)
        ui->lineEdit->setText(ui->lineEdit->text()+'!');
}

void MainWindow::on_piBtn_clicked()
{
    QString pi=ui->piBtn->text();
    if(waitForOperand)
        ui->lineEdit->setText(pi);
    else
        ui->lineEdit->setText(ui->lineEdit->text()+pi);
    waitForOperand=false;
}
