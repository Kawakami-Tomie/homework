#ifndef __List_H__
#define __List_H__
#include"ListNode.h"


//列表，玩家
template<typename T>
class List {
private:
	int _size;
	Posi(T) header;
	Posi(T) trailer;

public:
	List() { Init(); }
	~List() {};
	void Init();
	Rank size() { return _size; }
	bool empty() { return _size <= 0; }
	T Data(Posi(T) p) { return p->data; }
	Posi(T) first() const { return header->succ; }
	Posi(T) last() const { return trailer->pred; }
	Posi(T) insertA(Posi(T) p, T const& e);
	Posi(T) insertB(Posi(T) p, T const& e);
	Posi(T) insertAsFist(T const& e);
	Posi(T) insertAsLast(T const& e);
	void show(string* arry);
	T remove(Posi(T) p);
	Posi(T) find(T const& e);
	Posi(T) search(T const& e, int n, Posi(T) p);
	void insertSort(Posi(T) p, int n);
	T Search(T const& e);
	int Place(int place) { return place; }

};
//初始化
template<typename T>
void List<T>::Init()
{
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->succ = trailer; header->pred = NULL;
	trailer->pred = header; trailer->succ = NULL;
	_size = 0;
}


//首节点插入
template<typename T>
Posi(T) List<T>::insertAsFist(T const& e)
{
	_size++;
	return header->insertAsSucc(e);
}
//末节点插入
template<typename T>
Posi(T) List<T>::insertAsLast(T const& e)
{
	_size++;
	return trailer->insertAsPred(e);
}
//后插入
template<typename T>
Posi(T) List<T>::insertA(Posi(T) p, T const& e)
{
	_size++;
	return p->insertAsSucc(e);
}

//前插入
template<typename T>
Posi(T) List<T>::insertB(Posi(T) p, T const& e)
{
	_size++;
	return p->insertAsPred(e);
}
//展示
template<typename T>
void List<T>::show(string* Arry)
{
	Posi(T) p = header->succ;;
	while (p->succ)
	{
		cout << Arry[p->data] << " ";
		p = p->succ;
	}
	cout << endl;
}
//查找
template<typename T>
Posi(T) List<T>::find(T const& e)
{
	Posi(T) p = header->succ;
	while (p->succ)
	{
		if (p->data == e)
			return p;
		p = p->succ;
	}
	return NULL;
}
//删除
template<typename T>
T List<T>::remove(Posi(T) p)
{
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;
}
//查找不大于e最后一个元素
template<typename T>
Posi(T) List<T>::search(T const& e, int n, Posi(T) p)
{
	while (0 <= n--)
	{
		p = p->pred;
		if (p->data <= e)
			break;
	}
	return p;
}

//插入排序
template<typename T>
void List<T>::insertSort(Posi(T) p, int n)
{
	for (int r = 0; r < n; r++)
	{
		insertA(search(p->data, r, p), p->data);
		p = p->succ;
		remove(p->pred);
	}
}
//查找大于e第一个元素
template<typename T>
T List<T>::Search(T const& e)
{
	Posi(T) p = header->succ;
	while (p->succ)
	{
		if (p->data > e)
			return p->data;
		p = p->succ;
	}
	return NULL;
}

#endif
