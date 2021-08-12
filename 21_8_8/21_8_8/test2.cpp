//class Solution {
//public:
//    int numberOfArithmeticSlices(vector<int>& nums) {
//        /*
//        // 先将连续子序列 的等差子序列数目 算出来
//        int res = 0, tmp = 0;
//        for(int i = 2; i < nums.size(); ++i){
//            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
//                res += ++tmp;
//        }
//        // 计算不连续的 等差子序列数目
//        */
//        int res = 0;
//        vector<unordered_map<long long, int>> dp(nums.size());
//        for (int i = 0; i < nums.size(); ++i) {
//            int tmp = 0;
//            for (int j = 0; j < i; j++) {
//                long long d = (long long)nums[i] - nums[j];
//                unordered_map<long long, int>::iterator it = dp[j].find(d);
//                if (it == dp[j].end()) {
//                    tmp = 0;
//                }
//                else {
//                    tmp = it->second;
//                }
//                res += tmp;
//                dp[i][d] += tmp + 1;
//            }
//        }
//        return res;
//    }
//};