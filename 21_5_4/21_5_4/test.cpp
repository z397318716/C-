#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int tmp = 0;
            for (int j = 0; j < nums.size(); ++j) {
                // ͳ�Ƶ�iλ�� �ж��ٸ�1
                if (((nums[j] >> i) & 1) == 1)
                    tmp++;
            }
            if (tmp % 3 == 1) {
                res |= 1 << i;
            }
        }
        return res;
    }
};