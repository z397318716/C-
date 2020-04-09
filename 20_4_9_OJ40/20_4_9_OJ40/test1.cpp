#include<iostream>
#include<vector>
using namespace std;

void LIS(vector<int>& v)
{
	//¶¯Ì¬¹æ»®
	vector<int> dp(v.size(), 1);
	int sum = 1;
	for (size_t i = 1; i < v.size(); i++)
	{
		for (size_t j = 0; j<i; j++)
		if (v[i]>v[j])
			dp[i] = max(dp[i], dp[j] + 1);
		sum = max(sum, dp[i]);
	}
	cout << sum << endl;
}


int main()
{
	int n;
	while (cin >> n)
	{
		getchar();
		vector<int> v(n);
		for (size_t i = 0; i < n; i++)
			cin >> v[i];
		LIS(v);
	}
	return 0;
}