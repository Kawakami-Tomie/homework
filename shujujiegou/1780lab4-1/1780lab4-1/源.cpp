#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
// 归并操作
void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)//对两个数组最左边元素进行比较
    {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// 归并排序
void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// 冒泡排序
void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSort_reverseVec(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n = 100000;

    // 生成无序向量A和逆序向量B
    int* unorderedVec = new int[n];
    int* reverseVec = new int[n];
 //   int* tempVec = new int[n];
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        int value =( rand() % 200000 + 1)*6.1;
        unorderedVec[i] = value;
        reverseVec[i] = value;
    }
    bubbleSort_reverseVec(reverseVec, n);
    //for (int i = 0; i < 100000; i++)
    //{
    //    reverseVec[i] = tempVec[n-1];
    //    n--;
    //        
    //}
    for (int i = 0; i < 100000; i++) {
            cout << reverseVec[i] << " ";
         }
    cout << endl;
    // 归并排序无序向量A并计时
    clock_t start_time = clock();
    mergeSort(unorderedVec, 0, n - 1);
    clock_t end_time = clock();
    double mergeSortTime = double(end_time - start_time) / CLOCKS_PER_SEC;

    // 输出归并排序结果和时间
    cout << "归并排序无序向量结果：" <<endl;
    cout << "归并排序下标为[0~19]结果示例：" << endl;
    for (int i = 0; i < 20; i++) {
       cout << unorderedVec[i] << " ";
    }
    cout << endl;
    cout << "归并排序下标为[50000~50019]结果示例：" << endl;
    for (int i = 50000; i < 50020; i++) {
        cout << unorderedVec[i] << " ";
    }
    cout << endl;
    cout << "归并排序下标为[99980~99999]结果示例：" << endl;
    for (int i = 99980; i < 100000; i++) {
        cout << unorderedVec[i] << " ";
    }
    cout << endl;
    cout << "归并排序无序向量时间：" << mergeSortTime << "秒" << endl;

    // 冒泡排序无序向量A并计时
    start_time = clock();
    bubbleSort(unorderedVec, n);
    end_time = clock();
    double bubbleSortTime = double(end_time - start_time) / CLOCKS_PER_SEC;

    // 输出冒泡排序结果和时间
    cout << "冒泡排序无序向量的结果：" << endl;
        cout << "冒泡排序下标为[0~19]结果示例：" << endl;
    for (int i = 0; i < 20; i++) {
       cout << unorderedVec[i] << " ";
    }
    cout << endl;
    cout << "冒泡排序下标为[50000~50019]结果示例：" << endl;
    for (int i = 50000; i < 50020; i++) {
        cout << unorderedVec[i] << " ";
    }
    cout << endl;
    cout << "冒泡排序下标为[99980~99999]结果示例：" << endl;
    for (int i = 99980; i < 100000; i++) {
        cout << unorderedVec[i] << " ";
    }
   cout << endl;
    cout << "冒泡排序无序向量的时间：" << bubbleSortTime << "秒" << endl;

    // 归并排序逆序向量B并计时
    start_time = clock();
    mergeSort(reverseVec, 0, n - 1);
    end_time = clock();
    double mergeSortReverseTime = double(end_time - start_time) / CLOCKS_PER_SEC;

    // 输出归并排序逆序向量B结果和时间
    cout << "归并排序逆序结果：" << endl;
    cout << "归并排序下标为[0~19]结果示例：" << endl;
    for (int i = 0; i < 20; i++) {
        cout << reverseVec[i] << " ";
    }
    cout << endl;
    cout << "归并排序下标为[50000~50019]结果示例：" << endl;
    for (int i = 50000; i < 50020; i++) {
        cout << reverseVec[i] << " ";
    }
    cout << endl;
    cout << "归并排序下标为[99980~99999]结果示例：" << endl;
    for (int i = 99980; i < 100000; i++) {
        cout << reverseVec[i] << " ";
    }
    cout << endl;
    cout << "归并排序B逆序时间：" << mergeSortReverseTime << "秒" <<endl;

    // 冒泡排序逆序向量B并计时
    start_time = clock();
    bubbleSort(reverseVec, n);
    end_time = clock();
    double bubbleSortReverseTime = double(end_time - start_time) / CLOCKS_PER_SEC;

    // 输出冒泡排序结果和时间
    cout << "冒泡排序逆序结果：" << endl;
    cout << "冒泡排序下标为[0~19]结果示例：" << endl;
    for (int i = 0; i < 20; i++) {
        cout << reverseVec[i] << " ";
    }
    cout << endl;
    cout << "冒泡排序下标为[50000~50019]结果示例：" << endl;
    for (int i = 50000; i < 50020; i++) {
        cout << reverseVec[i] << " ";
    }
    cout << endl;
    cout << "冒泡排序下标为[99980~99999]结果示例：" << endl;
    for (int i = 99980; i < 100000; i++) {
        cout << reverseVec[i] << " ";
    }
    cout << std::endl;
    cout << "冒泡排序逆序时间：" << bubbleSortReverseTime << "秒" << endl;

    delete[] unorderedVec;
    delete[] reverseVec;
//    delete[] tempVec;
    return 0;
}
