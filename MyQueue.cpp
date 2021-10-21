#pragma once
//Một queue là một cấu trúc dữ liệu mà việc thêm phần tử được thực hiện
//  ở cuối (tail) và xóa phần tử được thực hiện ở đầu(head).
template<class T>
struct QNode
{
	T Info;
	QNode<T>* Next;
};
template<class T>
struct Queue
{

	QNode<T>* Head;
	QNode<T>* Tail;

};
//--------------------------------------------
template<class T>
void iNiQueue(Queue<T>& Q)
{
	Q.Head = Q.Tail = NULL;
}
template<class T>
bool isEmpty(Queue<T> Q)
{//// nếu rỗng thì xuất false, có xuất true;
	if (Q.Head == NULL)
		return false;
	return true;
}
template<class T>
QNode<T>* createQnode(T x)
{
	QNode<T>* p = new QNode<T>;
	if (p == NULL)
	{
		std::cout << "\n Khong du bo nho !!!";
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
template<class T>
QNode<T>* popQ(Queue<T>& Q)
{
	QNode<T>* p = NULL;
	if (Q.Head != NULL)
	{
		p = Q.Head;
		Q.Head = Q.Head->Next;
		p->Next = NULL;
	}
	return p; // delete p sau khi xuất p trong hàm cần sử dụng
}
template<class T>
void pushQ(Queue<T>& Q, QNode<T>* p)
{
	if (p != NULL)
		if (Q.Head == NULL)
			Q.Head =Q.Tail = p;
		else
		{
			Q.Tail->Next = p;
			Q.Tail = p;
		}
}

//--------------------------------
template<class T>
void insert(Queue<T>& Q, QNode<T>* p)
{
	if (!p) return;
	if (!isEmpty(Q))
		Q.Head = Q.Tail = p;
	else
	{
		Q.Tail->Next = p;
		Q.Tail = p;
	}
}
template<class T> 
void remove(Queue<T>& Q, T x)
{
	if (isEmpty(Q) == false)
		return;
	QNode<T>* p = Q.Head;
	Q.Head = Q.Head->Next;
	x = p->Info;
	p->Next = NULL;
	delete p;
}
