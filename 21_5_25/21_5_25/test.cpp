#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        // ��̬�滮, dp���鱣�浱ǰ�����������, ��ļ۸�ȡ��ǰ��֮ǰ��С��,
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