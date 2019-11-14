#include<iostream>
//#include<vector>
#include<string>

using namespace std;
// 基于排列组合的古典概型
int SumWayNum(int n, int m)
{
	int step = n + m;
	int sumway = 1;
	int tmp = 0;
	int tmp1 = 1;
	int tmp2 = 1;
	if (n < m)
	{
		tmp = n;
	} else
	{
		tmp = m;
	}
	//int right = n, below = m;

	for (int i = step - tmp + 1; i <= step; i++)
	{
		sumway = sumway * i;
	}
	for (int i = 1; i <= tmp; i++)
	{
		tmp1 = tmp1 * i;
	}


	return (sumway / tmp1);
}


int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	cout << SumWayNum(n, m);


	return 0;
}