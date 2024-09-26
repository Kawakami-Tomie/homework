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
#include<QTextBlock>
#include<QMainWindow>
#include "conversion.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCurrentText("0");
    waitForOperator=false; //是否等待下一个式子（换行后）

    on_action_3_triggered(false);

    //构造函数自动调用
    connectSlots();
    setShortcutKeys();

    //切换回计算器
    this->window=new conversion;
    connect(window,&conversion::goback,this,[=](){
        window->close();
        this->show();
    });

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
    setCurrentText("0");
    waitForOperator=true;
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

   QPushButton *operatorBtns[8]={
       ui->addBtn,ui->substactionBtn,ui->multiplicationBtn,ui->divisionBtn,
       ui->leftBracketBtn,ui->rightBracketBtn,ui->powBtn,ui->percentBtn
   };
   for(auto btn: operatorBtns)
       connect(btn,&QPushButton::clicked,this,&MainWindow::operatorClicked);

   QPushButton *specialOperatorBtns[5]={
       ui->sinBtn,ui->cosBtn,ui->tanBtn,ui->lnBtn,ui->lgBtn
   };
   for(auto btn:specialOperatorBtns)
       connect(btn,&QPushButton::clicked,this,&MainWindow::specialOperatorClicked);
}

void MainWindow::on_clearBtn_clicked()
{
    //将当前显示的数归零
    setCurrentText("0");
    waitForOperator=true;
}

//槽的实现
void MainWindow::digitClicked()
{
    //多个信号对应一个槽函数
    QPushButton *digitBtn=static_cast<QPushButton*>(sender());//确认传信号对象
    QString value=digitBtn->text();//保存按钮数字
    QString current=currentText();
    if(current=="0"&& value == "0")
        return;
    if(waitForOperator)
    {
        log.append(current+'\n');
        ui->textEdit->append(value);
        waitForOperator=false;
    }
    else    //保存多位数据
    {
        if(current!="0")
            setCurrentText(currentText()+value);
        else
            setCurrentText(value);
    }
}

void MainWindow::on_ClearAllBtn_clicked()
{
    //将当前数据清零，并将之前保留数据运算清除
    ui->textEdit->setText("0");
    waitForOperator=true;
}

void MainWindow::on_equalBtn_clicked()
{
    double result=0.0;
    try
    {
        result=compute(inToPost(currentText()));
    }
    catch(const char *er)
    {
        error=er;
        abortOpreration();
        return;
    }
    log.append(currentText()+'\n'); //记录式子
    ui->textEdit->append(QString::number(result)); //append自动换？
    waitForOperator=true; //等待下一个公式
}

void MainWindow::on_signBtn_clicked()
{
    QString text=currentText();
    QChar sign=text[text.size()-1];
    if(sign=='-')
    {
        text.remove(text.size()-1,1);
    }
    else
    {
        text.append('-');
    }
    setCurrentText(text);
}

void MainWindow::operatorClicked()
{
    //多个信号一个槽函数
    QPushButton *clickedBtn=qobject_cast<QPushButton *>(sender());
    QString clickedOperator=clickedBtn->text();
    if(clickedOperator=='('&&waitForOperator)
    {
        log.append(currentText()+'\n');
        ui->textEdit->append(clickedOperator);
        waitForOperator=false;
    }
    else
        setCurrentText(currentText()+clickedOperator);
    waitForOperator=false;
}


void MainWindow::on_pointBtn_clicked()
{
    if(waitForOperator)
        setCurrentText("0");
    setCurrentText(currentText()+".");
    waitForOperator=false;
}


//设置键盘快捷键
void MainWindow::setShortcutKeys()
{
    Qt::Key key[27]={
        Qt::Key_0, Qt::Key_1, Qt::Key_2, Qt::Key_3, Qt::Key_4,
        Qt::Key_5, Qt::Key_6, Qt::Key_7, Qt::Key_8, Qt::Key_9,
        Qt::Key_Plus, Qt::Key_Minus, Qt::Key_Asterisk, Qt::Key_Slash,
        Qt::Key_Return, Qt::Key_Period, Qt::Key_Backspace, Qt::Key_M,
        Qt::Key_ParenLeft, Qt::Key_ParenRight, Qt::Key_AsciiCircum, Qt::Key_Percent,
        Qt::Key_S, Qt::Key_C, Qt::Key_T, Qt::Key_N, Qt::Key_G
    };

    QPushButton *btn[27]={
        ui->digitBtn0, ui->digitBtn1, ui->digitBtn2, ui->digitBtn3, ui->digitBtn4,
        ui->digitBtn5, ui->digitBtn6, ui->digitBtn7, ui->digitBtn8, ui->digitBtn9,
        ui->addBtn, ui->substactionBtn, ui->multiplicationBtn, ui->divisionBtn,
        ui->equalBtn, ui->pointBtn, ui->clearBtn, ui->signBtn,
        ui->leftBracketBtn, ui->rightBracketBtn, ui->powBtn, ui->percentBtn,
        ui->sinBtn, ui->cosBtn, ui->tanBtn, ui->lnBtn, ui->lgBtn
    };

    //键盘事件响应，触发控件信号合起来
    for(int i=0;i<27;i++)
        btn[i]->setShortcut(QKeySequence(key[i]));
    ui->ClearAllBtn->setShortcut(QKeySequence("Ctrl+Backspace"));
}

void MainWindow::specialOperatorClicked()
{
    QPushButton *specialOperatorBtn=static_cast<QPushButton*>(sender());
    QString value=specialOperatorBtn->text();
    QString current=currentText();
    if(waitForOperator)
    {
        log.append(current+'\n'); //等号，清除后，等待下一个式子,历史记录换行
        ui->textEdit->append(value);
        waitForOperator=false;
    }
    else
    {
        if(current!="0")
            setCurrentText(current+value);
        else
            setCurrentText(value);
    }
}

QString MainWindow::currentText() //得到当前最后一行文本
{
    QTextDocument *document=ui->textEdit->document();
    QTextBlock block=document->lastBlock(); //最后一个文本块
    return block.text();
}

void MainWindow::setCurrentText(QString text) //设置最后一行文本
{
    QString allText=ui->textEdit->toPlainText();
    int pos=allText.lastIndexOf('\n'); //找到最后一个换行
    if(pos>=0)
        allText.replace(allText.lastIndexOf('\n')+1,allText.size(),text); //test放最后一行
    else
        allText=text;
    ui->textEdit->setText(allText);
}

QString MainWindow::inToPost(QString infix) noexcept//逆波兰式
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
    priority['s']=3;
    priority['c']=3;
    priority['t']=3;
    priority['n']=3;
    priority['g']=3;
    priority['%']=3;

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
        case '%':
            if(infix[i-1]!=')') //判断是数字，加#，标识数字输完
            {
                if(infix[i-1].isDigit())
                    postfix.push_back('#');
                else if(infix[i-1]=='%')
                    infix.begin();  //什么也不做，跳出
                else
                    throw "expression is illegality";
            }
            if(!stack.empty())  //判断运算符优先级
            {
                char tempTop=stack.top();   //栈顶符号
                while(tempTop!='('&&priority[current]<priority[tempTop])   //优先级高就出栈
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
        case 's':
        case 'c':
        case 't':
            if(i>0 && infix[i-1].isDigit())
                throw "表达式非法";
            if(!stack.empty())
            {
                char tempTop=stack.top();
                while (tempTop!='('&&priority[current]<priority[tempTop])
                {
                    stack.pop();
                    postfix.push_back(tempTop);
                    if(stack.empty())
                        break;
                    tempTop=stack.top();
                }
            }
            stack.push(current);
            i+=2;
            break;
        case 'l':
            if(i>0&&infix[i-1].isDigit())
                throw "表达式非法";
            if(!stack.empty())
            {
                char tempTop=stack.top();
                while (tempTop!='('&&priority[infix[i+1].toLatin1()]<priority[tempTop])
                {
                    stack.pop();
                    postfix.push_back(tempTop);
                    if(stack.empty())
                        break;
                    tempTop=stack.top();
                }
            }
            stack.push(infix[i+1].toLatin1());
            i++;
            break;
        case '.':
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
        default:
            throw "expression has illegality character";
            break;
        }
    }
    if(infix[infix.size()-1]!=')')
    {
        if(infix[infix.size()-1].isDigit())
            postfix.push_back('#');
        else if(infix[infix.size()-1]=='%')
            infix.begin();
        else
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

double MainWindow::compute(QString s) noexcept
{
    const double PI=std::acos(-1);
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
        case 's':
            temNum1=stack.top();
            stack.pop();
            stack.push(std::sin(temNum1/180.0*PI));
            break;
        case 'c':
            temNum1=stack.top();
            stack.pop();
            stack.push(std::cos(temNum1/180.0*PI));
            break;
        case 't':
            temNum1=stack.top();
            stack.pop();
            stack.push(std::tan(temNum1/180.0*PI));
            break;
        case 'n':
            temNum1=stack.top();
            stack.pop();
            stack.push(std::log(temNum1));
            break;
        case 'g':
            temNum1=stack.top();
            stack.pop();
            stack.push(std::log10(temNum1));
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
        default:
            throw "expression has illegality character";
            break;
        }
    }
    curr=stack.top();
    return curr;
}



void MainWindow::on_action_triggered()
{
    ui->textEdit->setText(log);
    setCurrentText("0");
    waitForOperator=false;
}



void MainWindow::on_action_2_triggered()
{
    log.clear();
}

void MainWindow::on_action_Ctrl_V_triggered()
{
    QClipboard *board=QApplication::clipboard();
    QString text=board->text();
    ui->textEdit->append(text);
}

void MainWindow::on_action_3_triggered(bool checked)//科学计算器转换
{
    if(checked)
    {
        ui->percentBtn->show();
        ui->sinBtn->show();
        ui->cosBtn->show();
        ui->tanBtn->show();
        ui->lnBtn->show();
        ui->lgBtn->show();
    }
    else
    {
        ui->percentBtn->hide();
        ui->sinBtn->hide();
        ui->cosBtn->hide();
        ui->tanBtn->hide();
        ui->lnBtn->hide();
        ui->lgBtn->hide();
    }
}

void MainWindow::on_action_4_triggered()
{
    this->hide();
    window->show();
}



