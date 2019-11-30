// 小易的升级之路
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 求两个数的最大公约数
int MaxDivisor(int a, int b)
{
	int tmp = 1;
	int max = 0;
	if (a > b)
		swap(a, b);
	for (int i = 1; i <= a; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			tmp = i;
		}
		if (max < tmp)
			max = tmp;
	}
	return max;
}

int Power(vector<int> v1, int a)
{
	int num = v1.size(); // 记录怪物的数量
	int ablity = a;
	for (auto &i : v1)
	{
		if (ablity >= i)
		{
			ablity += i;
		} else
		{
			ablity += MaxDivisor(ablity, i);
		}
	}
	return ablity;
}


int main()
{
	int a, ablity;
	//vector<int> v1;
	while (scanf("%d %d", &a, &ablity) != EOF)
	{

		for (int i = 0; i < a; i++)
		{
			int tmp;
			cin >> tmp;
			if (ablity >= tmp)
				ablity += tmp;
			else
				ablity += MaxDivisor(tmp, ablity);
		}


		cout << ablity << endl;
	}


	return 0;
}