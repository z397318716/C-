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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> q1;
        q1.push(root);
        int count = 0;
        while (!q1.empty()) {
            int n = q1.size();
            for (int i = 0; i < n; ++i) {
                root = q1.front();
                q1.pop();
                if (root->left)
                    q1.push(root->left);
                if (root->right)
                    q1.push(root->right);

            }
            count++;
        }
        return count;
    }
};