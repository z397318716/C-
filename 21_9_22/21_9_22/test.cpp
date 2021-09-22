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
class Solution {
    vector<vector<int>> res;
    vector<int> tmp;
public:
    void dfs(TreeNode* root, int target) {
        if (root == nullptr) {
            return;
        }
        target -= root->val;
        tmp.push_back(root->val);
        if (0 == target && root->left == nullptr && root->right == nullptr) {
            res.push_back(tmp);
        }
        dfs(root->left, target);
        dfs(root->right, target);
        tmp.erase(tmp.begin() + tmp.size() - 1);
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);

        return res;
    }
};