// 二叉树的前序遍历
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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        stack<TreeNode*> s1;
        TreeNode* tmp = root;
        s1.push(tmp);
        while (!s1.empty()) {
            tmp = s1.top();
            s1.pop();
            res.push_back(tmp->val);
            if (tmp->right)
                s1.push(tmp->right);
            if (tmp->left)
                s1.push(tmp->left);
        }
        return res;
    }
};