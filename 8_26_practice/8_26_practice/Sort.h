#pragma once
#include <iostream>
using namespace std;
/***************************************************************************************************
1、写一个排序函数接口，能完成对整数和小数的排序。
2、接口中多传入一个缺省参数，如果不指定，就采用A排序方式，如果指定了，就按他的选择决定排序方式（至少包含三种）。
3、在上述的基础上，完成对结构体的排序。通过传入判断大小的函数来实现。
**************************************************************************************************/
void MySort(double* arr,int size,int n);

void MyPrint(double* arr,int size);
void BubbleSort(double* arr, int size);
void SelectSort(double* arr, int size);
void ShellSort(double* arr, int size);
void InsertSort(double* arr, int size);

typedef struct student
{
	char name[1024];
	int age;
}student;

