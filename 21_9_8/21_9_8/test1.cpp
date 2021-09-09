#include<stdio.h>
#include<stdlib.h>
//void getmax(int* result, int* buf, int buflen) {
//	int i;
//	result = buf;
//	for (i = 1; i < buflen; ++i) {
//		if (*result < buf[i]) {
//			result = buf + i;
//		}
//	}
//}
//
//struct A {
//	char a1;
//	short a2;
//	int a4;
//	char* p1;
//};
//extern "C" int getlin(char* s);
//int getlin(char* s) {
//	char* p = s;
//	while (*p != '\0') {
//		p++;
//	}
//	return (p - s);
//}
#pragma pack(8)//将默认对齐数改为8
typedef struct rect_tag {
	char a;
	float b;
	double c;
	bool d;
};
int main() {
	/*int buf[] = { 3,5,4,1,2 };
	int max = 0;
	getmax(&max, buf, 5);
	printf("%d\n", max);*/

	//int arr[3][3] = { 0 };
	//char b[30];
	//char* c = (char*)malloc(sizeof(char) * 10);
	rect_tag a;
	printf("%d,", sizeof(a));

	
}