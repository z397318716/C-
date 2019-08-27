#include "Test.h"

void MySwap1(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
bool strtoi(const char* arr, int & res)
{
	if (!arr)
		return false;
	while (*arr <= ' ')
	{
		arr ++ ;
	}
	int flag = 1;
	if (*arr == '-')
	{
		flag = -1;
		arr++;
	}
	if (*arr >= '9' || *arr < '0')
	{
		return false;
	}
	int sum = 0;
	int tmp = 0;
	for (int i = 0; arr[i] <='9' && arr[i] >='0'; i++)
	{
		tmp = arr[i] - '0';
		sum = sum * 10 + tmp;
	}
	res = sum * flag;

	return true;
}

void sysReverse(int& n, int k)
{
	int tmp, sum = 0;
	for (int i = 0; i; i /= k)
	{
		tmp = i % k;
		sum = sum * k + tmp;
	}
	n = sum;
}

