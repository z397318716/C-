//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        if (nums.empty())
//            return 0;
//        int len = nums.size();
//        vector<int> dp(len);
//        // dp[i] = max(dp[i-1], dp[i-1]+nums[i])
//        dp[0] = nums[0];
//        int res = nums[0];
//        for (int i = 1; i < len; ++i) {
//            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
//            res = max(res, dp[i]);
//        }
//        return res;
//    }
//    int maxProfit(vector<int>& prices) {
//        // 暴力， dp[i][j] 表示 第 i天 到 j天 间交易的最大利润
//        if (prices.empty())
//            return 0;
//        int len = prices.size();
//        vector<int> dp(len);
//        dp[0] = 0;
//        int minnum = prices[0];
//        for (int i = 1; i < len; ++i) {
//            minnum = min(minnum, prices[i]);
//            dp[i] = max(prices[i] - minnum, dp[i - 1]);
//        }
//        return dp[len - 1];
//    }
//    int numWays(int n) {
//        // dp[i] = dp[i-1] + dp[i-2]; dp[0] = 1; dp[1] = 1;
//        // 相当于菲薄纳妾 数列
//        if (n < 2)
//            return 1;
//        int a1 = 1;
//        int a2 = 1;
//        int a3;
//        for (int i = 2; i <= n; ++i) {
//            a3 = (a1 + a2) % 1000000007;
//            a1 = a2;
//            a2 = a3;
//        }
//        return a2;
//    }
//    int fib(int n) {
//        if (n < 2)
//            return n;
//        int a1 = 0;
//        int a2 = 1;
//        int a3;
//        for (int i = 2; i <= n; ++i) {
//            a3 = (a1 + a2) % 1000000007;
//            a1 = a2;
//            a2 = a3;
//        }
//        return a2;
//    }
//    bool recur(TreeNode* left, TreeNode* right) {
//        if (left == nullptr && right == nullptr)
//            return true;
//        if (left == nullptr || right == nullptr || left->val != right->val)
//            return false;
//        return recur(left->left, right->right) && recur(left->right, right->left);
//    }
//    bool isSymmetric(TreeNode* root) {
//        if (root == nullptr)
//            return true;
//        return recur(root->left, root->right);
//    }
//
//};