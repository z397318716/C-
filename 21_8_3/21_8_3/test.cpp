class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // ˼·1: �Ը������������, ��ͷ��β���м���ԭ������бȽ�
        //        ����ͬ��λ����Ϊ��̵������鳤��
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