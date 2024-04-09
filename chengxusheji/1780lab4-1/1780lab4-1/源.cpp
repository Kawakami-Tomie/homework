#include <iostream>
using namespace std;


int factorial(int n) {
    if (n == 0 || n == 1) { // 0或1的阶乘均为1
        return 1;
    }
    else {
        return n * factorial(n - 1); // 递归
    }
}

int main() {
    int n;
    cout << "请输入一个正整数n：";
    cin >> n;
    if (n < 0)
    { 
        cout << "输入不合法";//只接受正整数
    }
    else {
        cout << n << "的阶乘是：" << factorial(n);
    }
    return 0;
}