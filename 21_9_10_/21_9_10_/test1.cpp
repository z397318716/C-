#include<iostream>

#define n 5


void test1() {
	char s[50] = "12345678", * p = s;
	int i = 0;
	i = *(p + 5) - *(p + 2);
	s[3] = 0;
	printf("%d\n", i + strlen(s) + sizeof(s) + sizeof(s[0]));
	
}

int main() {
	test1();


	return 0;
}