
#include <iostream>
#include <string>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef int Rank;
#define ListNodePosi(T)ListNode<T>*
template<typename T>
struct ListNode {
	T card;
	ListNodePosi(T) pred;
	ListNodePosi(T) succ;
	ListNode() {}
	ListNode(T e, ListNode<T>* p = NULL, ListNode<T>* s = NULL) :card(e), pred(p), succ(s) {}
	ListNodePosi(T) insertAsPred(T const& e);
	ListNodePosi(T) insertAsSucc(T const& e);
};
template<typename T>class List {
private:
	int _size;
	ListNodePosi(T) header;
	ListNodePosi(T) trailer;
public:
	List() { init(); }
	void init();
	List(List<T> const& L);
	List(ListNodePosi(T) p, int n);
	void copyFrom(ListNodePosi(T) p, int n);
	~List();
	Rank size() { return _size; }
	T& operator[](int r)const;
	ListNodePosi(T) first()const { return header->succ; }
	ListNodePosi(T) last()const { return trailer->pred; }
	ListNodePosi(T) find(T const& e)const { return find(e, _size, trailer); }
	ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p)const;
	ListNodePosi(T) insertAsFirst(T const& e);
	ListNodePosi(T) insertAsLast(T const& e);
	T remove(ListNodePosi(T) p);
	int clear();
};
template<typename T>void List<T>::init() {
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->succ = trailer; header->pred = NULL;
	trailer->pred = header; trailer->succ = NULL;
	_size = 0;
}
template<typename T> T& List<T>::operator[](int r)const {
	ListNodePosi(T) p = first();
	while (0 < r--)p = p->succ;
	return p->card;
}
template<typename T>ListNodePosi(T) List<T>::insertAsFirst(T const& e) {
	_size++;
	return header->insertAsSucc(e);
}
template<typename T>ListNodePosi(T) List<T>::insertAsLast(T const& e) {
	_size++;
	return trailer->insertAsPred(e);
}
template<typename T>ListNodePosi(T) ListNode<T>::insertAsPred(T const& e) {
	ListNodePosi(T) x = new ListNode(e, pred, this);
	pred->succ = x; pred = x;
	return x;
}
template<typename T>ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e) {
	ListNodePosi(T) x = new ListNode(e, this, succ);
	succ->pred = x; pred = x;
	return x;
}

template<typename T>void List<T>::copyFrom(ListNodePosi(T) p, int n) {
	init();
	while (n--) { insertAsLast(p->card); p = p->succ; }
}
template<typename T>List<T>::List(ListNodePosi(T) p, int n) {
	copyFrom(p, n);
}
template<typename T>List<T>::List(List<T> const& L) {
	copyFrom(L.first(), L.last());
}
template<typename T>T List<T>::remove(ListNodePosi(T) p) {
	T e = p->card;
	(p->pred)->succ = p->succ;
	(p->succ)->pred = p->pred;
	delete p; _size--;
	return e;
}
template<typename T>List<T>::~List() {
	clear();
	delete header;
	delete trailer;
}
template<typename T>int List<T>::clear() {
	int oldSize = _size;
	while (0 < _size)remove(header->succ);
	return oldSize;
}
template<typename T>ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p)const {
	while (0 < n--) {
		if (e == (p = p->pred)->card)return p;
	}
	return NULL;
}



void Cardlist(List<string>& kachi) {
	string card[54] = { "黑桃A","黑桃2" ,"黑桃3" ,"黑桃4" ,"黑桃5", "黑桃6" ,"黑桃7" ,"黑桃8" ,"黑桃9","黑桃10","黑桃J","黑桃Q","黑桃K",
			"红桃A","红桃2" ,"红桃3" ,"红桃4" ,"红桃5", "红桃6" ,"红桃7" ,"红桃8" ,"红桃9","红桃10","红桃J","红桃Q","红桃K",
				"方块A","方块2" ,"方块3" ,"方块4" ,"方块5", "方块6" ,"方块7" ,"方块8" ,"方块9","方块10","方块J","方块M","方块K",
			"梅花A","梅花2" ,"梅花3" ,"梅花4" ,"梅花5", "梅花6" ,"梅花7" ,"梅花8" ,"梅花9","梅花10","梅花J","梅花M","梅花K" ,"大王","小王" };
	int Number[54];
	srand(time(nullptr));
	for (int i = 0; i < 54; i++)
		Number[i] = i;
	for (int i = 54; i > 0; i--)
		swap(Number[i - 1], Number[rand() % i]);
	for (int i = 0; i < 54; i++) {
		kachi.insertAsLast(card[Number[i]]);
	}

}
int main() {
	ListNodePosi(string) P = NULL;
	List<string>Play1;
	List<string>Play2;
	List<string>Play3;
	List<string>List;
	Cardlist(List);
	cout << "洗牌结束" << endl;
	for (int i = 0; i < List.size(); i++) {
		cout << List[i] << " ";
	}
	cout << endl;

	cout << "开始发牌" << endl;




	while (0 < List.size()) {
		P = List.last(); Play1.insertAsLast(P->card); List.remove(P);
		P = List.last(); Play2.insertAsLast(P->card); List.remove(P);
		P = List.last(); Play3.insertAsLast(P->card); List.remove(P);
	}

	cout << "玩家1的牌为：";
	for (int i = 0; i < Play1.size(); i++) {
		cout << Play1[i] << " ";
	}
	cout << endl;
	cout << endl;
	cout << "玩家2的牌为：";
	for (int i = 0; i < Play2.size(); i++) {
		cout << Play2[i] << " ";
	}
	cout << endl;
	cout << endl;
	cout << "玩家3的牌为：";
	for (int i = 0; i < Play3.size(); i++) {
		cout << Play3[i] << " ";
	}
	cout << endl;
	cout << endl;
	int player;
	cout << "选择玩家：";
	cin >> player;
	char retry;
	do {
		switch (player) {

		case 1: {
			ListNodePosi(string)p = NULL;

			int number1;
		flag1:
			cout << "选择出牌张数：";
			cin >> number1;

			if (number1 == 1) {
				string card1;
			flag11:
				cout << "选择出牌：";
				cin >> card1;
				Play1.find(card1);
				p = Play1.find(card1);
				if (p == NULL) {
					cout << "手中无此牌！" << endl;
					goto flag11;
				}
				p->card = card1;
				List.insertAsLast(p->card);

				cout << "玩家1的牌为：";
				for (int i = 0; i < Play1.size(); i++) {
					cout << Play1[i] << " ";
				}
				cout << endl;
				cout << "卡池中的卡牌" << endl;
				for (int i = 0; i < List.size(); i++) {
					cout << List[i] << " ";
				}
				cout << endl;
			}
			else if (number1 == 2) {
				string card11, card12;
				ListNodePosi(string)cardfind11;
				ListNodePosi(string)cardfind12;
			flag12:
				cout << "选择出牌：";
				cin >> card11 >> card12;
				Play1.find(card11);
				cardfind11 = Play1.find(card11);
				if (cardfind11 == NULL) {
					cout << "手中无此牌！请重新选牌" << endl;
					goto flag12;
				}
				Play1.find(card12);
				cardfind12 = Play1.find(card12);
				if (cardfind12 == NULL) {
					cout << "手中无此牌！请重新选牌" << endl;
					goto flag12;
				}
				cardfind11->card = card11;
				cardfind12->card = card12;
				List.insertAsLast(cardfind11->card);
				List.insertAsLast(cardfind12->card);
				Play1.remove(cardfind11);
				Play1.remove(cardfind12);
				cout << "玩家1的牌为：";
				for (int i = 0; i < Play1.size(); i++) {
					cout << Play1[i] << " ";
				}
				cout << endl;
				cout << "卡池中的卡牌" << endl;
				for (int i = 0; i < List.size(); i++) {
					cout << List[i] << " ";
				}
				cout << endl;

			}
			else if (number1 == 4) {
				string card11, card12, card13, card14;
				ListNodePosi(string)cardfind11;
				ListNodePosi(string)cardfind12;
				ListNodePosi(string)cardfind13;
				ListNodePosi(string)cardfind14;
			flag14:
				cout << "选择出牌：";
				cin >> card11 >> card12 >> card13 >> card14;
				Play1.find(card11);
				cardfind11 = Play1.find(card11);
				if (p == NULL) {
					cout << "手中无此牌！请重新选牌" << endl;
					goto flag14;
				}
				Play1.find(card12);
				cardfind12 = Play1.find(card12);
				if (p == NULL) {
					cout << "手中无此牌！请重新选牌" << endl;
					goto flag14;
				}
				Play1.find(card13);
				cardfind13 = Play1.find(card13);
				if (p == NULL) {
					cout << "手中无此牌！请重新选牌" << endl;
					goto flag14;
				}
				Play1.find(card14);
				cardfind14 = Play1.find(card14);
				if (p == NULL) {
					cout << "手中无此牌！请重新选牌" << endl;
					goto flag14;
				}
				cardfind11->card = card11;
				cardfind12->card = card12;
				cardfind13->card = card13;
				cardfind14->card = card14;
				List.insertAsLast(cardfind11->card);
				List.insertAsLast(cardfind12->card);
				List.insertAsLast(cardfind13->card);
				List.insertAsLast(cardfind14->card);
				Play1.remove(cardfind11);
				Play1.remove(cardfind12);
				Play1.remove(cardfind13);
				Play1.remove(cardfind14);
				cout << "玩家1的牌为：";
				for (int i = 0; i < Play1.size(); i++) {
					cout << Play1[i] << " ";
				}
				cout << endl;
				cout << "卡池中的卡牌" << endl;
				for (int i = 0; i < List.size(); i++) {
					cout << List[i] << " ";
				}
				cout << endl;

			}
			else {
				cout << "出牌张数不合法" << endl;
				goto flag1;
			}


		}break;
		case 2: {
			ListNodePosi(string)p = NULL;

			int number1;
		flag2:
			cout << "选择出牌张数：";
			cin >> number1;
			if (number1 == 1) {
				string card1;
			flag21:
				cout << "选择出牌：";
				cin >> card1;
				Play2.find(card1);
				p = Play2.find(card1);
				if (p == NULL) {
					cout << "手中无此牌！" << endl;
					goto flag21;
				}
				p->card = card1;
				List.insertAsLast(p->card);

				cout << "玩家2的牌为：";
				for (int i = 0; i < Play2.size(); i++) {
					cout << Play1[i] << " ";
				}
				cout << endl;
				cout << "卡池中的卡牌" << endl;
				for (int i = 0; i < List.size(); i++) {
					cout << List[i] << " ";
				}
				cout << endl;
			}
			else if (number1 == 2) {
				string card11, card12;
				ListNodePosi(string)cardfind11;
				ListNodePosi(string)cardfind12;
			flag22:
				cout << "选择出牌：";
				cin >> card11 >> card12;
				Play2.find(card11);
				cardfind11 = Play2.find(card11);
				if (p == NULL) {
					cout << "手中无此牌！请重新选牌" << endl;
					goto flag22;
				}
				Play2.find(card12);
				cardfind12 = Play2.find(card12);
				if (p == NULL) {
					cout << "手中无此牌！请重新选牌" << endl;
					goto flag22;
				}
				cardfind11->card = card11;
				cardfind12->card = card12;
				List.insertAsLast(cardfind11->card);
				List.insertAsLast(cardfind12->card);
				Play2.remove(cardfind11);
				Play2.remove(cardfind12);
				cout << "玩家2的牌为：";
				for (int i = 0; i < Play2.size(); i++) {
					cout << Play2[i] << " ";
				}
				cout << endl;
				cout << "卡池中的卡牌" << endl;
				for (int i = 0; i < List.size(); i++) {
					cout << List[i] << " ";
				}
				cout << endl;

			}
			else if (number1 == 4) {
				string card11, card12, card13, card14;
				ListNodePosi(string)cardfind11;
				ListNodePosi(string)cardfind12;
				ListNodePosi(string)cardfind13;
				ListNodePosi(string)cardfind14;
			flag24:
				cout << "选择出牌：";
				cin >> card11 >> card12 >> card13 >> card14;
				Play2.find(card11);
				cardfind11 = Play2.find(card11);
				if (p == NULL) {
					cout << "手中无此牌！请重新选牌" << endl;
					goto flag24;
				}
				Play2.find(card12);
				cardfind12 = Play2.find(card12);
				if (p == NULL) {
					cout << "手中无此牌！请重新选牌" << endl;
					goto flag24;
				}
				Play2.find(card13);
				cardfind13 = Play2.find(card13);
				if (p == NULL) {
					cout << "手中无此牌！请重新选牌" << endl;
					goto flag24;
				}
				Play2.find(card14);
				cardfind14 = Play2.find(card14);
				if (p == NULL) {
					cout << "手中无此牌！请重新选牌" << endl;
					goto flag24;
				}
				cardfind11->card = card11;
				cardfind12->card = card12;
				cardfind13->card = card13;
				cardfind14->card = card14;
				List.insertAsLast(cardfind11->card);
				List.insertAsLast(cardfind12->card);
				List.insertAsLast(cardfind13->card);
				List.insertAsLast(cardfind14->card);
				Play2.remove(cardfind11);
				Play2.remove(cardfind12);
				Play2.remove(cardfind13);
				Play2.remove(cardfind14);
				cout << "玩家2的牌为：";
				for (int i = 0; i < Play1.size(); i++) {
					cout << Play2[i] << " ";
				}
				cout << endl;
				cout << "卡池中的卡牌" << endl;
				for (int i = 0; i < List.size(); i++) {
					cout << List[i] << " ";
				}
				cout << endl;

			}
			else {
				cout << "出牌张数不合法" << endl;
				goto flag2;
			}

		}break;
		case 3: {
			ListNodePosi(string)p = NULL;

			int number1;
		flag3:
			cout << "选择出牌张数：";
			cin >> number1;
			if (number1 == 1) {
				string card1;
			flag31:
				cout << "选择出牌：";
				cin >> card1;
				Play3.find(card1);
				p = Play3.find(card1);
				if (p == NULL) {
					cout << "手中无此牌！" << endl;
					goto flag31;
				}
				p->card = card1;
				List.insertAsLast(p->card);

				cout << "玩家3的牌为：";
				for (int i = 0; i < Play3.size(); i++) {
					cout << Play3[i] << " ";
				}
				cout << endl;
				cout << "卡池中的卡牌" << endl;
				for (int i = 0; i < List.size(); i++) {
					cout << List[i] << " ";
				}
				cout << endl;
			}
			else if (number1 == 2) {
				string card11, card12;
				ListNodePosi(string)cardfind11;
				ListNodePosi(string)cardfind12;
			flag32:
				cout << "选择出牌：";
				cin >> card11 >> card12;
				Play3.find(card11);
				cardfind11 = Play3.find(card11);
				if (p == NULL) {
					cout << "手中无此牌！请重新选牌" << endl;
					goto flag32;
				}
				Play3.find(card12);
				cardfind12 = Play3.find(card12);
				if (p == NULL) {
					cout << "手中无此牌！请重新选牌" << endl;
					goto flag32;
				}
				cardfind11->card = card11;
				cardfind12->card = card12;
				List.insertAsLast(cardfind11->card);
				List.insertAsLast(cardfind12->card);
				Play3.remove(cardfind11);
				Play3.remove(cardfind12);
				cout << "玩家3的牌为：";
				for (int i = 0; i < Play3.size(); i++) {
					cout << Play3[i] << " ";
				}
				cout << endl;
				cout << "卡池中的卡牌" << endl;
				for (int i = 0; i < List.size(); i++) {
					cout << List[i] << " ";
				}
				cout << endl;

			}
			else if (number1 == 4) {
				string card11, card12, card13, card14;
				ListNodePosi(string)cardfind11;
				ListNodePosi(string)cardfind12;
				ListNodePosi(string)cardfind13;
				ListNodePosi(string)cardfind14;
			flag34:
				cout << "选择出牌：";
				cin >> card11 >> card12 >> card13 >> card14;
				Play3.find(card11);
				cardfind11 = Play3.find(card11);
				if (p == NULL) {
					cout << "手中无此牌！请重新选牌" << endl;
					goto flag34;
				}
				Play3.find(card12);
				cardfind12 = Play3.find(card12);
				if (p == NULL) {
					cout << "手中无此牌！请重新选牌" << endl;
					goto flag34;
				}
				Play3.find(card13);
				cardfind13 = Play3.find(card13);
				if (p == NULL) {
					cout << "手中无此牌！请重新选牌" << endl;
					goto flag34;
				}
				Play3.find(card14);
				cardfind14 = Play3.find(card14);
				if (p == NULL) {
					cout << "手中无此牌！请重新选牌" << endl;
					goto flag34;
				}
				cardfind11->card = card11;
				cardfind12->card = card12;
				cardfind13->card = card13;
				cardfind14->card = card14;
				List.insertAsLast(cardfind11->card);
				List.insertAsLast(cardfind12->card);
				List.insertAsLast(cardfind13->card);
				List.insertAsLast(cardfind14->card);
				Play3.remove(cardfind11);
				Play3.remove(cardfind12);
				Play3.remove(cardfind13);
				Play3.remove(cardfind14);
				cout << "玩家3的牌为：";
				for (int i = 0; i < Play3.size(); i++) {
					cout << Play3[i] << " ";
				}
				cout << endl;
				cout << "卡池中的卡牌" << endl;
				for (int i = 0; i < List.size(); i++) {
					cout << List[i] << " ";
				}
				cout << endl;
			}
			else {
				cout << "出牌张数不合法" << endl;
				goto flag3;
			}


		}break;
		default:break;

		}

		cout << "继续输Y，否则退出:";
		cin >> retry;
		if (retry != 'Y')break;
	} while (retry == 'Y');

	return 0;
}