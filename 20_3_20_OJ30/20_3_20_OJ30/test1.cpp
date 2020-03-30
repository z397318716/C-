// write your code here cpp
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

/*
�������ڼ��㷨���� Zeller��ʽ
w = y + [y / 4] + [c / 4] - 2c + [26(m + 1) / 10] + d -1
w: ����
c: ����-1
y: ��(�����λ��)
m: ��( 3 <= m <= 14  �ڸù�ʽ��,ÿһ��� 1,2�·�Ҫ��������һ���13,14�·�������,��ʱc��y������һ��ȡֵ)
d: ��
[]: ����ȡ��,
*/
int week(int year, int m, int d)
{


	int w, c, y;
	c = year / 100;
	y = year % 100;
	if (m < 3)
	{
		m += 12;
		y -= 1;
		if (y == 0)
			c -= 1;
	}
	w = y + (y / 4) + (c / 4) - 2 * c + (26 * (m + 1) / 10) + d - 1;
	int tmp = w % 7;
	if (tmp == 0)
		tmp = 7;
	return tmp;
}
void Print(int year, int month, int day)
{
	std::cout << year << "-";
	std::cout << setfill('0') << setw(2) << month << "-";
	std::cout << setfill('0') << setw(2) << day << std::endl;
}
void UsHoliday(int year)
{
	// Ԫ��
	Print(year, 1, 1);
	//1�µĵ���������һ:��.·�½������
	if (1 == week(year, 1, 1))
		Print(year, 1, 15);
	else
	{
		int tmp = week(year, 1, 1);
		Print(year, 1, (7 - tmp + 1 + 1 + 14));
	}
	//2�µĵ���������һ:
	if (1 == week(year, 2, 1))
		Print(year, 2, 15);
	else
	{
		int tmp = week(year, 2, 1);
		Print(year, 2, (7 - tmp) + 1 + 1 + 14);
	}
	// 5�µ����һ������һ
	if (1 == week(year, 5, 31))
		Print(year, 5, 31);
	else
	{
		int tmp = week(year, 5, 31);
		Print(year, 5, 31 - tmp + 1);
	}
	// 7��4��
	Print(year, 7, 4);
	// 9�µĵ�һ������һ
	if (1 == week(year, 9, 1))
		Print(year, 9, 1);
	else
	{
		int tmp = week(year, 9, 1);
		Print(year, 9, (7 - tmp + 1 + 1));
	}
	//11�µĵ��ĸ�������
	if (4 == week(year, 11, 1))
		Print(year, 11, 22);
	else
	{
		int tmp = week(year, 11, 1);
		if (tmp < 4)
			Print(year, 11, (4 - tmp + 1 + 21));
		else
		{
			Print(year, 11, (7 - tmp + 1 + 4 + 21));
		}
	}
	// 12��25��
	Print(year, 12, 25);

}

int main()
{
	int year;
	while (cin >> year)
	{
		UsHoliday(year);
		std::cout << std::endl;
	}



	return 0;
}