#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// 无序向量结构体
struct Vector {
    int* data;       // 数据数组
    int capacity;    // 容量
    int size;        // 当前大小
};


void initVector(Vector& vec, int capacity) {
    vec.data = new int[capacity]; //申请数组空间
    vec.capacity = capacity;
    vec.size = 0;
}

// 销毁
void destroyVector(Vector& vec) {
    delete[] vec.data;
}

// 扩容
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

// 删除
bool removeElements(Vector& vec, int rank, int count) {
    if (rank < 0 || rank + count > vec.size) {
        return false;
    }
    for (int i = rank; i < vec.size - count; i++)//后面的元素前移
    {
        vec.data[i] = vec.data[i + count];
    }
    vec.size -= count;
    return true;
}

//逐一查找
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
    initVector(vec, 20);//初始容量为20
    char choose='N';

    // 随机生成10个整数的无序向量，并输出内容
    generateRandomVector(vec, 10);
    cout << "随机生成的无序向量：";
    printVector(vec);

    // 插入操作
    int insertRank, insertValue;
    bool overall_insert;
 flag_insert:
    cout << "请输入要插入的位置和元素：";
    cin >> insertRank >> insertValue;
    overall_insert=insertElement(vec, insertRank, insertValue);
    if (overall_insert== false)
    {
        cout << "插入位置超出向量范围,请重新输入" << endl; goto flag_insert;
    }
    else

    cout << "插入元素后的无序向量：";
    printVector(vec);
    cout << "是否继续插入（Y/N）" << endl;
    cin >> choose;
    if (choose == 'Y')goto flag_insert;

    // 删除操作
    int removeRank, removeCount,first_remove;
    bool overall_remove;
flag_remove:
    cout << "请输入要删除的起始位置和元素个数：";
    cin >> removeRank >> removeCount;
    first_remove = vec.data[removeRank];
    overall_remove=removeElements(vec, removeRank, removeCount);
    if (overall_remove == false)
    {
        cout << "删除位置或者元素个数超出向量范围, 请重新输入" << endl;
        goto flag_remove;
    }
    else
    cout << "第一个被删除的元素为" << first_remove << endl;
    cout << "删除元素后的无序向量：";
    printVector(vec);
    cout << "是否继续删除（Y/N）" << endl;
    cin >> choose;
    if (choose == 'Y')goto flag_remove;


    // 查找操作
    int findValue;
flag_find:
    cout << "请输入要查找的元素：";
    cin >> findValue;
    int foundRank = findElement(vec, findValue);
    if (foundRank != -1) {
        cout << "元素 " << findValue << " 在无序向量中的秩为：" << foundRank << endl;
    }
    else {
        cout << "无此元素" << endl;
    }

    cout << "是否继续查找（Y/N）" << endl;
    cin >> choose;
    if (choose == 'Y')goto flag_find;



    destroyVector(vec);

    return 0;
}
