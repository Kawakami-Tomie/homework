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


	cout << "���С������������������" << endl;
	cin >> a >> b;
	while (a == b) {
		cout << "����������ȣ�����������" << endl;
		cin >> a >> b;
		if (a != b)
			break;
	}
	if (a != b)
	{


		if ((b - a) > 10000) {

			cout << "���ܻỨ�ѽϳ��ļ���ʱ��,�Ƿ��������룬����������롰Y����������������롰N����" << endl;
			cin >> retry;
			if (retry == 'Y') goto FLAG;
			if (retry == 'N')
			{
				cout << "�޷�����" << endl;
			}
			while (retry != 'N') {
				cout << "���ܻỨ�ѽϳ��ļ���ʱ��,�Ƿ��������룬����������롰Y����������������롰N����" << endl;
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

	cout << "�����ĸ���Ϊ��" << m << endl;
    return 0;
}
