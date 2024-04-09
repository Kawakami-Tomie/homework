#include <iostream>
#include <vector>
#include <algorithm>

// 生成随机数
int generateRandomNumber() {
    return rand() % 1000 + 1;  // 生成1~1000的随机数
}

// 生成有序向量
std::vector<int> generateSortedVector(int size) {
    std::vector<int> vec;
    for (int i = 0; i < size; i++) {
        vec.push_back(generateRandomNumber());
    }
    std::sort(vec.begin(), vec.end());  // 对向量进行排序
    return vec;
}

// 二分查找
int binarySearch(const std::vector<int>& vec, int target, int& count) {
    int left = 0, right = vec.size() - 1;
    int minRank = INT_MAX;
    count = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target) {
            minRank = std::min(minRank, mid);
            count++;
            right = mid - 1;  // 继续向左查找更小的秩
        }
        else if (vec[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return minRank;
}

int main() {
    const int size = 1000;
    std::vector<int> sortedVec = generateSortedVector(size);

    // 输出有序向量
    std::cout << "有序向量：" << std::endl;
    for (int i = 0; i < sortedVec.size(); i++) {
        std::cout << sortedVec[i] << " ";
    }
    std::cout << std::endl;

    // 从键盘输入一个数
    int target;
    std::cout << "请输入一个数：";
    std::cin >> target;

    // 二分查找并统计数量
    int count;
    int minRank = binarySearch(sortedVec, target, count);

    // 输出结果
    if (count > 0) {
        std::cout << "最小秩：" << minRank << std::endl;
        std::cout << "数量：" << count << std::endl;
    }
    else {
        std::cout << "无此元素" << std::endl;
    }

    return 0;
}
