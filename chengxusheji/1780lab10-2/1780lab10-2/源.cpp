#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sentence, keyword;
    int index = 0, num = 0;
    

    cout << "请输入一段英文句子：" << endl;
    getline(cin, sentence);

    while (true)
    {
        cout << "请输入需要查找的关键词：" << endl;
        getline(cin, keyword);

        if (keyword.length() == 0)
        {
            cout << "关键词不能为空，请重新输入！" << endl;
            continue;
        }
       
        index = sentence.find(keyword);

        if (index== string::npos)
        {
            cout << "无法找到关键词，请重新输入！" << endl;
            continue;
        }

        while (index != string::npos)
        {
            num++;
            index = sentence.find(keyword, index + 1);
        }

        cout << "关键词第一次出现的位置为：" << sentence.find(keyword) + 1 << endl;
        cout << "关键词出现的总次数为：" << num << endl;
        break;
    }

    return 0;
}

