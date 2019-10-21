//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//
//int main()
//{
//	int arr[1024][10] = { 0 };
//	srand((unsigned)time(NULL));
//	for (int j = 0; j < 500; j++)
//	{
//		for (int i = 0; i < 10; i++)
//		{
//			arr[j][i] = rand() % 20;	// 生成0 -20 的随机数,并写进数组
//		}
//	}
//	for (int i = 0; i < 500; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		putchar('\n');
//	}
//	/*int tmp = 0;
//	for (int i = 0; i < 500; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			tmp += arr[i][j];
//		}
//	}
//	int sub = tmp / 5000;
//	printf("%d\n", tmp);*/
//	//// 写入 Excel
//	//FILE *fp = NULL;
//	//fp = open("456.csv","w+");
//	//	for (int j = 0; j < 10; j++)
//	//	{
//	//		fprintf(fp, "%d \n", 1);
//	//	}
//
//	//fclose(fp);
//	return 0;
//}