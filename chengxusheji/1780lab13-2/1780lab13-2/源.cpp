// 2022111767lab13.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include <fstream>
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
	int num = 0;
	string name = " ";
	int MathGrade = 0;
	int EnglishGrade = 0;

	struct Student st;

	int i = 0;//the number of students
	vector<Student>arr;

	cout << "�������ļ�����" << endl;
	char f[64];
	cin >> f;
	ifstream ifs;
	ifs.open(f, ios::in);
	if (!ifs.is_open())
	{
		cout << "û���ҵ����ļ������½�һ���ļ�" << endl;
	}
	else if (ifs.is_open())
	{
		cout << "���ļ��Ѵ��ڣ�" << endl;
		char buf[1024] = { 0 };
		while (ifs >> buf)
		{
			cout << buf << endl;
		}
	}
	ifs.close();
	ofstream ofs;

	int cmd;
	string choose;
	
flag3:
	cout << "1.¼��ɼ�   2.�˳�¼��" << endl;
	cin >> cmd;
	if (cmd == 2)
	{
		goto exit;
	}

	do {
			
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

			cout << "�Ƿ����¼��ɼ���Y/N��  " << endl;
			cin >> choose;
			if (choose == "Y")
			{
				goto flag1;
			}
			else if (choose == "N")
			{

				goto exit;
			}
			break;
		
	} while (cmd != 2);

flag2:
	//PrintInfo(arr, i);//print the result
	goto flag3;

exit:
	ofs.open(f, ios::out | ios::app);

	for (int j = 0; j < i; j++)
	{
		ofs << "--------------------------------------------------" << endl;
		ofs << "ѧ��:" << arr[j].num << "����:" << arr[j].name << "�����ɼ�:" << arr[j].MathGrade << "Ӣ��ɼ�:" << arr[j].EnglishGrade << endl;
		
	}
	cout << "�����ѱ��浽" <<f<<"�ļ���" <<endl;
	ofs.close();
	ifs.open(f, ios::in);
	if (ifs.is_open())
	{
		char buf[1024] = { 0 };
		while (ifs >> buf)
		{
			cout << buf << endl;
		}
	}

	cout << "���˳�" << endl;
	return 0;
	ifs.close();

}




