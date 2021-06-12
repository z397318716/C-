#include <iostream>
#include <vector>
using std::vector;
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
    vector<int> path;
    vector<vector<int>> res;
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return res;
    }
    void dfs(TreeNode* root, int target) {
        if (root == nullptr)
            return;
        target -= root->val;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && target == 0)
            res.push_back(path);
        dfs(root->left, target);
        dfs(root->right, target);
        path.pop_back();
    }
};