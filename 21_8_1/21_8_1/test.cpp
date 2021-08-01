class Solution {
public:
    static bool cmp(pair<int, int> p1, pair<int, int> p2) {
        if (p1.second < p2.second)
            return true;
        if (p1.second == p2.second && p1.first < p2.first)
            return true;
        return false;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int, int> m1;
        vector<pair<int, int>> res;
        for (int i = 0; i < mat.size(); ++i) {
            int tmp = 0;
            for (int j = 0; j < mat[0].size(); ++j) {
                if (mat[i][j]) {
                    tmp++;
                }
                else
                    break;
            }
            res.emplace_back(make_pair(i, tmp));
        }
        sort(res.begin(), res.end(), cmp);
        vector<int> ans;
        for (auto e : res) {
            if (k--)
                ans.emplace_back(e.first);
            else
                break;
        }
        return ans;
    }
};