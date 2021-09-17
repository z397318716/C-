#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
int str_strncpy(void) {
	char str[16] = { "hello,world!\n" };
	strncpy(str, "ipc", strlen("ipc"));
	printf("%s\n", str);
	strncpy(str, "ipc\n", strlen("ipc"));
	printf("%s\n", str);
	strncpy(str, "ipc", strlen("ipc")+1);
	printf("%s\n", str);
	return 0;
}

void get_memory(char** p, int size) {
	*p = (char*)malloc(size);
}
void test() {
	char* str = NULL;
	get_memory(&str, 64);
	strcpy(str, "helloworld");
	printf(str);
}
void test1() {
	int y = 10;
	while (y--);
	printf("y=%d\n", y);
}
#define SQUARE(a) ((a)*(a))
typedef struct {
	int a;
	int b;
	int c;
}na, *pt;
int main() {
	//str_strncpy();
	int n[] = { '2','0','2','1' };
	pt p = (pt)&n[1];
	printf("%d", p->a + p->b + p->c);

	int M = 8;
	int K = (M++) + 1;
	return 0;
}