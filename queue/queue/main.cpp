#define _CRT_SECURE_NO_WARNINGS 1
#include "SqQueue.h"
#include "LinkQueue.h"


void test()
{
	LinkQueue Lq;
	int x;
	LinkNode* S = (LinkNode*)malloc(sizeof(LinkNode));
	InitLinkQueue(Lq);
	printf("%d", Is_Empty(Lq));
	En_LinkQueue(Lq, 4);
	En_LinkQueue(Lq, 4);
	En_LinkQueue(Lq, 4);
	En_LinkQueue(Lq, 4);
	search_LinkQueue(Lq, 4, S);
	printf("%d ", S->data);
	printf("%d", Is_Empty(Lq));

	Print_LinkQueue( Lq);
}	

int main()
{
	test();
	return 0;
}