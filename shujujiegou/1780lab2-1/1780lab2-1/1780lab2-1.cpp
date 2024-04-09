#include <iostream>
#include <cstdlib>
#include <ctime>
#include "pch.h"

using namespace std;

// 自定义无序向量结构
struct Vector {
    int* data;       // 数据数组
    int capacity;    // 容量
    int size;        // 当前大小
};

// 初始化无序向量
void initVector(Vector& vec, int capacity) {
    vec.data = new int[capacity];
    vec.capacity = capacity;
    vec.size = 0;
}

// 销毁无序向量
void destroyVector(Vector& vec) {
    delete[] vec.data;
}

// 扩容无序向量
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

// 向无序向量中插入元素
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

// 从无序向量中删除元素
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

// 在无序向量中查找元素
int findElement(const Vector& vec, int element) {
    for (int i = 0; i < vec.size; i++) {
        if (vec.data[i] == element) {
            return i;
        }
    }
    return -1;
}

// 随机生成n个整数的无序向量
void generateRandomVector(Vector& vec, int n) {
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        insertElement(vec, i, rand() % 100);
    }
}

// 输出向量内容
void printVector(const Vector& vec) {
    for (int i = 0; i < vec.size; i++) {
        cout << vec.data[i] << " ";
    }
    cout << endl;
}

int main() {
    Vector vec;
    initVector(vec, 20);

    // 随机生成10个整数的无序向量，并输出内容
    generateRandomVector(vec, 10);
    cout << "随机生成的无序向量：";
    printVector(vec);

    // 插入操作
    int _insertRank, _insertElement;
    cout << "请输入要插入的位置和元素（中间用空格隔开）：";
    cin >> _insertRank >> _insertElement;
    insertElement(vec, _insertRank, _insertElement);
    cout << "插入元素后的无序向量：";
    printVector(vec);

    // 删除操作
    int _removeRank, _removeCount;
    cout << "请输入要删除的起始位置和元素个数（中间用空格隔开）：";
    cin >> _removeRank >> _removeCount;
    removeElements(vec, _removeRank, _removeCount);
    cout << "删除元素后的无序向量：";
    printVector(vec);

    // 查找操作
    int _findElement;
    cout << "请输入要查找的元素：";
    cin >> _findElement;
    int _foundRank = findElement(vec, _findElement);
    if (_foundRank != -1) {
        cout << "元素 " << _findElement << " 在无序向量中的秩为：" << _foundRank << endl;
    }
    else {
        cout << "无此元素" << endl;
    }

    destroyVector(vec);

    return 0;
}
