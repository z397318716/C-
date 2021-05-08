#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool Judge_Ugly(int n) {
        if (n == 1)
            return true;
        while (n != 1) {
            if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0)
                return false;
            while (n % 2 == 0)
                n /= 2;
            while (n % 3 == 0)
                n /= 3;
            while (n % 5 == 0)
                n /= 5;
        }
        return true;
    }
    bool Judge_Ugly(int n) {
        if (n == 1)
            return true;
        while (n != 1) {
            if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0)
                return false;
            while (n % 2 == 0)
                n /= 2;
            while (n % 3 == 0)
                n /= 3;
            while (n % 5 == 0)
                n /= 5;
        }
        return true;
    }
    int nthUglyNumber(int n) {
        // 暴力方法超时
        /*
        int i = 1;
        while(n != 0){
            if(Judge_Ugly(i))
                n--;
            i++;
        }
        return --i;
        */
        // 1. 采用动态规划的方式
        // 维护三个指针, a,b,c 起始都指向dp数组首元素1, 索引0处
        // dp[i] = 数组i前面某个丑数 *2 | *3 | *5 的值 (三个值取最小的那个)
        // 每次使 a 指向的值 *2, b指向的值 *3  c--- *5
        // dp[i] 如果等于 a 指向的值 *2  则 a++;  bc 同理
        // 保证取得的dp数组有序且不重复
        /*
        vector<int> dp(n);
        dp[0] = 1;
        int a = 0, b = 0, c = 0;
        for(int i = 1; i < n; ++i){
            int n_2 = dp[a] * 2;
            int n_3 = dp[b] * 3;
            int n_5 = dp[c] * 5;
            dp[i] = min(min(n_2, n_3), n_5);
            if(dp[i] == n_2)
                a++;
            if(dp[i] == n_3)
                b++;
            if(dp[i] == n_5)
                c++;
        }
        return dp[n-1];
        */
        // 2. 最小堆来做
        vector<int> ugly = { 2,3,5 }; // 质因子
        priority_queue<long, vector<long>, greater<long>> heap;
        unordered_set<long> seen;
        heap.push(1);
        seen.insert(1);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            long cur = heap.top();
            heap.pop();
            res = (int)cur;
            for (int e : ugly) {
                long tmp = cur * e;
                if (!seen.count(tmp)) {
                    seen.insert(tmp);
                    heap.push(tmp);
                }
            }
        }
        return res;

    }
};

int main() {
    Solution A;
    A.nthUglyNumber(12);

    return 0;
}