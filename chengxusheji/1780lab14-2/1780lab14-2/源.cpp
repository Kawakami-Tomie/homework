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

// 成员函数
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

// 成员函数
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

// 成员函数
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

// 成员函数
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
	// 显示全部信息
}

void Teacher::displayStatistics() {
	// 显示信息统计
}

void Teacher::modifyPassword() {
	// 修改密码
}


void teacherMenu() {
	int option;
	do {
		cout << "请选择功能：" << endl;
		cout << "1.录入或修改课程信息" << endl;
		cout << "2.录入或修改评分项目" << endl;
		cout << "3.录入或修改学生信息" << endl;
		cout << "4.删除学生信息" << endl;
		cout << "5.显示全部信息" << endl;
		cout << "6.显示信息统计" << endl;
		cout << "7.修改密码" << endl;
		cout << "0.退出" << endl;
		cin >> option;
		switch (option) {
		case 1:
			// 录入或修改课程信息
			break;
		case 2:
			// 录入或修改评分项目
			break;
		case 3:
			// 录入或修改学生信息
			break;
		case 4:
			// 删除学生信息
			break;
		case 5:
			// 显示全部信息
			break;
		case 6:
			// 显示信息统计
			break;
		case 7:
			// 修改密码
			break;
		case 0:
			// 退出
			break;
		default:
			// 错误处理
			break;
		}
	} while (option != 0);
}


void studentMenu() {
	int option;
	do {
		cout << "请选择功能：" << endl;
		cout << "1.显示全部信息" << endl;
		cout << "2.显示信息统计" << endl;
		cout << "3.查询个人成绩" << endl;
		cout << "0.退出" << endl;
		cin >> option;
		switch (option) {
		case 1:
			// 显示全部信息
			break;
		case 2:
			// 显示信息统计
			break;
		case 3:
			// 查询个人成绩
			break;
		case 0:
			// 退出
			break;
		default:
			// 错误处理
			break;
		}
	} while (option != 0);
}


void writeFile(Teacher teacher) {
	// 存储文件
}

Teacher readFile() {
	Teacher teacher;
	// 读取文件
	return teacher;
}


int main()
{
	int role;
	do {
		cout << "请选择您的身份：1.教师 2.学生" << endl;
		cin >> role;
	} while (role != 1 && role != 2);
	if (role == 1) {// 进入教师子菜单
		
		
		
		
		
		teacherMenu();
	}
	else {// 进入学生子菜单
		studentMenu();
	}
	return 0;
}
