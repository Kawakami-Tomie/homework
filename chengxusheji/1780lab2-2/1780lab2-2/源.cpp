#include<iostream>
using namespace std;

int main()
{
	int A;
	cout << "请输入A的值：" << endl;
	cin >> A;
	int B;
	cout << "请输入B的值：" << endl;
	cin >> B;
	int C = A + B;
	cout << int(C % 5);

	return 0;

}