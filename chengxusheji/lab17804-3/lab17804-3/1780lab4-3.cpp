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
    cout << "����������������" << endl;
    cin >> a >> b>>c ;
    double d = 0, e = 0,f=0 ;
    cout << "����������˫��������" << endl;
    cin >> d >> e>>f;
    cout << "" << endl;
    cout << a << "��" << b<<"��" << c << "�����ֵΪ��" << maxl(a,b,c) << endl;
    cout << "" << endl; 
    cout << d << "��" << e<<"��" << f << "�����ֵΪ��" << maxl(d,e,f) << endl;
    return 0;
}