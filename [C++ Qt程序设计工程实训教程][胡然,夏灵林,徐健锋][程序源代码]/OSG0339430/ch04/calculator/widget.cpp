#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QDebug>
#include <map>
#include <stack>
#include <cmath>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    initUi();
    waitForOperand = true;
    connectSlots();
    setShortcutKeys();
}

Widget::~Widget()
{
    delete ui;
}



void Widget::abortOperation()
{
    ui->lineEdit->setText("0");
    waitForOperand = true;
    QMessageBox::warning(this, "运算错误", error);
}

void Widget::digitClicked()
{
    QPushButton *digitBtn = static_cast<QPushButton*>(sender());
    QString value = digitBtn->text();
    if(ui->lineEdit->text() == "0" && value == "0")
        return;
    if(waitForOperand)
    {
        ui->lineEdit->setText(value);
        waitForOperand = false;
    }
    else
    {
        ui->lineEdit->setText(ui->lineEdit->text() + value);
    }
}

void Widget::on_clearBtn_clicked()
{
    //去掉末尾字符
    QString str = ui->lineEdit->text();
    if (str != "0")
    {
        ui->lineEdit->setText(str.left(str.count() - 1));
    }
}

void Widget::on_clearAllBtn_clicked()
{
    //将当前显示的数据归零，并将之前保存的数据运算清除
    ui->lineEdit->setText("0");
    waitForOperand = true;
}

void Widget::on_equalBtn_clicked()
{
    double result = 0.0;
    try
    {
        result = compute(inToPost(ui->lineEdit->text()));
    }
    catch(const char *er)
    {
        error = er;
        abortOperation();
        return;
    }
    ui->lineEdit->setText(ui->lineEdit->text() + '=' + QString::number(result));
    waitForOperand = true;
}

void Widget::on_signBtn_clicked()
{
    QString text = ui->lineEdit->text();
    QChar sign = text[text.size() - 1];
    if(sign == '-')
    {
        text.remove(text.size() - 1, 1);
    }
    else
    {
        text.append('-');
    }
    ui->lineEdit->setText(text);
}

void Widget::operatorClicked()
{
    QPushButton *clickedBtn = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedBtn->text();
    if (waitForOperand)
    {
        ui->lineEdit->setText(clickedOperator);
        waitForOperand = false;
    }
    else
        ui->lineEdit->setText(ui->lineEdit->text() + clickedOperator);
}

void Widget::on_pointBtn_clicked()
{
    if (waitForOperand)
        ui->lineEdit->setText("0");
    ui->lineEdit->setText(ui->lineEdit->text() + ".");
    waitForOperand = false;
}

QString Widget::inToPost(QString infix) throw(const char*)
{
    std::stack<char> stack;
    char current = 0;//读入的字符
    QString postfix;//写入后缀表达式的字符串

    std::map<char,int> priority;//运算符号优先级表
    priority['+'] = 0;
    priority['-'] = 0;
    priority['*'] = 1;
    priority['/'] = 1;
    priority['^'] = 2;

    for(int i = 0; i < infix.length() ;++i)//逐个读取中缀表达式字符串中的字符
    {
        current =infix[i].toLatin1();
        if(isdigit(current))//如果是数字直接输出
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
            //postfix.push_back('#');
            if(i > 0)    //如果运算符的前一项不是右括号则说明前一个数字输入完毕，用#标识前面几个字符组成一个数字
             {
                if (infix[i-1] != ')')
                    postfix.push_back('#');
                /*if(infix[i-1].isDigit())
                    postfix.push_back('#');
                else
                    throw "expression is illegality";*/
            }
            else
                postfix.push_back('#');
            if(!stack.empty())//比较目前符号与栈顶符号优先级，低于则出栈，并输出字符串
            {
                char tempTop=stack.top();
                while(tempTop != '(' && priority[current]<=priority[tempTop])
                {
                    stack.pop();
                    postfix.push_back(tempTop);
                    if(stack.empty())
                        break;
                    tempTop=stack.top();
                }
            }
            stack.push(current);//符号全部出栈或者遇到了'('或者大于栈顶符号的优先级，将新符号压入栈中
            break;
        case '.':
            postfix.push_back(current);
            break;
        case '%':
            postfix.push_back(current);
            break;
        case '(':
            stack.push(current);//左括号直接入栈
            break;
        case ')':
            postfix.push_back('#');//右括号说明前方数字输入完成，标识一下
            char tempTop;
            tempTop=stack.top();
            while(tempTop !='(')//直到栈顶元素是左括号才停止循环
            {
                stack.pop();
                postfix.push_back(tempTop);
                tempTop=stack.top();
            }
            stack.pop();
            break;
        default:
            throw "expression has illegality character";
            break;
        }
    }
    if(infix[infix.size()-1] != ')')
    {
        if(infix[infix.size()-1].isDigit())
            postfix.push_back('#');
        else
            throw "expression is illegality";
    }
    while(!stack.empty())
    {
        char tempOut=stack.top();
        stack.pop();
        postfix.push_back(tempOut);
    }
    return postfix;
}

double Widget::compute(QString s) throw(const char*)
{
    std::stack<double> stack;
    QString str;
    double curr;

    double  temNum1;
    double  temNum2;
    for(auto i = s.begin();i != s.end(); i++)
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
            stack.push(temNum2 + temNum1);
            break;
        case '-':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(temNum2 - temNum1);
            break;
        case '*':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(temNum2 * temNum1);
            break;
        case '/':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(temNum2 / temNum1);
            break;
        case '^':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(pow(temNum2, temNum1));
            break;
        case '.':
            str.push_back(*i);
            break;
        case '#':
            curr =str.toDouble();//字符串转换为浮点型
            str.clear();
            stack.push(curr);
            break;
        case '%':
            curr = stack.top();
            stack.pop();
            curr*=0.01;
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

void Widget::initUi()
{
    ui->setupUi(this);
    ui->lineEdit->setText("0");
    setWindowFlags(windowFlags() & ~(Qt::WindowMaximizeButtonHint));
}

void Widget::connectSlots()
{
    QPushButton *digitBtns[10] = {
        ui->digitBtn0,      ui->digitBtn1,          ui->digitBtn2,          ui->digitBtn3,
        ui->digitBtn4,      ui->digitBtn5,          ui->digitBtn6,          ui->digitBtn7,
        ui->digitBtn8,      ui->digitBtn9
    };
    for (auto btn : digitBtns)
        connect(btn, &QPushButton::clicked, this, &Widget::digitClicked);
    QPushButton *operatorBtns[7] = {
        ui->addBtn,         ui->subtractionBtn,     ui->multiplicationBtn,  ui->divisionBtn,
        ui->leftBracketBtn, ui->rightBracketBtn,    ui->powBtn
    };
    for (auto btn : operatorBtns)
        connect(btn, &QPushButton::clicked, this, &Widget::operatorClicked);
}

void Widget::setShortcutKeys()
{

    Qt::Key key[21] = {
        Qt::Key_0,          Qt::Key_1,          Qt::Key_2,          Qt::Key_3,
        Qt::Key_4,          Qt::Key_5,          Qt::Key_6,          Qt::Key_7,
        Qt::Key_8,          Qt::Key_9,
        Qt::Key_Plus,       Qt::Key_Minus,      Qt::Key_Asterisk,   Qt::Key_Slash,
        Qt::Key_Enter,      Qt::Key_Period,     Qt::Key_Backspace,  Qt::Key_M,
        Qt::Key_ParenLeft,  Qt::Key_ParenRight, Qt::Key_AsciiCircum
    };
    QPushButton *btn[21] = {
        ui->digitBtn0,      ui->digitBtn1,          ui->digitBtn2,          ui->digitBtn3,
        ui->digitBtn4,      ui->digitBtn5,          ui->digitBtn6,          ui->digitBtn7,
        ui->digitBtn8,      ui->digitBtn9,
        ui->addBtn,         ui->subtractionBtn,     ui->multiplicationBtn,  ui->divisionBtn,
        ui->equalBtn,       ui->pointBtn,           ui->clearBtn,           ui->signBtn,
        ui->leftBracketBtn, ui->rightBracketBtn,    ui->powBtn
    };
    for (int i = 0; i < 21; i++)
        btn[i]->setShortcut(QKeySequence(key[i]));
    ui->clearAllBtn->setShortcut(QKeySequence("Ctrl+Backspace"));
}
