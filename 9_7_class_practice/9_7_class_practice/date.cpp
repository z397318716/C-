#include "date.h"




static uint GetMonthDay(uint y,uint m)
{
	if (m == 0 || m > 12)
		return 0;
	else if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		return 30;
	}
	else if (m == 2)
	{
		return 28 + (y % 400 == 0 || (y % 4 == 0 && y % 100));
	}  else
		return 31;
}

int GetLeapNum(int sy, int ey)
{
	int tmp = sy % 4;
	if (tmp)
	{
		sy += (4 - tmp);
	}
	return (ey - sy) / 4 + 1;
}

// + 运算符重载
Date Date::operator + (uint delay)const
{
	Date res = *this;
	uint tmp;

	int numy = delay / 365;		// 年数
	int numd = delay % 365;		// 

	int flag = 0;
	// 在 2月 以前,从该年开始计算闰年
	if (res.m_month > 2)
	{
		flag = 1;
	}

	int Leapnum = GetLeapNum(res.m_year + flag, res.m_year);
	
	numd -= Leapnum;
	res.m_year += numy;
	delay = numd;

	tmp = GetMonthDay(res.m_year, res.m_month);
	while (delay >= tmp)
	{
		
		delay -= tmp;
		res.m_month++;
		if (res.m_month > 12)
		{
			res.m_month = 1;
			res.m_year++;
		}
		tmp = GetMonthDay(res.m_year, res.m_month);
	}
	res.m_day += delay;
	if (res.m_day > tmp)
	{
		res.m_month++;
		res.m_day -= tmp;
	}
	return res;
}

// 输出流运算符重载
ostream & operator << (ostream & os, Date & d)
{
	os << d.m_year << '-' << d.m_month << '-' << d.m_day << endl;
	return os;
}

bool Date::operator <(const Date &d)const{
	if (m_year < d.m_year)
	{
		return true;
	}
	else if (m_year == d.m_year && m_month < d.m_month)
	{
		return true;
	}
	else if (m_year == d.m_year && m_month == d.m_month && m_day < d.m_day)
	{
		return true;
	}  else
		return false;
}
bool Date::operator >(const Date &d)const{
	if (m_year > d.m_year)
	{
		return true;
	} else if (m_year == d.m_year && m_month > d.m_month)
	{
		return true;
	} else if (m_year == d.m_year && m_month == d.m_month && m_day > d.m_day)
	{
		return true;
	} else
		return false;
}
bool Date::operator <=(const Date & d)const{
	return !(*this > d);
}
bool Date::operator >=(const Date & d)const{
	return !(*this < d);
}
bool Date::operator !=(const Date &d)const{
	return (*this < d) || (*this > d);
}