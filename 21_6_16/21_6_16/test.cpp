class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int dp[piles.size()][piles.size()];
        for (int i = 0; i < piles.size(); ++i) {
            dp[i][i] = piles[i];
        }
        for (int i = piles.size() - 1; i >= 0; --i) {
            for (int j = i + 1; j < piles.size(); ++j) {
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][piles.size() - 1];
    }
};