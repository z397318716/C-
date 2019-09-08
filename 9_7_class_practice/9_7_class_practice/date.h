#pragma once
#include <iostream>
using namespace std;
typedef unsigned int uint;


class Date{
	int m_year;
	uint m_month;
	uint m_day;

	//uint GetMonthDay();
public:

	Date(uint y, uint m, uint d) :
		m_year(y),
		m_month(m),
		m_day(d)
	{

	}

	// Date* this 已经隐式的传入了
	Date operator +(uint delay)const;

	// 输出流运算符重载
	friend ostream & operator << (ostream & os, Date & d);
};
static uint GetMonthDay(uint y, uint m);