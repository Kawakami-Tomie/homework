#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	int a;
	char chr, chr0;
	vector<int> number;
flag:
	cout << "请输入一个加密密钥,长度不超过10，内容为数字1 - 4的组合" << endl;
	while (cin >> a) {
		number.push_back(a);
		chr=cin.get();
		if (chr != ' ')
			break;
		if (number.size() >= 10) {
			cout << "加密密钥长度超过10，请重新输入！" << endl;
			goto flag;
		}
	}

	string sentence;
	cout << "请输入一个需要加密的字符串,仅包含字母、数字、空格" << endl;
	
	getline(cin, sentence);//读取数据
	int j = 0;
	for (int i = 0; i < sentence.length(); i++)//加密
	{
		sentence[i] += number[j];
		j++;
		if (j == number.size())//循环
			j = 0;
		
	}
	cout << "加密后的密文为" << sentence << endl;
	j = 0;
	for (int i = 0; i < sentence.length(); i++)//解密
	{
		sentence[i] -= number[j];
		j++;
		if (j == number.size())
			j = 0;
	}
	vector<int> number0;
flag0:cout << "请输入密钥以解开密文" << endl;
	while (cin >> a) {
		number0.push_back(a);
		chr0=cin.get();
		if (chr0 != ' ')
			break;
	}
	for (int m = 0; m < number.size(); m++)
	{
		if (number[m] != number0[m]) {
			cout << "无法解密，请重新输入！" << endl;
			goto flag0;
		}
	}
	cout << "解密后的字符串为：" << sentence << endl;
	return 0;

}

