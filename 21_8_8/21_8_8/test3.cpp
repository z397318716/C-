//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//    int longestPalindromeSubseq(string s) {
//        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
//        for (int i = s.size() - 1; i >= 0; --i) {
//            for (int j = i; j < s.size(); ++j) {
//                if (i == j) {
//                    dp[i][j] = 1;
//                    continue;
//                }
//                if (s[i] == s[j]) {
//                    dp[i][j] = dp[i + 1][j - 1] + 2;
//                }
//                else {
//                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//                }
//            }
//        }
//        return dp[0][s.size() - 1];
//    }
//};
//
//int main() {
//    Solution A;
//    A.longestPalindromeSubseq("bbbab");
//
//
//
//
//    return 0;
//}