//class Solution {
//public:
//    int numberOfArithmeticSlices(vector<int>& nums) {
//        int res = 0, tmp = 0;;
//        for (int i = 2; i < nums.size(); ++i) {
//            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
//                res += (++tmp);
//            else
//                tmp = 0;
//        }
//        return res;
//    }
//};