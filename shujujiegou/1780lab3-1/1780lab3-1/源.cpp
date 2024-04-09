#include <iostream>
#include<ctime>
#include <cstdlib>
using namespace std;
class SortedVector {
private:
    int* arr;//数组
    int size;//当前大小
    int capacity;//容量

public:
    SortedVector() {
        capacity = 10;
        size = 0;
        arr = new int[capacity];
    }

    ~SortedVector() {
        delete[] arr;
    }

    void insert(int value) {
        if (size == capacity) {
            expand();
        }

        int i = size - 1;
        while (i >= 0 && arr[i] > value)//大于value的都后移
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = value;
        size++;
    }

    void remove(int value) {
        int i = 0, j = 0;

        while (j < size) {//逐一判断是否相同
            if (arr[j] != value) {
                arr[i] = arr[j];
                i++;
            }
            j++;
        }

        size = i;
    }

    void search_line(int value)//逐一查找法
    {
        int count = 0;
        int rank = -1;

        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                if (rank == -1) {
                    rank = i;
                }
                count++;

            }
        }

        if (rank != -1) {
            cout << "使用逐一查找最小秩：" << rank << "，数量：" << count << endl;
        }
        else {
            cout << "使用逐一查找无此元素" << endl;
        }
    }

    // 使用二分查找算法找到第一个等于给定元素的位置并统计数量
    void search_bin(int value)
    {
        int count = 0;
        int rank = -1;
        int lo = 0, hi = size - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] < value) //深入后半段(mi, hi)
            {
                lo = mid + 1;
            }
            else if (arr[mid] > value)//深入前半段[lo, mi)继续查找
            {
                hi = mid - 1;
            }
            else//mid=value
            {
                if (rank == -1)
                {
                    rank = mid;
                }
                count++;
                hi = mid - 1;//查找更小的秩
            }
        }
        if (rank != -1) {
            cout << "使用二分法查找到最小秩：" << rank << "，数量：" << count << endl;
        }
        else {
            cout << "使用二分法查找到无此元素" << endl;
        }

    }



    void search_insert(int value)//插值法
    {
        int count = 0;
        int rank = -1;
        int lo = 0, hi = size - 1;
        while (lo <= hi && value >= arr[lo] && value <= arr[hi]) {
            int pos = lo + ((value - arr[lo]) * (hi - lo)) / (arr[hi] - arr[lo]);
            if (arr[pos] == value) {
                count++;
                if (rank == -1)
                {
                    rank = pos;
                }

            }
            if (arr[pos] < value) {
                lo = pos + 1;
            }
            else {
                hi = pos - 1;
            }
        }
        if (rank != -1) {
            cout << "使用插值法查找到最小秩：" << rank << "，数量：" << count << endl;
        }
        else {
            cout << "使用插值法查找到无此元素" << endl;
        }
    }





    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
    void expand() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
};

int main() {
    SortedVector sortedVector;
    char choose = 'N';
    srand(time(nullptr));

    for (int i = 0; i < 1000; i++) {
        int value = rand() % 1000;
        sortedVector.insert(value);
    }

    cout << "有序向量初始内容：" << endl;
    sortedVector.display();
 flag_insert:
    int insertValue;
    cout << "请输入要插入的数字：";
    cin >> insertValue;
    sortedVector.insert(insertValue);
    cout << "插入元素后的有序向量：" << endl;
    sortedVector.display();
    cout << "是否继续插入（Y/N)" << endl;
    cin >> choose;
    if (choose == 'Y')goto flag_insert;
flag_delet:
    int removeValue;
    cout << "请输入要删除的数字：";
    cin >> removeValue;
    sortedVector.remove(removeValue);
    cout << "删除元素后的有序向量：" << endl;
    sortedVector.display();
    cout << "是否继续删除（Y/N)" << endl;
    cin >> choose;
    if (choose == 'Y')goto flag_delet;
flag_find:
    int searchValue;
    clock_t start, end;
    cout << "请输入要查找的数字：";
    cin >> searchValue;
  

    start = clock();
    sortedVector.search_line(searchValue);
    end = clock();
    cout << "逐一查找时间：" << (double)(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << endl;

    start = clock();
    sortedVector.search_bin(searchValue);
    end = clock();
    cout << "二分查找时间：" << (double)(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << endl;

    start = clock();
    sortedVector.search_insert(searchValue);
    end = clock();
    cout << "插值查找时间：" << (double)(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
    cout << "是否继续查找（Y/N)" << endl;
    cin >> choose;
    if (choose == 'Y')goto flag_find;


    return 0;
}
