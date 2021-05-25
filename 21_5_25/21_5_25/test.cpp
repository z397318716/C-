#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        // 动态规划, dp数组保存当前卖的最大利润, 买的价格取当前天之前最小的,
        //vector<int> res(prices.size(), 0);
        int res1 = 0;
        int buy_min = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            buy_min = min(buy_min, prices[i]);
            //dp[i] = max(dp[i], prices[i] - buy_min);
            res1 = max(res1, prices[i] - buy_min);
        }
        return res1;
    }
};