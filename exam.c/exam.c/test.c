#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Fib(int n)
{
	if (n < 0)
		return -1;
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2);
}
int MinStep(int n)
{
	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < 100; i++)
	{
		num1 = Fib(i);
		num2 = Fib(i + 1);
		if (n <= num2  && n >= num1)
		{
			int tmp1 = n - num1;
			int tmp2 = num2 - n;
			if (tmp1 > tmp2)
			{
				return tmp2;
			}
			else
			{
				return tmp1;
			}
		}
	}
}
int main()
{
	int num = MinStep(34);
	printf("%d\n", num);

	system("pause");
	return 0;
}