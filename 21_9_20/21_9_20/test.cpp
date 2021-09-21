class Solution {
public:
    bool Judge(int x, int y, const int k) {
        int res = 0;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        while (y) {
            res += y % 10;
            y /= 10;
        }
        if (res <= k)
            return true;
        return false;
    }
    int movingCount(int m, int n, int k) {
        // BFS
        int res = 0;
        queue<pair<int, int>> q1;
        vector<vector<int>> tag(m, vector<int>(n, true));
        //tag[0][0] = false;
        pair<int, int> root = make_pair(0, 0);
        q1.push(root);
        while (!q1.empty()) {
            pair<int, int> cur = q1.front();
            q1.pop();
            int l = cur.first;
            int r = cur.second;
            if (tag[l][r] == false) {
                continue;
            }
            res++;
            tag[l][r] = false;
            // 判断上下左右是否满足 k 的条件
            if (l - 1 >= 0 && r < n && Judge(l - 1, r, k)) {
                pair<int, int> t1 = make_pair(l - 1, r);
                q1.push(t1);
            }
            if (l + 1 < m && r < n && Judge(l + 1, r, k)) {
                pair<int, int> t1 = make_pair(l + 1, r);
                q1.push(t1);
            }
            if (l < m && r - 1 >= 0 && Judge(l, r - 1, k)) {
                pair<int, int> t1 = make_pair(l, r - 1);
                q1.push(t1);
            }
            if (l < m && r + 1 < n && Judge(l, r + 1, k)) {
                pair<int, int> t1 = make_pair(l, r + 1);
                q1.push(t1);
            }
        }
        return res;
    }
};