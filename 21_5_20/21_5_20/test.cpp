class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> res(6);
        for (int i = 0; i < 6; ++i) {
            res[i] = 1.0 / 6.0;
        }

        for (int i = 2; i <= n; ++i) {
            vector<double> tmp(5 * i + 1, 0);
            for (int j = 0; j < res.size(); ++j) {
                for (int k = 0; k < 6; ++k) {
                    tmp[j + k] += res[j] / 6.0;
                }
            }
            res = tmp;
        }
        return res;
    }
};