class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param n int����
     * @return int����
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