#include <iostream>
#include <ctime>
#include <cstdlib>
// ���������ඨ��
class SortedVector {
private:
    int* data; // ���ݴ洢����
    int size;  // �����С

public:
    SortedVector(int maxSize) {
        data = new int[maxSize];
        size = 0;
    }

    ~SortedVector() {
        delete[] data;
    }

    // ����һ��Ԫ�ز���������
    void insert(int value) {
        int i = size - 1;
        while (i >= 0 && data[i] > value) {
            data[i + 1] = data[i];
            i--;
        }
        data[i + 1] = value;
        size++;
    }

    // ���ֲ����㷨����Ԫ��λ��
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

    // ���Բ����㷨���ҵ�һ��ƥ���Ԫ��λ��
    int linearSearch(int value) {
        for (int i = 0; i < size; ++i) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }

    // ˳������㷨���ҵ�һ��ƥ���Ԫ��λ��
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

    // ��ȡ������С
    int getSize() {
        return size;
    }
};

int main() {
    int maxSize = 1000;  // �����������
    SortedVector vec(maxSize);

    // �������������������
    srand(time(NULL));
    for (int i = 0; i < maxSize; ++i) {
        vec.insert(rand() % 10000);  // ����0��9999�������
    }

    // �Ӽ�������Ҫ���ҵ���
    int target;
    std::cout << "������Ҫ���ҵ�����";
    std::cin >> target;

    // ʹ�������㷨���Ҳ�ͳ��������������ʱ��
    int minRank;
    int count = 0;
    clock_t start, end;

    // ���ֲ����㷨
    start = clock();
    minRank = vec.binarySearch(target);
    end = clock();
    if (minRank != -1) {
        count++;
    }
    std::cout << "���ֲ��ҽ����";
    if (minRank != -1) {
        std::cout << "Ԫ�������������е���С��Ϊ" << minRank << std::endl;
    }
    else {
        std::cout << "�޴�Ԫ��" << std::endl;
    }
    std::cout << "���ֲ���ʱ�䣺" << (double)(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << std::endl;

    // ���Բ����㷨
    start = clock();
    minRank = vec.linearSearch(target);
    end = clock();
    if (minRank != -1) {
        count++;
    }
    std::cout << "���Բ��ҽ����";
    if (minRank != -1) {
        std::cout << "Ԫ�������������е���С��Ϊ" << minRank << std::endl;
    }
    else {
        std::cout << "�޴�Ԫ��" << std::endl;
    }
    std::cout << "���Բ���ʱ�䣺" << (double)(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << std::endl;

    // ˳������㷨
    start = clock();
    minRank = vec.sequentialSearch(target);
    end = clock();
    if (minRank != -1) {
        count++;
    }
    std::cout << "˳����ҽ����";
    if (minRank != -1) {
        std::cout << "Ԫ�������������е���С��Ϊ" << minRank << std::endl;
    }
    else {
        std::cout << "�޴�Ԫ��" << std::endl;
    }
    std::cout << "˳�����ʱ�䣺" << (double)(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << std::endl;

    // ͳ������
    std::cout << "���������е���" << target << "��Ԫ������Ϊ" << count << std::endl;

    return 0;
}