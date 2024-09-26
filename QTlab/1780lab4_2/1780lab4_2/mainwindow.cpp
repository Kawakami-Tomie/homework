#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QKeyEvent>
#include <map>
#include <stack>
#include <cmath>
#include <QClipboard>
#include <QtMath>
#include <QTextBlock>
#include <QRadioButton>


MainWindow::MainWindow(QMainWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   setCurrentText("0");
   waitForOperator=false;
   on_action_4_triggered(false);
   on_action_5_triggered(false);
   //radio_2->setChecked(false);
   connectSlots();
   setShortcutKeys();


   //ui->setupUi(this);
  // this->setWindowTitle("进制转换器");
   //this->setFixedSize(QSize(this->width(),this->height()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::abortOPeration()
{
   setCurrentText("0");
   waitForOperator=true;
   statusBar()->showMessage(error,4000);
}

void MainWindow::connectSlots()
{
    QPushButton *digitBtns[10] = {
        ui->digitBtn0,ui->digitBtn1,ui->digitBtn2,ui->digitBtn3,
        ui->digitBtn4,ui->digitBtn5,ui->digitBtn6,ui->digitBtn7,
        ui->digitBtn8,ui->digitBtn9
    };
    for(auto btn:digitBtns)
        connect(btn,&QPushButton::clicked,this,&MainWindow::digitClicked);
    QPushButton *operatorBtns[9] = {
        ui->addBtn,ui->subtractionBtn,ui->multiplicationBtn,
        ui->divisionBtn, ui->leftBracketBtn,ui->rightBracketBtn,
        ui->powBtn,ui->percentBtn
    };
    for(auto btn:operatorBtns)
         connect(btn,&QPushButton::clicked,this,&MainWindow::operatorClicked);
    QPushButton *specialOperatorBtns[7]={
        ui->sinBtn,ui->cosBtn,ui->tanBtn,ui->lnBtn,ui->lgBtn,ui->genhaoBtn,ui->levelBtn
    };
    for(auto btn:specialOperatorBtns)
        connect(btn,&QPushButton::clicked,this,&MainWindow::specialOperatorClicked);
}

void MainWindow::digitClicked()
{
   QPushButton *digitBtn=static_cast<QPushButton*>(sender());
   QString value=digitBtn->text();
   QString current=currentText();
   if(current=="0"&&value=="0")
       return;
   if(waitForOperator)
   {
       log.append(current+'\n');
       ui->textEdit->append(value);
       ui->textEdit->moveCursor(QTextCursor::End);
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

void MainWindow::on_clearBtn_clicked()
{
    //将当前显示的数归零
    setCurrentText("0");
    waitForOperator=true;
}

void MainWindow::on_clearAllBtn_clicked()
{
    //将当前显示的数据归零，并将之前保存的数据运算清除
    ui->textEdit->setText("0");
    waitForOperator = true;
}

void MainWindow::on_equalBtn_clicked()
{
    double result=0.0;
    try
    {
        result=compute(inToPost(currentText()));
    }
    catch (const char *er)
    {
        error=er;
        abortOPeration();
        return;
    }
    log.append(currentText()+'\n');
    ui->textEdit->append(QString::number(result));
    ui->textEdit->moveCursor(QTextCursor::End);
    waitForOperator=true;
}

void MainWindow::on_signBtn_clicked()
{
//    QString text = currentText();
//    QChar sign=text[text.size()-1];
//    if(sign=='-')
//    {
//        text.remove(text.size()-1,1);
//    }
//    else
//    {
//        text.append('-');
//    }
//    setCurrentText(text);
    QString current = currentText();
    if (waitForOperator)
    {
        log.append(current + '\n');
        ui->textEdit->append("-");
        ui->textEdit->moveCursor(QTextCursor::End);
        waitForOperator = false;
    }
    else
    {
        if (current[0] == '-')
            current[0] = '+';
        else
            current[0] = '-';
        setCurrentText(current);
    }

}

void MainWindow::operatorClicked()
{
    QPushButton *clickedBtn = qobject_cast<QPushButton*>(sender());
    QString clickedOperator = clickedBtn->text();
   setCurrentText(currentText()+clickedOperator);
   waitForOperator=false;
}

void MainWindow::on_pointBtn_clicked()
{
    if(waitForOperator)
        setCurrentText("0");
    setCurrentText(currentText()+'.');
    waitForOperator=false;
}

QString MainWindow::currentText()
{
    QTextDocument *document=ui->textEdit->document();
    QTextBlock block=document->lastBlock();
    return block.text();
}

void MainWindow::setCurrentText(QString text)
{
    QString allText=ui->textEdit->toPlainText();
    int pos=allText.lastIndexOf('\n');
    if(pos>=0)
        allText.replace(allText.lastIndexOf('\n')+1,allText.size(),text);
    else
        allText=text;
    ui->textEdit->setText(allText);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_0:
        emit ui->digitBtn0->clicked();
        break;
    case Qt::Key_1:
        emit ui->digitBtn1->clicked();
        break;
    case Qt::Key_2:
        emit ui->digitBtn2->clicked();
        break;
    case Qt::Key_3:
        emit ui->digitBtn3->clicked();
        break;
    case Qt::Key_4:
        emit ui->digitBtn4->clicked();
        break;
    case Qt::Key_5:
        emit ui->digitBtn5->clicked();
        break;
    case Qt::Key_6:
        emit ui->digitBtn6->clicked();
        break;
    case Qt::Key_7:
        emit ui->digitBtn7->clicked();
        break;
    case Qt::Key_8:
        emit ui->digitBtn8->clicked();
        break;
    case Qt::Key_9:
        emit ui->digitBtn9->clicked();
        break;
    case Qt::Key_Plus:
        emit ui->addBtn->clicked();
        break;
    case Qt::Key_Minus:
        emit ui->subtractionBtn->clicked();
        break;
    case Qt::Key_Asterisk:
        emit ui->multiplicationBtn->clicked();
        break;
    case Qt::Key_Slash:
        emit ui->divisionBtn->clicked();
        break;
    //case Qt::Key_Exclam:
      // emit ui->factorialBtn->clicked();
       // break;
    case Qt::Key_AsciiCircum:
        emit ui->powBtn->clicked();
        break;
    case Qt::Key_Enter:
    case Qt::Key_Equal:
        emit ui->equalBtn->clicked();
        break;
    case Qt::Key_Period:
        emit ui->pointBtn->clicked();
        break;
    case Qt::Key_M:
        emit ui->signBtn->clicked();
        break;
    case Qt::Key_S:
        emit ui->sinBtn->clicked();
        break;
    case Qt::Key_C:
        emit ui->cosBtn->clicked();
        break;
    case Qt::Key_Q:
        emit ui->levelBtn->clicked();
        break;
    case Qt::Key_R:
        emit ui->genhaoBtn->clicked();
        break;
    case Qt::Key_Backspace:
        if(event->modifiers()==Qt::ControlModifier)
        {
            emit ui->clearAllBtn->clicked();
        }
        else
        {
            emit ui->clearBtn->clicked();
        }
        break;
    default:
        break;
    }
}

void MainWindow::setShortcutKeys()
{
    Qt::Key key[29] = {
        Qt::Key_0,  Qt::Key_1,  Qt::Key_2,  Qt::Key_3,
        Qt::Key_4,  Qt::Key_5,  Qt::Key_6,  Qt::Key_7,
        Qt::Key_8,  Qt::Key_9,
        Qt::Key_Plus,  Qt::Key_Minus,  Qt::Key_Asterisk,  Qt::Key_Slash,
        Qt::Key_Enter, Qt::Key_Period, Qt::Key_Backspace, Qt::Key_M,
        Qt::Key_ParenLeft,Qt::Key_ParenRight,Qt::Key_AsciiCircum,
        Qt::Key_Percent,Qt::Key_S,Qt::Key_C,
        Qt::Key_T,Qt::Key_N,Qt::Key_G,Qt::Key_Q,Qt::Key_R
    };
    QPushButton *btn[29]={
        ui->digitBtn0,  ui->digitBtn1,  ui->digitBtn2,  ui->digitBtn3,
        ui->digitBtn4,  ui->digitBtn5,  ui->digitBtn6,  ui->digitBtn7,
        ui->digitBtn8,  ui->digitBtn9,
        ui->addBtn, ui->subtractionBtn, ui->multiplicationBtn, ui->divisionBtn,
        ui->equalBtn, ui->pointBtn, ui->clearBtn,ui->signBtn,
        ui->leftBracketBtn,ui->rightBracketBtn,ui->powBtn,
        ui->percentBtn,ui->sinBtn,ui->cosBtn,ui->tanBtn,ui->lnBtn,ui->lgBtn,ui->levelBtn,ui->genhaoBtn
    };
    for(int i=0;i<29;i++)
        btn[i]->setShortcut(QKeySequence(key[i]));
    ui->clearAllBtn->setShortcut(QKeySequence("Ctrl+Backspace"));
}

//void MainWindow::InitUi()
//{
//    ui->setupUi(this);
//    ui->lineEdit->setText("0");
//    setWindowFlags(windowFlags()&~(Qt::WindowMaximizeButtonHint));
//}

QString MainWindow::inToPost(QString infix) noexcept
{
    std::stack<char> stack;
    char current=0;//读入的字符
    QString postfix;//写入后缀表达式的字符串

    std::map<char,int>priority;//运算符号优先级表
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
    priority['!']=3;
    priority['r']=3;
    //priority['|']=3;

    for(int i=0;i<infix.length();++i)//逐个读取中缀表达式字符串中的字符
    {
        current=infix[i].toLatin1();
        if(isdigit(current))//如果是数字直接输出
        {
            postfix.push_back(current);
            continue;
        }
        switch (current)
        {
          case '+':
          case '-':
          case '*':
          case '/':
          case '^':
          case '%':
            if(infix[i-1]!=')')//如果运算符的前一项不是右括号则说明前一个数字输入完毕，用#标识前面几个字符组成一个数字
            {
                if(infix[i-1].isDigit())
                    postfix.push_back('#');
                else if(infix[i-1]=='%')
                    infix.begin();
                else
                    throw "表达式非法";
            }
            if(!stack.empty())//比较目前符号与栈顶符号优先级，低于则出栈，并输出字符串
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
            stack.push(current);//符号全部出栈或者遇到了'('或者大于栈顶符号的优先级，将新符号压入栈中
            break;
        case 's':
        case 'c':
        case 't':

            if(i>0&&infix[i-1].isDigit())
                throw "表达式非法";
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
            i+=2;
            break;
        case 'l':
            if(i>0&&infix[i-1].isDigit())
                throw"表达式非法";
            if(!stack.empty())//比较目前符号与栈顶符号优先级，低于则出栈，并输出字符串
            {
                char tempTop=stack.top();
                while(tempTop!='('&&priority[infix[i+1].toLatin1()]<=priority[tempTop])
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
        case 'r':
            if(i>0&&infix[i-1].isDigit())
                throw "表达式非法";
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
            i+=3;
            break;
        case '!':
            if(i>0&&infix[i-1].isDigit())
                postfix.push_back('#');
            if(!stack.empty())//比较目前符号与栈顶符号优先级，低于则出栈，并输出字符串
            {
                char tempTop=stack.top();
                while(tempTop!='('&&priority[infix[i+1].toLatin1()]<=priority[tempTop])
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
        case '.':
            postfix.push_back(current);
            break;
        case '(':
            stack.push(current);//左括号直接入栈
            break;
        case ')':
            if(infix[i-1].isDigit())
               postfix.push_back('#');
            char tempTop;
            tempTop=stack.top();
            while(tempTop!='(')
            {
                stack.pop();
                postfix.push_back(tempTop);
                tempTop=stack.top();
            }
            stack.pop();
            break;
        default:
            throw "表达式中含有非法字符";
            break;
        }
    }
    if(infix[infix.size()-1]!=')')
    {
        if(infix[infix.size()-1].isDigit())
            postfix.push_back("#");
        else if(infix[infix.size()-1]=='%')
            infix.begin();
        else if(infix[infix.size()-1]!='!')
            throw "表达式非法";
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

    const double PI=std::acos(-1.0);
    std::stack<double> stack;
    QString str;
    double curr;

    double temNum1;
    double temNum2;
    for(auto i=s.begin();i!=s.end();i++)
    {
        if((*i).isDigit())
        {
            str.push_back(*i);
            continue;
        }
        switch ((*i).toLatin1())
        {
        case '+':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(temNum2+temNum1);
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
            stack.push(temNum2*temNum1);
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
            stack.push(qSin(temNum1/180.0*PI));
            break;
        case 'c':
            temNum1=stack.top();
            stack.pop();
            stack.push(qCos(temNum1/180.0*PI));
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
        case 'r':
            temNum1=stack.top();
            stack.pop();
            stack.push(std::sqrt(temNum1));
        case '.':
            str.push_back(*i);
            break;
        case '#':
            curr=str.toDouble();//字符串转换为浮点型
            str.clear();
            stack.push(curr);
            break;
        case '%':
            curr=stack.top();
            stack.pop();
            curr*=0.01;
            stack.push(curr);
            break;
        case '!':
            int t;
            t=stack.top();
            curr=1;
            stack.pop();
            while(t>0)
            {
              curr*=t;
              t=t-1;
            }
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
    QClipboard *board=QApplication::clipboard();
    QString text=board->text();
    setCurrentText(text);
}



void MainWindow::on_action_2_triggered()
{
    ui->textEdit->setText(log);
    setCurrentText("0");
    waitForOperator=false;
}



void MainWindow::on_action_3_triggered()
{
    log.clear();
}



void MainWindow::on_action_4_triggered(bool checked)
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

void MainWindow::specialOperatorClicked()
{
    QPushButton *specialOperatorBtn=static_cast<QPushButton*>(sender());
    QString value=specialOperatorBtn->text();
    QString current=currentText();
    if(waitForOperator)
    {
        log.append(current+'\n');
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




    void MainWindow::two_transition(QString texts) //二进制
    {
        QStack<int> stack;
        QQueue<int> queue;
        QString text = texts; //整数部分
        QString f_text; //小数部分
        if(is_float)//如果是小数，整数部分和小数部分分开计算
        {
            text = texts.section(".",0,0);
            f_text = texts.section(".",1,1);
        }

      //转二进制
        QString text2 = text;
        if(is_minus)
            text2 = "-"+text2;
        if(is_float)
            text2 = text2 + "."+ f_text;
        text2 = delete_zero(text2);
        ui->le_2->setText(text2);

      //转八进制
        QString text_clone = text; //拷贝
        int len = text_clone.length();
       while(len)
       {
           if(len<3)//若当前位数小于3位，则补0
           {
               while(len!=3)
               {
                   text_clone = "0" + text_clone;
                   len = text_clone.length();
               }
           }
           QString temp = text_clone.mid(len-3,3);
           int tem_len = temp.length();
           int num = twoToeight(temp);
           stack.push(num); //入栈
          text_clone.remove(len-tem_len,tem_len);//更新字符串
          len = text_clone.length();
       }
       QString num8;//整数部分
       QString f_num8;//小数部分
       while(!stack.empty())
       {
           QString str = QString::number(stack.pop());
           num8 += str;
       }
       if(is_float) //处理小数
       {
           QString f_text_clone = f_text;//拷贝
           int len = f_text_clone.length();
           if(len<3) //长度小于3后位补0
           {
               while(len!=3)
               {
                    f_text_clone += "0";
                    len = f_text_clone.length();
               }

           }
           while(len)
           {
               QString temp = f_text_clone.mid(0,3);
               if(temp.length()<3)
               {
                   while(temp.length()!=3)
                   {
                       temp += "0";
                   }

               }
               int res = twoToeight(temp);
               queue.enqueue(res);
               f_text_clone.remove(0,3);
               len =  f_text_clone.length();
           }
           while(!queue.empty())
           {
               QString ret = QString::number(queue.dequeue());//出队
               f_num8 += ret;
           }
       }
       if(is_minus)
        num8 = "-"+num8;
       if(is_float)
        num8 = num8 + "." +f_num8;
       num8 = delete_zero(num8);
       ui->le_8->setText(num8);
       //转十进制
       QString text_clone1 = text; //拷贝
       int sum = 0;
       double f_sum = 0; //小数部分和
       int len1 = text_clone1.length();
       for(int i = len1 - 1,k = 0;i>=0;i--,k++)
       {
           QString n = text_clone1.at(i);
           int num = n.toInt();
           int p = num * qPow(2,k);
           sum = sum + p;
       }
       if(is_float) //处理小数
       {
           QString f_text_clone = f_text;//拷贝
           int len = f_text_clone.length();
           for(int i = 0,k = -1;i<len;i++,k--)
           {
               QString num = f_text_clone.at(i);
               double ret = num.toDouble();
               double df = ret * qPow(2,k);
               f_sum+=df;
           }
           //去除头部的0.
           QString t_f_sum = QString::number(f_sum).section(".",1,1);
           f_sum = t_f_sum.toDouble();
       }
       QString temp_sum = QString::number(sum);
       if(is_minus)
       temp_sum = "-" + temp_sum;
       if(is_float)
       temp_sum = temp_sum + "." + QString::number(f_sum);
       temp_sum = delete_zero(temp_sum);
       ui->le_10->setText(temp_sum);
       //转十六进制
       QString text_clone2 = text; //拷贝
       int len2 = text_clone2.length();
      while(len2)
      {
          if(len2<4)//若当前位数小于4位，则补0
          {
              while(len2!=4)
              {
                  text_clone2 = "0" + text_clone2;
                  len2 = text_clone2.length();
              }
          }
          QString temp = text_clone2.mid(len2-4,4);
          int tem_len = temp.length();
          int num = twoTosixteen(temp);
          stack.push(num); //入栈
         text_clone2.remove(len2-tem_len,tem_len);//更新字符串
         len2 = text_clone2.length();
      }
      QString num16;
      QString f_num16;
      while(!stack.empty())
      {
          QString n = QString::number(stack.pop());
          if(n=="10")
          num16 += "A";
          else if(n=="11")
          num16 += "B";
          else if(n=="12")
          num16 += "C";
          else if(n=="13")
          num16 += "D";
          else if(n=="14")
          num16 += "E";
          else if(n=="15")
          num16 += "F";
          else
          num16 += n;
      }
      if(is_float)//处理小数部分
      {
          QString f_text_clone = f_text;//拷贝
          int len = f_text_clone.length();
          if(len<4) //长度小于4后位补0
          {
              while(len!=4)
              {
                   f_text_clone += "0";
                   len = f_text_clone.length();
              }

          }
          while(len)
          {
              QString temp = f_text_clone.mid(0,4);
              if(temp.length()<4)
              {
                  while(temp.length()!=4)
                  {
                      temp += "0";
                  }

              }
              int res = twoTosixteen(temp);
              queue.enqueue(res);
              f_text_clone.remove(0,4);
              len =  f_text_clone.length();
          }
          while(!queue.empty())
          {

              QString ret = QString::number(queue.dequeue());//出队
              if(ret=="10")
              f_num16 += "A";
              else if(ret=="11")
              f_num16 += "B";
              else if(ret=="12")
              f_num16 += "C";
              else if(ret=="13")
              f_num16 += "D";
              else if(ret=="14")
              f_num16 += "E";
              else if(ret=="15")
              f_num16 += "F";
              else
              f_num16 += ret;
          }
      }
       if(is_minus)
       num16 = "-"+num16;
       if(is_float)
       num16 = num16 + "." + f_num16;
       num16 = delete_zero(num16);
      ui->le_16->setText(num16);
    }

    void MainWindow::eight_transition(QString texts)//八进制
    {
        QStack<int> stack;
        QQueue<int> queue;
        QString text = texts;
        QString f_text; //小数部分
        if(is_float)//如果是小数，整数部分和小数部分分开计算
        {
            text = texts.section(".",0,0);
            f_text = texts.section(".",1,1);
        }
       //转二进制
        QStack<QString> qstr_stack;
        QString text_clone = text; //拷贝
        int len = text_clone.length();
        for(int i = len - 1;i>=0;i--)
        {
            QString str = text_clone.at(i);
            int num = str.toInt();
            QString res = eightTotwo(num);
            qstr_stack.push(res);
        }
        QString num2;
        QString f_num2;
        while(!qstr_stack.empty())
        {
            QString tem = qstr_stack.pop();
            num2 += tem;
        }
        if(is_float)//处理小数
        {
            QString f_text_clone = f_text;//拷贝
            int len = f_text_clone.length();
            for(int i = 0;i<len;i++)
             {
                QString ret = f_text_clone.at(i);
                int num = ret.toInt();
                QString str = eightTotwo(num);
                f_num2 += str;
            }
        }
        QString num3 = num2;
        if(is_minus)
            num2 = "-"+num2;
        if(is_float)
            num2 = num2 + "." +f_num2;
        num2 = delete_zero(num2);
        ui->le_2->setText(num2);
        //转八进制
        QString tem_text = text;
        if(is_minus)
        tem_text = "-"+tem_text;
        if(is_float)
        tem_text = tem_text + "." + f_text;
        tem_text = delete_zero(tem_text);
         ui->le_8->setText(tem_text);
        //转十进制
        QString text_clone2 = text; //拷贝
        int len2 = text_clone2.length();
        int sum = 0;
        double f_sum = 0;
        for(int i = len2 - 1,k = 0;i>=0;i--,k++)
        {
            QString str = text_clone2.at(i);
            int num = str.toInt();
            int p = num * qPow(8,k);
            sum += p;
        }
        if(is_float)//处理小数部分
        {
            QString f_text_clone = f_text;//拷贝
            int len = f_text_clone.length();
            for(int i = 0,k = -1;i<len;i++,k--)
            {
                QString num = f_text_clone.at(i);
                double ret = num.toDouble();
                double df = ret * qPow(8,k);
                f_sum+=df;
            }
            //去除头部的0.
            QString t_f_sum = QString::number(f_sum).section(".",1,1);
            f_sum = t_f_sum.toDouble();
        }
        QString tem_sum = QString::number(sum);
        if(is_minus)
            tem_sum = "-" + tem_sum;
        if(is_float)
            tem_sum = tem_sum + "." + QString::number(f_sum);
        tem_sum = delete_zero(tem_sum);
        ui->le_10->setText(tem_sum);
        //转十六
        QString text_clone3 = num3; //拷贝
        int len3 = text_clone3.length();
       while(len3)
       {
           if(len3<4)//若当前位数小于4位，则补0
           {
               while(len3!=4)
               {
                   text_clone3 = "0" + text_clone3;
                   len3 = text_clone3.length();
               }
           }
           QString temp = text_clone3.mid(len3-4,4);
           int tem_len = temp.length();
           int num = twoTosixteen(temp);
           stack.push(num); //入栈
          text_clone3.remove(len3-tem_len,tem_len);//更新字符串
          len3 = text_clone3.length();
       }
       QString num16;
       QString f_num16;
       while(!stack.empty())
       {
           QString n = QString::number(stack.pop());
           if(n=="10")
           num16 += "A";
           else if(n=="11")
           num16 += "B";
           else if(n=="12")
           num16 += "C";
           else if(n=="13")
           num16 += "D";
           else if(n=="14")
           num16 += "E";
           else if(n=="15")
           num16 += "F";
           else
           num16 += n;
       }
       if(is_float)//处理小数部分
       {
           QString f_text_clone = f_num2;//拷贝
           int len = f_text_clone.length();
           if(len<4) //长度小于4后位补0
           {
               while(len!=4)
               {
                    f_text_clone += "0";
                    len = f_text_clone.length();
               }

           }
           while(len)
           {
               QString temp = f_text_clone.mid(0,4);
               if(temp.length()<4)
               {
                   while(temp.length()!=4)
                   {
                       temp += "0";
                   }

               }
               int res = twoTosixteen(temp);
               queue.enqueue(res);
               f_text_clone.remove(0,4);
               len =  f_text_clone.length();
           }
           while(!queue.empty())
           {

               QString ret = QString::number(queue.dequeue());//出队
               if(ret=="10")
               f_num16 += "A";
               else if(ret=="11")
               f_num16 += "B";
               else if(ret=="12")
               f_num16 += "C";
               else if(ret=="13")
               f_num16 += "D";
               else if(ret=="14")
               f_num16 += "E";
               else if(ret=="15")
               f_num16 += "F";
               else
               f_num16 += ret;
           }
       }
       if(is_minus)
       num16="-"+num16;
       if(is_float)
       num16 = num16 +"." +f_num16;
       num16 = delete_zero(num16);
       ui->le_16->setText(num16);
    }

    void MainWindow::ten_transition(QString texts) //十进制
    {
        QStack<int> stack;
        QQueue<int> queue;
        QString text = texts;
        QString f_text; //小数部分
        if(is_float)//如果是小数，整数部分和小数部分分开计算
        {
            text = texts.section(".",0,0);
            f_text = texts.section(".",1,1);
        }
        //转二进制
        int num = text.toInt();
        while(num)
        {
            int temp = num%2;
            stack.push(temp);//余数入栈
            num = num/2;
        }
        QString str;
        QString f_str;
        int count = 0;//计数器(保留10位小数)
        while(!stack.empty())
        {
            QString n = QString::number(stack.pop());
            str += n;
        }
        if(is_float)//处理小数部分
        {
            QString f_text_clone = f_text;//拷贝
            int len = f_text_clone.length();
             f_text_clone = "0."+f_text_clone;
            double num = f_text_clone.toDouble();
            double ret = num;
            while(ret&&count!=10)
            {
                ret = ret*2;
                if(ret>=1)
                {
                    queue.enqueue(1);
                    ret -= 1;
                }
                else
                {
                    queue.enqueue(0);
                }
                count++;
            }
            while (!queue.empty())
            {
                QString s = QString::number(queue.dequeue());
                f_str += s;
            }
        }
        if(is_minus)
            str = "-"+str;
        if(is_float)
            str = str + "." +f_str;
        str = delete_zero(str);
        ui->le_2->setText(str);
        //转八进制
        int num8 = text.toInt();
        while(num8)
        {
            int temp = num8%8;
            stack.push(temp);//余数入栈
            num8 = num8/8;
        }
        QString str8;
        QString f_str8;//小数部分
        count = 0;//计数器清0
        while(!stack.empty())
        {
            QString n = QString::number(stack.pop());
            str8 += n;
        }
        if(is_float)//处理小数部分
        {
            QString f_text_clone = f_text;//拷贝
            int len = f_text_clone.length();
             f_text_clone = "0."+f_text_clone;
            double num = f_text_clone.toDouble();
            double ret = num;
            while(ret&&count!=10)
            {
                ret = ret*8;
                if(ret>=1)
                {
                    QString tem = QString::number(ret);
                    int rs = tem.section(".",0,0).toInt();
                    ret -= rs;
                    queue.enqueue(rs);
                }
                else
                {
                    queue.enqueue(0);
                }
                count++;
            }
            while (!queue.empty())
            {
                QString s = QString::number(queue.dequeue());
                f_str8 += s;
            }
        }
        if(is_minus)
            str8 = "-"+str8;
        if(is_float)
            str8 = str8 +"."+f_str8;
         str8 = delete_zero(str8);
         ui->le_8->setText(str8);
          //转十进制
         QString tem_t = text;
         if(is_minus)
             tem_t = "-"+tem_t;
         if(is_float)
             tem_t = tem_t +"."+ f_text;
          tem_t = delete_zero(tem_t);
             ui->le_10->setText(tem_t);
         //转十六
         int num16 = text.toInt();
         while(num16)
         {
             int temp = num16%16;
             stack.push(temp);//余数入栈
             num16 = num16/16;
         }
         QString str16;
         QString f_str16;//小数部分
         count = 0;//计数器清0
         while(!stack.empty())
         {
             QString n = QString::number(stack.pop());
             if(n=="10")
             str16 += "A";
             else if(n=="11")
             str16 += "B";
             else if(n=="12")
             str16 += "C";
             else if(n=="13")
             str16 += "D";
             else if(n=="14")
             str16 += "E";
             else if(n=="15")
             str16 += "F";
             else
             str16 += n;
         }
         if(is_float)//处理小数部分
         {
             QString f_text_clone = f_text;//拷贝
             int len = f_text_clone.length();
              f_text_clone = "0."+f_text_clone;
             double num = f_text_clone.toDouble();
             double ret = num;
             while(ret&&count!=10)
             {
                 ret = ret*16;
                 if(ret>=1)
                 {
                     QString tem = QString::number(ret);
                     int rs = tem.section(".",0,0).toInt();
                     ret -= rs;
                     queue.enqueue(rs);
                 }
                 else
                 {
                     queue.enqueue(0);
                 }
                 count++;
             }
             while (!queue.empty())
             {
                 QString n = QString::number(queue.dequeue());
                 if(n=="10")
                 f_str16 += "A";
                 else if(n=="11")
                 f_str16 += "B";
                 else if(n=="12")
                 f_str16 += "C";
                 else if(n=="13")
                 f_str16 += "D";
                 else if(n=="14")
                 f_str16 += "E";
                 else if(n=="15")
                 f_str16 += "F";
                 else
                 f_str16 += n;
             }
         }
         if(is_minus)
             str16 = "-" + str16;
         if(is_float)
             str16 = str16 +"."+f_str16;
         str16 = delete_zero(str16);
         ui->le_16->setText(str16);
    }

    void MainWindow::sixteen_transition(QString texts)//十六进制
    {

        QStack<int> stack;
        QQueue<int> queue;
        QStack<QString> qstr_stack;
        QQueue<QString> qstr_queue;
        QString text = texts;
        QString f_text;
        if(is_float)//如果是小数，整数部分和小数部分分开计算
        {
            text = texts.section(".",0,0);
            f_text = texts.section(".",1,1);
        }
       //转二进制
        QString text_clone = text;
        int len = text_clone.length();
        for(int i = len-1;i>=0;i--)
        {
            int num;
            QString str = text_clone.at(i);
            if(str=="A"||str=="a")
                num=65;
            else if(str=="B"||str=="b")
                num=66;
            else if(str=="C"||str=="c")
                num=67;
            else if(str=="D"||str=="d")
                num=68;
            else if(str=="E"||str=="e")
                num=69;
            else if(str=="F"||str=="f")
                num=70;
            else
             num = str.toInt();
            QString res = sixteenTotwo(num);
            qstr_stack.push(res);
        }
        QString num2;
        QString f_num2;
        while(!qstr_stack.empty())
        {
            QString str = qstr_stack.pop();
            num2 += str;
        }
        QString num3 = num2;
        if(is_float)//处理小数部分
        {
            QString f_text_clone = f_text;//拷贝
            int len = f_text_clone.length();
            for(int i = 0;i<len;i++)
            {
                QString ret = f_text_clone.at(i);
                int num =ret.toInt();
                QString res = sixteenTotwo(num);
                qstr_queue.enqueue(res);
            }
            while(!qstr_queue.empty())
            {
                QString s = qstr_queue.dequeue();
                f_num2 += s;
            }
        }
        if(is_minus)
            num2 = "-"+num2;
        if(is_float)
            num2 = num2 +"."+f_num2;
        num2 = delete_zero(num2);
        ui->le_2->setText(num2);
        //转八进制
        QString text_clone1 = num3; //拷贝
        int len1 = text_clone1.length();
       while(len1)
       {
           if(len1<3)//若当前位数小于3位，则补0
           {
               while(len1!=3)
               {
                   text_clone1 = "0" + text_clone1;
                   len1 = text_clone1.length();
               }
           }
           QString temp = text_clone1.mid(len1-3,3);
           int tem_len = temp.length();
           int num = twoToeight(temp);
           stack.push(num); //入栈
          text_clone1.remove(len1-tem_len,tem_len);//更新字符串
          len1 = text_clone1.length();
       }
       QString num8;
       QString f_num8;
       while(!stack.empty())
       {
           QString str = QString::number(stack.pop());
           num8 += str;
       }
       if(is_float) //处理小数
       {
           QString f_text_clone = f_num2;//拷贝
           int len = f_text_clone.length();
           if(len<3) //长度小于3后位补0
           {
               while(len!=3)
               {
                    f_text_clone += "0";
                    len = f_text_clone.length();
               }

           }
           while(len)
           {
               QString temp = f_text_clone.mid(0,3);
               if(temp.length()<3)
               {
                   while(temp.length()!=3)
                   {
                       temp += "0";
                   }

               }
               int res = twoToeight(temp);
               queue.enqueue(res);
               f_text_clone.remove(0,3);
               len =  f_text_clone.length();
           }
           while(!queue.empty())
           {
               QString ret = QString::number(queue.dequeue());//出队
               f_num8 += ret;
           }
       }
       if(is_minus)
           num8 = "-"+num8;
       if(is_float)
           num8 = num8+"."+f_num8;
       num8 = delete_zero(num8);
       ui->le_8->setText(num8);
       //转十进制
       QString text_clone2 = num3; //拷贝
       int sum = 0;
       double f_sum = 0;
       int len2 = text_clone2.length();
       for(int i = len2 - 1,k = 0;i>=0;i--,k++)
       {
           QString n = text_clone2.at(i);
           int num = n.toInt();
           int p = num * qPow(2,k);
           sum = sum + p;
       }
       if(is_float) //处理小数
       {
           QString f_text_clone = f_num2;//拷贝
           int len = f_text_clone.length();
           for(int i = 0,k = -1;i<len;i++,k--)
           {
               QString num = f_text_clone.at(i);
               double ret = num.toDouble();
               double df = ret * qPow(2,k);
               f_sum+=df;
           }
           //去除头部的0.
           QString t_f_sum = QString::number(f_sum).section(".",1,1);
           f_sum = t_f_sum.toDouble();
       }
       QString tem_sum = QString::number(sum);
       if(is_minus)
           tem_sum = "-"+tem_sum;
       if(is_float)
           tem_sum =  tem_sum +"." +QString::number(f_sum);
        tem_sum = delete_zero(tem_sum);
       ui->le_10->setText(tem_sum);
       //转十六进制
       QString t_text = text;
       if(is_minus)
           t_text = "-"+t_text;
       if(is_float)
           t_text = t_text+"."+f_text;
        t_text = delete_zero(t_text);
       ui->le_16->setText(t_text);
    }

    int MainWindow::twoToeight(QString str) //2转8
    {
        if(str == "000")
            return 0;
        else if(str == "001")
            return 1;
        else if(str == "010")
            return 2;
        else if(str == "011")
            return 3;
        else if(str == "100")
            return 4;
        else if(str == "101")
            return 5;
        else if(str == "110")
            return 6;
        else if(str == "111")
            return 7;
    }

    int MainWindow::twoTosixteen(QString str)//2转16
    {
        if(str == "0000")
            return 0;
        else if(str == "0001")
            return 1;
        else if(str == "0010")
            return 2;
        else if(str == "0011")
            return 3;
        else if(str == "0100")
            return 4;
        else if(str == "0101")
            return 5;
        else if(str == "0110")
            return 6;
        else if(str == "0111")
            return 7;
        else if(str == "1000")
            return 8;
        else if(str == "1001")
            return 9;
        else if(str == "1010")
            return 10;
        else if(str == "1011")
            return 11;
        else if(str == "1100")
            return 12;
        else if(str == "1101")
            return 13;
        else if(str == "1110")
            return 14;
        else if(str == "1111")
            return 15;
    }

    QString MainWindow::eightTotwo(int num)//8转2
    {
        switch(num)
        {
            case 0:return "000";
            case 1:return "001";
            case 2:return "010";
            case 3:return "011";
            case 4:return "100";
            case 5:return "101";
            case 6:return "110";
            case 7:return "111";
        default:return 0;
        }
    }

    QString MainWindow::sixteenTotwo(int num)//16转2
    {
        switch (num)
        {
             case 0:return "0000";
             case 1:return "0001";
             case 2:return "0010";
             case 3:return "0011";
             case 4:return "0100";
             case 5:return "0101";
             case 6:return "0110";
             case 7:return "0111";
             case 8:return "1000";
             case 9:return "1001";
             case 65:return "1010";
             case 66:return "1011";
             case 67:return "1100";
             case 68:return "1101";
             case 69:return "1110";
             case 70:return "1111";
        default:return 0;
        }
    }

    QString MainWindow::delete_zero(QString ret)
    {
        //无效无用0
        QString str = ret;
        //删除头部无效0
        QString s = str.at(0);
        while(s=="0")
        {
            str.remove(0,1);
            s = str.at(0);
        }
        return str;
    }

    void MainWindow::error_tip()
    {
        QMessageBox::warning(this,"警告","输入数值格式不正确,不支持转换!");
    }


    void MainWindow::on_btn_transition_clicked()//转换
    {
        //获取用户输入
        QString texts = ui->le_cin->text();
        int len = texts.length();
        if(texts.at(0)=="-") //判断是否为负数
        {
            is_minus = true;
            texts = texts.remove(0,1);
        }
        else
            is_minus = false;
        if(texts.contains("."))//判断是否带小数
        {
            is_float = true;
        }
        else
            is_float = false;
        switch (system_flag)
        {
        case 2:
        {
            for(int i = 0;i<len;i++)
            {
                QString str = texts.at(i);
                if(str=="0"||str=="1"||str==".")
                    continue;
                else
                {
                    error_tip();
                    return;
                }
            }
            two_transition(texts);
        }
          break;
        case 8:
        {
            for(int i = 0;i<len;i++)
            {
                QString str = texts.at(i);
                if(str=="0"||str=="1"||str=="2"||str=="3"||str=="4"||str=="5"||str=="6"||str=="7"||str==".")
                    continue;
                else
                {
                    error_tip();
                    return;
                }
            }
            eight_transition(texts);
        }
          break;
        case 10:
        {
            for(int i = 0;i<len;i++)
            {
                QString str = texts.at(i);
                if(str=="0"||str=="1"||str=="2"||str=="3"||str=="4"||str=="5"||str=="6"||str=="7"||
                        str=="8"||str=="9"||str==".")
                    continue;
                else
                {
                    error_tip();
                    return;
                }
            }
            ten_transition(texts);
        }
          break;
        case 16:
        {
           if(is_float)
            {
                QString f_text = texts.section(".",-1,-1);
                for(int i = 0;i<f_text.length();i++)
                {
                    QString str = f_text.at(i);
                    if(str=="0"||str=="1"||str=="2"||str=="3"||str=="4"||str=="5"||str=="6"||str=="7"||
                            str=="8"||str=="9")
                        continue;
                    else
                    {
                        error_tip();
                        return;
                    }
                }
            }

            for(int i = 0;i<len;i++)
            {
                QString str = texts.at(i);
                if(str=="0"||str=="1"||str=="2"||str=="3"||str=="4"||str=="5"||str=="6"||str=="7"||
                   str=="8"||str=="9"||str=="."||str=="A"||str=="B"||str=="C"||str=="D"||str=="E"||str=="F"||
                   str=="a"||str=="b"||str=="c"||str=="d"||str=="e"||str=="f")
                    continue;
                else
                {
                    error_tip();
                    return;
                }
            }
            sixteen_transition(texts);
        }
          break;
        default:
            return;
    }

}




void MainWindow::on_action_5_triggered(bool checked)
{
    if(checked)
    {
        ui->radio_2->show();
        ui->radio_8->show();
        ui->radio_10->show();
        ui->radio_16->show();
        ui->le_cin->show();
        ui->le_2->show();
        ui->le_8->show();
        ui->le_10->show();
        ui->le_16->show();
        ui->btn_transition->show();
        ui->label->show();
        ui->label_2->show();
        ui->label_3->show();
        ui->label_4->show();

    }
    else
    {
        ui->radio_2->hide();
        ui->radio_8->hide();
        ui->radio_10->hide();
        ui->radio_16->hide();
        ui->le_cin->hide();
        ui->le_2->hide();
        ui->le_8->hide();
        ui->le_10->hide();
        ui->le_16->hide();
        ui->btn_transition->hide();
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
    }
}

