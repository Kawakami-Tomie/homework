#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
void PrintF(string& StringPrint)//���
{
    cout << StringPrint << endl;
}

int main() 
{
    int m = 0;
    vector<string> English;
    vector<string>::iterator EnglishIterator;//������������string���󣬶���������Χ

    string str;
    char chr;

    cout << "�������������ϵ�Ӣ�ģ�" << endl;
    while (cin >> str)
    {
        English.push_back(str);//���µ�Ԫ�ؼ���vector�����
        chr=cin.get();//���ڶ�ȡ���ݣ��ӵ�һλ���ո�
        if (chr != ' ')//enter
            break;
    }

    cout << "����ĵ���˳��:" << endl;
    for_each(English.begin(), English.end(), PrintF);//������������һ�������һ�������
    sort(English.begin(), English.end());//������������
    cout << "�����ĵ���˳��" << endl;
    for (int i = 0; i < English.size(); i++)
    {
        cout << English[i] << " ";
    }

    return 0;
}

