#include <iostream>
using namespace std;
int main()
{
	int f;
	float r, l, d, h, a, b, S;//小数
	string y, c, z, t;
	y = "圆形";
	c = "长方形";
	z = "正方形";
	t = "梯形";

	while (1) {
		cout << "请输入图形类型[0为圆形，1为正方形，2为长方形，3为梯形]：" << endl;
		cin >> f;
		switch (f) {
		case 0:
			cout << y << endl;
			cout << "请输入圆形的半径：" << endl;
			cin >> r;
			S = 3.14 * r * r;
			cout << "圆形的面积为：" << S << endl;;
			break;
		case 1:
			cout << z << endl;
			cout << "请输入正方形的边长：" << endl;
			cin >> l;
			S = l * l;
			cout << "正方形的面积为：" << S << endl;
			break;
		case 2:
			cout << c << endl;
			cout << "请输入长方形的长：" << endl;
			cin >> l;
			cout << "请输入长方形的宽：" << endl;
			cin >> d;
			S = l * d;
			cout << "长方形的面积为：" << S << endl;;
			break;
		case 3:
			cout << t<< endl;
			cout << "请输入梯形的上底长：" << endl;
			cin >> a;
			cout << "请输入梯形的下底长：" << endl;
			cin >> b;
			cout << "请输入梯形的高：" << endl;
			cin >> h;
			S = ((a + b) * h) / 2;
			cout << "梯形的面积为：" << S << endl;
			break;
		default:
			cout << "请重新输入" << endl;
			break;
		}
	}
	return 0;
}
