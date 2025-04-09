#define _CRT_SECURE_NO_WARNINGS 1

#include "LNode.h"
//���

//����ĳ�ʼ������������ͷ��㣩
bool InitList(LinkList& L)
{
	L = NULL;
	return true;
}
//��ͷ���ĳ�ʼ��
bool InitList1(LinkList& L)
{
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->next = NULL;
	return true;
}
//����ͷ�������ĵ�i��λ���ϲ���ָ��Ԫ��,���ǲ��ҼӺ��
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
//��ͷ�������
bool InsertList_NoHead(LinkList& L, int len, int e)
{
	if (len < 1)
		return false;
	if (len == 1)//�������
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
//������,��p���֮�����s,O(1)
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
//ǰ�������
//1.����������ͷ��㣬����ѭ���ҵ�ǰ����㣬Ȼ����
//2.͵�컻��
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
//ɾ����i���ڵ㣬����e
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
//ɾ��ָ���ڵ�
//������һ�����ַ���
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
//��λ����,���ص�i���ڵ�
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
//��ֵ����
LNode* LocateElem(LinkList& L,  int e)
{
	LNode* p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}
//����������
int LengthList(LinkList& L)
{
	LNode* p = L->next;
	//����ͷ���ʱ
	// p = L;
	int j = 0;
	while (p != NULL)
	{
		p = p->next;
		j++;
	}
	return j;
}
//β�巨����������
LNode * List_TailInsert(LinkList& L)
{
	//��ʼ������ռ�
	L = (LNode*)malloc(sizeof(LNode));
	int x;
	scanf("%d", &x);//�������ֵ
	LNode* s,*p = L;//������ָ��ָ��ͷ���
	while (x != 9999)//��������ֵ����������
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
//��ӡ����
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
//ͷ�巨������
LNode* List_HeadInsert(LinkList& L)
{
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;//�ؼ�
	int x;
	scanf("%d", &x);
	while (x != 999)
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;//�ؼ�
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}
//˫����ĺ�� ��p�����s
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
//˫����ĳ�ʼ��
bool Init_DLinkList(DLinkList& L)
{
	L = (DNode*)malloc(sizeof(DNode));
	L->data = 0;
	L->next = NULL;
	L->prior = NULL;
	return true;
}
//˫�����ɾ��p�ĺ�̽��q��̽��
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

//��ʼ��ѭ��������
bool Init_CLinkList(LinkList& L)
{
	L = (LNode*)malloc(sizeof(LNode));
	L->next = L;
	return true;
}
//�п�
bool is_empty_Link(LinkList& L)
{
	if (L->next == L)
		return true;
	return false;
}
//�ж�β�ڵ�
bool is_tail(LinkList& L, LNode* s)
{
	if (s->next = L)
		true;
	else
		false;
}
