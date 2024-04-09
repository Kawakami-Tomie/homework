#include <iostream>
using namespace std;

int maxl(int a, int b, int c)
{
    int maxl = a > b ? a : b;
    return maxl > c ? maxl : c;
}

double maxl(double a, double b,double c)
{
    double maxl = a > b ? a : b;
    return maxl > c ? maxl : c;
}

int main() 
{
    int a, b,c;
    cout << "请输入三个整数：" << endl;
    cin >> a >> b>>c ;
    double d = 0, e = 0,f=0 ;
    cout << "请输入三个双精度数：" << endl;
    cin >> d >> e>>f;
    cout << "" << endl;
    cout << a << "与" << b<<"与" << c << "的最大值为：" << maxl(a,b,c) << endl;
    cout << "" << endl; 
    cout << d << "与" << e<<"与" << f << "的最大值为：" << maxl(d,e,f) << endl;
    return 0;
}