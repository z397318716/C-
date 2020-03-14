#include<iostream>
#include<vector>
using namespace std;

int MaxAdd(int n, vector<int> v1)
{
	int max = 0;
	int tmp = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		if (tmp < 0)
		{
			tmp = v1[i];
		} else
		{
			tmp += v1[i];
		}
		if (max < tmp)
		{
			max = tmp;
		}

	}
	return max;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v1;
	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		cin >> tmp;
		v1[i] = tmp;
	}
	MaxAdd(n, v1);


	return 0;
}