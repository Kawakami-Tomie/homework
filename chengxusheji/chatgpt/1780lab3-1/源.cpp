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
    bool flag = false; //�����ж��Ƿ���Ҫ��������
    do {
        if (flag) {
            cout << "����������:" << endl;
        }
        else {
            cout << "��������������:" << endl;
        }
        cin >> num1 >> num2;
        flag = true;
        if (num1 == num2) {
            cout << "������������������,���������룡" << endl;
        }
        else if (abs(num2 - num1) >= 10000) {
            cout << "��������������ϴ�����ʱ����ܽϳ����Ƿ��������룿����������롰Y����������������롰N��" << endl;
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
    cout << "�����������ǣ�" << count << endl;

    return 0;
}


/*�����У�`IsPrime`���������ж�һ�����Ƿ�Ϊ������`main`�����У�����ʹ��do - whileѭ����
�ж�������������Ƿ�����Լ��Ƿ����ϴ������Ҫ�������룬��flag��Ϊfalse���ٴν���ѭ����
�������Ҫ�������룬��ʼ������������֮���������ͬʱͳ������������������������������*/

