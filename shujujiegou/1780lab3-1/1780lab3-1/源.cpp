#include <iostream>
#include<ctime>
#include <cstdlib>
using namespace std;
class SortedVector {
private:
    int* arr;//����
    int size;//��ǰ��С
    int capacity;//����

public:
    SortedVector() {
        capacity = 10;
        size = 0;
        arr = new int[capacity];
    }

    ~SortedVector() {
        delete[] arr;
    }

    void insert(int value) {
        if (size == capacity) {
            expand();
        }

        int i = size - 1;
        while (i >= 0 && arr[i] > value)//����value�Ķ�����
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = value;
        size++;
    }

    void remove(int value) {
        int i = 0, j = 0;

        while (j < size) {//��һ�ж��Ƿ���ͬ
            if (arr[j] != value) {
                arr[i] = arr[j];
                i++;
            }
            j++;
        }

        size = i;
    }

    void search_line(int value)//��һ���ҷ�
    {
        int count = 0;
        int rank = -1;

        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                if (rank == -1) {
                    rank = i;
                }
                count++;

            }
        }

        if (rank != -1) {
            cout << "ʹ����һ������С�ȣ�" << rank << "��������" << count << endl;
        }
        else {
            cout << "ʹ����һ�����޴�Ԫ��" << endl;
        }
    }

    // ʹ�ö��ֲ����㷨�ҵ���һ�����ڸ���Ԫ�ص�λ�ò�ͳ������
    void search_bin(int value)
    {
        int count = 0;
        int rank = -1;
        int lo = 0, hi = size - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] < value) //�������(mi, hi)
            {
                lo = mid + 1;
            }
            else if (arr[mid] > value)//����ǰ���[lo, mi)��������
            {
                hi = mid - 1;
            }
            else//mid=value
            {
                if (rank == -1)
                {
                    rank = mid;
                }
                count++;
                hi = mid - 1;//���Ҹ�С����
            }
        }
        if (rank != -1) {
            cout << "ʹ�ö��ַ����ҵ���С�ȣ�" << rank << "��������" << count << endl;
        }
        else {
            cout << "ʹ�ö��ַ����ҵ��޴�Ԫ��" << endl;
        }

    }



    void search_insert(int value)//��ֵ��
    {
        int count = 0;
        int rank = -1;
        int lo = 0, hi = size - 1;
        while (lo <= hi && value >= arr[lo] && value <= arr[hi]) {
            int pos = lo + ((value - arr[lo]) * (hi - lo)) / (arr[hi] - arr[lo]);
            if (arr[pos] == value) {
                count++;
                if (rank == -1)
                {
                    rank = pos;
                }

            }
            if (arr[pos] < value) {
                lo = pos + 1;
            }
            else {
                hi = pos - 1;
            }
        }
        if (rank != -1) {
            cout << "ʹ�ò�ֵ�����ҵ���С�ȣ�" << rank << "��������" << count << endl;
        }
        else {
            cout << "ʹ�ò�ֵ�����ҵ��޴�Ԫ��" << endl;
        }
    }





    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
    void expand() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
};

int main() {
    SortedVector sortedVector;
    char choose = 'N';
    srand(time(nullptr));

    for (int i = 0; i < 1000; i++) {
        int value = rand() % 1000;
        sortedVector.insert(value);
    }

    cout << "����������ʼ���ݣ�" << endl;
    sortedVector.display();
 flag_insert:
    int insertValue;
    cout << "������Ҫ��������֣�";
    cin >> insertValue;
    sortedVector.insert(insertValue);
    cout << "����Ԫ�غ������������" << endl;
    sortedVector.display();
    cout << "�Ƿ�������루Y/N)" << endl;
    cin >> choose;
    if (choose == 'Y')goto flag_insert;
flag_delet:
    int removeValue;
    cout << "������Ҫɾ�������֣�";
    cin >> removeValue;
    sortedVector.remove(removeValue);
    cout << "ɾ��Ԫ�غ������������" << endl;
    sortedVector.display();
    cout << "�Ƿ����ɾ����Y/N)" << endl;
    cin >> choose;
    if (choose == 'Y')goto flag_delet;
flag_find:
    int searchValue;
    clock_t start, end;
    cout << "������Ҫ���ҵ����֣�";
    cin >> searchValue;
  

    start = clock();
    sortedVector.search_line(searchValue);
    end = clock();
    cout << "��һ����ʱ�䣺" << (double)(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << endl;

    start = clock();
    sortedVector.search_bin(searchValue);
    end = clock();
    cout << "���ֲ���ʱ�䣺" << (double)(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << endl;

    start = clock();
    sortedVector.search_insert(searchValue);
    end = clock();
    cout << "��ֵ����ʱ�䣺" << (double)(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
    cout << "�Ƿ�������ң�Y/N)" << endl;
    cin >> choose;
    if (choose == 'Y')goto flag_find;


    return 0;
}
