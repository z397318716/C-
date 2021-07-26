class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        // �ҳ� target ��arr �������������
        // ��̬�滮 �� �����������---��ʱ O��mn)
        // dp[i][j] ��ʾ target[0:i] �� arr[0:j] �����������
        // dp[i][j] = dp[i-1][j-1] + 1 (tar[i] == arr[j])
        // dp[i][j] = max(dp[i-1][j], dp[i][j-1]) (tar[i] != arr[j])
        /*
        vector<vector<int>> dp(target.size()+1, vector<int>(arr.size()+1, 0));
        for(int i = 1; i <= target.size(); ++i){
            for(int j = 1; j <= arr.size(); ++j){
                if(target[i-1] == arr[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return target.size()-dp[target.size()][arr.size()];
        */
        // ��̬�滮 + ̰��
        unordered_map<int, int> m1;
        vector<int> dp;
        for (int i = 0; i < target.size(); ++i) {
            m1[target[i]] = i;
        }
        for (int val : arr) {
            if (m1.count(val) == 1) {
                int pos = m1[val];
                vector<int>::iterator it;
                it = lower_bound(dp.begin(), dp.end(), pos);
                if (it != dp.end()) {
                    *it = pos;
                }
                else {
                    dp.push_back(pos);
                }
            }
        }
        return target.size() - dp.size();
    }
};