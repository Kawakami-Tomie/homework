#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

//����ѧ���ɼ���Ϣ�Ľṹ������ࡣ

struct Student  //�ṹ��
{
	string ID;
	string name;
	float math, English;
};

int main() 
{
	char retry = 'Y';
	int n = 1;//arr.size()
	
	//���������͵�Vector���������Դ洢ѧ���ɼ���Ϣ��
	vector<Student>arr(n);
	struct Student st;//���¶���ṹ�����ڴ�������
flag:
	cout << "������ѧ����ѧ�š����֡������ɼ���Ӣ��ɼ���" << endl;
	cin >> arr[n - 1].ID >> arr[n - 1].name >> arr[n - 1].math >> arr[n - 1].English;
	if (retry == 'Y') {
		for (int j = 0; j < n - 1; j++) {

			if (arr[n - 1].ID == arr[j].ID) {
				cout << "�����ѧ���ظ��ˣ����������룡" << endl;
				cout << "������ѧ����ѧ�ţ�" << endl;
				cin >> arr[n - 1].ID;
			}
		}
		if (arr[n - 1].math < 0 || arr[n - 1].math>100) {
			cout << "��������ɼ���Ч�����������룡" << endl;
			cout << "��������������ɼ���" << endl;
			cin >> arr[n - 1].math;
		}
		if (arr[n - 1].English < 0 || arr[n - 1].English>100) {
			cout << "����Ӣ��ɼ���Ч�����������룡" << endl;
			cout << "����������Ӣ��ɼ���" << endl;
			cin >> arr[n - 1].English;
		}
		for (int i = n - 1; i > 0; i--)//�����������ʵ����������,ð������
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
		
		cout << "�Ƿ�������룿��������Y�������˳�" << endl;
		cin >> retry;
		
		if (retry == 'Y')
		{
			n++;
			arr.push_back(st);//�������룬�����������µĴ���ռ�
			goto flag;
		}
	}
	
	//��������ĳɼ��б�

	cout << "ѧ��\t����\t����\tӢ��" << endl;//����ɼ�
	cout << "_______________________________________" << endl;
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i].ID << "\t" << arr[i].name << "\t" << arr[i].math << "\t" << arr[i].English << endl;
	}
	cout << "_______________________________________" << endl;

	float maxmath = 0, maxEnglish = 0, math_average = 0, English_average = 0, minmath = 100, minEnglish = 100, math_fail = 0, English_fail = 0;

	for (int k = 0; k < arr.size(); k++)//ȡ��С��ȡƽ��
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

	int c = 0, d = 0;//�����ҿ�������Ӣ��ҿ�����
	
	for (int p = 0; p < arr.size(); p++)//����ҿ���
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
	
	
	//���ͳ����Ϣ������ѧ��������ÿ�ſε���ߡ���͡�ƽ���ɼ����������ʡ�
	cout << endl;
	cout << "��Ŀ" << "\t" << "����" << "\t" << "��߷�" << "\t" << "��ͷ�" << "\t"<<"ƽ����"<< "\t"<<"��������"<<endl;
	cout << "_____________________________________________" << endl;
	cout << "����" << "\t" <<arr.size()<< "\t" << maxmath << "\t" << minmath << "\t" << math_average << "\t" << math_fail << "%" << endl;
	cout << "Ӣ��" << "\t" << arr.size() << "\t" << maxEnglish << "\t" << minEnglish << "\t" << English_average << "\t" << English_fail << "%" << endl;
	cout << "_____________________________________________" << endl;
	cout << "�Ƿ�������룬��������Y" << endl;
	cin >> retry;
	if (retry == 'Y')
	{
		n++;
		arr. push_back(st);
		goto flag;
	}
	return 0;
}

