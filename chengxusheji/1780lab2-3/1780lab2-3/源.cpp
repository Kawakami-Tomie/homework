#include<iostream>
using namespace std;

int main() 
{
    char A, B, C;
    cout << "����������char�����ݣ�";
    cin >> A >> B;

    A = ~A;
    B << 2;
    C= A & B;

    cout << "A��λȡ���Ľ��Ϊ��" << (int)A << endl;
    cout << "B����2λ�Ľ��Ϊ��" << (int)B << endl;
    cout << "��λ��Ľ��Ϊ��" << (int)C << endl;

    return 0;
}
