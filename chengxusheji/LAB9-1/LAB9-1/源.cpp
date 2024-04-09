// 1767lab9.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include<algorithm>
using namespace std;

struct Student
{
	int num;
	string name;
	int MathGrade;
	int EnglishGrade;

};

bool cmp(Student a, Student b)
{
	return a.num < b.num;
}

void EngMax(vector<Student>& arr, int& EngMax)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].EnglishGrade > EngMax)
		{
			EngMax = arr[i].EnglishGrade;
		}
	}
}
void EngMin(vector<Student>& arr, int& EngMin)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].EnglishGrade < EngMin)
		{
			EngMin = arr[i].EnglishGrade;
		}
	}
}

void MathMax(vector<Student>& arr, int& MathMax)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].MathGrade > MathMax)
		{
			MathMax = arr[i].MathGrade;
		}
	}
}
void MathMin(vector<Student>& arr, int& MathMin)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].MathGrade < MathMin)
		{
			MathMin = arr[i].MathGrade;
		}
	}
}

double EngAverage(vector<Student>& arr)
{
	double sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		sum += arr[i].EnglishGrade;
	}
	double aver = sum / arr.size();
	return aver;
}
double MathAverage(vector<Student>& arr)
{
	double sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		sum += arr[i].MathGrade;
	}
	double aver = sum / arr.size();
	return aver;
}

double EngPassRate(vector<Student>& arr)
{
	int p = 0;//the people who failed the exam
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].EnglishGrade < 60)
		{
			p++;
		}
	}
	double rate = (double)p / arr.size();
	return rate;
}
double MathPassRate(vector<Student>& arr)
{
	int p = 0;//the people who failed the exam
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].MathGrade < 60)
		{
			p++;
		}
	}
	double rate = (double)p / arr.size();
	return rate;
}

void PrintInfo(vector<Student>& arr, int n)
{
	cout << "*************ѧ���ɼ�ͳ�ƽ��*************" << endl;
	sort(arr.begin(), arr.end(), cmp);
	cout << "---------------------------------------------" << endl;
	cout << std::left << setw(12) << "ѧ�� " << std::left << setw(12) << "����" << std::left << setw(12) << "�����ɼ�" << std::left << setw(12) << "Ӣ��ɼ�\t" << endl;
	cout << "---------------------------------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << std::left << setw(12) << arr[i].num << setw(12) << arr[i].name << setw(12) << arr[i].MathGrade << setw(12) << arr[i].EnglishGrade << endl;
	}
	cout << "---------------------------------------------------------" << endl;
	cout << std::left << setw(11) << "��Ŀ" << std::left << setw(12) << "��߷�" << setw(12) << "��ͷ�" << setw(12) << "ƽ����" << setw(12) << "��������" << "\t" << endl;
	cout << "---------------------------------------------------------" << endl;
	int Engmax = 0, Engmin = 100;
	int Mathmax = 0, Mathmin = 100;
	EngMax(arr, Engmax);
	EngMin(arr, Engmin);
	MathMax(arr, Mathmax);
	MathMin(arr, Mathmin);
	cout << std::left << setw(12) << "\nӢ��" << std::left << setw(12) << Engmax << std::left << setw(12) << Engmin << std::left << setw(12) << EngAverage(arr) << setw(2) << EngPassRate(arr) * 100 << "%" << "\t" << endl;
	cout << std::left << setw(12) << "\n����" << std::left << setw(12) << Mathmax << std::left << setw(12) << Mathmin << std::left << setw(12) << MathAverage(arr) << setw(2) << MathPassRate(arr) * 100 << "%" << "\t" << endl;
}
//Check the student
int isExist(vector<Student>& arr, int num)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (num == arr[i].num)
		{
			return i;
		}
	}
	return -1;

}
void CheckStudents(vector<Student>& arr)
{
	while (1)
	{
		cout << "\n������ѧ����ѧ��:" << endl;
		int num;
		cin >> num;

		int ret = isExist(arr, num);

		if (ret != -1)
		{
			cout << "ѧ�ţ�" << arr[ret].num << endl;
			cout << "������" << arr[ret].name << endl;
			cout << "�����ɼ���" << arr[ret].MathGrade << endl;
			cout << "Ӣ��ɼ���" << arr[ret].EnglishGrade << endl;
		}
		else
		{
			cout << "�����ѧ������" << endl;
			continue;
		}
	}
}

int main()
{
	int num;
	string name;
	int MathGrade;
	int EnglishGrade;

	struct Student st;

	int i = 0;//the number of students
	vector<Student>arr;

	int cmd;
	cout << "*************ѧ���ɼ�����ϵͳ*************" << endl;
flag3:
	cout << "1.¼����Ϣ  2.��ѯ��Ϣ  3.�˳�" << endl;
	cin >> cmd;
	if (cmd == 3)
	{
		goto exit;
	}
	do {
		switch (cmd)
		{
		case 1:
		{
			/*********************************¼��ѧ����Ϣ*****************************************/
		flag1:
			cout << "�������" << i + 1 << "��ѧ������Ϣ:ѧ�� ���� �����ɼ� Ӣ��ɼ�" << endl;
			cin >> num >> name >> MathGrade >> EnglishGrade;

			while (MathGrade < 0 || MathGrade >100)
			{
				cout << "���������ɼ���Ч�����������룺";
				cin >> MathGrade;
				break;
			}
			while (EnglishGrade < 0 || EnglishGrade>100)
			{
				cout << "����Ӣ��ɼ���Ч�����������룺";
				cin >> EnglishGrade;
				break;
			}
			for (int j = 0; j < i; ++j)
			{
				while (arr[j].num == num)
				{
					cout << "�����ظ�¼��ѧ�ţ�\n���������룺" << endl;
					cin >> num;
				}
			}

			st.num = num;
			st.name = name;
			st.MathGrade = MathGrade;
			st.EnglishGrade = EnglishGrade;

			arr.push_back(st);//add students
			i++;

			cout << "1.����¼��  2.�˳�¼��" << endl;
			cin >> cmd;
			if (cmd == 1)
			{
				goto flag1;
			}
			else if (cmd == 2)
			{
				goto flag2;
			}
			break;
		}
		case 2:
			/*********************************��ѯѧ����Ϣ*****************************************/
			CheckStudents(arr);
			break;
		}
	} while (cmd != 3);

flag2:
	PrintInfo(arr, i);//print the result
	goto flag3;

exit:
	cout << "���˳�" << endl;
	return 0;
}

