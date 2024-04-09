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
	void cul_score()//�ܳɼ����㷽ʽ
	{
		m_score = m_dailyscore*0.2+ m_endscore*0.5+ m_experimentscore*0.2+ m_homeworkscore*0.1;
	}
	int m_id;
	string m_name;
	double m_dailyscore;//���гɼ�
	double m_endscore;//��ĩ�ɼ�
	double m_experimentscore;//ʵ��ɼ�
	double m_homeworkscore;//��ҵ�ɼ�
	double m_score;//�ܳɼ�
};
Student maxscore(vector<Student> xarr_student)//ͳ����߷�
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
	temp.m_dailyscore = maxdailyscore;//���гɼ�����߷�
	temp.m_endscore = maxendscore;//��ĩ�ɼ���߷�
	temp.m_experimentscore = maxexperimentscore;//ʵ��ɼ�����߷�
	temp.m_homeworkscore = maxhomeworkscore;//��ҵ�ɼ���߷�
	temp.m_score = maxscore;//�ܳɼ���߷�
	return temp;
}
Student minscore(vector<Student> xarr_student)//ͳ����ͷ�
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
	temp.m_dailyscore = mindailyscore;//ƽʱ�ɼ���ͷ�
	temp.m_endscore = minendscore;//��ĩ�ɼ���ͷ�
	temp.m_experimentscore = minexperimentscore;//ʵ��ɼ�����ͷ�
	temp.m_homeworkscore = minhomeworkscore;//��ҵ�ɼ���ͷ�
	temp.m_score = minscore;//�ܳɼ���ͷ�
	return temp;
}
Student avescore(vector<Student> xarr_student)//ͳ��ƽ����
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
	temp.m_dailyscore = avedailyscore; //ƽʱ�ɼ�ƽ����
	temp.m_endscore = aveendscore;//��ĩ�ɼ�ƽ����
	temp.m_experimentscore = aveexperimentscore;//ʵ��ɼ�����ͷ�
	temp.m_homeworkscore = avehomeworkscore;//��ҵ�ɼ���ͷ�
	temp.m_score = avescore;//�ܳɼ�ƽ����
	return temp;
}

void dailyscorenum(vector<Student> xarr_student)//���зַ�����
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


void endscorenum(vector<Student> xarr_student)//��ĩ�ɼ�������
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
void experimentscorenum(vector<Student> xarr_student)//ʵ��ɼ�������
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

void homeworkscorenum(vector<Student> xarr_student)//��ҵ�ɼ�������
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


void scorenum(vector<Student> xarr_student)//�ַܷ�����ͳ��
{
	int temp50 = 0; int temp60 = 0; int temp70 = 0; int temp80 = 0; int temp90 = 0;
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_score < 60)//������
		{
			temp50++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_score < 70 && xarr_student[i].m_score >= 60)//60~70������
		{
			temp60++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_score < 80 && xarr_student[i].m_score >= 70)//70~80������
		{
			temp70++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)
	{
		if (xarr_student[i].m_score < 90 && xarr_student[i].m_score >= 80)//80~90������
		{
			temp80++;
		}
	}
	for (int i = 0; i < xarr_student.size(); i++)//90~100������
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
	//����
	int number[4] = { 4,3,2,1 };//����4,3,2,1λ
	for (int i = 0; i < xkey.length(); i++)
	{
		xkey[i] += (number[i % 4]);
	}
}
void decrypt(string& xkey)
{
	//����
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
		cout << "��ӭʹ�óɼ�����ϵͳ" << endl;
		cout << "��ѡ���ܣ�\n1.���ǽ�ʦ\n2.����ѧ��\n3.�˳�" << endl;
		cin >> identchoice;
		cout << endl;
		if (identchoice == 1) //��ʦ���
		{
			ifs_key.open("key.txt", ios::in);
			ifs_key >> memory_key;
			ifs_key.close();
			decrypt(memory_key);
			while (1)
			{
				cout << "����������(��ʼ����Ϊ123456):" << endl;
				char k;
				key = "\0";
				while (1)
				{
					k = _getch();
					cout << "*";
					if (k == '\r')//�س�
					{
						break;
					}
					key += k;
				}
				if (key != memory_key)
				{
					cout << endl;
					cout << "����������������룺" << endl;
				}
				else
				{
					cout << endl;
					break;
				}
			}
			cout << "��������ǣ���ʦ" << endl;
			ifs_sub.open("�γ���Ϣ.txt", ios::in);
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
			ifs_stu.open("ѧ����Ϣ.txt", ios::in);
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
			cout << "1.�γ���Ϣ" << endl; cout << "2.ѧ���ɼ�" << endl; cout << "3.��Ϣ��ʾ" << endl; cout << "4.�޸�����" << endl;
			int teacherchoice = 0; char yorn = 'Y'; int input_stu_choice = 0; int temp_id = 0; bool gotonone = 1; int showchoice = 0;
			cin >> teacherchoice;
			cout << endl;
			if (teacherchoice == 1) //����γ���Ϣ
			{
				while (1) //��vector�д洢���޸Ŀγ���Ϣ
				{
					int subchoice = 0; int temp_subid = 0;
					cout << endl;
					cout << "1.¼��γ���Ϣ 2.�޸Ŀγ���Ϣ" << endl;
					cin >> subchoice;
					cout << endl;
					if (subchoice == 1)
					{
						cout << "������γ̵ı�š����ƣ�" << endl;
						cin >> subject.m_subjectid; cin >> subject.m_subjectname;
						arr_subject.push_back(subject);
						cout << "����¼����޸Ŀγ���Ϣ(Y/N)";
						cin >> yorn;
						if (yorn != 'Y') { break; }
					}
					else if (subchoice == 2)
					{
						bool subcheck = 1;
						cout << "������Ҫ�޸Ŀγ̵ı��" << endl;
						cin >> temp_subid;
						for (int i = 0; i < arr_subject.size(); i++)
						{
							if (arr_subject[i].m_subjectid == temp_subid)
							{
								cout << "��������Ҫ������޸�Ϊ��" << endl;
								cin >> arr_subject[i].m_subjectid;
								cout << "��������Ҫ�������޸�Ϊ��" << endl;
								cin >> arr_subject[i].m_subjectname;
								subcheck = 0;
							}
						}
						if (subcheck)
						{
							cout << "δ�ҵ��ÿγ̱��" << endl;
						}
						cout << "�����޸Ŀγ̱��(Y/N)" << endl;
						cin >> yorn;
						cout << endl;
						if (yorn != 'Y')
						{
							break;
						}
					}
				}
				ofs_sub.open("�γ���Ϣ.txt", ios::out);
				for (int i = 0; i < arr_subject.size(); i++) //���γ���Ϣ¼�뵽�ļ���
				{
					ofs_sub << arr_subject[i].m_subjectid << " " << arr_subject[i].m_subjectname << endl;
				}
				ofs_sub.close();
			}
			else if (teacherchoice == 2) //����ѧ����Ϣ
			{
				while (1)
				{
					cout << "1.¼��ѧ���ɼ�" << endl;
					cout << "2.�޸�ѧ���ɼ�" << endl;
					cout << "3.ɾ��ѧ���ɼ�" << endl;
					cin >> input_stu_choice;
					cout << endl;
					switch (input_stu_choice)
					{
					case 1: //¼��ѧ���ɼ�
						cout << "������ѧ��ѧ�ţ�"; cin >> student.m_id;
						cout << "������ѧ��������"; cin >> student.m_name;
						cout << "������ѧ��ʵ��ɼ���"; cin >> student.m_experimentscore;
						cout << "������ѧ����ҵ�ɼ���"; cin >> student.m_homeworkscore;
						cout << "������ѧ�����гɼ���"; cin >> student.m_dailyscore;
						cout << "������ѧ����ĩ�ɼ���"; cin >> student.m_endscore;
						cout << endl;
						student.cul_score();
						arr_student.push_back(student);
						break;
					case 2: //�޸�ѧ���ɼ�
						cout << "������Ҫ�޸�ѧ����ѧ��" << endl;
						cin >> temp_id;
						cout << endl;
						for (int i = 0; i < arr_student.size(); i++)
						{
							if (arr_student[i].m_id == temp_id)
							{
								cout << "�뽫ѧ��ʵ��ɼ��޸�Ϊ��"; cin >> arr_student[i].m_experimentscore;
								cout << "�뽫ѧ����ҵ�ɼ��޸�Ϊ��"; cin >> arr_student[i].m_homeworkscore;
								cout << "�뽫ѧ��ƽʱ�ɼ��޸�Ϊ��"; cin >> arr_student[i].m_dailyscore;
								cout << "�뽫ѧ����ĩ�ɼ��޸�Ϊ��"; cin >> arr_student[i].m_endscore;
								arr_student[i].cul_score();
								gotonone = 0;
							}
						}
						if (gotonone)
						{
							cout << "û���ҵ���ѧ��" << endl;
						}
						break;
					case 3: //ɾ��ѧ���ɼ�
						cout << "������Ҫɾ��ѧ����ѧ�ţ�"; cin >> temp_id;
						for (int i = 0; i < arr_student.size(); i++)
						{
							if (arr_student[i].m_id == temp_id)
							{
								arr_student.erase(arr_student.begin() + i);
								gotonone = 0;
							}
							if (gotonone)
							{
								cout << "û���ҵ���ѧ��" << endl;
							}
						}
						break;
					}
					cout << "�����༭ѧ���ɼ�(Y/N)" << endl;
					cin >> yorn;
					cout << endl;
					if (yorn != 'Y')
					{
						break;
					}
				}

				ofs_stu.open("ѧ����Ϣ.txt", ios::out);
				for (int i = 0; i < arr_student.size(); i++) //��ѧ����Ϣ¼�뵽�ļ���
				{
					ofs_stu << arr_student[i].m_id << " " << arr_student[i].m_name << " "<<arr_student[i].m_experimentscore << " " << arr_student[i].m_homeworkscore << " " << arr_student[i].m_dailyscore << " " << arr_student[i].m_endscore << " " << arr_student[i].m_score << endl;
				}
				ofs_stu.close();
			}
			else if (teacherchoice == 3) //��Ϣ��ʾ
			{
				cout << "1.��ʾ�γ���Ϣ" << endl;
				cout << "2.��ʾѧ����Ϣ" << endl;
				cout << "3.��ʾѧ���ɼ�ͳ��" << endl;
				cin >> showchoice;
				cout << endl;
				if (showchoice == 1)
				{
					if (arr_subject.empty())
					{
						cout << "���޿γ���Ϣ" << endl << endl;
					}
					else
					{
						cout << "���\t����" << endl;
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
						cout << "���޳ɼ���Ϣ" << endl << endl;
					}
					else
					{
						cout << "ѧ��\t����\tʵ��\t��ҵ\t����\t��ĩ\t�ܳɼ�" << endl;
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
						cout << "���޳ɼ���Ϣ" << endl;
					}
					else
					{
						cout << "\t��߷�\t��ͷ�\tƽ����\t60����\t60�ֶ�\t70�ֶ�\t80�ֶ�\t90�ֶ�" << endl;
						cout << "�ܳɼ�\t" << maxscore(arr_student).m_score << "\t" << minscore(arr_student).m_score << "\t" << avescore(arr_student).m_score << "\t"; scorenum(arr_student);
						cout << "ʵ��ɼ�" << maxscore(arr_student).m_experimentscore << "\t" << minscore(arr_student).m_experimentscore << "\t" << avescore(arr_student).m_experimentscore << "\t"; experimentscorenum(arr_student);
						cout << "��ҵ�ɼ�" << maxscore(arr_student).m_homeworkscore << "\t" << minscore(arr_student).m_homeworkscore << "\t" << avescore(arr_student).m_homeworkscore << "\t"; homeworkscorenum(arr_student);
						cout << "���гɼ�" << maxscore(arr_student).m_dailyscore << "\t" << minscore(arr_student).m_dailyscore << "\t" << avescore(arr_student).m_dailyscore << "\t"; dailyscorenum(arr_student);
						cout << "��ĩ�ɼ�" << maxscore(arr_student).m_endscore << "\t" << minscore(arr_student).m_endscore << "\t" << avescore(arr_student).m_endscore << "\t"; endscorenum(arr_student);
						cout << endl;
					}
				}
			}
			else if (teacherchoice == 4)
			{
				cout << "�������޸ĺ�����룺" << endl;
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
		else if (identchoice == 2) //ѧ�����
		{
			cout << "��������ǣ�ѧ��" << endl;
			ifs_sub.open("�γ���Ϣ.txt", ios::in);
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
			ifs_stu.open("ѧ����Ϣ.txt", ios::in);
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
				cout << "Ŀǰ����ѧ����Ϣ" << endl << endl;
			}
			cout << "1.��ʾ�γ���Ϣ" << endl;
			cout << "2.��ʾѧ���ɼ�" << endl;
			cout << "3.��ʾ�ɼ�ͳ��" << endl;
			cout << "4.������Ϣ��ѯ" << endl;
			int stuchoice = 0; int findchoice = 0; int temp_id = 0; string temp_name;
			cin >> stuchoice;
			cout << endl;
			switch (stuchoice)
			{
			case 1: //��ʾ�γ���Ϣ
				if (arr_subject.empty())
				{
					cout << "���޿γ���Ϣ" << endl << endl;
					break;
				}
				else
				{
					cout << "���\t����" << endl;
					for (int i = 0; i < arr_subject.size(); i++)
					{
						cout << arr_subject[i].m_subjectid << "\t" << arr_subject[i].m_subjectname << endl << endl;
					}
					break;
				}
			case 2: //��ʾѧ����Ϣ
				if (arr_student.empty())
				{
					cout << "���޳ɼ���Ϣ" << endl << endl;
					break;
				}
				else
				{
					cout << "ѧ��\t����\tʵ��\t��ҵ\t����\t��ĩ\t�ܳɼ�" << endl;
					for (int i = 0; i < arr_student.size(); i++)
					{
						cout << arr_student[i].m_id << "\t" << arr_student[i].m_name << "\t" << arr_student[i].m_experimentscore << "\t" << arr_student[i].m_homeworkscore << "\t" << arr_student[i].m_dailyscore << "\t" << arr_student[i].m_endscore << "\t" << arr_student[i].m_score << endl << endl;
					}
					break;
				}
			case 3:	//��ʾ�ɼ�ͳ��
				if (arr_student.empty())
				{
					cout << "���޳ɼ���Ϣ" << endl << endl;
					break;
				}
				else
				{
					cout << "\t��߷�\t��ͷ�\tƽ����\t60����\t60�ֶ�\t70�ֶ�\t80�ֶ�\t90�ֶ�" << endl;
					cout << "�ܳɼ�\t" << maxscore(arr_student).m_score << "\t" << minscore(arr_student).m_score << "\t" << avescore(arr_student).m_score << "\t"; scorenum(arr_student); cout << endl;
					cout << "ʵ��ɼ�" << maxscore(arr_student).m_experimentscore << "\t" << minscore(arr_student).m_experimentscore << "\t" << avescore(arr_student).m_experimentscore << "\t"; experimentscorenum(arr_student); cout << endl;
					cout << "��ҵ�ɼ�" << maxscore(arr_student).m_homeworkscore << "\t" << minscore(arr_student).m_homeworkscore << "\t" << avescore(arr_student).m_homeworkscore << "\t"; homeworkscorenum(arr_student); cout << endl;
					cout << "ƽʱ�ɼ�" << maxscore(arr_student).m_dailyscore << "\t" << minscore(arr_student).m_dailyscore << "\t" << avescore(arr_student).m_dailyscore << "\t"; dailyscorenum(arr_student); cout << endl;
					cout << "��ĩ�ɼ�" << maxscore(arr_student).m_endscore << "\t" << minscore(arr_student).m_endscore << "\t" << avescore(arr_student).m_endscore << "\t"; endscorenum(arr_student); cout << endl;
					break;
				}

			case 4: //������Ϣ��ѯ
				cout << "1.��ѧ�Ų�ѯ" << endl;
				cout << "2.��������ѯ" << endl;
				cin >> findchoice;
				cout << endl;
				if (findchoice == 1)
				{
					cout << "������Ҫ��ѯ��ѧ��" << endl;
					cin >> temp_id;
					cout << endl;
					bool nofind = 1;
					if (arr_student.empty())
					{
						cout << "���޳ɼ���Ϣ" << endl;
					}
					else
					{
						for (int i = 0; i < arr_student.size(); i++)
						{

							if (arr_student[i].m_id == temp_id)
							{
								cout << "���ĳɼ�Ϊ����" << endl;
								cout << "�ܳɼ�\tʵ��\t��ҵ\t����\t��ĩ\t����\t" << endl;
								cout << arr_student[i].m_score << "\t" << arr_student[i].m_experimentscore << "\t" << arr_student[i].m_homeworkscore << arr_student[i].m_dailyscore << "\t" << arr_student[i].m_endscore << "\t" << ranknum(arr_student[i], arr_student) << endl << endl;
								nofind = 0;
							}
						}
						if (nofind)
						{
							cout << "δ�ҵ���ѧ��" << endl;
							cout << endl;
						}
					}
				}
				if (findchoice == 2)
				{
					cout << "������Ҫ��ѯ������" << endl;
					cin >> temp_name;
					cout << endl;
					bool nofind = 1;
					if (arr_student.empty())
					{
						cout << "���޳ɼ���Ϣ" << endl;
					}
					else
					{
						for (int i = 0; i < arr_student.size(); i++)
						{

							if (arr_student[i].m_name == temp_name)
							{
								cout << "���ĳɼ�Ϊ����" << endl;
								cout << "�ܳɼ�\tʵ��\t��ҵ\t����\t��ĩ\t����\t" << endl;
								cout << arr_student[i].m_score << "\t" << arr_student[i].m_experimentscore << "\t" << arr_student[i].m_homeworkscore << arr_student[i].m_dailyscore << "\t" << arr_student[i].m_endscore << "\t" << ranknum(arr_student[i], arr_student) << endl << endl;
								nofind = 0;
							}
						}
						if (nofind)
						{
							cout << "δ�ҵ���ѧ��" << endl;
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