#pragma once
#include <iostream>
using namespace std;
/***************************************************************************************************
1��дһ���������ӿڣ�����ɶ�������С��������
2���ӿ��жഫ��һ��ȱʡ�����������ָ�����Ͳ���A����ʽ�����ָ���ˣ��Ͱ�����ѡ���������ʽ�����ٰ������֣���
3���������Ļ����ϣ���ɶԽṹ�������ͨ�������жϴ�С�ĺ�����ʵ�֡�
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

