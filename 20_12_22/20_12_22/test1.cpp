#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0)
			return 0;
		if (amount < 0)
			return -1;
		int res = INT_MAX;
		vector<int> dp(amount + 1, amount + 1);
		dp[0] = 0;
		for (int i = 0; i < dp.size(); i++)
		{
			for (int coin : coins)
			{
				// 子问题无解
				if (i - coin < 0)
					continue;
				dp[i] = min(dp[i], 1 + dp[i - coin]);
			}
		}
		return dp[amount] == amount + 1 ? -1 : dp[amount];
	}
};