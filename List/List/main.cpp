#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
#include "LNode.h"


void test()
{
	LNode* L;
	LNode * LS = List_HeadInsert(L);
	List_Print(LS);
}
int main()
{
	test();
	return 0;
}