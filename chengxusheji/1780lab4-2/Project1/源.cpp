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


	cout << "������x:" << endl;
	cin >> x;
	cout << "������������n��ֵ��" << endl;
	cin >> n;

	while (n <= 0) {
		cout << "��������������ֵ:" << endl;
		cin >> n;

	}

	for (i = 1; i <= n; i++) {
		e = e + pow(x, i) / fac(i);
	}

	cout << "e��x�η���n=" << n << "ʱ��ֵΪ��" << e << endl;

	cout << "��Ҫ��������һ��������Ҫ�����ַ���Y���������˳���" << endl;
	cin >> retry;
	if (retry == 'Y') goto FLAG;
	return 0;
}