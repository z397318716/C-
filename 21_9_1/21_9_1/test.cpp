class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        int n = s.size();
        int begin = 0;
        int maxlen = 1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            if (i + 1 < n && s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                begin = i;
                maxlen = 2;
            }
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n; ++i) {
                int j = len + i - 1;
                if (j >= n)
                    break;
                if (s[i] != s[j])
                    dp[i][j] = false;
                else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j] && j - i + 1 > maxlen) {
                    begin = i;
                    maxlen = j - i + 1;
                }
            }
        }
        return s.substr(begin, maxlen);
    }
};