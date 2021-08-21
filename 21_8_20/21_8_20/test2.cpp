#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;





int stoneGame(vector<int>& piles) {
    vector<vector<int>> dp(piles.size(), vector<int>(piles.size()));
    int res = 0;
    for (int i = 0; i < piles.size(); ++i) {
        dp[i][i] = piles[i];
        res += piles[i];
    }
    for (int i = piles.size() - 1; i >= 0; --i) {
        for (int j = i + 1; j < piles.size(); ++j) {
            dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
        }
    }
    res = (res - dp[0][piles.size() - 1]) / 2 + dp[0][piles.size() - 1];
    cout << res << '\n';
    return dp[0][piles.size() - 1];
}


int main() {
    vector<int> str({ 5,3,4,5 });
    //stoneGame(str);
    int a = 150 / 50 % 5;
    cout << a << endl;
    return 0;
}