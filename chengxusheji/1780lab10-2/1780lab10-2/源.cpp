#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sentence, keyword;
    int index = 0, num = 0;
    

    cout << "������һ��Ӣ�ľ��ӣ�" << endl;
    getline(cin, sentence);

    while (true)
    {
        cout << "��������Ҫ���ҵĹؼ��ʣ�" << endl;
        getline(cin, keyword);

        if (keyword.length() == 0)
        {
            cout << "�ؼ��ʲ���Ϊ�գ����������룡" << endl;
            continue;
        }
       
        index = sentence.find(keyword);

        if (index== string::npos)
        {
            cout << "�޷��ҵ��ؼ��ʣ����������룡" << endl;
            continue;
        }

        while (index != string::npos)
        {
            num++;
            index = sentence.find(keyword, index + 1);
        }

        cout << "�ؼ��ʵ�һ�γ��ֵ�λ��Ϊ��" << sentence.find(keyword) + 1 << endl;
        cout << "�ؼ��ʳ��ֵ��ܴ���Ϊ��" << num << endl;
        break;
    }

    return 0;
}

