#pragma once
#include <stdio.h>
#include <String.h>

#define maxsize 100
//双亲表示法
typedef struct {
	int data;
	int parent;
}PTNode;
typedef struct {
	PTNode nodes[maxsize];
	int n;
}PTree;//每个节点存放数据和双亲位置，记录总节点数

//孩子表示法
typedef struct CTNode {
	int child;//孩子在数组的位置
	struct CTNode* next;//下一个孩子
};
typedef struct {
	int data;
	struct CTNode* firstChild;//第一个孩子，不带头结点的链表
}CTBox;
typedef struct {
	CTBox nodes[maxsize];
	int n, r;//节点数和根的位置
}CTree;

//孩子兄弟表示法
typedef struct CSNode {
	int data;
	struct CSNode* firstchild, * nextsibling;
}CSNode, * CSTree;//存放第一个孩子和孩子的右兄弟指针

//树的遍历

//先根遍历，先根后子树的原则
//与二叉树的先序遍历相同

//后根遍历，先子树后根的原则
//与二叉树的中序遍历相同

//森林的变量

//先序变量森林
//访问第一个树的节点
//先序遍历第一个树
//依次先序遍历其他树

//中序遍历森林
//中序遍历第一个树
//访问第一个树根
//依次中序遍历其他树

//代码可以考虑使用二叉树的形式编写

//并查集
int UFSets[maxsize];

//初始化
void Initial(int s[])
{
	for (int i = 0; i < maxsize; i++)
		s[i] = -1;
}
//并查集的查找操作
int find(int s[], int x)
{
	while (s[x] >= 0)
	{
		x = s[x];
	}
	return x;
}

//并查集的union操作
void Union(int s[], int root1, int root2)
{
	if (root1 == root2)
		return;
	else
		s[root2] = root1;
}

//并查集的优化,优化后的数的高度小于Log2n向下取整+1
void Union(int s[], int root1, int root2)
{
	if (root1 < root2)
	{
		s[root1] += s[root2];
		s[root2] = root1;
	}
	else
	{
		s[root2] += s[root1];
		s[root1] = root1;
	}
}
//并查集的二次优化
int Find(int s[], int x)
{
	int root = x;
	while (s[root] > 0)
		root = s[root];
	while (x != root)
	{
		int t = s[x];//将路径内的每个节点的双亲节点都改为根节点的位置
		s[x] = root;
		x = t;
	}
	return root;//返回根节点编号
}