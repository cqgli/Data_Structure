#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct BinaryTree {
	int data;
	struct BinaryTree* lchild, * rchild;
}BinaryTree,*BiTree;

//�������Ĺ���
//bool CreatBiTree(BinaryTree T, definition);

//�������
bool PreOrderTraverse(BiTree T)
{
	if (T == NULL)
	{
		return true;
	}
	else
	{
		//visit(T);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

////�������
//InOrderTraverse(T);
//�������

