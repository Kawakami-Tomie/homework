# include"cClient.h"
#include<iostream>
#include<string>
using namespace std;

int main() {
	cClient Client1;
	string a, b;
	cout << "����������������û���" << endl;
	cin >> a >> b;
	Client1.SetName(a);
	Client1.SetServerName(b);
	Client1.Display();
	cout << "��ǰһ��������" << cClient::getClientNum() << "������������" << endl;
	cClient Client2;
	cout << "����������������û���" << endl;
	cin >> a >> b;
	Client2.SetName(a);
	Client2.SetServerName(b);
	Client2.Display();
	cout << "��ǰһ��������" << cClient::getClientNum() << "������������" << endl;

	return 0;


}
