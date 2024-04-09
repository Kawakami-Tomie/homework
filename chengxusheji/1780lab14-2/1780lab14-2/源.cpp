#include<iostream>
#include<vector>
using namespace std;
class Course {
private:
	string code;
	string name;
public:
	void setCode(string code);
	void setName(string name);
	string getCode();
	string getName();
};

// ��Ա����
void Course::setCode(string code) {
	this->code = code;
}

void Course::setName(string name) {
	this->name = name;
}

string Course::getCode() {
	return code;
}

string Course::getName() {
	return name;
}


class GradeProject {
private:
	string name;
	double weight;
public:
	void setName(string name);
	void setWeight(double weight);
	string getName();
	double getWeight();
};

// ��Ա����
void GradeProject::setName(string name) {
	this->name = name;
}

void GradeProject::setWeight(double weight) {
	this->weight = weight;
}

string GradeProject::getName() {
	return name;
}

double GradeProject::getWeight() {
	return weight;
}

class Student {
private:
	string id;
	string name;
	vector<double> grades;
public:
	void setId(string id);
	void setName(string name);
	void setGrades(vector<double> grades);
	string getId();
	string getName();
	vector<double> getGrades();
};

// ��Ա����
void Student::setId(string id) {
	this->id = id;
}

void Student::setName(string name) {
	this->name = name;
}

void Student::setGrades(vector<double> grades) {
	this->grades = grades;
}

string Student::getId() {
	return id;
}

string Student::getName() {
	return name;
}

vector<double> Student::getGrades() {
	return grades;
}


class Teacher {
private:
	string password;
	vector<Course> courses;
	vector<GradeProject> projects;
	vector<Student> students;
public:
	bool checkPassword(string password);
	void setPassword(string password);
	void addCourse(Course course);
	void addProject(GradeProject project);
	void addStudent(Student student);
	void deleteStudent(string id);
	void displayAllInfo();
	void displayStatistics();
	void modifyPassword();
};

// ��Ա����
bool Teacher::checkPassword(string password) {
	return (this->password == password);
}

void Teacher::setPassword(string password) {
	this->password = password;
}

void Teacher::addCourse(Course course) {
	courses.push_back(course);
}

void Teacher::addProject(GradeProject project) {
	projects.push_back(project);
}

void Teacher::addStudent(Student student) {
	students.push_back(student);
}

void Teacher::deleteStudent(string id) {
	for (vector<Student>::iterator it = students.begin(); it != students.end(); it++)
	{
		if (it->getId() == id) {
			students.erase(it);
			break;
		}
	}
}

void Teacher::displayAllInfo() {
	// ��ʾȫ����Ϣ
}

void Teacher::displayStatistics() {
	// ��ʾ��Ϣͳ��
}

void Teacher::modifyPassword() {
	// �޸�����
}


void teacherMenu() {
	int option;
	do {
		cout << "��ѡ���ܣ�" << endl;
		cout << "1.¼����޸Ŀγ���Ϣ" << endl;
		cout << "2.¼����޸�������Ŀ" << endl;
		cout << "3.¼����޸�ѧ����Ϣ" << endl;
		cout << "4.ɾ��ѧ����Ϣ" << endl;
		cout << "5.��ʾȫ����Ϣ" << endl;
		cout << "6.��ʾ��Ϣͳ��" << endl;
		cout << "7.�޸�����" << endl;
		cout << "0.�˳�" << endl;
		cin >> option;
		switch (option) {
		case 1:
			// ¼����޸Ŀγ���Ϣ
			break;
		case 2:
			// ¼����޸�������Ŀ
			break;
		case 3:
			// ¼����޸�ѧ����Ϣ
			break;
		case 4:
			// ɾ��ѧ����Ϣ
			break;
		case 5:
			// ��ʾȫ����Ϣ
			break;
		case 6:
			// ��ʾ��Ϣͳ��
			break;
		case 7:
			// �޸�����
			break;
		case 0:
			// �˳�
			break;
		default:
			// ������
			break;
		}
	} while (option != 0);
}


void studentMenu() {
	int option;
	do {
		cout << "��ѡ���ܣ�" << endl;
		cout << "1.��ʾȫ����Ϣ" << endl;
		cout << "2.��ʾ��Ϣͳ��" << endl;
		cout << "3.��ѯ���˳ɼ�" << endl;
		cout << "0.�˳�" << endl;
		cin >> option;
		switch (option) {
		case 1:
			// ��ʾȫ����Ϣ
			break;
		case 2:
			// ��ʾ��Ϣͳ��
			break;
		case 3:
			// ��ѯ���˳ɼ�
			break;
		case 0:
			// �˳�
			break;
		default:
			// ������
			break;
		}
	} while (option != 0);
}


void writeFile(Teacher teacher) {
	// �洢�ļ�
}

Teacher readFile() {
	Teacher teacher;
	// ��ȡ�ļ�
	return teacher;
}


int main()
{
	int role;
	do {
		cout << "��ѡ��������ݣ�1.��ʦ 2.ѧ��" << endl;
		cin >> role;
	} while (role != 1 && role != 2);
	if (role == 1) {// �����ʦ�Ӳ˵�
		
		
		
		
		
		teacherMenu();
	}
	else {// ����ѧ���Ӳ˵�
		studentMenu();
	}
	return 0;
}
