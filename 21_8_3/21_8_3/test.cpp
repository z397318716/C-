class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 思路1: 对该数组进行排序, 从头和尾向中间与原数组进行比较
        //        不相同的位数即为最短的子数组长度
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == tmp[i]) {
                res++;
            }
            else
                break;
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] == tmp[i]) {
                res++;
            }
            else
                break;
        }
        if (res > nums.size())
            return 0;
        return nums.size() - res;
    }
};