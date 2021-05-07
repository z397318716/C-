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
        // 动态规划
        // 利用 dp数组保存到当前位置的最大礼物价值
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[grid.size()][grid[0].size()];
    }
    int lengthOfLongestSubstring(string s) {
        // 双指针维护一个子串, 遍历字符串在栓指针维护的子串中找有没有出现当前字符
        // 如果子串中出现, 左指针移动到第一个重复元素的后面
        // 如果没有出现, 右指针向后移动, 长度加1
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