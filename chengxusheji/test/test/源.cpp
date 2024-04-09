#include <iostream>

using namespace std;

//交换a与b的数据
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//主函数
int main() {
    int Array[5] = { 2, 5, 4, 1, 3 };

    //实现冒泡的双重循环
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (Array[j + 1] < Array[j])
            swap(Array[j + 1], Array[j]);
        }
    }

    //输出排序后的数组
    for (int i = 0; i < 5; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;

    return 0;
}
