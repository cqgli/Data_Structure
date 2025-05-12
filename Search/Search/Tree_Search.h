#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//二叉排序树
typedef struct {
	int key;
	BSTNode* Lchild, * Rchild;
}BSTNode, * BSTree;

//二叉排序树的查找
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
	//递归查找
	/*if (T == NULL)
		return NULL;
	if (T->key == k)
		return T;
	else if (T->key < k)
		return BST_Search(T->Lchild, k);
	else
		return BST_Search(T->Rchild, k);*/
}

//二叉排序树的插入
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
	//非递归
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

	//while (current != NULL) // 找到插入位置
	//{
	//	parent = current;
	//	if (current->key == k)
	//		return false; // 如果键值已存在，返回 false
	//	else if (current->key > k)
	//		current = current->Lchild;
	//	else
	//		current = current->Rchild;
	//}

	//// 创建新节点
	//BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
	//if (newNode == NULL) return false; // 检查内存分配是否成功
	//newNode->key = k;
	//newNode->Lchild = NULL;
	//newNode->Rchild = NULL;

	//// 将新节点插入到父节点的正确位置
	//if (parent->key > k)
	//	parent->Lchild = newNode;
	//else
	//	parent->Rchild = newNode;

	//return true;
}

//二叉排序树的构造
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

