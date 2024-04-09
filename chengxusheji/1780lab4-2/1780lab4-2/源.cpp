#include <iostream>
#include <cmath>

using namespace std;

double factorial(int n)//�ݹ�
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
        cout << "������x��";
        cin >> x;
        cout << "������n��";
        cin >> n;
        if (n < 0)
        {
            cout << "n����С��0�����������롣" << endl;
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

    cout << "��Ȼ������" << x << "�η���" << n << "��̩��չ�����Ϊ��" << taylor << endl;
    cout << "��֤��e^x��ֵΪ��" << result << endl;

    return 0;
}