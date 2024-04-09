#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
// �鲢����
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

    while (i < n1 && j < n2)//���������������Ԫ�ؽ��бȽ�
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

// �鲢����
void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// ð������
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

    // ������������A����������B
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
    // �鲢������������A����ʱ
    clock_t start_time = clock();
    mergeSort(unorderedVec, 0, n - 1);
    clock_t end_time = clock();
    double mergeSortTime = double(end_time - start_time) / CLOCKS_PER_SEC;

    // ����鲢��������ʱ��
    cout << "�鲢�����������������" <<endl;
    cout << "�鲢�����±�Ϊ[0~19]���ʾ����" << endl;
    for (int i = 0; i < 20; i++) {
       cout << unorderedVec[i] << " ";
    }
    cout << endl;
    cout << "�鲢�����±�Ϊ[50000~50019]���ʾ����" << endl;
    for (int i = 50000; i < 50020; i++) {
        cout << unorderedVec[i] << " ";
    }
    cout << endl;
    cout << "�鲢�����±�Ϊ[99980~99999]���ʾ����" << endl;
    for (int i = 99980; i < 100000; i++) {
        cout << unorderedVec[i] << " ";
    }
    cout << endl;
    cout << "�鲢������������ʱ�䣺" << mergeSortTime << "��" << endl;

    // ð��������������A����ʱ
    start_time = clock();
    bubbleSort(unorderedVec, n);
    end_time = clock();
    double bubbleSortTime = double(end_time - start_time) / CLOCKS_PER_SEC;

    // ���ð����������ʱ��
    cout << "ð���������������Ľ����" << endl;
        cout << "ð�������±�Ϊ[0~19]���ʾ����" << endl;
    for (int i = 0; i < 20; i++) {
       cout << unorderedVec[i] << " ";
    }
    cout << endl;
    cout << "ð�������±�Ϊ[50000~50019]���ʾ����" << endl;
    for (int i = 50000; i < 50020; i++) {
        cout << unorderedVec[i] << " ";
    }
    cout << endl;
    cout << "ð�������±�Ϊ[99980~99999]���ʾ����" << endl;
    for (int i = 99980; i < 100000; i++) {
        cout << unorderedVec[i] << " ";
    }
   cout << endl;
    cout << "ð����������������ʱ�䣺" << bubbleSortTime << "��" << endl;

    // �鲢������������B����ʱ
    start_time = clock();
    mergeSort(reverseVec, 0, n - 1);
    end_time = clock();
    double mergeSortReverseTime = double(end_time - start_time) / CLOCKS_PER_SEC;

    // ����鲢������������B�����ʱ��
    cout << "�鲢������������" << endl;
    cout << "�鲢�����±�Ϊ[0~19]���ʾ����" << endl;
    for (int i = 0; i < 20; i++) {
        cout << reverseVec[i] << " ";
    }
    cout << endl;
    cout << "�鲢�����±�Ϊ[50000~50019]���ʾ����" << endl;
    for (int i = 50000; i < 50020; i++) {
        cout << reverseVec[i] << " ";
    }
    cout << endl;
    cout << "�鲢�����±�Ϊ[99980~99999]���ʾ����" << endl;
    for (int i = 99980; i < 100000; i++) {
        cout << reverseVec[i] << " ";
    }
    cout << endl;
    cout << "�鲢����B����ʱ�䣺" << mergeSortReverseTime << "��" <<endl;

    // ð��������������B����ʱ
    start_time = clock();
    bubbleSort(reverseVec, n);
    end_time = clock();
    double bubbleSortReverseTime = double(end_time - start_time) / CLOCKS_PER_SEC;

    // ���ð����������ʱ��
    cout << "ð��������������" << endl;
    cout << "ð�������±�Ϊ[0~19]���ʾ����" << endl;
    for (int i = 0; i < 20; i++) {
        cout << reverseVec[i] << " ";
    }
    cout << endl;
    cout << "ð�������±�Ϊ[50000~50019]���ʾ����" << endl;
    for (int i = 50000; i < 50020; i++) {
        cout << reverseVec[i] << " ";
    }
    cout << endl;
    cout << "ð�������±�Ϊ[99980~99999]���ʾ����" << endl;
    for (int i = 99980; i < 100000; i++) {
        cout << reverseVec[i] << " ";
    }
    cout << std::endl;
    cout << "ð����������ʱ�䣺" << bubbleSortReverseTime << "��" << endl;

    delete[] unorderedVec;
    delete[] reverseVec;
//    delete[] tempVec;
    return 0;
}
