# include"cClient.h"
#include<iostream>
#include<string>
using namespace std;

int main() {
	cClient Client1;
	string a, b;
	cout << "请输入服务器名与用户名" << endl;
	cin >> a >> b;
	Client1.SetName(a);
	Client1.SetServerName(b);
	Client1.Display();
	cout << "当前一共输入了" << cClient::getClientNum() << "个服务器名称" << endl;
	cClient Client2;
	cout << "请输入服务器名与用户名" << endl;
	cin >> a >> b;
	Client2.SetName(a);
	Client2.SetServerName(b);
	Client2.Display();
	cout << "当前一共输入了" << cClient::getClientNum() << "个服务器名称" << endl;

	return 0;


}
