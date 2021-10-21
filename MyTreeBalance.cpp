//=============================================
#include<iostream>
//balance tree
template<class data>
struct TNode
{
	data Info;
	TNode<data>* Left;
	TNode<data>* Right;
};
template<class data>
struct BTree
{
	TNode<data>* Root;
};
template<class data>
TNode<data>* createBSNode(data x) // tạo 1 node chứa giá trị x 
{
	TNode<data>* p = new TNode<data>;
	if (!p)
		return NULL;
	p->Info = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}
template<class data>
void iniBSTree(BTree<data>& bst) // gán BTRee (Không thể thiếu), khoi tao
{
	bst.Root = NULL;
}
template<class data>
int insertBTNode(TNode<data>*& root, TNode<data>* p)

{
	if (!p) return 0; // them kp thanh cong
	if (!root)
	{// them 
		root = p;
		return 1;
	}
	if (root->Info == p->Info)
		return 0;
	if (p->Info < root->Info)
		insertBTNode(root->Left, p);
	else
		insertBTNode(root->Right, p);
	return 1;
}
//---------------------------------------
template<class data>
int deleteTree(TNode<data>* root)
{// xóa hết cây.
	if (!root) return 0;
	deleteTree(root->Left);
	deleteTree(root->Right);
	delete root;
	return 1;
}
template<class data>
int deleteTNodeLeft(TNode<data>* T)
{
	if (!T) return 0;
	TNode<data>* p = T->Left;
	if (!p) return 0;
	if (p->Left || p->Right)
		return 0;
	delete p;
	return 1;
}
template<class data>
int deleteTNodeRight(TNode<data>* T)
{// xóa TNode nếu nó là TNode lá
	if (!T) return 0;
	TNode<data>* p = T->Right;
	if (!p) return 0;
	if (p->Left || p->Right)
		return 0;
	delete p;
	return 1;
}
template<class data>
TNode<data>* findTNodeReplace(TNode<data>*& p)
{// Nút thế mạng cho nút xóa
	TNode<data>* f = p, * rp = p->Right;
	while (rp->Left != NULL)
	{
		f = rp; // lưu giá trị của rp
		rp = rp->Left; // rp sang giá trị tiếp theo
	}
	p->Info = rp->Info; // tìm dc phan tu the mạng cho p la rp
	if (f == p)
		f->Right = rp->Right;
	else
		f->Left = rp->Right;
	return rp;
}
template<class data>
// delete data x
int deleteTNode(TNode<data>*& root, data x)
{
	if (!root) return 0;
	if (root->Info > x)// tìm bên trái
		return deleteTNode(root->Left, x);
	else if (root->Info < x) // tìm bên phải
		return deleteTNode(root->Right, x);
	else
	{
		TNode<data>* p = root;
		TNode<data>* rp = findTNodeReplace(p);
		deleteTNode(rp);
	}
}
// tìm x trên cây
template<class data>
TNode<data>* findTNodeX(TNode<data>* root, data x)
{ //tim nút có giá trị x
	if (!root) return NULL;
	if (root->Info == x) return root;
	if (root->Info > x)
		return findTNodeX(root->Left, x);
	else
		return findTNodeX(root->Right, x);
}
template<class data>
TNode<data>* findTNode_X(TNode<data>* root, data x)
{// khong dùng đệ quy
	TNode<data>* p = root;
	while (p && p->Info != x)
	{
		if (p->Info > x)
			p = p->Left;
		else
			p = p->Right;
	}
	return p;
}
template<class data>
TNode<data>* maxTNodeBSTree(TNode<data>* root)
{
	//Tìm hàm có
}
//---------------------------------------------
template<class data>
int insertBTNodeLeft(TNode<data>* T, TNode<data>* p)
{
	if (T == NULL)
		return 0;
	if (T->Left != NULL) return 0;
	T->Left = p;
	return 1;
}
template<class data>
int insertBTNodeRight(TNode<data>* T, TNode<data>* p)
{
	if (T == NULL)
		return 0;
	if (T->Right != NULL) return 0;
	T->Right = p;
	return 1;
}
template<class data>
int countNode(TNode<data>* root)
{
	if (!root)
		return 0;
	int cnl = countNode(root->Left);
	int cnr = countNode(root->Right);
	return (1 + cnl + cnr);
}
template<class data>
bool XetNutLeaf(TNode<data>* root)
{
	if (!root->Left && !root->Right)
		return true;
	return false;
}
//=============================================
