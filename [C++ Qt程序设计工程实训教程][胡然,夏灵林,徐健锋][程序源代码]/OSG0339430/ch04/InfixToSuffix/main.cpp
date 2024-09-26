#include <stack>
#include <string>
#include <map>
#include <iostream>
#include <cmath>
#include <cstdlib>

std::string inToPost(std::string infix) throw(const char*)
{
    std::stack<char> stack;
    char current = 0;//读入的字符
    std::string postfix;//写入后缀表达式的字符串

    std::map<char,int> priority;//运算符号优先级表
    priority['+'] = 0;
    priority['-'] = 0;
    priority['*'] = 1;
    priority['/'] = 1;
    priority['^'] = 2;

    for(int i = 0; i < infix.length() ;++i)//逐个读取中缀表达式字符串中的字符
    {
        current =infix[i];
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
            if(i > 0)    //如果运算符的前一项不是右括号则说明前一个数字输入完毕，用#标识前面几个字符组成一个数字
             {
                if (infix[i-1] != ')')
                    postfix.push_back('#');
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
        if(isdigit(infix[infix.size()-1]))
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
int main(int argc, char *argv[])
{
    std::string infix;
    std::cout << "please input a sufix expression:";
    std::cin >> infix;
    std::cout << "the suffix expression is :" << inToPost(infix);
    return 0;
}
