class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // �ҵ�һ�����±�λ�ö�Ӧ���ϵ����֣�
        // ���һ��λ��i �� nums[i] == i ˵���ڸ�������λ�� i֮��
        // ��� nums[i] != i �������� λ��i֮ǰ
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