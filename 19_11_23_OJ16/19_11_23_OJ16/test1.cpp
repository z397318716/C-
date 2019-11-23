#include<iostream>
#include<vector>
using namespace std;

// 判断一个数是否是完全数
bool ISPerfectNum(int n)
{
	vector<int> v1;
	int tmp = 0;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			v1.push_back(i);
		}
	}
	for (auto & a : v1)
	{
		tmp += a;
	}
	if (tmp == n)
	{
		return true;
	} else
	{
		return false;
	}
}
int Count(int n)
{
	int count = 0;
	if (n < 1 || n > 500000)
	{
		return -1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (ISPerfectNum(i))
			count++;
	}
	return count;
}





int main()
{
	int n;
	while (cin >> n)
	{
		cout << Count(n) << endl;
	}


	return 0;
}