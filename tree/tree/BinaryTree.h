#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct BinaryTree {
	int data;
	struct BinaryTree* lchild, * rchild;
}BinaryTree,*BiTree;

//二叉树的构造
//bool CreatBiTree(BinaryTree T, definition);

//先序遍历
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

////中序遍历
//InOrderTraverse(T);
//后序遍历

