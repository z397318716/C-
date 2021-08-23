//class Solution {
//public:
//    int Fib(int n, vector<int>& dp) {
//        if (n < 2)
//            return 1;
//        if (dp[n] != -1)
//            return dp[n];
//        return dp[n] = Fib(n - 1, dp) + Fib(n - 2, dp);
//    }
//    int jumpFloor(int number) {
//        /*
//        // 1. 动态规划
//        // dp[i] 表示第i级台阶的跳法总数
//        // 初始条件 dp[1] = 1  dp[0] = 0
//        // dp[i] = dp[i-1] + dp[i-2]
//        if(number < 3){
//            return number;
//        }
//        int a = 0, b= 1,c;
//        while(number--){
//            c = a + b;
//            a = b;
//            b = c;
//        }
//        return c;
//        */
//        // 2. 递归
//        vector<int> dp(45, -1);
//        return Fib(number, dp);
//
//    }
//};