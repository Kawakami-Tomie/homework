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
//判断随机数不重复
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
		case 0:return "方块";
			break;
		case 1:return "梅花";
			break;
		case 2:return "红桃";
			break;
		case 3:return "黑桃";
			break;
		}
	else
		switch(id)
		{
		case 52:return "小王";
			break;
		case 53:return "大王";
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
//创建一副牌
string pai[54];
List<int> poker()
{
	
	List<int> pai_wash;
	
	string num[13]={"3","4","5","6","7","8","9","10","J","Q","K","A","2"};
	string type[4]={"方块","梅花","红桃","黑桃"};
	int k=0;

	for(int i=0;i<13;i++)
		for(int j=0;j<4;j++)
			pai[k++]=type[j]+num[i];
	pai[52]="小王";
	pai[53]="大王";
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

//删除扑克
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
//玩家A出牌正确(单张）
bool reasonable(int t1,int num1,char chooseplay)
{
	if(t1!=-1){//出得起
		if(num1==1){//A出单张
			if (chooseplay == 'A') {
				if (A.find(t1) == NULL)
				{
					cout << "牌不存在！" << endl;
					return false;
				}
				else
					return true;
			}
			else if (chooseplay == 'B') {
					if (B.find(t1) == NULL)
					{
						cout << "牌不存在！" << endl;
						return false;
					}
					else
						return true;
			}
			else if (chooseplay == 'C') {
				if (C.find(t1) == NULL)
				{
					cout << "牌不存在！" << endl;
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
//判断是对子

bool isDuizi(int const e,List<int> list)
{
	Posi(int) p;
	Posi(int) x;
	p=list.find(e);
	if(p!=NULL){//输入牌面存在
	x=p->succ;//后继节点
	int Next=list.Data(x);//投机取巧(前提是输入正确)
	
	if(SmallType(e)==SmallType(Next))//判断数字是否相同
		return true;
	else
		return false;
	}
	else
		return false;
}

//判断是炸弹
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
	
	 if (SmallType(e) == SmallType(next) == SmallType(nnext) == SmallType(nnnext))//判断数字是否相同
		 return true;
	 else
		 return false;
	//if(pai[e][3]==pai[next][3]==pai[nnext][3]==pai[nnnext][3])
	//	return true;
	//else
	//	return false;
	
	
}
//找最小对子
Posi(int) minDuizi(List<int> &list)
{
	Posi(int) p=list.first();
	if(list.size()>=2){//只要列表存在两张牌及以上
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
//找最小炸弹
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
//找大王小王，看玩家列表是否存在王炸
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
//出对子
void Duizi(int &my,int another,int &nummy,List<int> &list)
{
		Posi(int) p;
		Posi(int) x;
		my=list.Search(another);//查找比another大的第一张牌
			if(list.size()>1){
				Posi(int) t=list.find(my);
				while(SmallType(my)==SmallType(another)&&t->succ)//找到的牌数值相同的话需要后移
				{
					t=t->succ;
					my=list.Data(t);
				}
			}
			p=list.find(my);
			if(p!=NULL)//找对子
			{	
				x=p->succ;
				while(!isDuizi(my,list)&&x->succ!=NULL)
				{
					my=list.Data(x);
					x=x->succ;//如果不满足对子条件，节点后移									
				}
			
			if(isDuizi(my,list)&&(SmallType(my)!=SmallType(another)))//满足对子条件，且数值不相同
			{
				for(int m=0;m<2;m++){
					deletePoker(my,list);
					stack.insertAsLast(my);
					cout<<pai[my]<<" ";
					if(m==0)my=list.Data(x);
				}
			 cout<<endl;

			 nummy=2;//更新num2

			}
			else if(minZhadan(list)!=NULL)//如果出不了对子，看炸弹
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
				nummy=4;//更新num2
				}
			else if(DaXiaoWang(list))//2对子和4炸弹条件都不成立，看王炸
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
					nummy=2;//更新num2
				}
			else
				{
				cout<<"过！"<<endl;
				my=-1;
				nummy=1;
				}
			}
			else
				{
				cout<<"过！"<<endl;
				my=-1;
				nummy=1;
			}
}
//出炸弹
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
				cout<<"过！"<<endl;
				my=-1;
				nummy=1;
			}
			}
			else
			{
				cout<<"过！"<<endl;
				my=-1;
				nummy=1;
			}
		}
		else
			{
				cout<<"过！"<<endl;
				my=-1;
				nummy=1;
			}
}
//出牌(同时更新下标值
int chuPai(int &t1,int &t2,int &t3,int &num1,int &num2,int &num3,List<int> &list)
{
	//以玩家B为例子
	Posi(int) x;
	Posi(int) p;
	if(num1==1 && num3==1)//出单牌
	{
		if(t1>0||t3>0)//AC已出牌
		{
			if(t1>=t3)//A大
			{
				t2=list.Search(t1);//Search：查找大于t1的第一个元素
				if(t2!=NULL)
				{
				deletePoker(t2,list);
				stack.insertAsLast(t2);
				cout<<pai[t2]<<endl;
				}
				else //单张没有更大的
				{
					if(minDuizi(list)!=NULL)//对子
					{	
						p=minDuizi(list);
						t2=list.Data(p);
						x=p->succ;
						for(int m=0;m<2;m++){//删除t2 与 t2的后继节点
							deletePoker(t2,list);
							stack.insertAsLast(t2);
							cout<<pai[t2]<<" ";
							t2=list.Data(x);
						}
					num2=2;//更新num2
					cout<<endl;
					}
					else if(minZhadan(list)!=NULL)//没有对子就看炸弹
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
						num2=4;//更新num2
					}
					else if(DaXiaoWang(list))//没有炸弹再看有无王炸
					{
						p=list.last();//如果有，列表最后一位是大王
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
						cout<<"过！"<<endl;
					t2=-1;
					num2=1;
					}
				}
			}
			else //C大，内容同上
			{
				t2=list.Search(t3);
				if(t2!=NULL)
				{
				deletePoker(t2,list);
				stack.insertAsLast(t2);
				cout<<pai[t2]<<endl;
				}
				else //单张没有更大的
				{
					if(minDuizi(list)!=NULL)//对子
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
					else if(minZhadan(list)!=NULL)//炸弹
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
						cout<<"过！"<<endl;
					t2=-1;
					num2=1;
					}
				}
			}

		}
		else//其他都过
		{
			Posi(int) temp2=list.first();
			t2=list.Data(temp2);
			list.remove(temp2);
			stack.insertAsLast(t2);
			cout<<pai[t2]<<endl;
			num2=1;
		}
	}
	else if(num1==2||num3==2)//AC中有一个人出对子
	{
		if(num1==2 &&num3==1)
			Duizi(t2,t1,num2,list);//B出牌，参考A
		else if(num1==1 && num3==2)
			Duizi(t2,t3,num2,list);//B出牌，参考C
		
		else if(num1==2&&num3==2)//B出牌，参考更小的对子
		{
			if(t1!=52&&t3!=52){//出的不是王炸
				if(t1>t3)
				Duizi(t2,t1,num2,list);
				else 
				Duizi(t2,t3,num2,list);
			}
			else
			{
				cout<<"过！"<<endl;
				num2=1;
				t2=-1;
			}

		}
		
	}
	else if(num1==4||num3==4)//AC有一个人出炸弹，方法同出对子
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
				cout<<"过！"<<endl;
				num2=1;
				t2=-1;
			}
		}
		
	}
	
	return t2;
}

//A出多张牌
bool unlimitA(int &n,int num2,int num3,int &t1,int t2,int t3,List<int>&list)
{
	string storePai[16]={};
	
	int k=0,j=0,c=0;
	
	int m=n;//出牌张数

	cout<<"要出的牌："<<endl;
		while(m>0)//出牌张数决定循环次数
		{
			cin>>pok;
			storePai[k++]=pok;//临时存放输入的牌
			m--;
		}

	int i;
		for (i = 0; i < 54; i++) {//标记下标
			if (pai[i] == storePai[0])
				break;
		}
		if(i!=54)//出牌合法
			t1=i;//标记下标
		for (i = 0; i < 54; i++) {
			if (pai[i] == storePai[1])
				break;
		}
		if(i!=54)
			c=i;

	//出多张牌
	if(A.find(t1)!=NULL && A.find(c)!=NULL){//输入都合法，再进行查重
		if(!isDuizi(t1,A) && !DaXiaoWang(A) && n==2){
			cout<<"不是对子！"<<endl;
			return false;
		}

		if(n==4 && !isZhadan(t1,A)){
			cout<<"不是炸弹！"<<endl;
			return false;
		}
		//合法再判断

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
			cout<<"牌不存在！"<<endl;
			return false;
}
	
}

//B出多张牌
bool unlimitB(int& num1, int n, int num3, int& t1, int t2, int t3, List<int>& list)
{
	string storePai[16] = {};

	int k = 0, j = 0, c = 0;

	int m = n;//出牌张数

	cout << "要出的牌：" << endl;
	while (m > 0)//出牌张数决定循环次数
	{
		cin >> pok;
		storePai[k++] = pok;//临时存放输入的牌
		m--;
	}

	int i;
	for (i = 0; i < 54; i++) {//标记下标
		if (pai[i] == storePai[0])
			break;
	}
	if (i != 54)//出牌合法
		t2 = i;//标记下标
	for (i = 0; i < 54; i++) {
		if (pai[i] == storePai[1])
			break;
	}
	if (i != 54)
		c = i;

	//出多张牌
	if (B.find(t2) != NULL && B.find(c) != NULL) {//输入都合法，再进行查重
		if (!isDuizi(t2, B) && !DaXiaoWang(B) && n == 2) {
			cout << "不是对子！" << endl;
			return false;
		}

		if (n == 4 && !isZhadan(t2, B)) {
			cout << "不是炸弹！" << endl;
			return false;
		}
		//合法再判断

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
		cout << "牌不存在！" << endl;
		return false;
	}

}

//C出多张牌
bool unlimitC(int& num1, int num2, int n, int& t1, int t2, int t3, List<int>& list)
{
	string storePai[16] = {};

	int k = 0, j = 0, c = 0;

	int m = n;//出牌张数

	cout << "要出的牌：" << endl;
	while (m > 0)//出牌张数决定循环次数
	{
		cin >> pok;
		storePai[k++] = pok;//临时存放输入的牌
		m--;
	}

	int i;
	for (i = 0; i < 54; i++) {//标记下标
		if (pai[i] == storePai[0])
			break;
	}
	if (i != 54)//出牌合法
		t3 = i;//标记下标
	for (i = 0; i < 54; i++) {
		if (pai[i] == storePai[1])
			break;
	}
	if (i != 54)
		c = i;

	//出多张牌
	if (C.find(t3) != NULL && C.find(c) != NULL) {//输入都合法，再进行查重
		if (!isDuizi(t3, C) && !DaXiaoWang(C) && n == 2) {
			cout << "不是对子！" << endl;
			return false;
		}

		if (n == 4 && !isZhadan(t3, C)) {
			cout << "不是炸弹！" << endl;
			return false;
		}
		//合法再判断

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
		cout << "牌不存在！" << endl;
		return false;
	}

}


//方 < 梅 < 红 < 黑

int main()
{
	
	int pok_num1=1;
	int pok_num2=1;
	int pok_num3=1;//出牌数量
	 List<int> Pok=poker();
	char ch;

		cout<<"当前的牌为："<<endl;
		Pok.show(pai);
		cout<<endl;
	
	
	//发牌
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
	//展示
	cout<<"排序前玩家A的牌为："<<endl;
	A.show(pai);
	cout<<"排序前玩家B的牌为："<<endl;
	B.show(pai);
	cout<<"排序前玩家C的牌为："<<endl;
	C.show(pai);
	cout<<endl;
	//理牌
	A.insertSort(A.first(),A.size());
	B.insertSort(B.first(),B.size());
	C.insertSort(C.first(),C.size());
	//展示
	cout<<"排序后玩家A的牌为："<<endl;
	A.show(pai);
	cout<<"排序后玩家B的牌为："<<endl;
	B.show(pai);
	cout<<"排序后玩家C的牌为："<<endl;
	C.show(pai);
	cout<<endl;
	//
	int t1=-1;
	int t2=-1;
	int t3=-1;//存放牌的下标
	int place=1;
	int p1=0,p2=0,p3=0;
	char choose_player = 'N';
	while(!((A.empty()&&B.empty())||(C.empty()&&B.empty())||(A.empty()&&C.empty()))){//至少有两个列表非空
		int i;
		flag_again:
		cout << "请选择出牌玩家(A/B/C)" << endl;
		cin >> choose_player;
		if (choose_player == 'A') {
			if (!A.empty()) {//A列表没有清空时执行
				do {//单张合法
					cout << "玩家A出牌：" << endl;
					cout << "出牌数量：" << endl;
					cin >> pok_num1;
					if (pok_num1 == 1) {
						cout << "要出的牌：" << endl;
						cin >> pok;
						for (i = 0; i < 54; i++) {
							if (pai[i] == pok)
								break;
						}
						if (i != 54) {
							t1 = i;
						}
						if (pok == "过") {
							t1 = -1;
							pok_num1 = 1;
						}
					}
				} while (!reasonable(t1, pok_num1, choose_player));//判断合法性
				if (pok_num1 == 1)
				{
					if (pok != "过")//出得起
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
				else if (pok_num1 == 2)//A出对子
					while (!unlimitA(pok_num1, pok_num2, pok_num3, t1, t2, t3, A));
				else if (pok_num1 == 4)//A出炸弹
					while (!unlimitA(pok_num1, pok_num2, pok_num3, t1, t2, t3, A));

				if (A.empty())//最后A清空
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
				do {//单张合法
					cout << "玩家B出牌：" << endl;
					cout << "出牌数量：" << endl;
					cin >> pok_num2;
					if (pok_num2 == 1) {
						cout << "要出的牌：" << endl;
						cin >> pok;
						for (i = 0; i < 54; i++) {
							if (pai[i] == pok)
								break;
						}
						if (i != 54) {
							t2 = i;
						}
						if (pok == "过") {
							t2 = -1;
							pok_num2 = 1;
						}
					}
				} while (!reasonable(t2,pok_num2, choose_player));//判断合法性
				if (pok_num2 == 1)
				{
					if (pok != "过")//出得起
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
				else if (pok_num2 == 2)//B出对子
					while (!unlimitB(pok_num1, pok_num2, pok_num3, t1, t2, t3, B));
				else if (pok_num2 == 4)//B出炸弹
					while (!unlimitB(pok_num1, pok_num2, pok_num3, t1, t2, t3, B));

				if (B.empty())//最后A清空
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
				do {//单张合法
					cout << "玩家C出牌：" << endl;
					cout << "出牌数量：" << endl;
					cin >> pok_num3;
					if (pok_num3 == 1) {
						cout << "要出的牌：" << endl;
						cin >> pok;
						for (i = 0; i < 54; i++) {
							if (pai[i] == pok)
								break;
						}
						if (i != 54) {
							t3 = i;
						}
						if (pok == "过") {
							t3 = -1;
							pok_num3 = 1;
						}
					}
				} while (!reasonable(t3, pok_num3 ,choose_player));//判断合法性
				if (pok_num3 == 1)
				{
					if (pok != "过")//出得起
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
				else if (pok_num3 == 2)//A出对子
					while (!unlimitC(pok_num1, pok_num2, pok_num3, t1, t2, t3, C));
				else if (pok_num3 == 4)//A出炸弹
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
		else { cout << "输入错误，请重新输入" << endl; goto flag_again; }
		cout<<"玩家A的牌为："<<endl;
		A.show(pai);
		cout<<"玩家B的牌为："<<endl;
		B.show(pai);
		cout<<"玩家C的牌为："<<endl;
		C.show(pai);
		cout<<"牌堆的牌为："<<endl;
		stack.show(pai);
	
	}
	
	
	cout<<"最终名次为："<<endl;
	if(p1==0){
		p1=A.Place(3);
	cout<<"玩家A:"<<p1<<endl;
	cout<<"玩家B:"<<p2<<endl;
	cout<<"玩家C:"<<p3<<endl;
	}
	else if(p2==0){
		p2=B.Place(3);
	cout<<"玩家A:"<<p1<<endl;
	cout<<"玩家B:"<<p2<<endl;
	cout<<"玩家C:"<<p3<<endl;
	}
	else if(p3==0){
		p3=C.Place(3);
	cout<<"玩家A:"<<p1<<endl;
	cout<<"玩家B:"<<p2<<endl;
	cout<<"玩家C:"<<p3<<endl;
	}
	else
	{
	cout<<"玩家A:"<<p1<<endl;
	cout<<"玩家B:"<<p2<<endl;
	cout<<"玩家C:"<<p3<<endl;
	}
	return 0;
	}