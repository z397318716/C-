#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        // 分组位运算
        // 1. 对数组所有数进行异或操作,得到所求两个值的异或结果
        int tmp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            tmp ^= nums[i];
        }
        // 2. 从异或结果中找出一位不为0的位
        int div = 1;
        while ((div & tmp) == 0)
            div <<= 1;
        vector<int> res;
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if ((nums[i] & div) == 0) {
                a ^= nums[i];
            }
            else {
                b ^= nums[i];
            }
        }
        res.push_back(a);
        res.push_back(b);
        return res;
    }
};