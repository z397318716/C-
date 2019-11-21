// 计算日期到天数转换
#include<iostream>
#include<vector>
using namespace std;

// 判断是否是闰年
bool IsLeapYear(int num)
{
	if (num % 4 == 0 && num % 100 != 0)
		return true;
	else if (num % 400 == 0)
		return true;
	else
		return false;
}
// 判断是闰年的哪一天
int WhichDay(int year, int month, int day)
{
	// 输入合法性判断
	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
		return -1;
	/*
	else if(IsLeapYear(year) && month == 2 && (day > 29))
	return -1;
	else if(!IsLeapYear(year) && month == 2 && (day > 28))
	return -1;
	else if(month == 1 || month == 3 || month == 5 || month == 7 ||month == 8 || month ==10 || month == 12 && (day > 31))
	return -1;
	else if(month == 4 || month == 6 || month == 9 || month == 11 && (day > 30))
	return -1;
	*/

	int count = 0;

	vector<int> v1{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	vector<int> v2{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (IsLeapYear(year))
	{
		if (day > v2[month - 1])
			return -1;
	} else if (!IsLeapYear(year))
	{
		if (day > v1[month - 1])
			return -1;
	}
	vector<int> v;
	if (IsLeapYear(year))
	{
		v = v2;
	} else
	{
		v = v1;
	}
	for (int i = 0; i < month - 1; i++)
	{
		count += v[i];
	}
	count += day;
	return count;
}


int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		cout << WhichDay(year, month, day) << endl;
	}




	return 0;
}