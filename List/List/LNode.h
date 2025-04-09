#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;//��ʾ���ṹ�������ض���ΪLNode,�ṹ��ָ��������ΪLinkLNode

typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode, * DLinkList;

//����ĳ�ʼ������������ͷ��㣩
bool InitList(LinkList& L);
//��ͷ���ĳ�ʼ��
bool InitList1(LinkList& L);
//����ͷ�������ĵ�i��λ���ϲ���ָ��Ԫ��,���ǲ��ҼӺ��
bool InsertList(LinkList& L, int len, int e);
//��ͷ�������
bool InsertList(LinkList& L, int len, int e);
//������,��p���֮�����s,O(1)
bool InsertNextList(LNode* p, int e);
//ǰ�������
//1.����������ͷ��㣬����ѭ���ҵ�ǰ����㣬Ȼ����
//2.͵�컻��
bool InsertPriorList(LNode* p, int e);
//ɾ����i���ڵ㣬����e
bool DeleteList(LinkList& L, int i, int& e);
//ɾ��ָ���ڵ�
//������һ�����ַ���
bool DeleteNode(LNode* p);
//��λ����,���ص�i���ڵ�
LNode* GetElem(LinkList& L, int i);
//��ֵ����
LNode* LocateElem(LinkList& L, int e);
//����������
int LengthList(LinkList& L);
//β�巨����������
LNode * List_TailInsert(LinkList& L);
//��ӡ����
bool List_Print(LinkList& L);
//ͷ�巨ʵ�ֵ�����
LNode* List_HeadInsert(LinkList& L);


//˫����ĳ�ʼ��
bool Init_DLinkList(DLinkList& L);
//˫����ĺ�� ��p�����s
bool Tail_DLinkInsert(DNode* p, DNode* s);
//˫�����ɾ��p�ĺ�̽��q��̽��
void DLinkList_delete(DNode* p);
//ǰ�����
//�������
//��λ����
//��ֵ����

//��ʼ��ѭ��������
bool Init_CLinkList(LinkList& L);
//�ж�β�ڵ�
bool is_tail(LinkList& L, LNode* s);
//ѭ��˫�����ʼ��
bool Init_CDlinkList(DLinkList& L)
{
	L = (DNode*)malloc(sizeof(DNode));
	L->prior = L;
	L->next = L;
	return true;
}
//�п�,ʹ�õ�˫ѭ������
bool is_empty_Link(LinkList& L);
//��p�����s�ڵ�
//˫�����ɾ��