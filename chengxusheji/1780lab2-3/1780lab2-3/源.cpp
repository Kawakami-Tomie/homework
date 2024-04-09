#include<iostream>
using namespace std;

int main() 
{
    char A, B, C;
    cout << "请输入两个char型数据：";
    cin >> A >> B;

    A = ~A;
    B << 2;
    C= A & B;

    cout << "A按位取反的结果为：" << (int)A << endl;
    cout << "B左移2位的结果为：" << (int)B << endl;
    cout << "按位与的结果为：" << (int)C << endl;

    return 0;
}
