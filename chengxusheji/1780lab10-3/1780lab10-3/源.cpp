#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	int a;
	char chr, chr0;
	vector<int> number;
flag:
	cout << "������һ��������Կ,���Ȳ�����10������Ϊ����1 - 4�����" << endl;
	while (cin >> a) {
		number.push_back(a);
		chr=cin.get();
		if (chr != ' ')
			break;
		if (number.size() >= 10) {
			cout << "������Կ���ȳ���10�����������룡" << endl;
			goto flag;
		}
	}

	string sentence;
	cout << "������һ����Ҫ���ܵ��ַ���,��������ĸ�����֡��ո�" << endl;
	
	getline(cin, sentence);//��ȡ����
	int j = 0;
	for (int i = 0; i < sentence.length(); i++)//����
	{
		sentence[i] += number[j];
		j++;
		if (j == number.size())//ѭ��
			j = 0;
		
	}
	cout << "���ܺ������Ϊ" << sentence << endl;
	j = 0;
	for (int i = 0; i < sentence.length(); i++)//����
	{
		sentence[i] -= number[j];
		j++;
		if (j == number.size())
			j = 0;
	}
	vector<int> number0;
flag0:cout << "��������Կ�Խ⿪����" << endl;
	while (cin >> a) {
		number0.push_back(a);
		chr0=cin.get();
		if (chr0 != ' ')
			break;
	}
	for (int m = 0; m < number.size(); m++)
	{
		if (number[m] != number0[m]) {
			cout << "�޷����ܣ����������룡" << endl;
			goto flag0;
		}
	}
	cout << "���ܺ���ַ���Ϊ��" << sentence << endl;
	return 0;

}

