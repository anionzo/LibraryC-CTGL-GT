#pragma once
#include<iostream>
//Mieu
template <class T>
struct  SNode
{
	T Info;
	SNode<T>* Next;

};
template <class T>
struct Stack
{
	SNode<T>* Top;
};

template<class T>
void iniStack(Stack<T>& s)
{
	s.Top = NULL;
}
template<class T>
bool isEmTy(Stack<T> s)
{
	if (s.Top == NULL)
		return false;
	return true;
}
template<class T>
SNode<T>* cretateSNode(T x)
{
	SNode<T>* p = new SNode<T>;
	if (p == NULL)
	{
		std::cout << "\nkhoong du bo nho!!!";
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
template<class T>
void pushStack(Stack<T>& s, SNode<T>* p)
{
	if (p == NULL) return;
	if (p != NULL)
		if (s.Top == NULL)
			s.Top = p;
		else
		{
			p->Next = s.Top;
			s.Top = p;
		}
}
template<class T>
SNode<T>* popStack(Stack<T>& s)
{
	SNode<T>* p = NULL;
	if (s.Top == NULL)
		s.Top= NULL;
	if (s.Top != NULL)
	{
		p = s.Top;
		s.Top = s.Top->Next;		
		p->Next = NULL;
	}
	return p;
}


//---------
