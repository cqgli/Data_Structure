#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"
ThreadNode* pre = NULL;


//�������ĳ�ʼ��
void InitBiTree(BiTree &T)
{
	T = (BiTNode*)malloc(sizeof(BiTree));
	T->lchild = NULL;
	T->parent = NULL;
	T->rchild = NULL;
}

//�������Ĺ���
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


//�������
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

////�������
void InOrder(BiTree T)
{
	if(T!=NULL)
	{
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}
//�������
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
//���Ĳ������
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
{	//pre��ʼʱĬ��ΪNULL
	if (!T->lchild)//���ڵ�����Ӳ����ڵ�ʱ���޸Ľڵ��ǰ��
	{
		T->lchild = pre;
		T->ltag = 1;
	}
	if (!pre || !T->rchild)//��preΪ��ʱ������ʱTΪ��һ���ڵ�
		//��ǰ�����Һ��Ӳ����ڵ�ʱ���޸�pre�ĺ��
	{
		pre->rchild = T;
		pre->rtag = 1;
	}
	pre = T;
}

//����������������
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


//����������������
void CreatePreThread(ThreadTree T)
{
	if (T != NULL)
	{
		visit(T);
		if(T->ltag == 0)//ǰ���Ľڵ��뵱ǰ�ڵ���ڹ�ϵ�����γɱջ�
			CreatePreThread(T->lchild);
		CreatePreThread(T->rchild);
		if (pre->rchild == NULL)
			pre->rtag == 1;
	}
}

//����������������
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


//�ҵ���һ����������Ľڵ�
ThreadNode* FirstNode(ThreadNode* p)
{
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}
//�������������������ҵ��ڵ�ĺ�̽ڵ�
ThreadNode* NextNode(ThreadNode* p)
{
	if (p->rtag == 1)
		return p->rchild;
	else
		return FirstNode(p->rchild);
}
//�����������������
void InOrder(ThreadNode* T)
{
	for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p))
	{
		visit(p);
	}
}

//�ҵ����һ������������Ľڵ�
ThreadNode* LastNode(ThreadNode* p)
{
	while (p->ltag == 0)
		p = p->rchild;
	return p;
}
//�������������������ҵ�p��ǰ���ڵ�
ThreadNode* PreNode(ThreadNode* p)
{
	if (p->rtag == 0)
		return LastNode(p->lchild);
	return p->lchild;
}
//���������������������
void RevInOrder(ThreadNode* T)
{
	for (ThreadNode* p = LastNode(T); p != NULL; p = PreNode(p))
	{
		visit(p);
	}
}

//�������������������Һ��
ThreadNode* NextPreNode(ThreadNode* p)
{
	if (p->rtag == 1)
		return p->rchild;
	else if (p->ltag == 0)
		return p->lchild;
	else
		return p->rchild;
}
//�Ҳ�������������������ǰ��
// ���������ǰ��
// ��Ϊ��ڵ�ʱ�����ڵ�Ϊ
// ��Ϊ�ҽڵ㣬����ڵ�Ϊ�գ����ڵ�Ϊ
// ��Ϊ�ҽڵ�ʱ����ڵ㲻Ϊ�գ�Ϊ�����������һ���ڵ�
//��������������

//���������������Һ���ǰ��
ThreadNode* PrePostOrder(ThreadNode* p)
{
	if (p->ltag == 1)
		return p->lchild;
	//����������
	else
	{
		if (p->rtag == 0)
			return p->rchild;
		else
			return p->lchild;
	}
}
//���������������Ҳ������
// ��Ϊ�Һ���ʱ�����Ϊ���ڵ�
// ��Ϊ����ʱ�����Һ���Ϊ�գ����Ϊ���ڵ�
// ��Ϊ���ӣ����Һ��Ӳ�Ϊ�գ����Ϊ�������ĺ�������ĵ�һ���ڵ�
//��Ϊ��������ʱ


