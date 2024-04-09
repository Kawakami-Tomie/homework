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
		cout << "请输入学生" << i + 1 << "的学号，姓名，高数成绩，英语成绩：" << endl;
		cin >> message[i].ID >> message[i].name >> message[i].Math >> message[i].English;
		for (int j = 0; j < i; j++)
		{
			if (message[j].ID == message[i].ID)//检查学号是否已经录入
			{
				cout << "学号不能重复录入，请重新输入：" << endl;
				i--;
				break;
			}
		}
		if (message[i].Math < 0 || message[i].Math>100 || message[i].English < 0 || message[i].English>100)//检测输入成绩是否合法
		{
			cout << "成绩超出范围，请重新录入" << endl;
			i--;
		}
	}
		cout << "学号\t姓名\t高数\t英语" << endl;//输出成绩
		for(int i=0;i<5;i++)
		{
			cout << message[i].ID << "\t" << message[i].name << "\t" << message[i].Math << "\t" << message[i].English << endl;
		}
		float Math_Sum=0, English_Sum=0, Math_Average, English_Average, Math_Max=0, English_Max=0, Math_Min = 100, English_Min = 100;
		for (int i = 0; i < 5; i++)//输出最大最小成绩
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
			cout << endl;//输入成绩
			cout << "科目" << "\t" << "最高分" << "\t" << "最低分" << "\t"<<"平均分"<<endl;
			cout << "_______________________________________" << endl;
			cout << "高数" << "\t" << Math_Max << "\t" << Math_Min << "\t" << Math_Average << endl;
			cout << "英语" << "\t" << English_Max << "\t" << English_Min << "\t" << English_Average << endl;
			cout << "_______________________________________" << endl;
			return 0;
	}





