#include<iostream>
#include<vector>
using std::vector;
class Solution {
public:
    int HammingDistance(int n1, int n2) {
        n1 = n1 ^ n2;
        n2 = 0;
        while (n1) {
            n1 &= n1 - 1;
            n2++;
        }
        return n2;
    }
    int totalHammingDistance(vector<int>& nums) {
        /* 超时
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i; j <nums.size(); ++j){
                if(i == j)
                    continue;
                res += HammingDistance(nums[i], nums[j]);
            }
        }
        return res;
        */
        int res = 0;
        for (int i = 0; i < 30; ++i) {
            int tmp = 0; // 表示二进制第 i位上有多少个 1
            for (int j = 0; j < nums.size(); ++j) {
                if (((nums[j] >> i) & 1) == 1)
                    tmp++;
            }
            res += tmp * (nums.size() - tmp);
        }
        return res;
    }
};