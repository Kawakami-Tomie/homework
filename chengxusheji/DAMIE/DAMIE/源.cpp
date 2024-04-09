#include<iostream>
using namespace std;

int main()
{
FLAG:
	int a;
	int b;
	char retry = 'N';
	int i;
	int n = 0;
	int m = 0;


	cout << "请从小到大输入两个整数：" << endl;
	cin >> a >> b;
	while (a == b) {
		cout << "两个整数相等，请重新输入" << endl;
		cin >> a >> b;
		if (a != b)
			break;
	}
	if (a != b)
	{


		if ((b - a) > 10000) {

			cout << "可能会花费较长的计算时间,是否重新输入，重新输入键入“Y”，不重新输入键入“N”：" << endl;
			cin >> retry;
			if (retry == 'Y') goto FLAG;
			if (retry == 'N')
			{
				cout << "无法计算" << endl;
			}
			while (retry != 'N') {
				cout << "可能会花费较长的计算时间,是否重新输入，重新输入键入“Y”，不重新输入键入“N”：" << endl;
				cin >> retry;
				if (retry == 'Y') goto FLAG;
			}

			for (i = a; i < b; i++) {
				for (n = 2; n < i; n++)
				{
					if (i % n == 0)
					{
						break;
					}
				}
				if (n == i)
				{
					m = m + 1;
					printf("%d ", i);

				}
			}


		}




		else if ((0 < b - a <= 10000))
			for (i = a; i < b; i++)
			{
				for (n = 2; n < i; n++)
				{

					if (i % n == 0)
					{
						break;
					}
				}
				if (n == i)
				{
					m = m + 1;
					printf("%d ", i);
				}
			}

	}

	cout << "质数的个数为：" << m << endl;
    return 0;
}
