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

    //����Ƿ�ƥ��
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

    //�����������
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

    // ����stack��ĸ��ֲ���
    cout << "��ʼ״̬ջ�Ƿ�Ϊ��? " << (stack.isEmpty() ? "Y" : "N") << endl;
    cout << "ѹջ����������5 10 15�� ...... " << endl;
    stack.push(5);
    stack.push(10);
    stack.push(15);
    cout << "ջ��Ԫ��: " << stack.top() << endl;
    cout << "ջ���: " << stack.size() << endl;
    stack.pop();
    cout << "��ջ���� ...... " << endl;
    cout << "ջ��Ԫ��: " << stack.top() << endl;
    cout << "ջ���: " << stack.size() << endl;
    cout << "ջ�Ƿ�Ϊ��? " << (stack.isEmpty() ? "Y" : "N") << endl;

    // �û����������ջ����ջ����������ʾջ��״̬
    string choice;
    while (true) {
        cout << "����push���һ��Ԫ�أ�deleteɾ��һ��Ԫ�أ�quit�˳�: ";
        cin >> choice;

        if (choice == "push") {
            int value;
            cout << "���������ֵ: ";
            cin >> value;
            stack.push(value);
        }
        else if (choice == "delete") {
            if (!stack.isEmpty()) {
                stack.pop();
            }
            else {
                cout << "ջ��!" << endl;
            }
        }
        else if (choice == "quit") {
            break;
        }
        else {
            cout << "��Ч����!" << endl;
        }

        cout << "ջ��Ԫ��: " << stack.top() << endl;
        cout << "ջ���: " << stack.size() << endl;
        cout << "ջ�Ƿ�Ϊ��? " << (stack.isEmpty() ? "Y" : "N") << endl;
    }

    // �����ʽ�����ŵ�ƥ��
    string expression;
    while (true) {
        cout << "�����뺬Բ���ŵı��ʽ (����quit�˳�): ";
        cin >> expression;

        if (expression == "quit") {
            break;
        }
        else {
            if (stack.checkParentheses(expression)) {
                cout << "����ƥ��!" << endl;
            }
            else {
                cout << "���Ų�ƥ��!" << endl;
            }
        }
    }

    return 0;
}
