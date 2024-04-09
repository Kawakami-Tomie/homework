#ifndef __List_H__
#define __List_H__
#include"ListNode.h"


//�б����
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
//��ʼ��
template<typename T>
void List<T>::Init()
{
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->succ = trailer; header->pred = NULL;
	trailer->pred = header; trailer->succ = NULL;
	_size = 0;
}


//�׽ڵ����
template<typename T>
Posi(T) List<T>::insertAsFist(T const& e)
{
	_size++;
	return header->insertAsSucc(e);
}
//ĩ�ڵ����
template<typename T>
Posi(T) List<T>::insertAsLast(T const& e)
{
	_size++;
	return trailer->insertAsPred(e);
}
//�����
template<typename T>
Posi(T) List<T>::insertA(Posi(T) p, T const& e)
{
	_size++;
	return p->insertAsSucc(e);
}

//ǰ����
template<typename T>
Posi(T) List<T>::insertB(Posi(T) p, T const& e)
{
	_size++;
	return p->insertAsPred(e);
}
//չʾ
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
//����
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
//ɾ��
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
//���Ҳ�����e���һ��Ԫ��
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

//��������
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
//���Ҵ���e��һ��Ԫ��
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
