class Solution {
public:
    int minPairSum(vector<int>& nums) {

        // �������������, ��βԪ�� ��� һ��, ֱ������
        int res = 0;
        if (nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int tmp = nums[l++] + nums[r--];
            res = max(tmp, res);
        }
        return res;
    }
};