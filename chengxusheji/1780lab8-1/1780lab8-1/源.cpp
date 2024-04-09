#include<iostream>
#include<string>
#include<cassert>
using namespace std;

class student
{
public:
	student():ID(""), name(""), Math(0), English(0) {};
	student (string ID, string name, float Math, float English) {};
	~student() {};
	string getID()const { return ID; }
	string getname()const { return name; }
	float getMath()const { return Math; }
	float getEnglish()const { return English; }
	void setID(string _ID) { ID = _ID; }
	void setname(string _name) { name = _name; }
	void setMath(float _Math) { Math = _Math; }
	void setEnglish(float _English) { English = _English; }

private:
	string ID,name;
	float Math, English;

};

class ArrayOfStudents //动态数组类
{	
public:
	ArrayOfStudents(int size) :size(size) //构造
	{
		message = new student[size];//申明变量空间
	}
	~ArrayOfStudents()//析构
	{
		delete[]message;  //删除变量申请的数组空间
	}
	//获得下标为index的数组元素
	student& element(int index) {
		assert(index >= 0 && index < size);//判断下标是否越界，如果下标越界，程序终止
		return message[index];
	}

private:student* message;
	   int size;
};




int main()
{
	string ID,name;
	float Math, English;
	int num;
	cout << "请输入学生个数：" << endl;
	cin >> num;
	
	ArrayOfStudents message(num);//创建对象数组
	
	for (int i = 0; i < num; i++)
	{
		cout << "请输入学生" << i + 1 << "的学号，姓名，高数成绩，英语成绩：" << endl;
		cin >>ID >> name >> Math >>English;
		message.element(i).setID(ID); message.element(i).setname(name);//设置
		message.element(i).setMath(Math); message.element(i).setEnglish(English);
		//访问数组成员函数
		for (int j = 0; j < i; j++)
		{
			if (message.element(j).getID() == message.element(i).getID())//检查学号是否已经录入
			{
				cout << "学号不能重复录入，请重新输入：" << endl;
				i--;
				break;
			}
		}
		if (message.element(i).getMath() < 0 || message.element(i).getMath() >100 || message.element(i).getEnglish() < 0 || message.element(i).getEnglish() >100)//检测输入成绩是否合法
		{
			cout << "成绩超出范围，请重新录入" << endl;
			i--;
		}
	}
	cout << "学号\t姓名\t高数\t英语" << endl;//输出成绩
	cout << "_______________________________________" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << message.element(i).getID() << "\t" << message.element(i).getname() << "\t" << message.element(i).getMath() << "\t" << message.element(i).getEnglish() << endl;
	}
	cout << "_______________________________________" << endl;
	float Math_Sum = 0, English_Sum = 0, Math_Average=0, English_Average=0, Math_Max = 0, English_Max = 0, Math_Min = 100, English_Min = 100;
	for (int i = 0; i < num; i++)//输出最大最小成绩
	{
		Math_Sum += message.element(i).getMath();
		English_Sum += message.element(i).getEnglish();
		if (Math_Max < message.element(i).getMath())
		{
			Math_Max = message.element(i).getMath();
		}
		if (English_Max < message.element(i).getEnglish())
		{
			English_Max = message.element(i).getEnglish();
		}
		if (Math_Min > message.element(i).getMath())
		{
			Math_Min = message.element(i).getMath();
		}
		if (English_Min > message.element(i).getEnglish())
		{
			English_Min = message.element(i).getEnglish();
		}
		Math_Average = Math_Sum / num;
		English_Average = English_Sum / num;
	}
	cout << endl;//输入成绩
	cout << "科目" << "\t" << "最高分" << "\t" << "最低分" << "\t" << "平均分" << endl;
	cout << "_______________________________________" << endl;
	cout << "高数" << "\t" << Math_Max << "\t" << Math_Min << "\t" << Math_Average << endl;
	cout << "英语" << "\t" << English_Max << "\t" << English_Min << "\t" << English_Average << endl;
	cout << "_______________________________________" << endl;
	

	while (1)
	{
		string inquireID;
		cout << "请输入所查询的学号：" << endl;
		cin >> inquireID;
		int  f=0;
		bool flag = false;
		for (int e = 0; e < num; e++)
		{
			if (message.element(e).getID() == inquireID)
			{
				flag = true;
				f = e;
				break;
			}
		}

		if(flag==false)
			cout << "输入的学号有误，请重新输入！" << endl;
		else 
		{
			cout << "学号\t姓名\t高数\t英语" << endl;//输出成绩

			cout << message.element(f).getID() << "\t" << message.element(f).getname() << "\t" << message.element(f).getMath() << "\t" << message.element(f).getEnglish() << endl;
		}
	
	}
	return 0;
}





