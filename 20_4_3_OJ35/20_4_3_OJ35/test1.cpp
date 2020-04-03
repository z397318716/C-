#include<iostream>
#include<iomanip>
#include<vector>
/*
错排算法原理:
https://blog.csdn.net/x121850182/article/details/51489453
公式: a(n) = n!/2! - n!/3! + n!/4! + .....
递推版: a(n) = (n-1)(a(n-1) + a(n-2)); a(1) = 0, a(2) = 1;
*/
// 阶乘
long long Jie(int n)
{
	long long tmp = 1;
	for (int i = 2; i <= n; i++)
	{
		tmp *= i;
	}
	return tmp;
}
using namespace std;
//非递推版
int Num(int num)
{
	if (num == 1 || num == 0)
		return 0;
	else if (num == 2)
		return 1;
	int count;
	int tmp = Jie(num);
	int tag = 0;
	for (int i = 2; i <= num; i++)
	{
		if (i % 2 == 0)
			tag = 1;
		else
			tag = -1;
		count += tag * (tmp / Jie(i));
	}
	return count;
}
// 递归
vector<long long> YNum()
{
	vector<long long> v1;
	v1.resize(21);
	v1[0] = 0, v1[1] = 0, v1[2] = 1;
	for (int i = 3; i < 21; i++)
	{
		v1[i] = (i - 1) * (v1[i - 1] + v1[i - 2]);
	}

	return v1;
}

int main()
{
	int num;
	vector<long long> v1(YNum());
	vector<long long> v2;
	v2.resize(21);
	v2[0] = 1;
	for (int i = 1; i < 21; i++)
	{
		v2[i] = Jie(i);
	}
	while (cin >> num)
	{
		double a = (double)v1[num];
		double b = (double)v2[num];
		double c = a / b * 100;
		cout << setprecision(2) << fixed << c << "%" << endl;
	}
	return 0;
}