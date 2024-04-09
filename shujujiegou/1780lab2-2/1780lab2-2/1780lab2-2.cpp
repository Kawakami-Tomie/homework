// 1780lab2-2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

//typedef int Rank;
//#define DEFAULT_CAPACITY 10//默认初始容量
//template <typename T> class Vector
//{
//
//protected:
//
//    Rank _size; Rank lo; Rank hi; int _capacity; T* _elem;T* _origin_elem;
//    void copyFrom(T const* A, Rank lo, Rank hi);
//    void expand();
//    bool bubble(Rank lo, Rank hi);//扫描交换
//public:
//    //构造函数
//    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)//容量为c，规模为s，所有元素初始化为v
//    {
//        _elem = new T[_capacity = c]; for (_size = 0; _size < s; _elem[_size++] = v);
//    }
//    Vector (Vector<T> const&V){copyFrom(V._elem,0,V._size) }//向量整体复制
//    Vector(Vector<T> const& V , Rank lo,Rank hi) { copyFrom(V._elem, lo,hi) }//区间
//
//    //析构函数
//    ~Vector() { delete[] _elem; }//释放内部空间
//   
//    
//    //只读访问接口
//    Rank size() const { return _size; }
//    Rank find(T const& e)const { return find(e, 0, _size); }//无序向量整体查找
//    Rank find(T const& e, Rank lo, Rank hi)const;//无序向量区间查找
//    Rank search(T const& e)const//有序向量整体查找
//    {
//        return (0 >= _size) ? -1 : search(e, 0, _size);
//    }
//    Rank search(T const& e, Rank lo, Rank hi)const;//无序向量区间查找
//
//
//    //可写访问接口
//    T& operator[](Rank r) const;//重载下标操作符
//    Vector<T>& operator=(Vector<T> const&);
//    T remove(Rank r);
//    int remove(Rank lo, Rank hi);
//    Rank insert(Rank r, T const& e);//插入元素
//    void sort(Rank lo, Rank hi);
//    void sort() { sort(0, _size); }
//    void unsort(Rank lo, Rank hi);//对[lo,hi)置乱
//    void unsort() {unsorted(0,_size) };//整体置乱
//    int deduplicate();//无序去重
//    int uniquify();//有序去重
//
//    //遍历
//    void traverse(void(*)(T&));//遍历（使用函数指针，只读或局部修改）
//    template <typename VST> void traverse(VST&);//遍历（使用函数对象，可全局修改）
//
//};
//Vector 确定向量的ADT接口，定义Vector模板类


void RandomArray(int arr[], int n)//生成随机数列
{
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}



int main()
{
    int origin_arr[10];
    RandomArray(origin_arr, 10);
    


    cout << "Hello World!\n";
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
