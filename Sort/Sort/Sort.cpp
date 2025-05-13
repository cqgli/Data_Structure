#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"


//����
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
//ֱ�Ӳ�������
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

//�۰��������
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
//ϣ������
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
//��������
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
//��������
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

//ѡ������
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

//������
void HeapAdjust(int a[], int k,int len)
{
	int m = a[k];//�洢���ڵ�Ԫ��
	//�����k��ʾ����һ�����ĸ��ڵ�λ��
	//ѭ���ȱ����ϲ������������ѣ�����������²����������������
	for (int i = 2 * k+1; i < len; i= 2*i+1)
	{
		if (i < len - 1 && a[i] < a[i + 1])//�������ж��Ƿ�����Һ��ӣ���ֹԽ�磩,Ȼ������ѡ���ϴ�ĺ���
			i++;
		if (m >= a[i])
			break;//���ڵ���ڽϴ�ĺ���
		else
		{
			a[k] = a[i];//���޸ĸ��ڵ㣬��ʱ���޸ĺ��ӽڵ�
			k = i;//�޸�k��ֵ���������±����۲��޸ĺ��k�����Ƿ������
		}
	}
	a[k] = m;//����޸ĺ��ӽڵ�

}
void CreateMaxHeap(int a[], int len)
{
	//len-1����2��ʾ�������һ������λ��
	//iΪ0��ʾ�������ѵĸ�
	for (int i = (len-1) / 2; i >= 0; i--)
	{
		HeapAdjust(a, i, len);
	}
}
void CreatMinHeap(int a[],int k, int len)
{
	//len-1����2��ʾ�������һ������λ��
	//iΪ0��ʾ�������ѵĸ�
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
		HeapAdjust(a, 0, i);//�����i��ʾ�������鳤��
	}
}
//�鲢����
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

//��������
void CountSort(int a[], int n, int k)
{
	//k��ʾ��������a�����Ԫ�ص�ֵ
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
		b[c[a[i]] - 1] = a[i];//c[ai]��ʾ���ǵ�С�ڵ���a[i]��Ԫ�ص�ֵ�ĸ�����Ҳ���ǽ�a[i]Ԫ�ط���Ӧ���е�λ��
		c[a[i]]--;//Ȼ��С�ڵ��ڵ�Ԫ�ؼ�һ
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = b[i];
	}
}