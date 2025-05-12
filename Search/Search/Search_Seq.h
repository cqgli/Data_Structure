#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int* elem; //��̬�����ַ
	int tableLen;
}SSTable;

int Search_Seq(SSTable ST, int key)
{
	//�ڱ�����
	/*ST.elem[0] = key;
	int i;
	for (i = ST.tableLen; ST.elem[i] != key; i--);
	return i;*/
	int i = 0;
	for (i = 0; i < ST.tableLen && ST.elem[i] != key; i++);
	return i == ST.tableLen ? -1 : i;
}

//�۰����
int Binary_Search(SSTable ST, int key)
{
	int low = 0, high = ST.tableLen - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (ST.elem[mid] == key)
			return mid;
		else if (ST.elem[mid] < key)
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}