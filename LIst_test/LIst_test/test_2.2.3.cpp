#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#define maxsize 10

typedef struct List {
	int data[maxsize];
	int length;
}SqlList;

//printf
void print_List(SqlList& L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");
}

//1.
int delete_max_List(SqlList& L)
{
	if (L.length == 0)
		exit;
	int max = L.data[0];
	int j = 0;
	for (int i = 0; i < L.length; i++)
	{
		if (max < L.data[i])
		{
			max = L.data[i];
			j = i;
		}
	}
	L.data[j] = L.data[L.length - 1];
	L.length--;
	return max;
}
//2.
void reverse_List(SqlList& L)
{
	for (int i = 0; i < L.length; i++)
	{
		int temp = L.data[i];
		L.data[i] = L.data[L.length - i-1];
		L.data[L.length - i - 1] = temp;
	}
}
//3.��Ҫ
//���ְ취��һ�ּ�¼������x��ֵ�ĸ������Դ˷��������У������ڸ������⣩
//�ڶ��У���¼��ǰ��������x�ĸ�������������x��ֵǰ��k��λ��
void delete_List_unique(SqlList& L, int x)
{
	int k = 0;
	for (int i = 0; i<L.length; i++)
	{
		if (L.data[i] != x)
		{
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;
}
void delete_list_unique(SqlList& L, int x)
{
	int k = 0;
	int i = 0;
	while (i < L.length)
	{
		if (L.data[i] == x)
			k++;
		else if (L.data[i] != x)
		{
			L.data[i - k] = L.data[i];
		}
		i++;
	}
	L.length = L.length - k;
}

//4.
void delete_List_range(SqlList& L, int s, int t)
{
	if (s >= t || L.length == 0)
	{
		return;
	}
	int k = 0;
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] < s || L.data[i] > t)
		{
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;
}
//5.�����ɾ���ظ�,��Ҫ
void delete_List_repeat(SqlList &L)
{
	int i,j;
	for (i=0,j=1; j < L.length; j++)
	{
		if (L.data[i] != L.data[j])
		{
			L.data[++i] = L.data[j];
		}
	}
	L.length = i;
}
//6.�ϲ������
SqlList  merge_List(SqlList& L, SqlList& L1)
{
	SqlList L2;
	L2.length = L.length + L1.length;
	L2.data[2 * maxsize] = { 0 };
	int j = 0,i = 0;
	int k = 0;
	for (; i < L.length && j<L1.length;)
	{
		if (L.data[i] <= L1.data[j])
		{
			L2.data[k++] = L.data[i];
			i++;
		}
		else
		{
			L2.data[k++] = L1.data[j];
			j++;
		}
	}
	if (i < L.length)
	{
		for (; i < L.length; i++)
		{
			L2.data[k++] = L.data[i];
		}
	}
	if (j < L1.length)
	{
		for (; j < L1.length; j++)
		{
			L2.data[k++] = L1.data[j];
		}
	}
	return L2;
}
//7.��һ�������ڵ���������λ�û���,��Ҫ
void reverse(SqlList& L, int left, int right)
{
	if (left >= right || right >= L.length) 
		return;
	int mid = (left + right) / 2;
	for (int i = 0; i <= mid-left; i++)
	{
		int temp = L.data[left + i];
		L.data[left + i] = L.data[right - i];
		L.data[right - i] = temp;
	}
}
void exchange_List(SqlList& L, int m, int n)
{
	reverse(L, 0, m + n - 1);
	reverse(L, 0, n - 1);
	reverse(L, n, m + n - 1);
}

//8.������������Ĳ���
void insert_x_List(SqlList& L, int x)//��������
{
	for (int i = 0; i < L.length-1; i++)
	{
		if (L.data[i]<x && L.data[i + 1]>x)
		{
			for (int j = L.length;j>i+1; j--)
			{
				L.data[j] = L.data[j - 1];
			}
			L.data[i + 1] = x;
			L.length++;
			break;//ע��任֮��Ϳ����˳�ѭ����
		}
		else if (L.data[i] == x)
		{
			int temp = L.data[i];
			L.data[i] = L.data[i + 1];
			L.data[i + 1] = temp;
			break;//����������˳�ѭ��
		}
	}
}
void search_exchange_List(SqlList& L, int x)
{
	int left = 0, right = L.length - 1, mid;
	while (left <= right)//ע������ĵȺ�
	{
		mid = (left + right) / 2;
		if (L.data[mid] < x)
			left = mid + 1;
		else if (L.data[mid] > x)
			right = mid - 1;
		else
			break;
	}
	if (L.data[mid] == x && mid != L.length-1)
	{
		int temp = L.data[mid];
		L.data[mid] = L.data[mid + 1];
		L.data[mid + 1] = temp;
	}
	if(left > right)
	{
		for (int i = L.length - 1; i > right; i--)
		{
			L.data[i+1] = L.data[i];
		}
		L.data[right+1] = x;
		L.length++;
	}
}
//9.��������������ͬԪ��
int max(int a, int b, int c)
{
	if (a > b)
	{
		if (a <= c)
			return c;
		else 
			return a;
	}
	else if (a <= b)
	{
		if (b <= c)
			return c;
		else
			return b;
	}
}
void print_same_List(SqlList& L1, SqlList& L2, SqlList& L3)
{
	int x = 0, y = 0, z = 0;
	for (; x < L1.length, y < L1.length, z < L1.length; )
	{
		int m = max(L1.data[x], L2.data[y], L3.data[z]);
		if (L1.data[x] == m && L2.data[y] == m && L3.data[z] == m)
		{
			printf("%d ", m);
			x++;
			y++;
			z++;
		}
		else
		{
			if (L1.data[x] < m)
				x++;
			if (L2.data[y] < m)
				y++;
			if (L3.data[z] < m)
				z++;
		}
	}
}
//10.������Ԫ��ȫ������p
void move_List(SqlList& L, int p)
{
	int a[maxsize] = { 0 };
	if (p > L.length)
		p = p % L.length;
	for (int i = 0; i < L.length; i++)
	{
		if (i < p)
		{
			a[i + L.length - p] = L.data[i];
		}
		else
		{
			a[i - p] = L.data[i];
		}
	}
	for (int i = 0; i < L.length; i++)
	{
		printf("%d ", a[i]);
	}
}
//�߼�
void move_high_List(SqlList& L, int p)
{
	reverse(L, 0, p-1);
	reverse(L, p,L.length-1);
	reverse(L, 0, L.length);
}

//11.Ѱ�������������λ��
int mid_List(SqlList& L, SqlList& L1)
{
	int i = 0, j = 0,m = 0;
	for (; i < L.length && j < L.length;)
	{
		m = i + j;
		if (m == L.length-1)
			return L.data[i]<L1.data[j]?L.data[i]:L1.data[j];
		if (L.data[i] >= L1.data[j])
		{
			j++;
		}
		else
			i++;
	}
}
//12.�����Ԫ�أ���Ԫ�ظ����������鳤�ȵ�һ��
int main_element(SqlList& L)
{
	int a[maxsize] = { 0 };//��һ���㹻�������,�ÿռ任ʱ��
	for (int i = 0; i < L.length; i++)
	{
		a[L.data[i]]++;
	}
	int max = 0;
	for (int i = 0; i < maxsize; i++)
	{
		if (a[max] < a[i])
			max = i;
	}
	if(a[max] > L.length/2)
		return max;	
	return -1;
}
//�߼��ⷨ
//���ҳ�һ����ѡԪ�أ�����֤���Ƿ�ܶ�
int main_high_element(SqlList& L)
{
	int i, c, count = 1;
	c = L.data[0];
	for(i = 1; i < L.length; i++)
	{
		if (L.data[i] == c)
			count++;
		else
			if (count > 0)
				count--;
			else
			{
				c = L.data[i];
				count = 1;
			}
	}
	if(count >0)
		for (i = count = 0; i < L.length; i++)
		{
			if (L.data[i] == c)
				count++;
		}
	if (count > L.length / 2)
	{
		return c;
	}
	return -1;
}
//13.�ҳ�δ���ֵ���С����
int search_min_ele(SqlList& L)
{
	int min = 1;
	for (int i = 0; i < L.length; i++)
	{
		if (min == L.data[i])
			min++;
	}
	return min;
}
//14.��С������Ԫ��
int abs(int a)
{
	return a > 0 ? a : -a;
}
bool min(int a, int b, int c)
{
	if (a <= c && a <= b)
		return true;
}
int three_List(SqlList& L, SqlList& L1, SqlList& L2)
{
	int i = 0, j = 0, k = 0, D_min = INT_MAX, D;
	while (i < L.length && j < L1.length && k < L2.length && D_min>0)
	{
		D = abs(L.data[i] - L1.data[j]) + abs(L1.data[j] - L2.data[k]) + abs(L2.data[k] - L.data[i]);
		if (D < D_min)
			D_min = D;
		if (min(L.data[i], L1.data[j], L2.data[k]))
			i++;
		else if (min(L1.data[j], L.data[i], L2.data[k]))
			j++;
		else
			k++;
	}
	return D_min;
}
void test()
{
	SqlList L,L1,L2;
	L.data[maxsize] = { 0 };
	L.length = 6;
	L1.length = 3;
	L2.length = 3;
	for (int i = 0; i < L.length; i++)
		scanf("%d", &L.data[i]);
	/*for (int i = 0; i < L1.length; i++)
		scanf("%d", &L1.data[i]);*/
	/*for (int i = 0; i < L2.length; i++)
		scanf("%d", &L2.data[i]);*/
	printf("%d", search_min_ele(L));
	//print_List(L);
}
int main()
{
	test();
	return 0;
}