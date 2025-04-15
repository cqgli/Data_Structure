#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"

void test()
{
	BiTree T;
	InitBiTree(T);
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	T = CreateBiTree(a, 0, 10);
	PreOrder(T);

}
int main()
{
	test();
	return 0;
}