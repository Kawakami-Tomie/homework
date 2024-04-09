

#include <iostream>
#include <cstdlib>   // 包含随机数生成函数所需的头文件
#include <ctime>     // 包含时间函数所需的头文件

// 定义有序向量的类
class SortedVector {
private:
    int* data;   // 存储数据的数组指针
    int size;    // 向量的大小
    int capacity;    // 数组的容量

public:
    // 构造函数
    SortedVector(int initialCapacity = 1000) {
        capacity = initialCapacity;
        data = new int[capacity];
        size = 0;
    }

    // 析构函数
    ~SortedVector() {
        delete[] data;
    }

    // 插入一个元素并保持有序性
    void insert(int num) {
        int i;
        for (i = size - 1; i >= 0 && data[i] > num; i--) {
            data[i + 1] = data[i];
        }
        data[i + 1] = num;
        size++;
    }

    // 使用线性查找算法找到第一个等于给定元素的位置并统计数量
    int linearSearch(int num) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (data[i] == num) {
                count++;
                return i;
            }
        }
        return -1;
    }

    // 使用二分查找算法找到第一个等于给定元素的位置并统计数量
    int binarySearch(int num) {
        int count = 0;
        int low = 0, high = size - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (data[mid] < num) {
                low = mid + 1;
            }
            else if (data[mid] > num) {
                high = mid - 1;
            }
            else {
                count++;
                return mid;
            }
        }
        return -1;
    }

    // 使用插值查找算法找到第一个等于给定元素的位置并统计数量
    int interpolationSearch(int num) {
        int count = 0;
        int low = 0, high = size - 1;
        while (low <= high && num >= data[low] && num <= data[high]) {
            int pos = low + ((num - data[low]) * (high - low)) / (data[high] - data[low]);
            if (data[pos] == num) {
                count++;
                return pos;
            }
            if (data[pos] < num) {
                low = pos + 1;
            }
            else {
                high = pos - 1;
            }
        }
        return -1;
    }
};

int main() {
    SortedVector vector;

    // 生成1000个随机数并插入有序向量
    srand(time(NULL));   // 初始化随机数种子
    for (int i = 0; i < 1000; i++) {
        int num = rand() % 1000;  // 生成0到999之间的随机数
        vector.insert(num);
    }

    int target;

    // 从键盘输入一个数并插入有序向量
    std::cout << "请输入一个数：";
    std::cin >> target;
    vector.insert(target);

    // 从键盘输入一个数并使用线性查找算法找到最小秩并统计数量
    std::cout << "请输入一个数：";
    std::cin >> target;
    int linearRank = vector.linearSearch(target);
    if (linearRank != -1) {
        std::cout << "最小秩：" << linearRank << std::endl;
        std::cout << "数量：" << 1 << std::endl;
    }
    else {
        std::cout << "无此元素" << std::endl;
    }

    // 从键盘输入一个数并使用二分查找算法找到最小秩并统计数量
    std::cout << "请输入一个数：";
    std::cin >> target;
    int binaryRank = vector.binarySearch(target);
    if (binaryRank != -1) {
        std::cout << "最小秩：" << binaryRank << std::endl;
        std::cout << "数量：" << 1 << std::endl;
    }
    else {
        std::cout << "无此元素" << std::endl;
    }

    // 从键盘输入一个数并使用插值查找算法找到最小秩并统计数量
    std::cout << "请输入一个数：";
    std::cin >> target;
    int interpolationRank = vector.interpolationSearch(target);
    if (interpolationRank != -1) {
        std::cout << "最小秩：" << interpolationRank << std::endl;
        std::cout << "数量：" << 1 << std::endl;
    }
    else {
        std::cout << "无此元素" << std::endl;
    }

    return 0;
}