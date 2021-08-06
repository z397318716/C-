#include <iostream>

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        queue<tuple<int, int, int>> q1;
        vector<vector<bool>> flag(n, vector<bool>(1 << n));
        for (int i = 0; i < n; ++i) {
            q1.push({ i, 1 << i, 0 });
            flag[i][1 << i] = true;
        }

        while (!q1.empty()) {
            auto [cur, mask, dist] = q1.front();
            q1.pop();

            if (mask == (1 << n) - 1)
                return dist;
            for (auto x : graph[cur]) {
                int nextmask = mask | (1 << x);
                if (!flag[x][nextmask]) {
                    q1.push({ x, nextmask, dist + 1 });
                    flag[x][nextmask] = true;
                }
            }
        }
        return 0;
    }
};
int main() {
	int x, z;
	short y;
	x = 127;
	y = -9;
	z = x + y;



	return 0;
}