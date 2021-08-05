class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> flag(n, 0);
        function<bool(int)>dfs = [&](int pos) {
            if (flag[pos] == 2)
                return true;
            if (flag[pos] == 1)
                return false;
            flag[pos] = 1;
            for (auto e : graph[pos]) {
                if (!dfs(e))
                    return false;
            }
            flag[pos] = 2;
            return true;
        };
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (dfs(i))
                res.push_back(i);

        }
        return res;
    }
};