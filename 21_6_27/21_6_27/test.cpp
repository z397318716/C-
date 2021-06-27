class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int res = board.size() * board[0].size();
        reverse(board.begin(), board.end());
        for (int i = 0; i < board.size(); ++i) {
            if (i % 2 != 0) {
                reverse(board[i].begin(), board[i].end());
            }
        }
        vector<int> tmp;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                tmp.push_back(board[i][j]);
            }
        }
        unordered_set<int> s;
        queue<int> q;
        s.insert(1);
        q.push(1);
        int step = 0;
        int n = 1;
        while (!q.empty()) {
            if (n == 0)
                n = q.size();
            int cur = q.front();
            q.pop();
            for (int i = 1; i < 7; ++i) {
                int temp = cur + i;
                if (temp == res)
                    return step + 1;
                if (temp > res)
                    break;
                if (tmp[temp - 1] > 0) {
                    temp = tmp[temp - 1];
                    if (temp == res)
                        return step + 1;
                    if (!s.count(temp)) {
                        s.insert(temp);
                        q.push(temp);
                    }
                }
                if (!s.count(temp)) {
                    s.insert(temp);
                    q.push(temp);
                }
            }
            if (--n == 0)
                step++;
        }
        return -1;
    }
};