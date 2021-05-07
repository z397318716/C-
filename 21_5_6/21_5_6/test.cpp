#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res(encoded.size() + 1);
        res[0] = first;
        for (int i = 1; i < res.size(); ++i) {
            res[i] = res[i - 1] ^ encoded[i - 1];
        }
        return res;
    }
    int maxValue(vector<vector<int>>& grid) {
        // ��̬�滮
        // ���� dp���鱣�浽��ǰλ�õ���������ֵ
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[grid.size()][grid[0].size()];
    }
    int lengthOfLongestSubstring(string s) {
        // ˫ָ��ά��һ���Ӵ�, �����ַ�����˨ָ��ά�����Ӵ�������û�г��ֵ�ǰ�ַ�
        // ����Ӵ��г���, ��ָ���ƶ�����һ���ظ�Ԫ�صĺ���
        // ���û�г���, ��ָ������ƶ�, ���ȼ�1
        if (s.empty())
            return 0;
        int l = 0, r = 0, res = 0;
        while(r < s.size()) {
            auto tmp = find(s.begin() + l, s.begin() + r, s[r]);
            if (tmp != s.begin() + r) {
                l = tmp - s.begin() + 1;
                if (r < l)
                    r = l;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};

int main() {
    string s1("bbbbb");
    Solution A;
    A.lengthOfLongestSubstring(s1);


    return 0;
}