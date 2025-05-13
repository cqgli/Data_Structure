#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

void test()
{
    int arr[] = { 1, 3 ,6, 2, 4 ,8};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    CountSort(arr, len, 9);

    printf("Sorted array: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

}
int main()
{
	test();
	return 0;
}