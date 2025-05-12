#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//����������
typedef struct {
	int key;
	BSTNode* Lchild, * Rchild;
}BSTNode, * BSTree;

//�����������Ĳ���
BSTNode* BST_Search(BSTree T,int k)
{
	while (T != NULL && k != T->key)
	{
		if (k > T->key)
			T = T->Rchild;
		else
			T = T->Lchild;
	}
	return T;
	//�ݹ����
	/*if (T == NULL)
		return NULL;
	if (T->key == k)
		return T;
	else if (T->key < k)
		return BST_Search(T->Lchild, k);
	else
		return BST_Search(T->Rchild, k);*/
}

//�����������Ĳ���
bool BST_Insert(BSTree& T, int k)
{
	if (T == NULL)
	{
		T = (BSTNode*)malloc(sizeof(BSTNode));
		T->key = k;
		T->Lchild = NULL;
		T->Rchild = NULL;
		return true;
	}
	else if (T->key == k)
		return false;
	else if (T->key > k)
		return BST_Insert(T->Lchild, k);
	else
		return BST_Insert(T->Rchild, k);
	//�ǵݹ�
	//if (T == NULL)
	//{
	//	T = (BSTNode*)malloc(sizeof(BSTNode));
	//	T->key = k;
	//	T->Lchild = NULL;
	//	T->Rchild = NULL;
	//	return true;
	//}
	//BSTNode* parent = NULL;
	//BSTNode* current = T;

	//while (current != NULL) // �ҵ�����λ��
	//{
	//	parent = current;
	//	if (current->key == k)
	//		return false; // �����ֵ�Ѵ��ڣ����� false
	//	else if (current->key > k)
	//		current = current->Lchild;
	//	else
	//		current = current->Rchild;
	//}

	//// �����½ڵ�
	//BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
	//if (newNode == NULL) return false; // ����ڴ�����Ƿ�ɹ�
	//newNode->key = k;
	//newNode->Lchild = NULL;
	//newNode->Rchild = NULL;

	//// ���½ڵ���뵽���ڵ����ȷλ��
	//if (parent->key > k)
	//	parent->Lchild = newNode;
	//else
	//	parent->Rchild = newNode;

	//return true;
}

//�����������Ĺ���
void Creat_BST(BSTree& T, int str[], int len)
{
	T = NULL;
	int i = 0;
	while (i < len)
	{
		BST_Insert(T, str[i]);
		i++;
	}
}

