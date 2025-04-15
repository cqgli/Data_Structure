#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"
ThreadNode* pre = NULL;


//二叉树的初始化
void InitBiTree(BiTree &T)
{
	T = (BiTNode*)malloc(sizeof(BiTree));
	T->lchild = NULL;
	T->parent = NULL;
	T->rchild = NULL;
}

//二叉树的构造
BiTree CreateBiTree(int* a, int i, int len)
{
	if (i >= len)
		return NULL;
	BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode) * len);
	p->data = a[i];
	p->lchild = CreateBiTree(a, 2 * i + 1, len);
	p->rchild = CreateBiTree(a, 2 * i + 2, len);
	return p;
}


//先序遍历
void visit(BiTree T)
{
	printf("%d ", T->data);
}
void PreOrder(BiTree T)
{
	if (T != NULL)
	{
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

////中序遍历
void InOrder(BiTree T)
{
	if(T!=NULL)
	{
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}
//后序遍历
void PostOrder(BiTree T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}
bool Is_Empty(LinkQueue Lq);
//树的层序遍历
//void LevelOrder(BiTree T)
//{
//	LinkQueue Lq;
//	//InitLinkQueue(Lq);
//	BiTree p;
//	//EnQueue(Lq, T);
//	while (!Is_Empty(Lq))
//	{
//		//DeQueue(Lq, p);
//		//visis(p);
//		if (p->lchild)
//			//EnQueue(Lq,p->lchild);
//			continue;
//		else if (p->rchild)
//			//EnQueue(Lq,p->rchild);
//			continue;
//	}
//}

void visit(ThreadNode* T)
{	//pre开始时默认为NULL
	if (!T->lchild)//当节点的左孩子不存在的时候修改节点的前驱
	{
		T->lchild = pre;
		T->ltag = 1;
	}
	if (!pre || !T->rchild)//当pre为空时表明此时T为第一个节点
		//当前驱的右孩子不存在的时候修改pre的后继
	{
		pre->rchild = T;
		pre->rtag = 1;
	}
	pre = T;
}

//中序线索化二叉树
void CreateInThread(ThreadTree T)
{
	if (T != NULL)
	{
		CreateInThread(T->lchild);
		visit(T);
		CreateInThread(T->rchild);
		if (pre->rchild == NULL)
			pre->rtag == 1;
	}
}


//先序线索化二叉树
void CreatePreThread(ThreadTree T)
{
	if (T != NULL)
	{
		visit(T);
		if(T->ltag == 0)//前驱的节点与当前节点存在关系，会形成闭环
			CreatePreThread(T->lchild);
		CreatePreThread(T->rchild);
		if (pre->rchild == NULL)
			pre->rtag == 1;
	}
}

//后序线索化二叉树
void CreatePreThread(ThreadTree T)
{
	if (T != NULL)
	{
		CreatePreThread(T->lchild);
		CreatePreThread(T->rchild);
		visit(T);
		if (pre->rchild == NULL)
			pre->rtag == 1;
	}
}


//找到第一个中序遍历的节点
ThreadNode* FirstNode(ThreadNode* p)
{
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}
//在中序线索二叉树中找到节点的后继节点
ThreadNode* NextNode(ThreadNode* p)
{
	if (p->rtag == 1)
		return p->rchild;
	else
		return FirstNode(p->rchild);
}
//中序遍历线索二叉树
void InOrder(ThreadNode* T)
{
	for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p))
	{
		visit(p);
	}
}

//找到最后一个被中序遍历的节点
ThreadNode* LastNode(ThreadNode* p)
{
	while (p->ltag == 0)
		p = p->rchild;
	return p;
}
//在中序线索二叉树中找到p的前驱节点
ThreadNode* PreNode(ThreadNode* p)
{
	if (p->rtag == 0)
		return LastNode(p->lchild);
	return p->lchild;
}
//逆向中序遍历线索二叉树
void RevInOrder(ThreadNode* T)
{
	for (ThreadNode* p = LastNode(T); p != NULL; p = PreNode(p))
	{
		visit(p);
	}
}

//在先序线索二叉树中找后继
ThreadNode* NextPreNode(ThreadNode* p)
{
	if (p->rtag == 1)
		return p->rchild;
	else if (p->ltag == 0)
		return p->lchild;
	else
		return p->rchild;
}
//找不到先序线索二叉树的前驱
// 三叉链表的前驱
// 当为左节点时，父节点为
// 当为右节点，且左节点为空，父节点为
// 当为右节点时，左节点不为空，为左子树的最后一个节点
//除非是三叉链表

//后序线索二叉树找后序前驱
ThreadNode* PrePostOrder(ThreadNode* p)
{
	if (p->ltag == 1)
		return p->lchild;
	//当存在左孩子
	else
	{
		if (p->rtag == 0)
			return p->rchild;
		else
			return p->lchild;
	}
}
//后序线索二叉树找不到后继
// 当为右孩子时，后继为父节点
// 当为左孩子时，且右孩子为空，后继为父节点
// 当为左孩子，且右孩子不为空，后继为右子树的后序遍历的第一个节点
//当为三叉链表时


