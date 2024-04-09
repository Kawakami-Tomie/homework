

#include <iostream>
#include <cstdlib>   // ������������ɺ��������ͷ�ļ�
#include <ctime>     // ����ʱ�亯�������ͷ�ļ�

// ����������������
class SortedVector {
private:
    int* data;   // �洢���ݵ�����ָ��
    int size;    // �����Ĵ�С
    int capacity;    // ���������

public:
    // ���캯��
    SortedVector(int initialCapacity = 1000) {
        capacity = initialCapacity;
        data = new int[capacity];
        size = 0;
    }

    // ��������
    ~SortedVector() {
        delete[] data;
    }

    // ����һ��Ԫ�ز�����������
    void insert(int num) {
        int i;
        for (i = size - 1; i >= 0 && data[i] > num; i--) {
            data[i + 1] = data[i];
        }
        data[i + 1] = num;
        size++;
    }

    // ʹ�����Բ����㷨�ҵ���һ�����ڸ���Ԫ�ص�λ�ò�ͳ������
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

    // ʹ�ö��ֲ����㷨�ҵ���һ�����ڸ���Ԫ�ص�λ�ò�ͳ������
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

    // ʹ�ò�ֵ�����㷨�ҵ���һ�����ڸ���Ԫ�ص�λ�ò�ͳ������
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

    // ����1000���������������������
    srand(time(NULL));   // ��ʼ�����������
    for (int i = 0; i < 1000; i++) {
        int num = rand() % 1000;  // ����0��999֮��������
        vector.insert(num);
    }

    int target;

    // �Ӽ�������һ������������������
    std::cout << "������һ������";
    std::cin >> target;
    vector.insert(target);

    // �Ӽ�������һ������ʹ�����Բ����㷨�ҵ���С�Ȳ�ͳ������
    std::cout << "������һ������";
    std::cin >> target;
    int linearRank = vector.linearSearch(target);
    if (linearRank != -1) {
        std::cout << "��С�ȣ�" << linearRank << std::endl;
        std::cout << "������" << 1 << std::endl;
    }
    else {
        std::cout << "�޴�Ԫ��" << std::endl;
    }

    // �Ӽ�������һ������ʹ�ö��ֲ����㷨�ҵ���С�Ȳ�ͳ������
    std::cout << "������һ������";
    std::cin >> target;
    int binaryRank = vector.binarySearch(target);
    if (binaryRank != -1) {
        std::cout << "��С�ȣ�" << binaryRank << std::endl;
        std::cout << "������" << 1 << std::endl;
    }
    else {
        std::cout << "�޴�Ԫ��" << std::endl;
    }

    // �Ӽ�������һ������ʹ�ò�ֵ�����㷨�ҵ���С�Ȳ�ͳ������
    std::cout << "������һ������";
    std::cin >> target;
    int interpolationRank = vector.interpolationSearch(target);
    if (interpolationRank != -1) {
        std::cout << "��С�ȣ�" << interpolationRank << std::endl;
        std::cout << "������" << 1 << std::endl;
    }
    else {
        std::cout << "�޴�Ԫ��" << std::endl;
    }

    return 0;
}