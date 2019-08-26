#include "Sort.h"

void MySort(double* arr,int size, int n = 0)
{
	if (1 == n)
	{
		SelectSort(arr, size);
	}
	else if (2 == n)
	{
		InsertSort(arr, size);
	}
	else
	{
		BubbleSort(arr, size);
	}
	MyPrint(arr, size);
}
void MyPrint(double* arr,int size)
{
	int i = 0;
	while (i < size)
	{
		//cout << arr[i] << endl;
		printf("%0.1f ", arr[i]);
		i++;
	}
	putchar('\n');
}

inline void MySwap(int a, int b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
inline void MySwap(double* a, double* b)
{

	double tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void BubbleSort(double* arr,int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				MySwap(arr + j, arr + j + 1);
			}
		}
	}
}
void SelectSort(double* arr, int size)
{
	int a = 0;
	int b = 0;
	int cur = 0;
	while (a < size)
	{
		b = a;
		cur = a;
		double tmp = arr[a];
		while (b < size)
		{
			if (arr[b] < tmp)
			{
				tmp = arr[b];
				cur = b;
			}
			b++;
		}
		MySwap(arr + a, arr + cur);
		a++;
	}
}

void ShellSort(double* arr, int size)
{
	int i, j, k;
	int gap;
	double tmp;
	for (gap = size / 2; gap; gap /= 2)
	{
		for (k = 0; k < gap; k++)
		{
			for (i = gap + k; i < size; i += gap)
			{
				tmp = arr[i];
				for (j = i; j >= gap && arr[j - gap] > tmp; j--)
				{
					arr[j] = arr[j - gap];
				}
				arr[j] = tmp;
			}
		}
	}
}

void InsertSort(double* arr, int size)
{
	int i, j;
	double tmp;
	for (i = 1; i < size; i++)
	{
		tmp = arr[i];
		for (j = i; j>0 && arr[j - 1] > tmp; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}
}