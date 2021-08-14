class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> order(n, vector<int>(n));
        // order[i][j]  表示j朋友 在 i 朋友的亲近度排名（越小表示亲近程度越高)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                order[i][preferences[i][j]] = j;
            }
        }
        vector<int> match(n);
        for (auto i : pairs) {
            match[i[0]] = i[1];
            match[i[1]] = i[0];
        }
        int res = 0;
        for (int x = 0; x < n; ++x) {
            int y = match[x];
            int index = order[x][y];
            for (int i = 0; i < index; ++i) {
                int u = preferences[x][i];
                int v = match[u];
                if (order[u][x] < order[u][v]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};