#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    struct node {
        int x;
        int y;
    };
    bool sumw(int i, int j, const int k) {
        // 判断 ij数位之和是否大于k
        int sum = 0;
        while (i != 0 || j != 0) {
            sum += i % 10;
            i /= 10;
            sum += j % 10;
            j /= 10;
            if (sum > k)
                return false;
        }
        return true;
    }

    int movingCount(int m, int n, int k) {
        // 方法1: 广度优先遍历, 借助队列, 和标记数组实现,
        queue<node> q1;
        int res = 0;
        vector<vector<bool>> flag(m, vector<bool>(n, false)); // 标记是否访问过
        vector<vector<bool>> flag1(flag); // 标记当前位置数位和是否大于k
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (sumw(i, j, k))
                    flag1[i][j] = true;
            }
        }
        if (k >= 0) {
            node pos{ 0,0 };
            q1.push(pos);
            flag[0][0] = true;
            res++;
        }

        while (!q1.empty()) {
            node cur = q1.front();
            q1.pop();

            // 向下和向右试
            if (cur.x + 1 >= 0 && cur.x + 1 < m && cur.y >= 0 && cur.y < n &&
                flag1[cur.x + 1][cur.y] && !flag[cur.x + 1][cur.y]) {
                node tmp{ cur.x + 1, cur.y };
                q1.push(tmp);
                flag[cur.x + 1][cur.y] = true;
                res++;
            }

            if (cur.x >= 0 && cur.x < m && cur.y + 1 >= 0 && cur.y + 1 < n &&
                flag1[cur.x][cur.y + 1] && !flag[cur.x][cur.y + 1]) {
                node tmp{ cur.x, cur.y + 1 };
                q1.push(tmp);
                flag[cur.x][cur.y + 1] = true;
                res++;
            }
        }
        return res;
    }
};

int main() {

    Solution A;
    A.movingCount(36,11, 15);
    A.sumw(11, 1, 4);
	return 0;
}