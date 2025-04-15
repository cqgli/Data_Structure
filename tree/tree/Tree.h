#pragma once
#include <stdio.h>
#include <String.h>

#define maxsize 100
//˫�ױ�ʾ��
typedef struct {
	int data;
	int parent;
}PTNode;
typedef struct {
	PTNode nodes[maxsize];
	int n;
}PTree;//ÿ���ڵ������ݺ�˫��λ�ã���¼�ܽڵ���

//���ӱ�ʾ��
typedef struct CTNode {
	int child;//�����������λ��
	struct CTNode* next;//��һ������
};
typedef struct {
	int data;
	struct CTNode* firstChild;//��һ�����ӣ�����ͷ��������
}CTBox;
typedef struct {
	CTBox nodes[maxsize];
	int n, r;//�ڵ����͸���λ��
}CTree;

//�����ֵܱ�ʾ��
typedef struct CSNode {
	int data;
	struct CSNode* firstchild, * nextsibling;
}CSNode, * CSTree;//��ŵ�һ�����Ӻͺ��ӵ����ֵ�ָ��

//���ı���

//�ȸ��������ȸ���������ԭ��
//������������������ͬ

//��������������������ԭ��
//������������������ͬ

//ɭ�ֵı���

//�������ɭ��
//���ʵ�һ�����Ľڵ�
//���������һ����
//�����������������

//�������ɭ��
//���������һ����
//���ʵ�һ������
//�����������������

//������Կ���ʹ�ö���������ʽ��д

//���鼯
int UFSets[maxsize];

//��ʼ��
void Initial(int s[])
{
	for (int i = 0; i < maxsize; i++)
		s[i] = -1;
}
//���鼯�Ĳ��Ҳ���
int find(int s[], int x)
{
	while (s[x] >= 0)
	{
		x = s[x];
	}
	return x;
}

//���鼯��union����
void Union(int s[], int root1, int root2)
{
	if (root1 == root2)
		return;
	else
		s[root2] = root1;
}

//���鼯���Ż�,�Ż�������ĸ߶�С��Log2n����ȡ��+1
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
//���鼯�Ķ����Ż�
int Find(int s[], int x)
{
	int root = x;
	while (s[root] > 0)
		root = s[root];
	while (x != root)
	{
		int t = s[x];//��·���ڵ�ÿ���ڵ��˫�׽ڵ㶼��Ϊ���ڵ��λ��
		s[x] = root;
		x = t;
	}
	return root;//���ظ��ڵ���
}