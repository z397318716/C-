#pragma once
#include <iostream>
#include <string>

#define MySwap2(a,b) {a += b;b = a - b;a = a - b;}

using namespace std;
/********************************************************************************
1���ֱ�ʹ�����úͺ���ɽ���������ʹ�������������������ͬ
2������ָ���ĺ�����������ɺ�����
a����һ���ַ���ת��Ϊ���֣�����ֵ����У��ת���Ƿ�ɹ�
bool strtoi(const char *, int &);
b����һ������ͨ��ָ�����ư�λ����ֱ�Ӹ���ԭ����
void sysReverse(int &, int);
********************************************************************************/

void MySwap1(int& a, int& b);
bool strtoi(const char* arr, int & res);
void sysReverse(int& n, int k);
