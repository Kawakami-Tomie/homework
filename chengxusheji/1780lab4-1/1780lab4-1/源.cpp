#include <iostream>
using namespace std;


int factorial(int n) {
    if (n == 0 || n == 1) { // 0��1�Ľ׳˾�Ϊ1
        return 1;
    }
    else {
        return n * factorial(n - 1); // �ݹ�
    }
}

int main() {
    int n;
    cout << "������һ��������n��";
    cin >> n;
    if (n < 0)
    { 
        cout << "���벻�Ϸ�";//ֻ����������
    }
    else {
        cout << n << "�Ľ׳��ǣ�" << factorial(n);
    }
    return 0;
}