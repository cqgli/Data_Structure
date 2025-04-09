#define _CRT_SECURE_NO_WARNINGS 1

#include "LNode.h"
//结点

//链表的初始化函数（不带头结点）
bool InitList(LinkList& L)
{
	L = NULL;
	return true;
}
//带头结点的初始化
bool InitList1(LinkList& L)
{
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->next = NULL;
	return true;
}
//在有头结点链表的第i个位置上插入指定元素,就是查找加后插
bool InsertList(LinkList& L,int len,int e)
{
	if (len < 1)
		return false;
	LNode* p = L;
	for (int i = 0; i < len-1 && p!=NULL; i++)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	LNode* L1 = (LNode*)malloc(sizeof(LNode));
	L1->data = e;
	L1->next = L->next;
	p->next = L1;
	return true;
}
//无头结点的情况
bool InsertList_NoHead(LinkList& L, int len, int e)
{
	if (len < 1)
		return false;
	if (len == 1)//特殊情况
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = L->next;
		L = s;
		return true;
	}
	LNode* p = L;
	for (int i = 0; i < len - 1 && p != NULL; i++)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	LNode* L1 = (LNode*)malloc(sizeof(LNode));
	L1->data = e;
	L1->next = L->next;
	p->next = L1;
	return true;
}
//后插操作,在p结点之后插入s,O(1)
bool InsertNextList(LNode *p, int e)
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
//前叉操作，
//1.函数参数有头结点，遍历循环找到前驱结点，然后后插
//2.偷天换日
bool InsertPriorList(LNode* p, int e)
{
	if (p == NULL)
	{
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = p->data;
	s->next = p->next;
	p->data = e;
	p->next = s;
	return true;
}
//删除第i个节点，返回e
bool DeleteList(LinkList& L, int i,int &e)
{
	if (i < 1)
		return false;
	LNode* p = L;
	int j = 0;
	while (j<i && p != NULL)
	{
		p = p->next;
		j++;
	}
	if (p == NULL || p->next == NULL)
	{
		return false;
	}
	e = p->next->data;
	LNode* q = p->next;
	p->next = q->next;
	free(q);
	return true;
}
//删除指定节点
//和上面一样两种方法
bool DeleteNode(LNode* p)
{
	if (p == NULL)
		return false;
	LNode* s = p->next;
	p->data = s->data;
	s->next = p->next;
	free(p);
	return true;
}
//按位查找,返回第i个节点
LNode* GetElem(LinkList& L, int i)
{
	if (i < 0)
		return NULL;
	LNode* p = L;
	int j = 0;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}
//按值查找
LNode* LocateElem(LinkList& L,  int e)
{
	LNode* p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}
//计算链表长度
int LengthList(LinkList& L)
{
	LNode* p = L->next;
	//不带头结点时
	// p = L;
	int j = 0;
	while (p != NULL)
	{
		p = p->next;
		j++;
	}
	return j;
}
//尾插法建立单链表
LNode * List_TailInsert(LinkList& L)
{
	//初始化链表空间
	L = (LNode*)malloc(sizeof(LNode));
	int x;
	scanf("%d", &x);//输入插入值
	LNode* s,*p = L;//将两个指针指向头结点
	while (x != 9999)//设置特殊值，输入后结束
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		p->next = s;
		p = s;
		scanf("%d", &x);
	}
	p->next = NULL;
	return L;
}
//打印链表
bool List_Print(LinkList& L)
{
	LNode* s = L->next;
	while (s != NULL)
	{
		printf("%d ", s->data);
		s = s->next;
	}
	printf("\n");
	return true;
}
//头插法单链表
LNode* List_HeadInsert(LinkList& L)
{
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;//关键
	int x;
	scanf("%d", &x);
	while (x != 999)
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;//关键
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}
//双链表的后插 在p后插入s
bool Tail_DLinkInsert(DNode* p, DNode* s)
{
	if (p == NULL || s == NULL)
		return false;
	s->next = p->next;
	if (p != NULL)
	{
		p->next->prior = s;
	}
	p->next = s;
	s->prior = p;
	return true;
}
//双链表的初始化
bool Init_DLinkList(DLinkList& L)
{
	L = (DNode*)malloc(sizeof(DNode));
	L->data = 0;
	L->next = NULL;
	L->prior = NULL;
	return true;
}
//双链表的删除p的后继结点q后继结点
void DLinkList_delete(DNode* p)
{
	if (p == NULL || p->next == NULL)
		return;
	DNode* q = p->next;
	p->next = q->next;
	if (q != NULL)
	{
		q->next->prior = p;
	}
	free(q);
}

//初始化循环单链表
bool Init_CLinkList(LinkList& L)
{
	L = (LNode*)malloc(sizeof(LNode));
	L->next = L;
	return true;
}
//判空
bool is_empty_Link(LinkList& L)
{
	if (L->next == L)
		return true;
	return false;
}
//判断尾节点
bool is_tail(LinkList& L, LNode* s)
{
	if (s->next = L)
		true;
	else
		false;
}
