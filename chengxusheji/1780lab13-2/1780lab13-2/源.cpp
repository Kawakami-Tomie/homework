// 2022111767lab13.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	int num = 0;
	string name = " ";
	int MathGrade = 0;
	int EnglishGrade = 0;

	struct Student st;

	int i = 0;//the number of students
	vector<Student>arr;

	cout << "请输入文件名：" << endl;
	char f[64];
	cin >> f;
	ifstream ifs;
	ifs.open(f, ios::in);
	if (!ifs.is_open())
	{
		cout << "没有找到该文件，将新建一个文件" << endl;
	}
	else if (ifs.is_open())
	{
		cout << "该文件已存在：" << endl;
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
	cout << "1.录入成绩   2.退出录入" << endl;
	cin >> cmd;
	if (cmd == 2)
	{
		goto exit;
	}

	do {
			
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

			cout << "是否继续录入成绩（Y/N）  " << endl;
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
		ofs << "学号:" << arr[j].num << "姓名:" << arr[j].name << "高数成绩:" << arr[j].MathGrade << "英语成绩:" << arr[j].EnglishGrade << endl;
		
	}
	cout << "数据已保存到" <<f<<"文件中" <<endl;
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

	cout << "已退出" << endl;
	return 0;
	ifs.close();

}




