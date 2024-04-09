#include <iostream>
#include <cmath>

using namespace std;

double factorial(int n)//递归
{
    if (n == 0)
    {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int main() 
{
    double x;
    int n;
    while (true)
    {
        cout << "请输入x：";
        cin >> x;
        cout << "请输入n：";
        cin >> n;
        if (n < 0)
        {
            cout << "n不能小于0，请重新输入。" << endl;
        }
        else  
        {
            break;
        }
    }

    double result = exp(x);
    double taylor=0;
    for (int i = 0; i <= n; i++) 
    {
        taylor+= pow(x, i) / factorial(i);
    }

    cout << "自然对数的" << x << "次方的" << n << "阶泰勒展开结果为：" << taylor << endl;
    cout << "验证：e^x的值为：" << result << endl;

    return 0;
}