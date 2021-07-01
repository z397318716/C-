class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        // 动态规划
        vector<vector<int>> dp(k + 1, vector<int>(n));
        // dp[i][j] 表示 第 i 轮传递 到 第 j 个玩家的 方案数, 所以 初始状态 dp[0][0] = 1;
        // 状态转移方程 dp[i+1][dst] = sum(dp[i][src])  限定条件 [src, dst] 属于 relation
        dp[0][0] = 1;
        for (int i = 0; i < k; ++i) {
            for (auto& e : relation) {
                int src = e[0], dst = e[1];
                dp[i + 1][dst] += dp[i][src];
            }
        }
        return dp[k][n - 1];
        /*
        // BFS
        // 1. 信息预处理, 使用 列表存储 有向边的关系, 能够在 O(1)时间内得到特定节点的相邻节点
        vector<vector<int>> edges(n);
        for(auto &e : relation){
            int src = e[0], dst = e[1];
            edges[src].push_back(dst);
        }
        int steps = 0;
        queue<int> que;
        que.push(0);
        while(!que.empty() && steps < k){
            steps++;
            int size = que.size();
            for(int i = 0; i < size; ++i){
                int index = que.front();
                que.pop();
                for(auto e : edges[index])
                    que.push(e);
            }
        }
        int ways = 0;
        if(steps == k){
            while(!que.empty()){
                if(que.front() == n-1)
                    ways++;
                que.pop();
            }

        }
        return ways;
        */
        /*
        // DFS
        // 1. 信息预处理, 使用 列表存储 有向边的关系, 能够在 O(1)时间内得到特定节点的相邻节点
        vector<vector<int>> edges(n);
        for(auto &e : relation){
            int src = e[0], dst = e[1];
            edges[src].push_back(dst);
        }
        int ways = 0;
        function<void(int, int)> DFS = [&](int index, int steps){
            if(steps == k){
                if(index == n-1)
                    ++ways;
                return;
            }
            for(int e : edges[index])
                DFS(e, steps + 1);
        };
        DFS(0, 0);
        return ways;
        */
    }
};