#include<iostream>
using namespace std;
int main()
{RETRY:
	int a;
	int b;
	char again = 'N';
	int i;
	int n = 0;
	int m = 0;
	cout << "���С������������������" << endl;
	cin >> a >> b;
	while (a == b)
	{
		cout << "����������ȣ�����������" << endl;
		cin >> a >> b;
		if (a != b)
			break;
	}
	if (a != b)
	{
		if ((b - a) > 10000) 
		{
			cout << "���ܻỨ�ѽϳ��ļ���ʱ��,�Ƿ��������룬����������롰Y����������������롰N����" << endl;
			cin >> again;
			if (again == 'Y') goto RETRY;
			while (again != 'N') 
			{
				cout << "���ܻỨ�ѽϳ��ļ���ʱ��,�Ƿ��������룬����������롰Y����������������롰N����" << endl;
				cin >> again;
				if (again == 'Y') goto RETRY;
			}
		CACULATE:
			for (i = a+1; i < b; i++) //�ж�����
			{
				for (n = 2; n <=i; n++)
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
		else if (0 < b - a <= 10000)goto CACULATE;
	
	}
	cout << "�����ĸ���Ϊ��" << m << endl;
	return 0;
}
