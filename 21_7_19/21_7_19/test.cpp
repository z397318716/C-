class Solution {
public:
    int maxNum(vector<int>& nums, int pos, int k) {
        int res = 1;
        for (int i = pos - 1; i >= 0; --i) {
            if (nums[i] + k >= nums[pos]) {
                res++;
                k -= nums[pos] - nums[i];
            }
            else
                break;
        }
        return res;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int res = 0;
        if (nums.empty())
            return res;
        sort(nums.begin(), nums.end());
        // 统计出每个 元素为 高频元素的 频数, 如果出现  数组大小的频数, 直接返回
        int i = nums.size() - 1;
        while (i >= 0) {
            int tmp = 0;
            while (i - 1 >= 0 && nums[i - 1] == nums[i]) {
                i--;
                tmp++;
            }
            res = max(res, maxNum(nums, i, k) + tmp);
            if (res == nums.size())
                return res;
            i--;
        }
        return res;
    }
};