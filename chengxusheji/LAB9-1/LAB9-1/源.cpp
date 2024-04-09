// 1767lab9.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	cout << "*************学生成绩统计结果*************" << endl;
	sort(arr.begin(), arr.end(), cmp);
	cout << "---------------------------------------------" << endl;
	cout << std::left << setw(12) << "学号 " << std::left << setw(12) << "姓名" << std::left << setw(12) << "高数成绩" << std::left << setw(12) << "英语成绩\t" << endl;
	cout << "---------------------------------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << std::left << setw(12) << arr[i].num << setw(12) << arr[i].name << setw(12) << arr[i].MathGrade << setw(12) << arr[i].EnglishGrade << endl;
	}
	cout << "---------------------------------------------------------" << endl;
	cout << std::left << setw(11) << "科目" << std::left << setw(12) << "最高分" << setw(12) << "最低分" << setw(12) << "平均分" << setw(12) << "不及格率" << "\t" << endl;
	cout << "---------------------------------------------------------" << endl;
	int Engmax = 0, Engmin = 100;
	int Mathmax = 0, Mathmin = 100;
	EngMax(arr, Engmax);
	EngMin(arr, Engmin);
	MathMax(arr, Mathmax);
	MathMin(arr, Mathmin);
	cout << std::left << setw(12) << "\n英语" << std::left << setw(12) << Engmax << std::left << setw(12) << Engmin << std::left << setw(12) << EngAverage(arr) << setw(2) << EngPassRate(arr) * 100 << "%" << "\t" << endl;
	cout << std::left << setw(12) << "\n高数" << std::left << setw(12) << Mathmax << std::left << setw(12) << Mathmin << std::left << setw(12) << MathAverage(arr) << setw(2) << MathPassRate(arr) * 100 << "%" << "\t" << endl;
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
		cout << "\n请输入学生的学号:" << endl;
		int num;
		cin >> num;

		int ret = isExist(arr, num);

		if (ret != -1)
		{
			cout << "学号：" << arr[ret].num << endl;
			cout << "姓名：" << arr[ret].name << endl;
			cout << "高数成绩：" << arr[ret].MathGrade << endl;
			cout << "英语成绩：" << arr[ret].EnglishGrade << endl;
		}
		else
		{
			cout << "输入的学号有误！" << endl;
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
	cout << "*************学生成绩管理系统*************" << endl;
flag3:
	cout << "1.录入信息  2.查询信息  3.退出" << endl;
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
			/*********************************录入学生信息*****************************************/
		flag1:
			cout << "请输入第" << i + 1 << "个学生的信息:学号 姓名 高数成绩 英语成绩" << endl;
			cin >> num >> name >> MathGrade >> EnglishGrade;

			while (MathGrade < 0 || MathGrade >100)
			{
				cout << "该生高数成绩无效，请重新输入：";
				cin >> MathGrade;
				break;
			}
			while (EnglishGrade < 0 || EnglishGrade>100)
			{
				cout << "该生英语成绩无效，请重新输入：";
				cin >> EnglishGrade;
				break;
			}
			for (int j = 0; j < i; ++j)
			{
				while (arr[j].num == num)
				{
					cout << "请勿重复录入学号！\n请重新输入：" << endl;
					cin >> num;
				}
			}

			st.num = num;
			st.name = name;
			st.MathGrade = MathGrade;
			st.EnglishGrade = EnglishGrade;

			arr.push_back(st);//add students
			i++;

			cout << "1.继续录入  2.退出录入" << endl;
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
			/*********************************查询学生信息*****************************************/
			CheckStudents(arr);
			break;
		}
	} while (cmd != 3);

flag2:
	PrintInfo(arr, i);//print the result
	goto flag3;

exit:
	cout << "已退出" << endl;
	return 0;
}

