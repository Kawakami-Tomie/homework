#include<iostream>
#include<string>
using namespace std;

struct student
{
	string ID;
	string name;
	float Math, English;

};

int main()
{
	student message[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "������ѧ��" << i + 1 << "��ѧ�ţ������������ɼ���Ӣ��ɼ���" << endl;
		cin >> message[i].ID >> message[i].name >> message[i].Math >> message[i].English;
		for (int j = 0; j < i; j++)
		{
			if (message[j].ID == message[i].ID)//���ѧ���Ƿ��Ѿ�¼��
			{
				cout << "ѧ�Ų����ظ�¼�룬���������룺" << endl;
				i--;
				break;
			}
		}
		if (message[i].Math < 0 || message[i].Math>100 || message[i].English < 0 || message[i].English>100)//�������ɼ��Ƿ�Ϸ�
		{
			cout << "�ɼ�������Χ��������¼��" << endl;
			i--;
		}
	}
		cout << "ѧ��\t����\t����\tӢ��" << endl;//����ɼ�
		for(int i=0;i<5;i++)
		{
			cout << message[i].ID << "\t" << message[i].name << "\t" << message[i].Math << "\t" << message[i].English << endl;
		}
		float Math_Sum=0, English_Sum=0, Math_Average, English_Average, Math_Max=0, English_Max=0, Math_Min = 100, English_Min = 100;
		for (int i = 0; i < 5; i++)//��������С�ɼ�
		{
			Math_Sum += message[i].Math;
			English_Sum += message[i].English;
			if (Math_Max < message[i].Math)
			{
				Math_Max = message[i].Math;
			}
			if (English_Max < message[i].English)
			{
				English_Max = message[i].English;
			}
			if (Math_Min > message[i].Math)
			{
				Math_Min = message[i].Math;
			}
			if (English_Min > message[i].English)
			{
				English_Min = message[i].English;
			}
			Math_Average = Math_Sum / 5;
			English_Average = English_Sum / 5;
		}
			cout << endl;//����ɼ�
			cout << "��Ŀ" << "\t" << "��߷�" << "\t" << "��ͷ�" << "\t"<<"ƽ����"<<endl;
			cout << "_______________________________________" << endl;
			cout << "����" << "\t" << Math_Max << "\t" << Math_Min << "\t" << Math_Average << endl;
			cout << "Ӣ��" << "\t" << English_Max << "\t" << English_Min << "\t" << English_Average << endl;
			cout << "_______________________________________" << endl;
			return 0;
	}





