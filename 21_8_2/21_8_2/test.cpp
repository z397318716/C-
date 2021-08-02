#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <functional>
using namespace std;
class Solution {

public:
    using pii = pair<int, int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii> > eg(n + 1);
        vector<int> vis(n + 1);
        int ans = 0;
        for (auto& x : times) {
            eg[x[0]].emplace_back(x[1], x[2]);
        }
        priority_queue<pii, vector<pii>, greater<pii> > q;
        q.emplace(0, k);
        while (q.size()) {
            auto [time, now] = q.top();
            q.pop();
            if (vis[now])continue;
            ans = max(ans, time);
            vis[now] = true;
            for (auto [next, nextTime] : eg[now]) {
                if (vis[next] == false) q.emplace(nextTime + time, next);
            }
        }
        return count(begin(vis) + 1, end(vis), true) == n ? ans : -1;
    }
    /*
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            // 利用 map 记录每个节点能到达的下个节点，并记录对应时间
            // dfs | bfs
            // 最后判断遍历的节点 数量 是否达到 n-1
            int step = 0;
            unordered_map<int, vector<int>> m1;
            map<pair<int, int>, int> m2;
            for (int i = 0; i < times.size(); ++i) {
                m1[times[i][0]].emplace_back(times[i][1]);
                m2[make_pair(times[i][0], times[i][1])] = times[i][2];
            }
            unordered_set<int> s1; // 记录出现过的节点， 防止成环
            map<int, int> ans; // 记录遍历过的节点，及到达时间
            function<void(int)>dfs = [&](int cur) {
                if (m1[cur].empty() || s1.count(cur) == 1) {
                    step = 0;
                    return;
                }
                s1.insert(cur);
                for (int e : m1[cur]) {
                    if (s1.count(e) == 1)
                        return;
                    step += m2[make_pair(cur, e)];
                    if (ans.find(e) == ans.end() || (ans.find(e) != ans.end() && ans[e] > step)) {
                        ans[e] = step;
                    }

                    dfs(e);
                }
            };
            dfs(k);

            if (ans.size() != n - 1)
                return -1;
            int num = 0;
            for (auto k : ans) {
                num = max(num, k.second);
            }
            return num;
        }
        */
};


int main() {
    //int a[3][3] = { {2,1,1} ,{2,3,1}, {3,4,1} };
    //vector<vector<int>> tmp({ {2,1,1} ,{2,3,1}, {3,4,1} });
    //vector<vector<int>> tmp({ {1,2,1} ,{2,1,3} });
    //vector<vector<int>> tmp({ {1,2,1} ,{2,3,2}, {1,3,2} });
    vector<vector<int>> tmp({ {1,2,1} ,{2,3,7}, {2,1,2},{2,1,2} });
    int n = 3, k = 2;
    Solution A;
    
    A.networkDelayTime(tmp, n, k);



    return 0;
}