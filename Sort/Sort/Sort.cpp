#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"


//交换
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
//直接插入排序
void InsertSort(int a[], int len)
{
	int i, j;
	for (i = 1; i < len ; i++)
	{
		int m = a[i];
		for (j = i-1; j >= 0 && a[j] > m; j--)
		{
			a[j + 1] = a[j];
		}
		a[j+1] = m;
	}
}

//折半插入排序
void Binary_InsertSort(int a[], int len)
{
	int i, j;
	int mid;
	for (int i = 1; i < len; i++)
	{
		int m = a[i];
		int low = 0, high = i - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (a[mid] <= m)
				low = mid + 1;
			else
				high = mid - 1;
		}
		for (j = i - 1; j >= low; --j)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = m;
	}
}
//希尔排序
void Shell_Sort(int a[], int len)
{
	int d, i, j;
	for (d = len / 2; d > 0; d = d / 2)
	{
		for (i = d; i < len; i++)
		{
			int m = a[i];
			for (j = i - d; j >= 0 && a[j] > m; j = j - d)
			{
				a[j + d] = a[j];
			}
			a[j + d] = m;
		}
	}
}
//交换排序
void bubble_Sort(int a[], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		int flag = 0;
		for (int j = len-1; j > i; j--)
		{
			if (a[j-1] > a[j])
			{
				swap(a[j-1], a[j]);
				flag = 1;
			}
		}
		if (flag == 0)
			return;
	}
}
//快速排序
int partition(int a[], int low,int high)
{
	int pivot = a[low];
	while (low < high)
	{
		while (low < high && a[high] >= pivot)
			--high;
		a[low] = a[high];
		while (low < high && a[low] <= pivot)
			++low;
		a[high] = a[low];
	}
	a[low] = pivot;
	return low;
}
void QuickSort(int a[], int low,int high)
{
	if (low < high)
	{
		int pivot = partition(a, low, high);
		QuickSort(a, low, pivot - 1);
		QuickSort(a, pivot + 1,high);
	}
}

//选择排序
void SelectSort(int a[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int min = i;
		for (int j = i+1; j < len; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		if (a[min] != a[i])
		{
			swap(a[i], a[min]);
		}
	}
}

//堆排序
void HeapAdjust(int a[], int k,int len)
{
	int m = a[k];//存储根节点元素
	//这里的k表示的是一个树的根节点位置
	//循环先遍历上层树，如果满足堆，则继续遍历下层树，不满足则调整
	for (int i = 2 * k+1; i < len; i= 2*i+1)
	{
		if (i < len - 1 && a[i] < a[i + 1])//这里先判断是否存在右孩子（防止越界）,然后大根堆选出较大的孩子
			i++;
		if (m >= a[i])
			break;//根节点大于较大的孩子
		else
		{
			a[k] = a[i];//仅修改根节点，暂时不修改孩子节点
			k = i;//修改k的值，继续向下遍历观察修改后的k子树是否不满足堆
		}
	}
	a[k] = m;//最后修改孩子节点

}
void CreateMaxHeap(int a[], int len)
{
	//len-1除以2表示的是最后一个树的位置
	//i为0表示的整个堆的根
	for (int i = (len-1) / 2; i >= 0; i--)
	{
		HeapAdjust(a, i, len);
	}
}
void CreatMinHeap(int a[],int k, int len)
{
	//len-1除以2表示的是最后一个树的位置
	//i为0表示的整个堆的根
	for (int i = (len - 1) / 2; i >= 0; i--)
	{
		HeapAdjust(a, i, len);
	}
}
void HeapSort(int a[], int len)
{
	CreateMaxHeap(a, len);
	for (int i = len-1; i > 0; i--)
	{
		swap(a[i], a[0]);
		printf("%d", a[i]);
		HeapAdjust(a, 0, i);//这里的i表示的是数组长度
	}
}
//归并排序
void Merge(int a[], int low,int mid ,int high)
{
	int* b = (int*)malloc((high + 1) * sizeof(int));
	int i, j, k;
	for (int k = low; k < high; k++)
		b[k] = a[k];
	for (i = low, j = mid + 1, k = low; i <= mid && j < high;k++)
	{
		if (b[i] <= b[j])
		{
			a[k] = b[i++];
		}
		else
			a[k] = b[j++];
	}
	while (i <= mid)
		a[k++] = b[i++];
	while (j < high)
		a[k++] = b[j++];
}

//计数排序
void CountSort(int a[], int n, int k)
{
	//k表示的是数组a的最大元素的值
	int i, c[10],b[10];
	for (int i = 0; i < k; i++)
	{
		c[i] = 0;
		b[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		c[a[i]]++;
	}
	for (int i = 1; i < k; i++)
	{
		c[i] = c[i] + c[i - 1];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		b[c[a[i]] - 1] = a[i];//c[ai]表示的是第小于等于a[i]个元素的值的个数，也就是将a[i]元素放在应该有的位置
		c[a[i]]--;//然后将小于等于的元素减一
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = b[i];
	}
}