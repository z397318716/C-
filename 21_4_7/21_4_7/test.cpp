#include "mytest.h"
using namespace std;
class Solution {
    
public:
    int fib(int n) {
        // �ⷨһ: ��̬�滮-ʹ���˸��������Ž��, 
        // ʱ�临�Ӷ� O(N) �ռ临�Ӷ� O(N)
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
        // �ⷨ��:
        // �� F(N) = F(N - 1) + F(N - 2) ��֪, ֻ����������, ������ɵ������
        // �������Ĺ��� �൱�ڽ���������ÿ�����ƽ��һ��λ��,
        int res = 0, a1 = 1, a2 = 0;
        for (int i = 0; i < n; ++i) {
            a2 = (res + a1) % 1000000007;
            res = a1;
            a1 = a2;
        }
        return res;
    }
};