#pragma once
#include <iostream>
#include <string>

#define MySwap2(a,b) {a += b;b = a - b;a = a - b;}

using namespace std;
/********************************************************************************
1、分别使用引用和宏完成交换方法（使用内联），体会两者异同
2、按照指定的函数声明，完成函数：
a、将一个字符串转换为数字，返回值用来校验转换是否成功
bool strtoi(const char *, int &);
b、将一个数字通过指定进制按位逆序（直接覆盖原数）
void sysReverse(int &, int);
********************************************************************************/

void MySwap1(int& a, int& b);
bool strtoi(const char* arr, int & res);
void sysReverse(int& n, int k);
