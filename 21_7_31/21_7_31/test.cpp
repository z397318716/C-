/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct nodes {
    int row;
    int col;
    int val;
}node;
static bool cmp(const struct nodes& n1, const struct nodes& n2) {
    if (n1.col < n2.col)
        return true;
    else if (n1.col == n2.col && n1.row < n2.row)
        return true;
    else if (n1.col == n2.col && n1.row == n2.row && n1.val < n2.val)
        return true;
    else
        return false;
    return false;
}
class Solution {

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<struct nodes> pos;
        // 先对树进行遍历， 记录节点的 行，列，值
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* cur, int row, int col) {
            if (!cur)
                return;
            struct nodes tmp;
            tmp.row = row;
            tmp.col = col;
            tmp.val = cur->val;
            pos.emplace_back(tmp);
            //pos.emplace_back({row, col, cur->val});
            dfs(cur->left, row + 1, col - 1);
            dfs(cur->right, row + 1, col + 1);
        };
        dfs(root, 0, 0);
        sort(pos.begin(), pos.end(), cmp);

        vector<vector<int>> res;
        int lastcol = INT_MIN;
        for (const struct nodes& temp : pos) {
            if (temp.col != lastcol) {
                lastcol = temp.col;
                res.emplace_back();
            }
            res.back().push_back(temp.val);
        }
        return res;
    }
};