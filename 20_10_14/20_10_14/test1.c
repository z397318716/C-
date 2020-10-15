#include<stdio.h>

int my_strlen(const char* str)
{
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}

int main()
{
	const char* p = "abcdef";

	int len = my_strlen(p);
	printf(" =%d\n", len);

	system("pause");
	return 0;
}
