#include <iostream>
#include <list>
#include "LIst.h"
#include "ListNode.h"
using namespace std;

template<typename T>
class Stack {
private:
    List<T> stackList;
   
public:
    //栈空
    bool isEmpty() {
        return stackList.empty();
    }
    //栈顶
   T top() {
        if (!isEmpty()) {                   
            return  stackList.laist();

        } else {
            cout << "栈空!" << endl;
            return 0;
        }
    }
    //栈深度
    int size() {
        return stackList.size();
    }
    //压栈
    void push(int value) {
        stackList.insertAsLast(value);
    }
    //出栈
    void pop() {
        if (!isEmpty()) {
           stackList.remove(stackList.last());
        } else {
            cout << "栈空!" << endl;
        }
    }
};
//括号匹配检测
void processExpression(const string& expression) {
    Stack<char> stack;
    bool isMatched = true;

    for (char ch : expression) {
        if (ch == '(') {
            stack.push(1);
        } else if (ch == ')') {
            if (stack.isEmpty()) {
                isMatched = false;
                break;
            } else {
                stack.pop();
            }
        }
    }

    if (!stack.isEmpty()) {
        isMatched = false;
        stack.pop();
    }

    if (isMatched) {
        cout << "括号匹配！" << endl;
    } else {
        cout << "括号不匹配!" << endl;
    }
}

int main() {
    Stack<int> stack;

    // 测试stack类的各种操作
    cout << "初始状态栈是否为空? " << (stack.isEmpty() ? "Y" : "N") << endl;
    cout << "压栈操作（list尾插入5 10 15） ...... " << endl;
    stack.push(5);
    stack.push(10);
    stack.push(15);
    
    cout << "栈顶元素: " << stack.top() << endl;
    cout << "栈深度: " << stack.size() << endl;
    stack.pop();
    cout << "出栈操作 （list尾删...... " << endl;
    cout << "栈顶元素: " << stack.top() << endl;
    cout << "栈深度: " << stack.size() << endl;
    cout << "栈是否为空? " << (stack.isEmpty() ? "Y" : "N") << endl;

    // 用户输入进行入栈、出栈操作，并显示栈的状态
    string choice;
    while (true) {
        cout << "输入push添加一个元素，delete删除一个元素，quit退出: ";
        cin >> choice;

        if (choice == "push") {
            int value;
            cout << "请输入插入值: ";
            cin >> value;
            stack.push(value);
        } else if (choice == "delete") {
            if (!stack.isEmpty()) {
                stack.pop();
            } else {
                cout << "栈空!" << endl;
            }
        } else if (choice == "quit") {
            break;
        } else {
            cout << "无效输入!" << endl;
        }

        cout << "栈顶元素: " << stack.top() << endl;
        cout << "栈深度: " << stack.size() << endl;
        cout << "栈是否为空? " << (stack.isEmpty() ? "Y" : "N") << endl;
    }

    // 检查表达式中括号的匹配
    string expression;
    while (true) {
        cout << "请输入含圆括号的表达式 (输入quit退出): ";
        cin >> expression;

        if (expression == "quit") {
            break;
        } else {
            processExpression(expression);
        }
    }

    return 0;
}
