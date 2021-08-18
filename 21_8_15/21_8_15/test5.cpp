#include <stdio.h>
#include <stdlib.h>
#include <string.h>





char* CopyStr(char* src) {
	char dst[16];
	printf("%s", dst);
	memcpy(src, dst, strlen(src) + 1);//
	return dst;
}
void test(void) {
	char* src = NULL;
	char* dst = NULL;
	dst = (char*)malloc(16);//
	
	char str[] = "01234567890123456789";
	printf("%s", str);//
	dst = CopyStr(str);
	printf("%s", dst);//
}

int main() {
	test();

	return 0;
}