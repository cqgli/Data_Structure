#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 100
//顺序存储，左孩子2i，右孩子2i+1，父节点i/2向下取整
//typedef struct BTree {
//	int value;
//	bool IsEmpty;
//};
//BTree Tree[maxsize];

typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
	struct BiTNode* parent;//三叉链表
}BiTNode,*BiTree;

typedef struct ThreadNode {
	int data;
	struct ThreadNode* lchild, * rchild;
	int ltag,rtag;//线索链表
}ThreadNode, * ThreadTree;

//队列
typedef struct LinkNode {
	BiTNode * data;//存的是树节点
	struct LinkNode* next;
}LinkNode;
typedef struct LinkQueue {
	LinkNode* rear, * front;
}LinkQueue;



//二叉树的初始化
void InitBiTree(BiTree &T);
//二叉线索树的初始化
void InitThreadTree(ThreadTree& T)
{
	T = (ThreadNode*)malloc(sizeof(ThreadNode));
	T->lchild = NULL;
	T->ltag = 1;
	T->rchild = NULL;
	T->rtag = 1;
}

//二叉树的构造
BiTree CreateBiTree(int* a, int i, int len);

//二叉线索树的构造
ThreadTree CreateThreadTree(int* a, int i, int len);

//先序遍历
void PreOrder(BiTree T);

////中序遍历
void InOrder(BiTree T);
//后序遍历
void PostOrder(BiTree T);

//树的层序遍历
bool Is_Empty(LinkQueue Lq);
void LevelOrder(BiTree T);


//中序线索化二叉树
void visit(ThreadNode* T);
void CreateInThread(ThreadTree T);

//找到最后一个被中序遍历的节点
ThreadNode* LastNode(ThreadNode* p);

//在中序线索二叉树中找到p的前驱节点
ThreadNode* PreNode(ThreadNode* p);

//逆向中序遍历线索二叉树
void RevInOrder(ThreadNode* T);

//在先序线索二叉树中找后继
ThreadNode* NextPreNode(ThreadNode* p);
//找不到先序线索二叉树的前驱
// 三叉链表的前驱
// 当为左节点时，父节点为
// 当为右节点，且左节点为空，父节点为
// 当为右节点时，左节点不为空，为左子树的最后一个节点
//除非是三叉链表

//后序线索二叉树找后序前驱
ThreadNode* PrePostOrder(ThreadNode* p);
//后序线索二叉树找不到后继
// 当为右孩子时，后继为父节点
// 当为左孩子时，且右孩子为空，后继为父节点
// 当为左孩子，且右孩子不为空，后继为右子树的后序遍历的第一个节点
//当为三叉链表时
