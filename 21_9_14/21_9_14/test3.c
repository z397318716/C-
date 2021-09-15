#include<stdio.h>

void fun(int* ptr) {
	*ptr = 1;
}

struct {
	int a;
	int b;
}t = {1};
int x;

void tese() {
	static int k;
	++k;
	printf("%d\n", k);
}

enum bg_color { BG_RED, BG_BLACK, BG_BLUE };
enum fg_color { FG_RED = 2, FG_BLACK, FG_YELLOW, FG_GREEN };

int get(int type)
{
	static int bc;
	static int fc = FG_BLACK;
	if (type == 0) { return ++bc; }
	else { return ++fc; }
}

int main() {

	
	printf("%d\n", get(0));
	printf("%d\n", get(1));
	printf("%d\n", get(0));
	/*char* p = "test";

	printf("%s\n", p);

	int a[5][2] = { 0,1,2,3,4,5,6,7 };
	int(*p2)[2] = &a[1];
	printf("%d\n", p2[2][2]);
	int ptr = 2;

	fun(&ptr);
	printf("%d\n", ptr);*/
	return 0;
}