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
//        // 1. ��̬�滮
//        // dp[i] ��ʾ��i��̨�׵���������
//        // ��ʼ���� dp[1] = 1  dp[0] = 0
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
//        // 2. �ݹ�
//        vector<int> dp(45, -1);
//        return Fib(number, dp);
//
//    }
//};