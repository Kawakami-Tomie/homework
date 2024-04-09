#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
using namespace std;
ofstream ofs_sub; ifstream ifs_sub;
ofstream ofs_stu; ifstream ifs_stu;
ofstream ofs_key; ifstream ifs_key;
class Subject
{
public:
	Subject() {}
	~Subject() {}
	int m_subjectid;
	string m_subjectname;
};
class Student
{
public:
	Student() {}
	~Student() {}
	void cul_score()//总成绩计算方式
	{
		m_score = m_dailyscore*0.2+ m_endscore*0.5+ m_experimentscore*0.2+ m_homeworkscore*0.1;
	}
	int m_id;
	string m_name;
	double m_dailyscore;//期中成绩
	double m_endscore;//期末成绩
	double m_experimentscore;//实验成绩
	double m_homeworkscore;//作业成绩
	double m_score;//总成绩
};
Student maxscore(vector<Student> xarr_student)//统计最高分
{
	double maxdailyscore = 0; double maxendscore = 0; double maxexperimentscore = 0; double maxhomeworkscore = 0; double maxscore = 0;
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (maxscore < xarr_student[i].m_score)
		{
			maxscore = xarr_student[i].m_score;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (maxdailyscore < xarr_student[i].m_dailyscore)
		{
			maxdailyscore = xarr_student[i].m_dailyscore;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (maxendscore < xarr_student[i].m_endscore)
		{
			maxendscore = xarr_student[i].m_endscore;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (maxexperimentscore < xarr_student[i].m_experimentscore)
		{
			maxexperimentscore = xarr_student[i].m_experimentscore;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (maxhomeworkscore < xarr_student[i].m_homeworkscore)
		{
			maxhomeworkscore = xarr_student[i].m_homeworkscore;
		}
	}
	Student temp;
	temp.m_dailyscore = maxdailyscore;//期中成绩的最高分
	temp.m_endscore = maxendscore;//期末成绩最高分
	temp.m_experimentscore = maxexperimentscore;//实验成绩的最高分
	temp.m_homeworkscore = maxhomeworkscore;//作业成绩最高分
	temp.m_score = maxscore;//总成绩最高分
	return temp;
}
Student minscore(vector<Student> xarr_student)//统计最低分
{
	double mindailyscore = 100; double minendscore = 100; double minscore = 100; double minexperimentscore = 0; double minhomeworkscore = 0;
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (minscore > xarr_student[i].m_score)
		{
			minscore = xarr_student[i].m_score;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (mindailyscore > xarr_student[i].m_dailyscore)
		{
			mindailyscore = xarr_student[i].m_dailyscore;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (minendscore > xarr_student[i].m_endscore)
		{
			minendscore = xarr_student[i].m_endscore;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (minexperimentscore > xarr_student[i].m_experimentscore)
		{
			minexperimentscore = xarr_student[i].m_experimentscore;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (minhomeworkscore < xarr_student[i].m_homeworkscore)
		{
			minhomeworkscore = xarr_student[i].m_homeworkscore;
		}
	}
	Student temp;
	temp.m_dailyscore = mindailyscore;//平时成绩最低分
	temp.m_endscore = minendscore;//期末成绩最低分
	temp.m_experimentscore = minexperimentscore;//实验成绩的最低分
	temp.m_homeworkscore = minhomeworkscore;//作业成绩最低分
	temp.m_score = minscore;//总成绩最低分
	return temp;
}
Student avescore(vector<Student> xarr_student)//统计平均分
{
	double avedailyscore = 0; double aveendscore = 0; double avescore = 0; double aveexperimentscore = 0; double avehomeworkscore = 0;
	for (int i = 0; i < xarr_student.size(); i++)
	{
		avescore += xarr_student[i].m_score;
	}
	avescore /= xarr_student.size();
	for (int i = 0; i < xarr_student.size(); i++)
	{
		avedailyscore += xarr_student[i].m_dailyscore;
	}
	avedailyscore /= xarr_student.size();
	for (int i = 0; i < xarr_student.size(); i++)
	{
		aveendscore += xarr_student[i].m_endscore;
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		aveexperimentscore += xarr_student[i].m_experimentscore;
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		avehomeworkscore += xarr_student[i].m_homeworkscore;
	}
	aveendscore /= xarr_student.size();
	Student temp;
	temp.m_dailyscore = avedailyscore; //平时成绩平均分
	temp.m_endscore = aveendscore;//期末成绩平均分
	temp.m_experimentscore = aveexperimentscore;//实验成绩的最低分
	temp.m_homeworkscore = avehomeworkscore;//作业成绩最低分
	temp.m_score = avescore;//总成绩平均分
	return temp;
}

void dailyscorenum(vector<Student> xarr_student)//期中分分数段
{
	int temp50 = 0; int temp60 = 0; int temp70 = 0; int temp80 = 0; int temp90 = 0;
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_dailyscore < 60)
		{
			temp50++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_dailyscore < 70 && xarr_student[i].m_dailyscore >= 60)
		{
			temp60++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_dailyscore < 80 && xarr_student[i].m_dailyscore >= 70)
		{
			temp70++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_dailyscore < 90 && xarr_student[i].m_dailyscore >= 80)
		{
			temp80++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_dailyscore >= 90)
		{
			temp90++;
		}
	}

	cout << temp50 << "\t" << temp60 << "\t" << temp70 << "\t" << temp80 << "\t" << temp90 << endl;
}


void endscorenum(vector<Student> xarr_student)//期末成绩分数段
{
	int temp50 = 0; int temp60 = 0; int temp70 = 0; int temp80 = 0; int temp90 = 0;
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_endscore < 60)
		{
			temp50++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_endscore < 70 && xarr_student[i].m_endscore >= 60)
		{
			temp60++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_endscore < 80 && xarr_student[i].m_endscore >= 70)
		{
			temp70++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_endscore < 90 && xarr_student[i].m_endscore >= 80)
		{
			temp80++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_endscore >= 90)
		{
			temp90++;
		}
	}

	cout << temp50 << "\t" << temp60 << "\t" << temp70 << "\t" << temp80 << "\t" << temp90 << endl;
}
void experimentscorenum(vector<Student> xarr_student)//实验成绩分数段
{
	int temp50 = 0; int temp60 = 0; int temp70 = 0; int temp80 = 0; int temp90 = 0;
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_experimentscore < 60)
		{
			temp50++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_experimentscore < 70 && xarr_student[i].m_experimentscore >= 60)
		{
			temp60++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_experimentscore < 80 && xarr_student[i].m_experimentscore >= 70)
		{
			temp70++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_experimentscore < 90 && xarr_student[i].m_experimentscore >= 80)
		{
			temp80++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_experimentscore >= 90)
		{
			temp90++;
		}
	}

	cout << temp50 << "\t" << temp60 << "\t" << temp70 << "\t" << temp80 << "\t" << temp90 << endl;
}

void homeworkscorenum(vector<Student> xarr_student)//作业成绩分数段
{
	int temp50 = 0; int temp60 = 0; int temp70 = 0; int temp80 = 0; int temp90 = 0;
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_homeworkscore < 60)
		{
			temp50++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_homeworkscore < 70 && xarr_student[i].m_homeworkscore >= 60)
		{
			temp60++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_homeworkscore < 80 && xarr_student[i].m_homeworkscore >= 70)
		{
			temp70++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_homeworkscore < 90 && xarr_student[i].m_homeworkscore >= 80)
		{
			temp80++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_homeworkscore >= 90)
		{
			temp90++;
		}
	}

	cout << temp50 << "\t" << temp60 << "\t" << temp70 << "\t" << temp80 << "\t" << temp90 << endl;
}


void scorenum(vector<Student> xarr_student)//总分分数段统计
{
	int temp50 = 0; int temp60 = 0; int temp70 = 0; int temp80 = 0; int temp90 = 0;
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_score < 60)//不及格
		{
			temp50++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_score < 70 && xarr_student[i].m_score >= 60)//60~70分数段
		{
			temp60++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_score < 80 && xarr_student[i].m_score >= 70)//70~80分数段
		{
			temp70++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_score < 90 && xarr_student[i].m_score >= 80)//80~90分数段
		{
			temp80++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)//90~100分数段
	{
		if (xarr_student[i].m_score >= 90)
		{
			temp90++;
		}
	}

	cout << temp50 << "\t" << temp60 << "\t" << temp70 << "\t" << temp80 << "\t" << temp90 << endl;
}
int ranknum(Student xstudent, vector<Student> xarr_student)
{
	int temp = 1;
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xstudent.m_score < xarr_student[i].m_score)
		{
			temp++;
		}
	}
	return temp;
}
void encryption(string& xkey)
{
	//加密
	int number[4] = { 4,3,2,1 };//后移4,3,2,1位
	for (int i = 0; i < xkey.length(); i++)
	{
		xkey[i] += (number[i % 4]);
	}
}
void decrypt(string& xkey)
{
	//解密
	int number[4] = { 4,3,2,1 };
	for (int i = 0; i < xkey.length(); i++)
	{
		xkey[i] -= (number[i % 4]);
	}
}
int main()
{
	vector<Subject> arr_subject; Subject subject;
	vector<Student> arr_student; Student student;
	int identchoice = 0; string key; string memory_key;
	while (1)
	{
		cout << "欢迎使用成绩管理系统" << endl;
		cout << "请选择功能：\n1.我是教师\n2.我是学生\n3.退出" << endl;
		cin >> identchoice;
		cout << endl;
		if (identchoice == 1) //老师身份
		{
			ifs_key.open("key.txt", ios::in);
			ifs_key >> memory_key;
			ifs_key.close();
			decrypt(memory_key);
			while (1)
			{
				cout << "请输入密码(初始密码为123456):" << endl;
				char k;
				key = "\0";
				while (1)
				{
					k = _getch();
					cout << "*";
					if (k == '\r')//回车
					{
						break;
					}
					key += k;
				}
				if (key != memory_key)
				{
					cout << endl;
					cout << "密码错误！请重新输入：" << endl;
				}
				else
				{
					cout << endl;
					break;
				}
			}
			cout << "您的身份是：老师" << endl;
			ifs_sub.open("课程信息.txt", ios::in);
			if (ifs_sub.is_open())
			{
				Subject tempsub;
				arr_subject.clear();
				while (ifs_sub >> tempsub.m_subjectid >> tempsub.m_subjectname)
				{
					arr_subject.push_back(tempsub);
				}
			}
			ifs_sub.close();
			ifs_stu.open("学生信息.txt", ios::in);
			if (ifs_stu.is_open())
			{
				Student tempstu;
				arr_student.clear();
				while (ifs_stu >> tempstu.m_id >> tempstu.m_name >> tempstu.m_dailyscore >> tempstu.m_endscore >> tempstu.m_score)
				{
					arr_student.push_back(tempstu);
				}

			}
			ifs_stu.close();
			cout << "1.课程信息" << endl; cout << "2.学生成绩" << endl; cout << "3.信息显示" << endl; cout << "4.修改密码" << endl;
			int teacherchoice = 0; char yorn = 'Y'; int input_stu_choice = 0; int temp_id = 0; bool gotonone = 1; int showchoice = 0;
			cin >> teacherchoice;
			cout << endl;
			if (teacherchoice == 1) //进入课程信息
			{
				while (1) //在vector中存储或修改课程信息
				{
					int subchoice = 0; int temp_subid = 0;
					cout << endl;
					cout << "1.录入课程信息 2.修改课程信息" << endl;
					cin >> subchoice;
					cout << endl;
					if (subchoice == 1)
					{
						cout << "请输入课程的编号、名称：" << endl;
						cin >> subject.m_subjectid; cin >> subject.m_subjectname;
						arr_subject.push_back(subject);
						cout << "继续录入或修改课程信息(Y/N)";
						cin >> yorn;
						if (yorn != 'Y') { break; }
					}
					else if (subchoice == 2)
					{
						bool subcheck = 1;
						cout << "请输入要修改课程的编号" << endl;
						cin >> temp_subid;
						for (int i = 0; i < arr_subject.size(); i++)
						{
							if (arr_subject[i].m_subjectid == temp_subid)
							{
								cout << "请输入您要将编号修改为：" << endl;
								cin >> arr_subject[i].m_subjectid;
								cout << "请输入您要将名称修改为：" << endl;
								cin >> arr_subject[i].m_subjectname;
								subcheck = 0;
							}
						}
						if (subcheck)
						{
							cout << "未找到该课程编号" << endl;
						}
						cout << "继续修改课程编号(Y/N)" << endl;
						cin >> yorn;
						cout << endl;
						if (yorn != 'Y')
						{
							break;
						}
					}
				}
				ofs_sub.open("课程信息.txt", ios::out);
				for (int i = 0; i < arr_subject.size(); i++) //将课程信息录入到文件里
				{
					ofs_sub << arr_subject[i].m_subjectid << " " << arr_subject[i].m_subjectname << endl;
				}
				ofs_sub.close();
			}
			else if (teacherchoice == 2) //进入学生信息
			{
				while (1)
				{
					cout << "1.录入学生成绩" << endl;
					cout << "2.修改学生成绩" << endl;
					cout << "3.删除学生成绩" << endl;
					cin >> input_stu_choice;
					cout << endl;
					switch (input_stu_choice)
					{
					case 1: //录入学生成绩
						cout << "请输入学生学号："; cin >> student.m_id;
						cout << "请输入学生姓名："; cin >> student.m_name;
						cout << "请输入学生实验成绩："; cin >> student.m_experimentscore;
						cout << "请输入学生作业成绩："; cin >> student.m_homeworkscore;
						cout << "请输入学生期中成绩："; cin >> student.m_dailyscore;
						cout << "请输入学生期末成绩："; cin >> student.m_endscore;
						cout << endl;
						student.cul_score();
						arr_student.push_back(student);
						break;
					case 2: //修改学生成绩
						cout << "请输入要修改学生的学号" << endl;
						cin >> temp_id;
						cout << endl;
						for (int i = 0; i < arr_student.size(); i++)
						{
							if (arr_student[i].m_id == temp_id)
							{
								cout << "请将学生实验成绩修改为："; cin >> arr_student[i].m_experimentscore;
								cout << "请将学生作业成绩修改为："; cin >> arr_student[i].m_homeworkscore;
								cout << "请将学生平时成绩修改为："; cin >> arr_student[i].m_dailyscore;
								cout << "请将学生期末成绩修改为："; cin >> arr_student[i].m_endscore;
								arr_student[i].cul_score();
								gotonone = 0;
							}
						}
						if (gotonone)
						{
							cout << "没有找到该学号" << endl;
						}
						break;
					case 3: //删除学生成绩
						cout << "请输入要删除学生的学号："; cin >> temp_id;
						for (int i = 0; i < arr_student.size(); i++)
						{
							if (arr_student[i].m_id == temp_id)
							{
								arr_student.erase(arr_student.begin() + i);
								gotonone = 0;
							}
							if (gotonone)
							{
								cout << "没有找到该学号" << endl;
							}
						}
						break;
					}
					cout << "继续编辑学生成绩(Y/N)" << endl;
					cin >> yorn;
					cout << endl;
					if (yorn != 'Y')
					{
						break;
					}
				}

				ofs_stu.open("学生信息.txt", ios::out);
				for (int i = 0; i < arr_student.size(); i++) //将学生信息录入到文件里
				{
					ofs_stu << arr_student[i].m_id << " " << arr_student[i].m_name << " "<<arr_student[i].m_experimentscore << " " << arr_student[i].m_homeworkscore << " " << arr_student[i].m_dailyscore << " " << arr_student[i].m_endscore << " " << arr_student[i].m_score << endl;
				}
				ofs_stu.close();
			}
			else if (teacherchoice == 3) //信息显示
			{
				cout << "1.显示课程信息" << endl;
				cout << "2.显示学生信息" << endl;
				cout << "3.显示学生成绩统计" << endl;
				cin >> showchoice;
				cout << endl;
				if (showchoice == 1)
				{
					if (arr_subject.empty())
					{
						cout << "暂无课程信息" << endl << endl;
					}
					else
					{
						cout << "编号\t名称" << endl;
						for (int i = 0; i < arr_subject.size(); i++)
						{
							cout << arr_subject[i].m_subjectid << "\t" << arr_subject[i].m_subjectname << endl << endl;
						}
					}
				}
				else if (showchoice == 2)
				{
					if (arr_student.empty())
					{
						cout << "暂无成绩信息" << endl << endl;
					}
					else
					{
						cout << "学号\t姓名\t实验\t作业\t期中\t期末\t总成绩" << endl;
						for (int i = 0; i < arr_student.size(); i++)
						{
							cout << arr_student[i].m_id << "\t" << arr_student[i].m_name << "\t" << arr_student[i].m_experimentscore << "\t" << arr_student[i].m_homeworkscore << "\t" << arr_student[i].m_dailyscore << "\t" << arr_student[i].m_endscore << "\t" << arr_student[i].m_score << endl << endl;
						}
					}
				}
				else if (showchoice == 3)
				{
					if (arr_student.empty())
					{
						cout << "暂无成绩信息" << endl;
					}
					else
					{
						cout << "\t最高分\t最低分\t平均分\t60分下\t60分段\t70分段\t80分段\t90分段" << endl;
						cout << "总成绩\t" << maxscore(arr_student).m_score << "\t" << minscore(arr_student).m_score << "\t" << avescore(arr_student).m_score << "\t"; scorenum(arr_student);
						cout << "实验成绩" << maxscore(arr_student).m_experimentscore << "\t" << minscore(arr_student).m_experimentscore << "\t" << avescore(arr_student).m_experimentscore << "\t"; experimentscorenum(arr_student);
						cout << "作业成绩" << maxscore(arr_student).m_homeworkscore << "\t" << minscore(arr_student).m_homeworkscore << "\t" << avescore(arr_student).m_homeworkscore << "\t"; homeworkscorenum(arr_student);
						cout << "期中成绩" << maxscore(arr_student).m_dailyscore << "\t" << minscore(arr_student).m_dailyscore << "\t" << avescore(arr_student).m_dailyscore << "\t"; dailyscorenum(arr_student);
						cout << "期末成绩" << maxscore(arr_student).m_endscore << "\t" << minscore(arr_student).m_endscore << "\t" << avescore(arr_student).m_endscore << "\t"; endscorenum(arr_student);
						cout << endl;
					}
				}
			}
			else if (teacherchoice == 4)
			{
				cout << "请输入修改后的密码：" << endl;
				char k; memory_key = "\0";
				while (1)
				{
					k = _getch();
					cout << "*";
					if (k == '\r')
					{
						break;
					}
					memory_key += k;
				}
				ofs_key.open("key.txt", ios::out);
				encryption(memory_key);
				ofs_key << memory_key;
				ofs_key.close();
				cout << endl;
			}

		}
		else if (identchoice == 2) //学生身份
		{
			cout << "您的身份是：学生" << endl;
			ifs_sub.open("课程信息.txt", ios::in);
			if (ifs_sub.is_open())
			{
				Subject tempsub;
				arr_subject.clear();
				while (ifs_sub >> tempsub.m_subjectid >> tempsub.m_subjectname)
				{
					arr_subject.push_back(tempsub);
				}
			}
			ifs_sub.close();
			ifs_stu.open("学生信息.txt", ios::in);
			if (ifs_stu.is_open())
			{
				Student tempstu;
				arr_student.clear();
				while (ifs_stu >> tempstu.m_id >> tempstu.m_name >> tempstu.m_dailyscore >> tempstu.m_endscore >> tempstu.m_score)
				{
					arr_student.push_back(tempstu);
				}
			}
			ifs_stu.close();
			if (arr_student.empty())
			{
				cout << "目前尚无学生信息" << endl << endl;
			}
			cout << "1.显示课程信息" << endl;
			cout << "2.显示学生成绩" << endl;
			cout << "3.显示成绩统计" << endl;
			cout << "4.进入信息查询" << endl;
			int stuchoice = 0; int findchoice = 0; int temp_id = 0; string temp_name;
			cin >> stuchoice;
			cout << endl;
			switch (stuchoice)
			{
			case 1: //显示课程信息
				if (arr_subject.empty())
				{
					cout << "暂无课程信息" << endl << endl;
					break;
				}
				else
				{
					cout << "编号\t名称" << endl;
					for (int i = 0; i < arr_subject.size(); i++)
					{
						cout << arr_subject[i].m_subjectid << "\t" << arr_subject[i].m_subjectname << endl << endl;
					}
					break;
				}
			case 2: //显示学生信息
				if (arr_student.empty())
				{
					cout << "暂无成绩信息" << endl << endl;
					break;
				}
				else
				{
					cout << "学号\t姓名\t实验\t作业\t期中\t期末\t总成绩" << endl;
					for (int i = 0; i < arr_student.size(); i++)
					{
						cout << arr_student[i].m_id << "\t" << arr_student[i].m_name << "\t" << arr_student[i].m_experimentscore << "\t" << arr_student[i].m_homeworkscore << "\t" << arr_student[i].m_dailyscore << "\t" << arr_student[i].m_endscore << "\t" << arr_student[i].m_score << endl << endl;
					}
					break;
				}
			case 3:	//显示成绩统计
				if (arr_student.empty())
				{
					cout << "暂无成绩信息" << endl << endl;
					break;
				}
				else
				{
					cout << "\t最高分\t最低分\t平均分\t60分下\t60分段\t70分段\t80分段\t90分段" << endl;
					cout << "总成绩\t" << maxscore(arr_student).m_score << "\t" << minscore(arr_student).m_score << "\t" << avescore(arr_student).m_score << "\t"; scorenum(arr_student); cout << endl;
					cout << "实验成绩" << maxscore(arr_student).m_experimentscore << "\t" << minscore(arr_student).m_experimentscore << "\t" << avescore(arr_student).m_experimentscore << "\t"; experimentscorenum(arr_student); cout << endl;
					cout << "作业成绩" << maxscore(arr_student).m_homeworkscore << "\t" << minscore(arr_student).m_homeworkscore << "\t" << avescore(arr_student).m_homeworkscore << "\t"; homeworkscorenum(arr_student); cout << endl;
					cout << "平时成绩" << maxscore(arr_student).m_dailyscore << "\t" << minscore(arr_student).m_dailyscore << "\t" << avescore(arr_student).m_dailyscore << "\t"; dailyscorenum(arr_student); cout << endl;
					cout << "期末成绩" << maxscore(arr_student).m_endscore << "\t" << minscore(arr_student).m_endscore << "\t" << avescore(arr_student).m_endscore << "\t"; endscorenum(arr_student); cout << endl;
					break;
				}

			case 4: //进入信息查询
				cout << "1.按学号查询" << endl;
				cout << "2.按姓名查询" << endl;
				cin >> findchoice;
				cout << endl;
				if (findchoice == 1)
				{
					cout << "请输入要查询的学号" << endl;
					cin >> temp_id;
					cout << endl;
					bool nofind = 1;
					if (arr_student.empty())
					{
						cout << "暂无成绩信息" << endl;
					}
					else
					{
						for (int i = 0; i < arr_student.size(); i++)
						{

							if (arr_student[i].m_id == temp_id)
							{
								cout << "您的成绩为如下" << endl;
								cout << "总成绩\t实验\t作业\t期中\t期末\t排名\t" << endl;
								cout << arr_student[i].m_score << "\t" << arr_student[i].m_experimentscore << "\t" << arr_student[i].m_homeworkscore << arr_student[i].m_dailyscore << "\t" << arr_student[i].m_endscore << "\t" << ranknum(arr_student[i], arr_student) << endl << endl;
								nofind = 0;
							}
						}
						if (nofind)
						{
							cout << "未找到该学生" << endl;
							cout << endl;
						}
					}
				}
				if (findchoice == 2)
				{
					cout << "请输入要查询的名字" << endl;
					cin >> temp_name;
					cout << endl;
					bool nofind = 1;
					if (arr_student.empty())
					{
						cout << "暂无成绩信息" << endl;
					}
					else
					{
						for (int i = 0; i < arr_student.size(); i++)
						{

							if (arr_student[i].m_name == temp_name)
							{
								cout << "您的成绩为如下" << endl;
								cout << "总成绩\t实验\t作业\t期中\t期末\t排名\t" << endl;
								cout << arr_student[i].m_score << "\t" << arr_student[i].m_experimentscore << "\t" << arr_student[i].m_homeworkscore << arr_student[i].m_dailyscore << "\t" << arr_student[i].m_endscore << "\t" << ranknum(arr_student[i], arr_student) << endl << endl;
								nofind = 0;
							}
						}
						if (nofind)
						{
							cout << "未找到该学生" << endl;
							cout << endl;
						}
					}
				}
				break;
			}
		}
		else if (identchoice == 3)
		{
			break;
		}
		ofs_sub.close(); ifs_sub.close(); ifs_stu.close(); ofs_stu.close(); ofs_key.close(); ifs_key.close();
	}
	return 0;
}