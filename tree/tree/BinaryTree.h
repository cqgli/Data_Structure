#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 100
//˳��洢������2i���Һ���2i+1�����ڵ�i/2����ȡ��
//typedef struct BTree {
//	int value;
//	bool IsEmpty;
//};
//BTree Tree[maxsize];

typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
	struct BiTNode* parent;//��������
}BiTNode,*BiTree;

typedef struct ThreadNode {
	int data;
	struct ThreadNode* lchild, * rchild;
	int ltag,rtag;//��������
}ThreadNode, * ThreadTree;

//����
typedef struct LinkNode {
	BiTNode * data;//��������ڵ�
	struct LinkNode* next;
}LinkNode;
typedef struct LinkQueue {
	LinkNode* rear, * front;
}LinkQueue;



//�������ĳ�ʼ��
void InitBiTree(BiTree &T);
//�����������ĳ�ʼ��
void InitThreadTree(ThreadTree& T)
{
	T = (ThreadNode*)malloc(sizeof(ThreadNode));
	T->lchild = NULL;
	T->ltag = 1;
	T->rchild = NULL;
	T->rtag = 1;
}

//�������Ĺ���
BiTree CreateBiTree(int* a, int i, int len);

//�����������Ĺ���
ThreadTree CreateThreadTree(int* a, int i, int len);

//�������
void PreOrder(BiTree T);

////�������
void InOrder(BiTree T);
//�������
void PostOrder(BiTree T);

//���Ĳ������
bool Is_Empty(LinkQueue Lq);
void LevelOrder(BiTree T);


//����������������
void visit(ThreadNode* T);
void CreateInThread(ThreadTree T);

//�ҵ����һ������������Ľڵ�
ThreadNode* LastNode(ThreadNode* p);

//�������������������ҵ�p��ǰ���ڵ�
ThreadNode* PreNode(ThreadNode* p);

//���������������������
void RevInOrder(ThreadNode* T);

//�������������������Һ��
ThreadNode* NextPreNode(ThreadNode* p);
//�Ҳ�������������������ǰ��
// ���������ǰ��
// ��Ϊ��ڵ�ʱ�����ڵ�Ϊ
// ��Ϊ�ҽڵ㣬����ڵ�Ϊ�գ����ڵ�Ϊ
// ��Ϊ�ҽڵ�ʱ����ڵ㲻Ϊ�գ�Ϊ�����������һ���ڵ�
//��������������

//���������������Һ���ǰ��
ThreadNode* PrePostOrder(ThreadNode* p);
//���������������Ҳ������
// ��Ϊ�Һ���ʱ�����Ϊ���ڵ�
// ��Ϊ����ʱ�����Һ���Ϊ�գ����Ϊ���ڵ�
// ��Ϊ���ӣ����Һ��Ӳ�Ϊ�գ����Ϊ�������ĺ�������ĵ�һ���ڵ�
//��Ϊ��������ʱ
