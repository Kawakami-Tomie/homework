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

class ArrayOfStudents //��̬������
{	
public:
	ArrayOfStudents(int size) :size(size) //����
	{
		message = new student[size];//���������ռ�
	}
	~ArrayOfStudents()//����
	{
		delete[]message;  //ɾ���������������ռ�
	}
	//����±�Ϊindex������Ԫ��
	student& element(int index) {
		assert(index >= 0 && index < size);//�ж��±��Ƿ�Խ�磬����±�Խ�磬������ֹ
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
	cout << "������ѧ��������" << endl;
	cin >> num;
	
	ArrayOfStudents message(num);//������������
	
	for (int i = 0; i < num; i++)
	{
		cout << "������ѧ��" << i + 1 << "��ѧ�ţ������������ɼ���Ӣ��ɼ���" << endl;
		cin >>ID >> name >> Math >>English;
		message.element(i).setID(ID); message.element(i).setname(name);//����
		message.element(i).setMath(Math); message.element(i).setEnglish(English);
		//���������Ա����
		for (int j = 0; j < i; j++)
		{
			if (message.element(j).getID() == message.element(i).getID())//���ѧ���Ƿ��Ѿ�¼��
			{
				cout << "ѧ�Ų����ظ�¼�룬���������룺" << endl;
				i--;
				break;
			}
		}
		if (message.element(i).getMath() < 0 || message.element(i).getMath() >100 || message.element(i).getEnglish() < 0 || message.element(i).getEnglish() >100)//�������ɼ��Ƿ�Ϸ�
		{
			cout << "�ɼ�������Χ��������¼��" << endl;
			i--;
		}
	}
	cout << "ѧ��\t����\t����\tӢ��" << endl;//����ɼ�
	cout << "_______________________________________" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << message.element(i).getID() << "\t" << message.element(i).getname() << "\t" << message.element(i).getMath() << "\t" << message.element(i).getEnglish() << endl;
	}
	cout << "_______________________________________" << endl;
	float Math_Sum = 0, English_Sum = 0, Math_Average=0, English_Average=0, Math_Max = 0, English_Max = 0, Math_Min = 100, English_Min = 100;
	for (int i = 0; i < num; i++)//��������С�ɼ�
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
	cout << endl;//����ɼ�
	cout << "��Ŀ" << "\t" << "��߷�" << "\t" << "��ͷ�" << "\t" << "ƽ����" << endl;
	cout << "_______________________________________" << endl;
	cout << "����" << "\t" << Math_Max << "\t" << Math_Min << "\t" << Math_Average << endl;
	cout << "Ӣ��" << "\t" << English_Max << "\t" << English_Min << "\t" << English_Average << endl;
	cout << "_______________________________________" << endl;
	

	while (1)
	{
		string inquireID;
		cout << "����������ѯ��ѧ�ţ�" << endl;
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
			cout << "�����ѧ���������������룡" << endl;
		else 
		{
			cout << "ѧ��\t����\t����\tӢ��" << endl;//����ɼ�

			cout << message.element(f).getID() << "\t" << message.element(f).getname() << "\t" << message.element(f).getMath() << "\t" << message.element(f).getEnglish() << endl;
		}
	
	}
	return 0;
}





