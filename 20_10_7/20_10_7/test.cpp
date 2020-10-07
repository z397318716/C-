#include<iostream>

void test(char ch[])
{
	printf("%d\n", sizeof(ch));
}

int main()
{

	int a = 0;
	int b = 0;
	bool flag = a++ && 1;
	char ch[2];
	test(ch);


	return 0;
}