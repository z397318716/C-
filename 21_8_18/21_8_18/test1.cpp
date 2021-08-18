class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return int整型
     */
    int Fibonacci(int n) {
        // write code here
        if (n < 2)
            return n;
        long long a = 0, b = 1;
        int c;
        for (int i = 2; i <= n; ++i) {
            c = (a + b) % 1000000007;
            a = b;
            b = c;
        }
        return c;
    }
};