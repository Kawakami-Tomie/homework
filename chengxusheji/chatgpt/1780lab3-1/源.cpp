#include <iostream>
using namespace std;

bool IsPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num1, num2;
    bool flag = false; //用于判断是否需要重新输入
    do {
        if (flag) {
            cout << "请重新输入:" << endl;
        }
        else {
            cout << "请输入两个整数:" << endl;
        }
        cin >> num1 >> num2;
        flag = true;
        if (num1 == num2) {
            cout << "输入的两个数不能相等,请重新输入！" << endl;
        }
        else if (abs(num2 - num1) >= 10000) {
            cout << "输入的两个数相差较大，运算时间可能较长，是否重新输入？重新输入键入“Y”，不重新输入键入“N”" << endl;
            char again;
            cin >> again;
            if (again== 'Y') 
            {
                flag = false;
            }
            else {
                return 0;
            }
        }
    } while (!flag);

    int count = 0;
    for (int i = num1; i <= num2; ++i) {
        if (IsPrime(i)) {
            cout << i << endl;
            count++;
        }
    }
    cout << "质数的数量是：" << count << endl;

    return 0;
}


/*代码中，`IsPrime`函数用于判断一个数是否为质数。`main`函数中，首先使用do - while循环，
判断输入的两个数是否相等以及是否相差较大，如果需要重新输入，则将flag置为false，再次进入循环。
如果不需要重新输入，则开始计算这两个数之间的质数，同时统计质数数量。最后输出质数的数量。*/

