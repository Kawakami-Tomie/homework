#include<iostream>
using namespace std;
#include"List.h"
#include"ListNode.h"
#include <string>
#include<ctime>
#include<cstdlib>
List<int> A;
List<int> B;
List<int> C;
List<int> stack;
string pok;
//
Posi(int) daoSi(List<int> list)
{
	Posi(int) p=list.last();
	return p->pred->pred->pred;
}

//
Posi(int) daoEr(List<int> list)
{
	Posi(int) p=list.last();
	return p->pred;
}
//�ж���������ظ�
int numGen[54];
bool isGenerated(int newNum)
{
	int i =0;
	for(i=0;i<54;i++)
	{
		if(numGen[i]==newNum)
			return true;
	}

		return false;
}
//
string BigType(int id)
{
	if(id>=0&&id<=51)
		switch(id%4)
		{
		case 0:return "����";
			break;
		case 1:return "÷��";
			break;
		case 2:return "����";
			break;
		case 3:return "����";
			break;
		}
	else
		switch(id)
		{
		case 52:return "С��";
			break;
		case 53:return "����";
			break;
		}
		return 0;
	
}
//
char SmallType(int id)
{
	if(id>=0&&id<=51)
	{	
		if(id>=0&&id<4)
			return '3';
		else if(id>=4&&id<8)
			return '4';
		else if(id>=8&&id<12)
			return '5';
		else if(id>=12&&id<16)
			return '6';
		else if(id>=16&&id<20)
			return '7';
		else if(id>=20&&id<24)
			return '8';
		else if(id>=24&&id<28)
			return '9';
		else if(id>=28&&id<32)
			return '1';
		else if(id>=32&&id<36)
			return 'J';
		else if(id>=36&&id<40)
			return 'Q';
		else if(id>=40&&id<44)
			return 'K';
		else if(id>=44&&id<48)
			return 'A';
		else if(id>=48&&id<52)
			return '2';
	}
	else if(id==52)
		return 'S';
	else if(id==53)
		return 'B';
	else
		return 0;

}
//����һ����
string pai[54];
List<int> poker()
{
	
	List<int> pai_wash;
	
	string num[13]={"3","4","5","6","7","8","9","10","J","Q","K","A","2"};
	string type[4]={"����","÷��","����","����"};
	int k=0;

	for(int i=0;i<13;i++)
		for(int j=0;j<4;j++)
			pai[k++]=type[j]+num[i];
	pai[52]="С��";
	pai[53]="����";
	srand(time(NULL));
	int newNum=rand()%54;
	for(int i=0;i<54;i++)
	{
		if(!isGenerated(newNum+1))
		{
			pai_wash.insertAsFist(newNum);
			numGen[i]=newNum+1;
			newNum=rand()%54;
		}
		else
		{	
			i--;
			newNum=rand()%54;
		}
	}
	return pai_wash;
}

//ɾ���˿�
int deletePoker(int num,List<int> &list)
{
	Posi(int) p=list.first();
	while(p->succ)
	{
		if(p->data==num)
			break;
		p=p->succ;
	}
	if(p!=NULL)
	{
	list.remove(p);
	return num;
	}
	else 
		return 0;
}
//���A������ȷ(���ţ�
bool reasonable(int t1,int num1,char chooseplay)
{
	if(t1!=-1){//������
		if(num1==1){//A������
			if (chooseplay == 'A') {
				if (A.find(t1) == NULL)
				{
					cout << "�Ʋ����ڣ�" << endl;
					return false;
				}
				else
					return true;
			}
			else if (chooseplay == 'B') {
					if (B.find(t1) == NULL)
					{
						cout << "�Ʋ����ڣ�" << endl;
						return false;
					}
					else
						return true;
			}
			else if (chooseplay == 'C') {
				if (C.find(t1) == NULL)
				{
					cout << "�Ʋ����ڣ�" << endl;
					return false;
				}
				else
					return true;
			}
		}
	}
	else
		return true;
}
//�ж��Ƕ���

bool isDuizi(int const e,List<int> list)
{
	Posi(int) p;
	Posi(int) x;
	p=list.find(e);
	if(p!=NULL){//�����������
	x=p->succ;//��̽ڵ�
	int Next=list.Data(x);//Ͷ��ȡ��(ǰ����������ȷ)
	
	if(SmallType(e)==SmallType(Next))//�ж������Ƿ���ͬ
		return true;
	else
		return false;
	}
	else
		return false;
}

//�ж���ը��
bool isZhadan(int const &e,List<int>list)
{
	Posi(int) p=list.find(e);
	Posi(int) x;
	Posi(int) q;
	Posi(int) y;
	int next,nnext,nnnext;
	
	 x=p->succ;
	next=list.Data(x);
	
	
	q=x->succ;
	nnext=list.Data(q);
	
	
	 y=q->succ;
	 nnnext=list.Data(y);
	
	 if (SmallType(e) == SmallType(next) == SmallType(nnext) == SmallType(nnnext))//�ж������Ƿ���ͬ
		 return true;
	 else
		 return false;
	//if(pai[e][3]==pai[next][3]==pai[nnext][3]==pai[nnnext][3])
	//	return true;
	//else
	//	return false;
	
	
}
//����С����
Posi(int) minDuizi(List<int> &list)
{
	Posi(int) p=list.first();
	if(list.size()>=2){//ֻҪ�б���������Ƽ�����
	while(p->succ->succ!=NULL)
	{
		if(isDuizi(p->data,list))
		{
			return p;
			break;
		}
		p=p->succ;
	}
	}
	return NULL;
}
//����Сը��
Posi(int) minZhadan(List<int> &list)
{
	Posi(int) p=list.first();
	if(list.size()>=4){
	while(p->succ->succ->succ->succ!=NULL)
	{
		if(isZhadan(p->data,list))
		{
			return p;
			break;
		}
		p=p->succ;
	}
	}
		return NULL;
}
//�Ҵ���С����������б��Ƿ������ը
bool DaXiaoWang(List<int> &list)
{
	Posi(int) p=list.last();
	Posi(int) x=p->pred;
	int i=0,j=0;
	i=list.Data(p);
	j=list.Data(x);
	if(i==53&&j==52)
		return true;
	else	
		return false;
}
//������
void Duizi(int &my,int another,int &nummy,List<int> &list)
{
		Posi(int) p;
		Posi(int) x;
		my=list.Search(another);//���ұ�another��ĵ�һ����
			if(list.size()>1){
				Posi(int) t=list.find(my);
				while(SmallType(my)==SmallType(another)&&t->succ)//�ҵ�������ֵ��ͬ�Ļ���Ҫ����
				{
					t=t->succ;
					my=list.Data(t);
				}
			}
			p=list.find(my);
			if(p!=NULL)//�Ҷ���
			{	
				x=p->succ;
				while(!isDuizi(my,list)&&x->succ!=NULL)
				{
					my=list.Data(x);
					x=x->succ;//�������������������ڵ����									
				}
			
			if(isDuizi(my,list)&&(SmallType(my)!=SmallType(another)))//�����������������ֵ����ͬ
			{
				for(int m=0;m<2;m++){
					deletePoker(my,list);
					stack.insertAsLast(my);
					cout<<pai[my]<<" ";
					if(m==0)my=list.Data(x);
				}
			 cout<<endl;

			 nummy=2;//����num2

			}
			else if(minZhadan(list)!=NULL)//��������˶��ӣ���ը��
			{	
				p=minZhadan(list);
				x=p->succ;
					for(int m=0;m<4;m++){
						deletePoker(my,list);
						stack.insertAsLast(my);
						cout<<pai[my]<<" ";
						my=list.Data(x);
						x=x->succ;
					}
				cout<<endl;
				nummy=4;//����num2
				}
			else if(DaXiaoWang(list))//2���Ӻ�4ը��������������������ը
				{
					p=list.last();
					x=p->pred;
					my=list.Data(x);
					deletePoker(my,list);
					stack.insertAsLast(my);
					cout<<pai[my]<<" ";
					my=list.Data(p);
					deletePoker(my,list);
					stack.insertAsLast(my);
					cout<<pai[my]<<" ";
					cout<<endl;
					nummy=2;//����num2
				}
			else
				{
				cout<<"����"<<endl;
				my=-1;
				nummy=1;
				}
			}
			else
				{
				cout<<"����"<<endl;
				my=-1;
				nummy=1;
			}
}
//��ը��
void Zhadan(int &my,int another,int &nummy,List<int> &list)
{
		my=list.Search(another);
		Posi(int)p=list.find(my);
		Posi(int) x;
		if(another!=52){
			if(my!=NULL)
			{
				x=p->succ;
				if(my!=NULL&&list.size()>=4)
			{
				while(!isZhadan(my,list)&&(x->succ->succ->succ!=NULL))
				{
					my=list.Data(x);
					x=x->succ;
				}
				if(isZhadan(my,list))
			{
				for(int m=0;m<4;m++){
			deletePoker(my,list);
			stack.insertAsLast(my);
			cout<<pai[my]<<" ";
			my=list.Data(x);
			x=x->succ;
				}
			cout<<endl;
			nummy=4;
				}
				}
			else
			{
				cout<<"����"<<endl;
				my=-1;
				nummy=1;
			}
			}
			else
			{
				cout<<"����"<<endl;
				my=-1;
				nummy=1;
			}
		}
		else
			{
				cout<<"����"<<endl;
				my=-1;
				nummy=1;
			}
}
//����(ͬʱ�����±�ֵ
int chuPai(int &t1,int &t2,int &t3,int &num1,int &num2,int &num3,List<int> &list)
{
	//�����BΪ����
	Posi(int) x;
	Posi(int) p;
	if(num1==1 && num3==1)//������
	{
		if(t1>0||t3>0)//AC�ѳ���
		{
			if(t1>=t3)//A��
			{
				t2=list.Search(t1);//Search�����Ҵ���t1�ĵ�һ��Ԫ��
				if(t2!=NULL)
				{
				deletePoker(t2,list);
				stack.insertAsLast(t2);
				cout<<pai[t2]<<endl;
				}
				else //����û�и����
				{
					if(minDuizi(list)!=NULL)//����
					{	
						p=minDuizi(list);
						t2=list.Data(p);
						x=p->succ;
						for(int m=0;m<2;m++){//ɾ��t2 �� t2�ĺ�̽ڵ�
							deletePoker(t2,list);
							stack.insertAsLast(t2);
							cout<<pai[t2]<<" ";
							t2=list.Data(x);
						}
					num2=2;//����num2
					cout<<endl;
					}
					else if(minZhadan(list)!=NULL)//û�ж��ӾͿ�ը��
					{	
							p=minZhadan(list);
							t2=list.Data(p);
							x=p->succ;
							for(int m=0;m<4;m++){
								deletePoker(t2,list);
								stack.insertAsLast(t2);
								cout<<pai[t2]<<" ";
								t2=list.Data(x);
								x=x->succ;
							}
						num2=4;//����num2
					}
					else if(DaXiaoWang(list))//û��ը���ٿ�������ը
					{
						p=list.last();//����У��б����һλ�Ǵ���
						x=p->pred;
						t2=list.Data(x);
						deletePoker(t2,list);
						stack.insertAsLast(t2);
						cout<<pai[t2]<<" ";
						t2=list.Data(p);
						deletePoker(t2,list);
						stack.insertAsLast(t2);
						cout<<pai[t2]<<" ";
						cout<<endl;
						num2=2;
					}
					else
					{
						cout<<"����"<<endl;
					t2=-1;
					num2=1;
					}
				}
			}
			else //C������ͬ��
			{
				t2=list.Search(t3);
				if(t2!=NULL)
				{
				deletePoker(t2,list);
				stack.insertAsLast(t2);
				cout<<pai[t2]<<endl;
				}
				else //����û�и����
				{
					if(minDuizi(list)!=NULL)//����
					{	
						p=minDuizi(list);
						t2=list.Data(p);
						x=p->succ;
						for(int m=0;m<2;m++){
					deletePoker(t2,list);
					stack.insertAsLast(t2);
					cout<<pai[t2]<<" ";
					t2=list.Data(x);
					}
					num2=2;
					cout<<endl;
					}
					else if(minZhadan(list)!=NULL)//ը��
						{	
							p=minZhadan(list);
							t2=list.Data(p);
							x=p->succ;
							for(int m=0;m<4;m++){
					deletePoker(t2,list);
					stack.insertAsLast(t2);
					cout<<pai[t2]<<" ";
					t2=list.Data(x);
					x=x->succ;
					}
					num2=4;
					cout<<endl;
					}
					else if(DaXiaoWang(list))
					{
						p=list.last();
						x=p->pred;
						t2=list.Data(x);
						deletePoker(t2,list);
						stack.insertAsLast(t2);
						cout<<pai[t2]<<" ";
						t2=list.Data(p);
						deletePoker(t2,list);
						stack.insertAsLast(t2);
						cout<<pai[t2]<<" ";
						cout<<endl;
						num2=2;
					}
					else
					{
						cout<<"����"<<endl;
					t2=-1;
					num2=1;
					}
				}
			}

		}
		else//��������
		{
			Posi(int) temp2=list.first();
			t2=list.Data(temp2);
			list.remove(temp2);
			stack.insertAsLast(t2);
			cout<<pai[t2]<<endl;
			num2=1;
		}
	}
	else if(num1==2||num3==2)//AC����һ���˳�����
	{
		if(num1==2 &&num3==1)
			Duizi(t2,t1,num2,list);//B���ƣ��ο�A
		else if(num1==1 && num3==2)
			Duizi(t2,t3,num2,list);//B���ƣ��ο�C
		
		else if(num1==2&&num3==2)//B���ƣ��ο���С�Ķ���
		{
			if(t1!=52&&t3!=52){//���Ĳ�����ը
				if(t1>t3)
				Duizi(t2,t1,num2,list);
				else 
				Duizi(t2,t3,num2,list);
			}
			else
			{
				cout<<"����"<<endl;
				num2=1;
				t2=-1;
			}

		}
		
	}
	else if(num1==4||num3==4)//AC��һ���˳�ը��������ͬ������
	{
		
		if(num1==4&&num3==1)
			Zhadan(t2,t1,num2,list);
		else if(num1==1&&num3==4)
			Zhadan(t2,t3,num2,list);
		else if(num1==4&&num3==4)
		{
			if(t1!=52&&t3!=52){
				if(t1>=t3)
				Zhadan(t2,t1,num2,list);
				else 
				Zhadan(t2,t3,num2,list);
			}
			else
			{
				cout<<"����"<<endl;
				num2=1;
				t2=-1;
			}
		}
		
	}
	
	return t2;
}

//A��������
bool unlimitA(int &n,int num2,int num3,int &t1,int t2,int t3,List<int>&list)
{
	string storePai[16]={};
	
	int k=0,j=0,c=0;
	
	int m=n;//��������

	cout<<"Ҫ�����ƣ�"<<endl;
		while(m>0)//������������ѭ������
		{
			cin>>pok;
			storePai[k++]=pok;//��ʱ����������
			m--;
		}

	int i;
		for (i = 0; i < 54; i++) {//����±�
			if (pai[i] == storePai[0])
				break;
		}
		if(i!=54)//���ƺϷ�
			t1=i;//����±�
		for (i = 0; i < 54; i++) {
			if (pai[i] == storePai[1])
				break;
		}
		if(i!=54)
			c=i;

	//��������
	if(A.find(t1)!=NULL && A.find(c)!=NULL){//���붼�Ϸ����ٽ��в���
		if(!isDuizi(t1,A) && !DaXiaoWang(A) && n==2){
			cout<<"���Ƕ��ӣ�"<<endl;
			return false;
		}

		if(n==4 && !isZhadan(t1,A)){
			cout<<"����ը����"<<endl;
			return false;
		}
		//�Ϸ����ж�

		else{
			if(DaXiaoWang(A))
				return true;
			else{
		while(storePai[j]!="")
		{
			for(i=0;i<54;i++)
				if(pai[i]==storePai[j])
					break;
			if(i!=54)
				t1=i;

			deletePoker(i,A);
			stack.insertAsLast(t1);
			j++;
		}
		return true;
			}
		}
	}
	else
		{
			cout<<"�Ʋ����ڣ�"<<endl;
			return false;
}
	
}

//B��������
bool unlimitB(int& num1, int n, int num3, int& t1, int t2, int t3, List<int>& list)
{
	string storePai[16] = {};

	int k = 0, j = 0, c = 0;

	int m = n;//��������

	cout << "Ҫ�����ƣ�" << endl;
	while (m > 0)//������������ѭ������
	{
		cin >> pok;
		storePai[k++] = pok;//��ʱ����������
		m--;
	}

	int i;
	for (i = 0; i < 54; i++) {//����±�
		if (pai[i] == storePai[0])
			break;
	}
	if (i != 54)//���ƺϷ�
		t2 = i;//����±�
	for (i = 0; i < 54; i++) {
		if (pai[i] == storePai[1])
			break;
	}
	if (i != 54)
		c = i;

	//��������
	if (B.find(t2) != NULL && B.find(c) != NULL) {//���붼�Ϸ����ٽ��в���
		if (!isDuizi(t2, B) && !DaXiaoWang(B) && n == 2) {
			cout << "���Ƕ��ӣ�" << endl;
			return false;
		}

		if (n == 4 && !isZhadan(t2, B)) {
			cout << "����ը����" << endl;
			return false;
		}
		//�Ϸ����ж�

		else {
			if (DaXiaoWang(B))
				return true;
			else {
				while (storePai[j] != "")
				{
					for (i = 0; i < 54; i++)
						if (pai[i] == storePai[j])
							break;
					if (i != 54)
						t2 = i;

					deletePoker(i, B);
					stack.insertAsLast(t2);
					j++;
				}
				return true;
			}
		}
	}
	else
	{
		cout << "�Ʋ����ڣ�" << endl;
		return false;
	}

}

//C��������
bool unlimitC(int& num1, int num2, int n, int& t1, int t2, int t3, List<int>& list)
{
	string storePai[16] = {};

	int k = 0, j = 0, c = 0;

	int m = n;//��������

	cout << "Ҫ�����ƣ�" << endl;
	while (m > 0)//������������ѭ������
	{
		cin >> pok;
		storePai[k++] = pok;//��ʱ����������
		m--;
	}

	int i;
	for (i = 0; i < 54; i++) {//����±�
		if (pai[i] == storePai[0])
			break;
	}
	if (i != 54)//���ƺϷ�
		t3 = i;//����±�
	for (i = 0; i < 54; i++) {
		if (pai[i] == storePai[1])
			break;
	}
	if (i != 54)
		c = i;

	//��������
	if (C.find(t3) != NULL && C.find(c) != NULL) {//���붼�Ϸ����ٽ��в���
		if (!isDuizi(t3, C) && !DaXiaoWang(C) && n == 2) {
			cout << "���Ƕ��ӣ�" << endl;
			return false;
		}

		if (n == 4 && !isZhadan(t3, C)) {
			cout << "����ը����" << endl;
			return false;
		}
		//�Ϸ����ж�

		else {
			if (DaXiaoWang(C))
				return true;
			else {
				while (storePai[j] != "")
				{
					for (i = 0; i < 54; i++)
						if (pai[i] == storePai[j])
							break;
					if (i != 54)
						t3 = i;

					deletePoker(i, C);
					stack.insertAsLast(t3);
					j++;
				}
				return true;
			}
		}
	}
	else
	{
		cout << "�Ʋ����ڣ�" << endl;
		return false;
	}

}


//�� < ÷ < �� < ��

int main()
{
	
	int pok_num1=1;
	int pok_num2=1;
	int pok_num3=1;//��������
	 List<int> Pok=poker();
	char ch;

		cout<<"��ǰ����Ϊ��"<<endl;
		Pok.show(pai);
		cout<<endl;
	
	
	//����
	Posi(int) p=Pok.first();
	
		while(p->succ)
		{
			A.insertAsLast(p->data);
			p=p->succ;
			B.insertAsLast(p->data);
			p=p->succ;
			C.insertAsLast(p->data);
			p=p->succ;
		}
	ch='N';	
	//չʾ
	cout<<"����ǰ���A����Ϊ��"<<endl;
	A.show(pai);
	cout<<"����ǰ���B����Ϊ��"<<endl;
	B.show(pai);
	cout<<"����ǰ���C����Ϊ��"<<endl;
	C.show(pai);
	cout<<endl;
	//����
	A.insertSort(A.first(),A.size());
	B.insertSort(B.first(),B.size());
	C.insertSort(C.first(),C.size());
	//չʾ
	cout<<"��������A����Ϊ��"<<endl;
	A.show(pai);
	cout<<"��������B����Ϊ��"<<endl;
	B.show(pai);
	cout<<"��������C����Ϊ��"<<endl;
	C.show(pai);
	cout<<endl;
	//
	int t1=-1;
	int t2=-1;
	int t3=-1;//����Ƶ��±�
	int place=1;
	int p1=0,p2=0,p3=0;
	char choose_player = 'N';
	while(!((A.empty()&&B.empty())||(C.empty()&&B.empty())||(A.empty()&&C.empty()))){//�����������б�ǿ�
		int i;
		flag_again:
		cout << "��ѡ��������(A/B/C)" << endl;
		cin >> choose_player;
		if (choose_player == 'A') {
			if (!A.empty()) {//A�б�û�����ʱִ��
				do {//���źϷ�
					cout << "���A���ƣ�" << endl;
					cout << "����������" << endl;
					cin >> pok_num1;
					if (pok_num1 == 1) {
						cout << "Ҫ�����ƣ�" << endl;
						cin >> pok;
						for (i = 0; i < 54; i++) {
							if (pai[i] == pok)
								break;
						}
						if (i != 54) {
							t1 = i;
						}
						if (pok == "��") {
							t1 = -1;
							pok_num1 = 1;
						}
					}
				} while (!reasonable(t1, pok_num1, choose_player));//�жϺϷ���
				if (pok_num1 == 1)
				{
					if (pok != "��")//������
					{
						deletePoker(i, A);
						stack.insertAsLast(t1);
					}
					else
					{
						t1 = -1;
						pok_num1 = 1;
					}
				}
				else if (pok_num1 == 2)//A������
					while (!unlimitA(pok_num1, pok_num2, pok_num3, t1, t2, t3, A));
				else if (pok_num1 == 4)//A��ը��
					while (!unlimitA(pok_num1, pok_num2, pok_num3, t1, t2, t3, A));

				if (A.empty())//���A���
				{
					p1 = A.Place(place);
					place++;
					t1 = -1;
					pok_num1 = 1;
				}
			}
		}
		else if (choose_player == 'B') {
			if (!B.empty()) {
				do {//���źϷ�
					cout << "���B���ƣ�" << endl;
					cout << "����������" << endl;
					cin >> pok_num2;
					if (pok_num2 == 1) {
						cout << "Ҫ�����ƣ�" << endl;
						cin >> pok;
						for (i = 0; i < 54; i++) {
							if (pai[i] == pok)
								break;
						}
						if (i != 54) {
							t2 = i;
						}
						if (pok == "��") {
							t2 = -1;
							pok_num2 = 1;
						}
					}
				} while (!reasonable(t2,pok_num2, choose_player));//�жϺϷ���
				if (pok_num2 == 1)
				{
					if (pok != "��")//������
					{
						deletePoker(i, B);
						stack.insertAsLast(t2);
					}
					else
					{
						t2= -1;
						pok_num2 = 1;
					}
				}
				else if (pok_num2 == 2)//B������
					while (!unlimitB(pok_num1, pok_num2, pok_num3, t1, t2, t3, B));
				else if (pok_num2 == 4)//B��ը��
					while (!unlimitB(pok_num1, pok_num2, pok_num3, t1, t2, t3, B));

				if (B.empty())//���A���
				{
					p2 = B.Place(place);
					place++;
					t2 = -1;
					pok_num2 = 1;
				}
			}
		}
		else if (choose_player == 'C') {
			if (!C.empty()) {
				do {//���źϷ�
					cout << "���C���ƣ�" << endl;
					cout << "����������" << endl;
					cin >> pok_num3;
					if (pok_num3 == 1) {
						cout << "Ҫ�����ƣ�" << endl;
						cin >> pok;
						for (i = 0; i < 54; i++) {
							if (pai[i] == pok)
								break;
						}
						if (i != 54) {
							t3 = i;
						}
						if (pok == "��") {
							t3 = -1;
							pok_num3 = 1;
						}
					}
				} while (!reasonable(t3, pok_num3 ,choose_player));//�жϺϷ���
				if (pok_num3 == 1)
				{
					if (pok != "��")//������
					{
						deletePoker(i, C);
						stack.insertAsLast(t3);
					}
					else
					{
						t3 = -1;
						pok_num3 = 1;
					}
				}
				else if (pok_num3 == 2)//A������
					while (!unlimitC(pok_num1, pok_num2, pok_num3, t1, t2, t3, C));
				else if (pok_num3 == 4)//A��ը��
					while (!unlimitC(pok_num1, pok_num2, pok_num3, t1, t2, t3, C));

				
				if (C.empty())
				{
					p3 = C.Place(place);
					place++;
					t3 = -1;
					pok_num3 = 1;
				}
			}
		}
		else { cout << "�����������������" << endl; goto flag_again; }
		cout<<"���A����Ϊ��"<<endl;
		A.show(pai);
		cout<<"���B����Ϊ��"<<endl;
		B.show(pai);
		cout<<"���C����Ϊ��"<<endl;
		C.show(pai);
		cout<<"�ƶѵ���Ϊ��"<<endl;
		stack.show(pai);
	
	}
	
	
	cout<<"��������Ϊ��"<<endl;
	if(p1==0){
		p1=A.Place(3);
	cout<<"���A:"<<p1<<endl;
	cout<<"���B:"<<p2<<endl;
	cout<<"���C:"<<p3<<endl;
	}
	else if(p2==0){
		p2=B.Place(3);
	cout<<"���A:"<<p1<<endl;
	cout<<"���B:"<<p2<<endl;
	cout<<"���C:"<<p3<<endl;
	}
	else if(p3==0){
		p3=C.Place(3);
	cout<<"���A:"<<p1<<endl;
	cout<<"���B:"<<p2<<endl;
	cout<<"���C:"<<p3<<endl;
	}
	else
	{
	cout<<"���A:"<<p1<<endl;
	cout<<"���B:"<<p2<<endl;
	cout<<"���C:"<<p3<<endl;
	}
	return 0;
	}