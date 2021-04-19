#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        int res = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) { // j <= i/2   // j < 4 模拟贪心的结果
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
                if (res < dp[i])
                    res = dp[i];
            }
        }
        return res;
    }
    int cuttingRope1(int n) {
        if (n < 4)
            return n - 1;
        long long res = 1;
        if (n == 4)
            return 4;
        while (n > 4) {
            res = res * 3 % 1000000007;
            n -= 3;
        }
        return (int)(res * n % 1000000007);
    }
};

int main() {
    Solution A;
    A.cuttingRope(10);

	return 0;
}
