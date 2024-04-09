#include <iostream>
using namespace std;
#include "List.h"


template<typename T>
class Stack {
private:
    List<T> stackList;

public:
    bool isEmpty() {
        return stackList.empty();
    }

    T top() {
        return stackList.first();
    }

    int size() {
        return stackList.size();
    }

    void push(const T& item) {
        stackList.insertAsfirst(item);
    }

    void pop() {
        stackList.remove();
    }

    //检查是否匹配
    bool isMatch(char open, char close) {
        if (open == '(' && close == ')') {
            return true;
        }
        else if (open == '{' && close == '}') {
            return true;
        }
        else if (open == '[' && close == ']') {
            return true;
        }
        else {
            return false;
        }
    }

    //检查输入括号
    bool checkParentheses(const string& expression) {
        Stack<char> parentheses;

        for (char ch : expression) {
            if (ch == '(' || ch == '{' || ch == '[') {
                parentheses.push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (parentheses.isEmpty() || !isMatch(parentheses.top(), ch)) {
                    return false;
                }
                else {
                    parentheses.pop();
                }
            }
        }

        return parentheses.isEmpty();
    }
};



int main() {
    Stack<int> stack;

    // 测试stack类的各种操作
    cout << "初始状态栈是否为空? " << (stack.isEmpty() ? "Y" : "N") << endl;
    cout << "压栈操作（插入5 10 15） ...... " << endl;
    stack.push(5);
    stack.push(10);
    stack.push(15);
    cout << "栈顶元素: " << stack.top() << endl;
    cout << "栈深度: " << stack.size() << endl;
    stack.pop();
    cout << "出栈操作 ...... " << endl;
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
        }
        else if (choice == "delete") {
            if (!stack.isEmpty()) {
                stack.pop();
            }
            else {
                cout << "栈空!" << endl;
            }
        }
        else if (choice == "quit") {
            break;
        }
        else {
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
        }
        else {
            if (stack.checkParentheses(expression)) {
                cout << "括号匹配!" << endl;
            }
            else {
                cout << "括号不匹配!" << endl;
            }
        }
    }

    return 0;
}
