#include <iostream>

using namespace std;

//����a��b������
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//������
int main() {
    int Array[5] = { 2, 5, 4, 1, 3 };

    //ʵ��ð�ݵ�˫��ѭ��
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (Array[j + 1] < Array[j])
            swap(Array[j + 1], Array[j]);
        }
    }

    //�������������
    for (int i = 0; i < 5; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;

    return 0;
}
