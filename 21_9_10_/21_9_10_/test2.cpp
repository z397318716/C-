//class Solution {
//public:
//    int maxValue(vector<vector<int>>& grid) {
//        if (grid.empty())
//            return 0;
//        int row = grid.size(), col = grid[0].size();
//        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
//
//        for (int i = 0; i < row; ++i) {
//            for (int j = 0; j < col; ++j) {
//                dp[i + 1][j + 1] += max(dp[i][j + 1] + grid[i][j], dp[i + 1][j] + grid[i][j]);
//            }
//        }
//        return dp[row][col];
//    }
//
//    int translateNum(int num) {
//        string str;
//        while (num) {
//            int tmp = num % 10;
//            num /= 10;
//            str.push_back(tmp + '0');
//        }
//        reverse(str.begin(), str.end());
//
//        vector<int> dp(str.size() + 1, 1);
//        for (int i = 1; i < str.size(); ++i) {
//            int tmp = (str[i - 1] - '0') * 10 + (str[i] - '0');
//            if (tmp >= 10 && tmp <= 25) {
//                dp[i + 1] = dp[i] + dp[i - 1];
//            }
//            else
//                dp[i + 1] = dp[i];
//        }
//        return dp[str.size()];
//    }
//};