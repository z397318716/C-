/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        unordered_map<TreeNode*, TreeNode*> m1; // 记录节点的父节点
        unordered_set<int> s1; // 记录访问过的节点， 避免出现向下遍历时，又向上遍历的类似情况
        function<void(TreeNode*)>dfs = [&](TreeNode* cur) {
            if (cur == nullptr)
                return;
            if (cur->left)
                m1[cur->left] = cur;
            if (cur->right)
                m1[cur->right] = cur;
            dfs(cur->left);
            dfs(cur->right);
        };
        dfs(root);
        function<void(TreeNode*, int)>Judge = [&](TreeNode* cur, int n) {
            if (cur == nullptr || s1.count(cur->val) == 1)
                return;
            s1.insert(cur->val);
            if (n == 0) {
                res.push_back(cur->val);
                return;
            }
            Judge(cur->left, n - 1);
            Judge(cur->right, n - 1);
            if (cur != root) {
                Judge(m1[cur], n - 1);
            }
        };
        Judge(target, k);
        return res;
    }
};