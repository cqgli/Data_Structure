#define _CRT_SECURE_NO_WARNINGS 1

#include "String.h"

void test()
{
	SString S;
	Init_SString(S);
	SString T;
	Init_SString(T);
	SString M;
	Init_SString(M);
	StrAssign(S, '1');
	StrAssign(S, '2');
	StrAssign(S, '3');
	StrAssign(S, '4');
	StrAssign(T, '4');
	StrAssign(T, '1');
	StrAssign(T, '2');
	StrAssign(T, '3');
	printf("%d", index(T, S));
	
	Print_String(S);
	Print_String(T);
	Print_String(M);
}
int main()
{
	test();
	return 0;
}