#include<iostream>
#include<math.h>


using namespace std;

double power(double x, int n) {
	double val = 1.0;
	while (n--)
		val *= x;
	return val;
}

unsigned fac(unsigned n) {
	unsigned f;
	if (n == 0)
		f = 1;
	else
		f = fac(n - 1) * n;
	return f;
}
int main()
{
FLAG:

	double x, e = 1.0, n = 0, i = 1;
	char retry;


	cout << "请输入x:" << endl;
	cin >> x;
	cout << "请输入正整数n的值：" << endl;
	cin >> n;

	while (n <= 0) {
		cout << "请输入正整数的值:" << endl;
		cin >> n;

	}

	for (i = 1; i <= n; i++) {
		e = e + pow(x, i) / fac(i);
	}

	cout << "e的x次方在n=" << n << "时的值为：" << e << endl;

	cout << "需要计算另外一组数吗？需要输入字符‘Y’，否则退出：" << endl;
	cin >> retry;
	if (retry == 'Y') goto FLAG;
	return 0;
}