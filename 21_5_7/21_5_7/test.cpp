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
        // ����������ʱ
        /*
        int i = 1;
        while(n != 0){
            if(Judge_Ugly(i))
                n--;
            i++;
        }
        return --i;
        */
        // 1. ���ö�̬�滮�ķ�ʽ
        // ά������ָ��, a,b,c ��ʼ��ָ��dp������Ԫ��1, ����0��
        // dp[i] = ����iǰ��ĳ������ *2 | *3 | *5 ��ֵ (����ֵȡ��С���Ǹ�)
        // ÿ��ʹ a ָ���ֵ *2, bָ���ֵ *3  c--- *5
        // dp[i] ������� a ָ���ֵ *2  �� a++;  bc ͬ��
        // ��֤ȡ�õ�dp���������Ҳ��ظ�
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
        // 2. ��С������
        vector<int> ugly = { 2,3,5 }; // ������
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