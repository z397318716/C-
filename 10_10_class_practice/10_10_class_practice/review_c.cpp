//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//int check_sys1()
//{
//	int i = 1;
//	char *tmp = (char *)&i;
//	return *tmp;
//}
//
//int check_sys2()
//{
//	union
//	{
//		int i;
//		char c;
//	}un;
//	un.i = 1;
//
//	return un.c;
//}
//
//void GetMemory(char *p)
//{
//	p = (char *)malloc(100);
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//
//void test1()
//{
//	char* pstr = "hello bit.";//这里是把一个字符串放到pstr指针变量里了吗？
//	printf("%s\n", pstr);
//}
//
//int main()
//{
//	Test();
//
//	/*int tmp = check_sys1();
//	if (tmp == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//
//	union Un
//	{
//		int i;
//		char c[5];
//
//	};
//	union Un1
//	{
//		short c[7];
//		int i;
//	};
//
//	
//	printf("%d\n", sizeof(union Un1));
//	printf("%d\n", sizeof(Un));*/
//	return 0;
//}