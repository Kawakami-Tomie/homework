#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;


float number1(string n)
{
	float x=0;
	if (n == "zero") { x = 0; }
	else if (n == "one") { x = 1; }
	else if (n == "two") { x = 2; }
	else if (n == "three") { x = 3; }
	else if (n == "four") { x = 4; }
	else if (n == "five") { x = 5; }
	else if (n == "six") { x = 6; }
	else if (n == "seven") { x = 7; }
	else if (n == "eight") { x = 8; }
	else if (n == "nine") { x = 9; }
	else if (n == "ten") { x = 10; }
	else if (n == "eleven") { x = 11; }
	else if (n == "twelve") { x = 12; }
	else if (n == "thirteen") { x = 13; }
	else if (n == "fourteen") { x = 14; }
	else if (n == "fifteen") { x = 15; }
	else if (n == "sixteen") { x = 16; }
	else if (n == "seventeen") { x = 17; }
	else if (n == "eighteen") { x = 18; }
	else if (n == "nineteen") { x = 19; }
	else if (n == "twenty") { x = 20; }

	return  x;
}

string  number2(int n)
{
	string a;
	if (n == 0) { a = "zero"; }
	else if (n == 1) { a = "one"; }
	else if (n == 2) { a = "two"; }
	else if (n == 3) { a = "three"; }
	else if (n == 4) { a = "four"; }
	else if (n == 5) { a = "five"; }
	else if (n == 6) { a = "six"; }
	else if (n == 7) { a = "seven"; }
	else if (n == 8) { a = "eight"; }
	else if (n == 9) { a = "nine"; }
	else if (n == 10) { a = "ten"; }
	else if (n == 11) { a = "eleven"; }
	else if (n == 13) { a = "thirteen"; }
	else if (n == 12) { a = "twelve"; }
	else if (n == 14) { a = "fourteen"; }
	else if (n == 15) { a = "sixteen"; }
	else if (n == 17) { a = "seventeen"; }
	else if (n == 18) { a = "eighteen"; }
	else if (n == 19) { a = "nineteen"; }

	return a;
}

string number3(int n)//����20��ʮλ���߰�λ
{
	string a;
	if (n == 1) { a = "ten"; }
	else if (n == 2) { a = "twenty"; }
	else if (n == 3) { a = "thirty"; }
	else if (n == 4) { a = "forty"; }
	else if (n == 5) { a = "fifty"; }
	else if (n == 6) { a = "sixty"; }
	else if (n == 7) { a = "seventy"; }
	else if (n == 8) { a = "eighty"; }
	else if (n == 9) { a = "ninety"; }
	return a;
}

int main() {
	string arr[20] = { "zero","one","two","three","four","five","seven","eight","nine","ten",
	"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nighteen","twenty" };
	string num11, num12, num13, num14, num21, num22, num23, num24;
	char retry = 'Y';
	int x = 0, y = 0;

flag1:
	cout << "�������һ�����ֵ�Ӣ�ģ�" << endl;
	cin >> num11 >> num12 >> num13 >> num14;//������С���㣬����λ



	for (int i = 0; i < 20; i++)//�ж��Ƿ񳬳���Χ
	{
		if (num11 == arr[i]) {
			x++;
			break;
		}
	}
	if (x == 0)
	{
		cout << "������ĵ�һ�����ֵ�Ӣ�ĵ��ʲ���20�ڣ����������룺" << endl;
		goto flag1;
	}
	if (number1(num11) == 20)//С������Խ��
	{
		if (number1(num13) != 0 || number1(num14) != 0) {
			cout << "������ĵ�һ�����ֵ�Ӣ�ĵ��ʲ���20�ڣ����������룺" << endl;
			goto flag1;
		}
	}
	float num1, num2;

	num1 = number1(num11) + (number1(num13) / 10) + (number1(num14) / 100);//�����һ������
	cout << num1 << endl;

flag2:
	cout << "������ڶ������ֵ�Ӣ�ģ�" << endl;
	cin >> num21 >> num22 >> num23 >> num24;



	for (int i = 0; i < 20; i++)//�����һ������
	{
		if (num21 == arr[i]) {
			y++;
			break;
		}
	}
	if (y == 0)
	{
		cout << "������ĵڶ������ֵ�Ӣ�ĵ��ʲ���20�ڣ����������룺" << endl;
		goto flag2;
	}
	if (number1(num21) == 20)//С������Խ��
	{
		if (number1(num23) != 0 || number1(num24) != 0) {
			cout << "������ĵڶ������ֵ�Ӣ�ĵ��ʲ���20�ڣ����������룺" << endl;
			goto flag2;
		}
	}

	num2 = number1(num21) + (number1(num23) / 10) + (number1(num24) / 100);//����ڶ�������
	cout << num2 << endl;

	float e;
	e = num1 * num2;

	int zhengshu = e;//float ת��int��������������
	float xiaoshu = e - zhengshu;//С������
	int first = xiaoshu * 10;//С����һλ
	int second = xiaoshu * 100;
	int second1 = second % 10;//С���ڶ�λ
	int thrid = xiaoshu * 1000;
	int thrid1 = ((thrid % 1000) % 100) % 10;//С������λ
	int forth = xiaoshu * 10000;
	int forth1 = (((forth % 10000) % 1000) % 100) % 10;//С������λ
	
	string xiaoshupart = number2(first) + number2(second1) + number2(thrid1) + number2(forth1);

	int single, tens, hundred, twodigit;
	if (zhengshu < 20 && zhengshu >= 0)//0-20
	{
		cout << "�����" << e << endl;
		cout << number2(zhengshu) << " point " << number2(first) << " " << number2(second1) << " " << number2(thrid1) << " " << number2(forth1) << endl;
	}
	if (zhengshu >= 20 && zhengshu < 100)//20-100
	{
		single = zhengshu % 10;//��λ
		tens = (zhengshu - single) / 10;//ʮλ
		if (single == 0)
		{
			cout << "�����" << e << endl;
			cout << number3(tens) << " point " << number2(first) << " " << number2(second1) << " " << number2(thrid1) << " " << number2(forth1) << endl;

		}
		else
		{
			cout << "�����" << e << endl;
			cout << number3(tens) << "-" << number2(single) << " point " << number2(first) << " " << number2(second1) << " " << number2(thrid1) << " " << number2(forth1) << endl;

		}
	}
	if (zhengshu >= 100)//100-400
	{
		twodigit = zhengshu % 100;//ʮλ�͸�λ
		single = twodigit % 10;//��λ
		tens = (twodigit - single) / 10;//ʮλ
		hundred = (zhengshu - twodigit) / 100;//��λ
		{
			if (single == 0)//��λΪ0
			{
				if (tens == 0)
				{
				 cout <<"�����"<< e << endl;
				 cout << number2(hundred) << " " << "hundred point " << number2(first) << " " << number2(second1) << " " << number2(thrid1) << " " << number2(forth1) << endl;
				}
				
				
				else 
				{
					cout << "�����" << e << endl;
					cout << number2(hundred) << " " << "hundred and" << " " << number3(tens) << " point " << number2(first) << " " << number2(second1) << " " << number2(thrid1) << " " << number2(forth1) << endl;
				}
			}
			else //��λ��Ϊ0
			{
				if (tens == 0) 
				{
					cout << "�����" << e << endl;
					cout << number2(hundred) << " " << "hundred and" << " " << number2(single) << " point " << number2(first) << " " << number2(second1) << " " << number2(thrid1) << " " << number2(forth1) << endl; }
				else if (tens == 1 )
				{
					cout << "�����" << e << endl;
					cout << number2(hundred) << " " << "hundred and" << " " << number2(twodigit) << " " << "point " << number2(first) << " " << number2(second1) << " " << number2(thrid1) << " " << number2(forth1) << endl;
				}
				/*else if (tens == 2)
				{
					cout << "�����" << e << endl;
					cout << number2(hundred) << " " << "hundred and" << " " << number2(twodigit) << " " << "point " << number2(first) << " " << number2(second1) << " " << number2(thrid1) << " " << number2(forth1) << endl;
				}*/
				else if (tens != 1  && tens != 0)
				{
					cout << "�����" << e << endl;
					cout << number2(hundred) << " " << "hundred and" << " " << number3(tens) << "-" << number2(single) << " point " << number2(first) << " " << number2(second1) << " " << number2(thrid1) << " " << number2(forth1) << endl; }
			}
		}
	}
	cout << "�Ƿ�������룿��������Y�������˳�" << endl;
	cin >> retry;
	if (retry == 'Y')
	{
		goto flag1;
	}
	return 0;
}


