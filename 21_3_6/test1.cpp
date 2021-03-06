#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int dfs(vector<vector<int>>& memo, vector<vector<int>>& matrix, int i, int j) {
        if (memo[i][j] != 0)
            return memo[i][j];
        memo[i][j]++;
        if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])
            memo[i][j] = max(memo[i][j], dfs(memo, matrix, i - 1, j) + 1);
        if (i + 1 < matrix.size() && matrix[i + 1][j] > matrix[i][j])
            memo[i][j] = max(memo[i][j], dfs(memo, matrix, i + 1, j) + 1);
        if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])
            memo[i][j] = max(memo[i][j], dfs(memo, matrix, i, j - 1) + 1);
        if (j + 1 < matrix[0].size() && matrix[i][j + 1] > matrix[i][j])
            memo[i][j] = max(memo[i][j], dfs(memo, matrix, i, j + 1) + 1);
        return memo[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        int ans = 0;
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                ans = max(ans, dfs(memo, matrix, i, j));
        return ans;
    }
};
