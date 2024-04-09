#include <iostream>
#include <vector>
#include <algorithm>

// ���������
int generateRandomNumber() {
    return rand() % 1000 + 1;  // ����1~1000�������
}

// ������������
std::vector<int> generateSortedVector(int size) {
    std::vector<int> vec;
    for (int i = 0; i < size; i++) {
        vec.push_back(generateRandomNumber());
    }
    std::sort(vec.begin(), vec.end());  // ��������������
    return vec;
}

// ���ֲ���
int binarySearch(const std::vector<int>& vec, int target, int& count) {
    int left = 0, right = vec.size() - 1;
    int minRank = INT_MAX;
    count = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target) {
            minRank = std::min(minRank, mid);
            count++;
            right = mid - 1;  // ����������Ҹ�С����
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

    // �����������
    std::cout << "����������" << std::endl;
    for (int i = 0; i < sortedVec.size(); i++) {
        std::cout << sortedVec[i] << " ";
    }
    std::cout << std::endl;

    // �Ӽ�������һ����
    int target;
    std::cout << "������һ������";
    std::cin >> target;

    // ���ֲ��Ҳ�ͳ������
    int count;
    int minRank = binarySearch(sortedVec, target, count);

    // ������
    if (count > 0) {
        std::cout << "��С�ȣ�" << minRank << std::endl;
        std::cout << "������" << count << std::endl;
    }
    else {
        std::cout << "�޴�Ԫ��" << std::endl;
    }

    return 0;
}
