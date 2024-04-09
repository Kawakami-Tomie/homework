#include <iostream>
#include <cstdlib>
#include <ctime>

// �Զ������������ṹ
struct Vector {
    int* data;       // ��������
    int capacity;    // ����
    int size;        // ��ǰ��С
};

// ��ʼ����������
void initVector(Vector& vec, int capacity) {
    vec.data = new int[capacity];
    vec.capacity = capacity;
    vec.size = 0;
}

// ������������
void destroyVector(Vector& vec) {
    delete[] vec.data;
}

// ������������
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

// ������������ɾ��Ԫ��
bool removeElements(Vector& vec, int rank, int count) {
    if (rank < 0 || rank + count > vec.size) {
        return false;
    }
    for (int i = rank; i < vec.size - count; i++) {
        vec.data[i] = vec.data[i + count];
    }
    vec.size -= count;
    return true;
}

// �����������в���Ԫ��
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
        std::cout << vec.data[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    Vector vec;
    initVector(vec, 20);

    // �������10���������������������������
    generateRandomVector(vec, 10);
    std::cout << "������ɵ�����������";
    printVector(vec);

    // �������
    int insertRank, insertValue;
    std::cout << "������Ҫ�����λ�ú�Ԫ�أ��м��ÿո��������";
    std::cin >> insertRank >> insertValue;
    insertElement(vec, insertRank, insertValue);
    std::cout << "����Ԫ�غ������������";
    printVector(vec);

    // ɾ������
    int removeRank, removeCount;
    std::cout << "������Ҫɾ������ʼλ�ú�Ԫ�ظ������м��ÿո��������";
    std::cin >> removeRank >> removeCount;
    removeElements(vec, removeRank, removeCount);
    std::cout << "ɾ��Ԫ�غ������������";
    printVector(vec);

    // ���Ҳ���
    int findValue;
    std::cout << "������Ҫ���ҵ�Ԫ�أ�";
    std::cin >> findValue;
    int foundRank = findElement(vec, findValue);
    if (foundRank != -1) {
        std::cout << "Ԫ�� " << findValue << " �����������е���Ϊ��" << foundRank << std::endl;
    }
    else {
        std::cout << "�޴�Ԫ��" << std::endl;
    }

    destroyVector(vec);

    return 0;
}
