#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

//定义学生成绩信息的结构体或者类。

struct Student  //结构体
{
	string ID;
	string name;
	float math, English;
};

int main() 
{
	char retry = 'Y';
	int n = 1;//arr.size()
	
	//申明该类型的Vector向量，用以存储学生成绩信息。
	vector<Student>arr(n);
	struct Student st;//重新定义结构体用于储存数据
flag:
	cout << "请输入学生的学号、名字、高数成绩、英语成绩：" << endl;
	cin >> arr[n - 1].ID >> arr[n - 1].name >> arr[n - 1].math >> arr[n - 1].English;
	if (retry == 'Y') {
		for (int j = 0; j < n - 1; j++) {

			if (arr[n - 1].ID == arr[j].ID) {
				cout << "输入的学号重复了，请重新输入！" << endl;
				cout << "请输入学生的学号：" << endl;
				cin >> arr[n - 1].ID;
			}
		}
		if (arr[n - 1].math < 0 || arr[n - 1].math>100) {
			cout << "输入高数成绩无效，请重新输入！" << endl;
			cout << "请重新输入高数成绩：" << endl;
			cin >> arr[n - 1].math;
		}
		if (arr[n - 1].English < 0 || arr[n - 1].English>100) {
			cout << "输入英语成绩无效，请重新输入！" << endl;
			cout << "请重新输入英语成绩：" << endl;
			cin >> arr[n - 1].English;
		}
		for (int i = n - 1; i > 0; i--)//交换数组对象，实现升序排列,冒泡排序
		{
			if (arr[i].ID < arr[i - 1].ID)
			{
				swap(arr[i].ID, arr[i - 1].ID);
				swap(arr[i].name, arr[i - 1].name);
				swap(arr[i].math, arr[i - 1].math);
				swap(arr[i].English, arr[i - 1].English);
			}
		}
		st.ID = arr[n - 1].ID;
		st.name = arr[n - 1].name;
		st.math = arr[n - 1].math;
		st.English = arr[n - 1].English;
		
		cout << "是否继续输入？继续输入Y，否则退出" << endl;
		cin >> retry;
		
		if (retry == 'Y')
		{
			n++;
			arr.push_back(st);//重新输入，申请数组中新的储存空间
			goto flag;
		}
	}
	
	//输出排序后的成绩列表。

	cout << "学号\t姓名\t高数\t英语" << endl;//输出成绩
	cout << "_______________________________________" << endl;
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i].ID << "\t" << arr[i].name << "\t" << arr[i].math << "\t" << arr[i].English << endl;
	}
	cout << "_______________________________________" << endl;

	float maxmath = 0, maxEnglish = 0, math_average = 0, English_average = 0, minmath = 100, minEnglish = 100, math_fail = 0, English_fail = 0;

	for (int k = 0; k < arr.size(); k++)//取大小，取平均
	{
		if (maxmath < arr[k].math)
			maxmath = arr[k].math;
	
		if (minmath > arr[k].math)
			minmath = arr[k].math;
	
		if (maxEnglish<arr[k].English)
			maxEnglish = arr[k].English;
	
		if (minEnglish > arr[k].English)
			minEnglish = arr[k].English;
	
		math_average += arr[k].math;
		English_average +=arr[k].English;
	}
	math_average = math_average / arr.size();
	English_average = English_average / arr.size();

	int c = 0, d = 0;//高数挂科人数，英语挂科人数
	
	for (int p = 0; p < arr.size(); p++)//计算挂科率
	{
		if (arr[p].math < 60)
		{
			c++;
		}
	}
	math_fail = ((double)c / arr.size()) * 100;

	for (int q = 0; q < arr.size(); q++) {
		if (arr[q].English < 60)
		{
			d++;
		}
	}
	English_fail = ((double)d / arr.size()) * 100;
	
	
	//输出统计信息，包括学生人数，每门课的最高、最低、平均成绩，不及格率。
	cout << endl;
	cout << "科目" << "\t" << "人数" << "\t" << "最高分" << "\t" << "最低分" << "\t"<<"平均分"<< "\t"<<"不及格率"<<endl;
	cout << "_____________________________________________" << endl;
	cout << "高数" << "\t" <<arr.size()<< "\t" << maxmath << "\t" << minmath << "\t" << math_average << "\t" << math_fail << "%" << endl;
	cout << "英语" << "\t" << arr.size() << "\t" << maxEnglish << "\t" << minEnglish << "\t" << English_average << "\t" << English_fail << "%" << endl;
	cout << "_____________________________________________" << endl;
	cout << "是否继续输入，是请输入Y" << endl;
	cin >> retry;
	if (retry == 'Y')
	{
		n++;
		arr. push_back(st);
		goto flag;
	}
	return 0;
}

