#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int maxProfit(int k, vector<int>& prices) {
	int size = prices.size();
	if (size <= 1)
		return 0;
	int **dp = new int*[size + 1];
	for (int i = 0; i < size; ++i)
	{
		dp[i] = new int[2];
	}
	int ***dp1 = new int **[size + 1];
	for (int i = 0; i < size; ++i)
	{
		dp1[i] = new int*[k + 1];
		for (int j = 0; j < k; j++)
		{
			dp1[i][j] = new int[2];
		}
	}
	// 相当于没有k 的约束情况
	if (k > size / 2)
	{
		for (int i = 0; i < size; ++i)
		{
			if (i == 0)
			{
				dp[i][0] = 0;
				dp[i][1] = -prices[i];
				continue;
			}
			int tmp = dp[i][0];
			dp[i][0] = max(dp[i][0], dp[i - 1][1] + prices[i]);
			dp[i][1] = max(dp[i][1], tmp - prices[i]);
		}
		return dp[size - 1][0];
	}
	dp1[0][0][0] = 0;
	dp1[0][0][1] = -prices[0];
	for (int i = 0; i < size; ++i)
	{
		for (int j = k; j >= 1; --j)
		{
			if (i == 0)
			{

				dp1[i][j][0] = 0;
				dp1[i][j][1] = -prices[i];
				continue;
			}
			dp1[i][j][0] = max(dp1[i - 1][j][0], dp1[i - 1][j][1] + prices[i]);
			dp1[i][j][1] = max(dp1[i - 1][j][1], dp1[i - 1][j - 1][0] - prices[i]);
		}
	}

	return dp1[size - 1][k][0];

}


int main()
{
	vector<int> v1({ 2, 4, 1 });
	cout << maxProfit(2, v1) << endl;

	return 0;
}