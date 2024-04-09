#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
void PrintF(string& StringPrint)//输出
{
    cout << StringPrint << endl;
}

int main() 
{
    int m = 0;
    vector<string> English;
    vector<string>::iterator EnglishIterator;//迭代器，访问string对象，定义容器范围

    string str;
    char chr;

    cout << "请输入三个以上的英文：" << endl;
    while (cin >> str)
    {
        English.push_back(str);//将新的元素加在vector最后面
        chr=cin.get();//用于读取数据，从第一位到空格
        if (chr != ' ')//enter
            break;
    }

    cout << "输入的单词顺序:" << endl;
    for_each(English.begin(), English.end(), PrintF);//三个参数，第一个，最后一个，输出
    sort(English.begin(), English.end());//用于排序，升序
    cout << "排序后的单词顺序：" << endl;
    for (int i = 0; i < English.size(); i++)
    {
        cout << English[i] << " ";
    }

    return 0;
}

