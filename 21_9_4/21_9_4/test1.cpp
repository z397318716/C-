class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 找第一个与下标位置对应不上的数字，
        // 如果一个位置i 处 nums[i] == i 说明在该数字在位置 i之后
        // 如果 nums[i] != i 该数字在 位置i之前
        int i = 0;
        int len = nums.size();
        int j = len - 1;
        int mid;
        while (i <= j) {
            mid = i + (j - i) / 2;
            if (nums[mid] == mid) {
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
        }
        return i;
    }
};