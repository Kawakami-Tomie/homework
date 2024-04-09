// 1780lab1-1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void bubbleSort_diedai(int arr[], int n)//迭代
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1])//大的排后面
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSort_digui(int arr[], int n)//递归
{
    if (n == 1) 
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i]);
        }
    }
    bubbleSort_digui(arr, n - 1);
}

void RandomArray(int arr[], int n)//生成随机数列
{
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

void CountdownArray(int arr[], int n) //生成逆序
{
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

int main() {
  

    int arr_random1[1000];
    int arr_random2[10000];
    int arr_countdown1[1000];
    int arr_countdown2[10000];

    // 生成随机排列
    RandomArray(arr_random1, 1000);
    RandomArray(arr_random2, 10000);

    // 生成逆序
    CountdownArray(arr_countdown1, 1000);
    CountdownArray(arr_countdown2, 10000);

    // 迭代算法排序
    clock_t startTime = clock();
    bubbleSort_diedai(arr_random1, 1000);
    clock_t endTime = clock();
   
    cout << "迭代算法排序1000个随机元素的运行时间：" << double(endTime - startTime) / CLOCKS_PER_SEC << "秒" << endl;
    cout << "下标为0-19的元素分别为：" << endl;
    for (int i = 0; i < 20; i++) {
        cout << arr_random1[i] << " ";
    }
    cout << endl;
    startTime = clock();
    bubbleSort_diedai(arr_countdown1, 1000);
    endTime = clock();
    cout << "迭代算法排序1000个逆序元素的运行时间：" << double(endTime - startTime) / CLOCKS_PER_SEC << "秒" << endl;
    cout << "下标为0-19的元素分别为：" << endl;
    for (int i = 0; i < 20; i++) {
        cout << arr_countdown1[i] << " ";
    }
    cout << endl;
    startTime = clock();
    bubbleSort_diedai(arr_random2, 10000);
    endTime = clock();
    cout << "迭代算法排序10000个随机元素的运行时间：" << double(endTime - startTime) / CLOCKS_PER_SEC << "秒" << endl;
    cout << "下标为0-19的元素分别为：" << endl;
    for (int i = 0; i < 20; i++) {
        cout << arr_random2[i] << " ";
    }
    cout << endl;
    startTime = clock();
    bubbleSort_diedai(arr_countdown2, 10000);
    endTime = clock();
    cout << "迭代算法排序10000个逆序元素的运行时间：" << double(endTime - startTime) / CLOCKS_PER_SEC << "秒" << endl;
    cout << "下标为0-19的元素分别为：" << endl;
    for (int i = 0; i < 20; i++) {
        cout << arr_countdown2[i] << " ";
    }
    cout << endl;
    // 递归算法排序
    startTime = clock();
    bubbleSort_digui(arr_random1, 1000);
    endTime = clock();
    cout << "递归算法排序1000个随机元素的运行时间：" << double(endTime - startTime) / CLOCKS_PER_SEC << "秒" << endl;
    cout << "下标为0-19的元素分别为：" << endl;
    for (int i = 0; i < 20; i++) {
        cout << arr_random1[i] << " ";
    }
    cout << endl;
    startTime = clock();
    bubbleSort_digui(arr_countdown1, 1000);
    endTime = clock();
    cout << "递归算法排序1000个逆序元素的运行时间：" << double(endTime - startTime) / CLOCKS_PER_SEC << "秒" << endl;
    cout << "下标为0-19的元素分别为：" << endl;
    for (int i = 0; i < 20; i++) {
        cout << arr_countdown1[i] << " ";
    }
    cout << endl;
    startTime = clock();
    bubbleSort_digui(arr_random2,10000 );
    endTime = clock();
    cout << "递归算法排序10000个随机元素的运行时间：" << double(endTime - startTime) / CLOCKS_PER_SEC << "秒" << endl;
    cout << "下标为0-19的元素分别为：" << endl;
    for (int i = 0; i < 20; i++) {
        cout << arr_random2[i] << " ";
    }
    cout << endl;
    startTime = clock();
    bubbleSort_digui(arr_countdown2, 10000);
    endTime = clock();
    cout << "递归算法排序10000个逆序元素的运行时间：" << double(endTime - startTime) / CLOCKS_PER_SEC << "秒" << endl;
    for (int i = 0; i < 20; i++) {
        cout << arr_countdown2[i] << " ";
    }
    cout << endl;
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
