#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ���������ṹ��
struct Vector {
    int* data;       // ��������
    int capacity;    // ����
    int size;        // ��ǰ��С
};


void initVector(Vector& vec, int capacity) {
    vec.data = new int[capacity]; //��������ռ�
    vec.capacity = capacity;
    vec.size = 0;
}

// ����
void destroyVector(Vector& vec) {
    delete[] vec.data;
}

// ����
void expandVector(Vector& vec) {
    int newCapacity = vec.capacity * 2;
    int* newData = new int[newCapacity];
    for (int i = 0; i < vec.size; i++) {
        newData[i] = vec.data[i];
    }
    delete[] vec.data;
    vec.data = newData;
    vec.capacity = newCapacity;
}

// �����������в���Ԫ��
bool insertElement(Vector& vec, int rank, int element) {
    if (rank < 0 || rank > vec.size) {
        return false;
    }
    if (vec.size == vec.capacity) {
        expandVector(vec);
    }
    for (int i = vec.size; i > rank; i--) {
        vec.data[i] = vec.data[i - 1];
    }
    vec.data[rank] = element;
    vec.size++;
    return true;
}

// ɾ��
bool removeElements(Vector& vec, int rank, int count) {
    if (rank < 0 || rank + count > vec.size) {
        return false;
    }
    for (int i = rank; i < vec.size - count; i++)//�����Ԫ��ǰ��
    {
        vec.data[i] = vec.data[i + count];
    }
    vec.size -= count;
    return true;
}

//��һ����
int findElement(const Vector& vec, int element) {
    for (int i = 0; i < vec.size; i++) {
        if (vec.data[i] == element) {
            return i;
        }
    }
    return -1;
}

// �������n����������������
void generateRandomVector(Vector& vec, int n) {
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        insertElement(vec, i, rand() % 100);
    }
}

// �����������
void printVector(const Vector& vec) {
    for (int i = 0; i < vec.size; i++) {
       cout << vec.data[i] << " ";
    }
    cout << endl;
}

int main() {
    Vector vec;
    initVector(vec, 20);//��ʼ����Ϊ20
    char choose='N';

    // �������10���������������������������
    generateRandomVector(vec, 10);
    cout << "������ɵ�����������";
    printVector(vec);

    // �������
    int insertRank, insertValue;
    bool overall_insert;
 flag_insert:
    cout << "������Ҫ�����λ�ú�Ԫ�أ�";
    cin >> insertRank >> insertValue;
    overall_insert=insertElement(vec, insertRank, insertValue);
    if (overall_insert== false)
    {
        cout << "����λ�ó���������Χ,����������" << endl; goto flag_insert;
    }
    else

    cout << "����Ԫ�غ������������";
    printVector(vec);
    cout << "�Ƿ�������루Y/N��" << endl;
    cin >> choose;
    if (choose == 'Y')goto flag_insert;

    // ɾ������
    int removeRank, removeCount,first_remove;
    bool overall_remove;
flag_remove:
    cout << "������Ҫɾ������ʼλ�ú�Ԫ�ظ�����";
    cin >> removeRank >> removeCount;
    first_remove = vec.data[removeRank];
    overall_remove=removeElements(vec, removeRank, removeCount);
    if (overall_remove == false)
    {
        cout << "ɾ��λ�û���Ԫ�ظ�������������Χ, ����������" << endl;
        goto flag_remove;
    }
    else
    cout << "��һ����ɾ����Ԫ��Ϊ" << first_remove << endl;
    cout << "ɾ��Ԫ�غ������������";
    printVector(vec);
    cout << "�Ƿ����ɾ����Y/N��" << endl;
    cin >> choose;
    if (choose == 'Y')goto flag_remove;


    // ���Ҳ���
    int findValue;
flag_find:
    cout << "������Ҫ���ҵ�Ԫ�أ�";
    cin >> findValue;
    int foundRank = findElement(vec, findValue);
    if (foundRank != -1) {
        cout << "Ԫ�� " << findValue << " �����������е���Ϊ��" << foundRank << endl;
    }
    else {
        cout << "�޴�Ԫ��" << endl;
    }

    cout << "�Ƿ�������ң�Y/N��" << endl;
    cin >> choose;
    if (choose == 'Y')goto flag_find;



    destroyVector(vec);

    return 0;
}
