#ifndef  __ListNode_H__
#define __ListNode_H__
#include <iostream>
using namespace std;
#define Posi(T) ListNode<T>*
typedef int Rank;

//结点
template <typename T>
struct ListNode {
	T data;
	Posi(T) pred;
	Posi(T) succ;
	ListNode() {};
	ListNode(T e, Posi(T) p = NULL, Posi(T) s = NULL)
	{
		data = e; pred = p; succ = s;
	}
	Posi(T) insertAsSucc(T const& e);
	Posi(T) insertAsPred(T const& e);

};

//后插入
template <typename T>
Posi(T) ListNode<T>::insertAsSucc(T const& e)
{
	Posi(T) x = new ListNode(e, this, succ);
	succ->pred = x; succ = x;
	return x;
}

//前插入
template <typename T>
Posi(T) ListNode<T>::insertAsPred(T const& e)
{
	Posi(T) x = new ListNode(e, pred, this);
	pred->succ = x; pred = x;
	return x;
}
#endif

