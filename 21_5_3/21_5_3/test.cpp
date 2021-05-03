#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        // ����λ����
        // 1. ����������������������,�õ���������ֵ�������
        int tmp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            tmp ^= nums[i];
        }
        // 2. ����������ҳ�һλ��Ϊ0��λ
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