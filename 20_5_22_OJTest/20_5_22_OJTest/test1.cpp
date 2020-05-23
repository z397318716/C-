#include<iostream>

int main1()
{
#if 0
	short i = 65536;
	int j = i + 1;
	int a = 32767 * 2;
	std::cout << i <<' ' << j << std::endl;
	std::cout << a << std::endl;
	std::cout << "INT_MAX:" << INT_MAX << std::endl;
	std::cout << "short_max: " << SHRT_MAX << std::endl;
#endif

	int a[] = { 2, 4, 6, 8, 10 }, *p, **k;
	p = a;
	k = &p;
	printf(" % d", *(p++));
	printf(" % d\n", **k);
	return 0;

	system("pause");

	return 0;
}