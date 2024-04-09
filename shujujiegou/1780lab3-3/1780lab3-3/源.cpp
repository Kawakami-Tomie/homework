#include <iostream>
#include <ctime>
#include <cstdlib>
// 有序向量类定义
class SortedVector {
private:
    int* data; // 数据存储数组
    int size;  // 数组大小

public:
    SortedVector(int maxSize) {
        data = new int[maxSize];
        size = 0;
    }

    ~SortedVector() {
        delete[] data;
    }

    // 插入一个元素并保持有序
    void insert(int value) {
        int i = size - 1;
        while (i >= 0 && data[i] > value) {
            data[i + 1] = data[i];
            i--;
        }
        data[i + 1] = value;
        size++;
    }

    // 二分查找算法查找元素位置
    int binarySearch(int value) {
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (data[mid] == value) {
                return mid;
            }
            else if (data[mid] < value) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }

    // 线性查找算法查找第一个匹配的元素位置
    int linearSearch(int value) {
        for (int i = 0; i < size; ++i) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }

    // 顺序查找算法查找第一个匹配的元素位置
    int sequentialSearch(int value) {
        int i = 0;
        while (i < size && data[i] < value) {
            i++;
        }
        if (data[i] == value) {
            return i;
        }
        else {
            return -1;
        }
    }

    // 获取向量大小
    int getSize() {
        return size;
    }
};

int main() {
    int maxSize = 1000;  // 向量最大容量
    SortedVector vec(maxSize);

    // 生成随机数并插入向量
    srand(time(NULL));
    for (int i = 0; i < maxSize; ++i) {
        vec.insert(rand() % 10000);  // 生成0到9999的随机数
    }

    // 从键盘输入要查找的数
    int target;
    std::cout << "请输入要查找的数：";
    std::cin >> target;

    // 使用三种算法查找并统计数量，并计算时间
    int minRank;
    int count = 0;
    clock_t start, end;

    // 二分查找算法
    start = clock();
    minRank = vec.binarySearch(target);
    end = clock();
    if (minRank != -1) {
        count++;
    }
    std::cout << "二分查找结果：";
    if (minRank != -1) {
        std::cout << "元素在有序向量中的最小秩为" << minRank << std::endl;
    }
    else {
        std::cout << "无此元素" << std::endl;
    }
    std::cout << "二分查找时间：" << (double)(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << std::endl;

    // 线性查找算法
    start = clock();
    minRank = vec.linearSearch(target);
    end = clock();
    if (minRank != -1) {
        count++;
    }
    std::cout << "线性查找结果：";
    if (minRank != -1) {
        std::cout << "元素在有序向量中的最小秩为" << minRank << std::endl;
    }
    else {
        std::cout << "无此元素" << std::endl;
    }
    std::cout << "线性查找时间：" << (double)(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << std::endl;

    // 顺序查找算法
    start = clock();
    minRank = vec.sequentialSearch(target);
    end = clock();
    if (minRank != -1) {
        count++;
    }
    std::cout << "顺序查找结果：";
    if (minRank != -1) {
        std::cout << "元素在有序向量中的最小秩为" << minRank << std::endl;
    }
    else {
        std::cout << "无此元素" << std::endl;
    }
    std::cout << "顺序查找时间：" << (double)(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << std::endl;

    // 统计数量
    std::cout << "有序向量中等于" << target << "的元素数量为" << count << std::endl;

    return 0;
}