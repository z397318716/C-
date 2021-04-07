#include "mytest.h"
using namespace std;
class Solution {
    
public:
    int fib(int n) {
        // 解法一: 动态规划-使用了辅助数组存放结果, 
        // 时间复杂度 O(N) 空间复杂度 O(N)
        /*
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        vector<int> res;
        res.resize(n + 1, 0);
        res[0] = 0;
        res[1] = 1;
        for (int i = 2; i <= n; ++i) {
            res[i] = (res[i - 1] + res[i - 2]) % 1000000007;
        }
        return res[n];
        */
        // 解法二:
        // 由 F(N) = F(N - 1) + F(N - 2) 可知, 只需三个变量, 即可完成迭代求解
        // 迭代求解的过程 相当于将这三个数每次向后平移一个位置,
        int res = 0, a1 = 1, a2 = 0;
        for (int i = 0; i < n; ++i) {
            a2 = (res + a1) % 1000000007;
            res = a1;
            a1 = a2;
        }
        return res;
    }
};