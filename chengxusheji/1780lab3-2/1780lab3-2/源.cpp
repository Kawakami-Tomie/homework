#include <iostream>
using namespace std;
int main()
{
	int f;
	float r, l, d, h, a, b, S;//С��
	string y, c, z, t;
	y = "Բ��";
	c = "������";
	z = "������";
	t = "����";

	while (1) {
		cout << "������ͼ������[0ΪԲ�Σ�1Ϊ�����Σ�2Ϊ�����Σ�3Ϊ����]��" << endl;
		cin >> f;
		switch (f) {
		case 0:
			cout << y << endl;
			cout << "������Բ�εİ뾶��" << endl;
			cin >> r;
			S = 3.14 * r * r;
			cout << "Բ�ε����Ϊ��" << S << endl;;
			break;
		case 1:
			cout << z << endl;
			cout << "�����������εı߳���" << endl;
			cin >> l;
			S = l * l;
			cout << "�����ε����Ϊ��" << S << endl;
			break;
		case 2:
			cout << c << endl;
			cout << "�����볤���εĳ���" << endl;
			cin >> l;
			cout << "�����볤���εĿ�" << endl;
			cin >> d;
			S = l * d;
			cout << "�����ε����Ϊ��" << S << endl;;
			break;
		case 3:
			cout << t<< endl;
			cout << "���������ε��ϵ׳���" << endl;
			cin >> a;
			cout << "���������ε��µ׳���" << endl;
			cin >> b;
			cout << "���������εĸߣ�" << endl;
			cin >> h;
			S = ((a + b) * h) / 2;
			cout << "���ε����Ϊ��" << S << endl;
			break;
		default:
			cout << "����������" << endl;
			break;
		}
	}
	return 0;
}
