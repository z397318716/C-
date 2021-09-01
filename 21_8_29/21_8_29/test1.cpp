//class Solution {
//public:
//    int longestCommonSubsequence(string text1, string text2) {
//        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
//        int res = 0;
//        for (int i = 1; i < text1.size() + 1; ++i) {
//            for (int j = 1; j < text2.size() + 1; ++j) {
//                if (text1[i - 1] == text2[j - 1]) {
//                    dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
//                    res = max(dp[i][j], res);
//                }
//                else {
//                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                }
//            }
//        }
//        return res;
//    }
//};
//class Solution {
//public:
//    int findRepeatNumber(vector<int>& nums) {
//        /*
//        sort(nums.begin(), nums.end());
//        for(int i = 1;i < nums.size(); ++i){
//            if(nums[i-1] == nums[i])
//                return nums[i];
//        }
//        return -1;
//        */
//        int i = 0;
//        while (i < nums.size()) {
//            if (nums[i] == i) {
//                i++;
//                continue;
//            }
//            if (nums[nums[i]] == nums[i])
//                return nums[i];
//            swap(nums[i], nums[nums[i]]);
//        }
//        return 0;
//    }
//};