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
    //ջ��
    bool isEmpty() {
        return stackList.empty();
    }
    //ջ��
   T top() {
        if (!isEmpty()) {                   
            return  stackList.laist();

        } else {
            cout << "ջ��!" << endl;
            return 0;
        }
    }
    //ջ���
    int size() {
        return stackList.size();
    }
    //ѹջ
    void push(int value) {
        stackList.insertAsLast(value);
    }
    //��ջ
    void pop() {
        if (!isEmpty()) {
           stackList.remove(stackList.last());
        } else {
            cout << "ջ��!" << endl;
        }
    }
};
//����ƥ����
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
        cout << "����ƥ�䣡" << endl;
    } else {
        cout << "���Ų�ƥ��!" << endl;
    }
}

int main() {
    Stack<int> stack;

    // ����stack��ĸ��ֲ���
    cout << "��ʼ״̬ջ�Ƿ�Ϊ��? " << (stack.isEmpty() ? "Y" : "N") << endl;
    cout << "ѹջ������listβ����5 10 15�� ...... " << endl;
    stack.push(5);
    stack.push(10);
    stack.push(15);
    
    cout << "ջ��Ԫ��: " << stack.top() << endl;
    cout << "ջ���: " << stack.size() << endl;
    stack.pop();
    cout << "��ջ���� ��listβɾ...... " << endl;
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
        } else if (choice == "delete") {
            if (!stack.isEmpty()) {
                stack.pop();
            } else {
                cout << "ջ��!" << endl;
            }
        } else if (choice == "quit") {
            break;
        } else {
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
        } else {
            processExpression(expression);
        }
    }

    return 0;
}
