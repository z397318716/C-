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
    int findSecondMinimumValue(TreeNode* root) {
        int res = -1;
        // ±éÀú
        // Ç°Ðò
        set<int> s1;
        TreeNode* cur;
        queue<TreeNode*> q1;
        q1.push(root);
        while (!q1.empty()) {
            cur = q1.front();
            q1.pop();
            s1.insert(cur->val);
            if (cur->right)
                q1.push(cur->right);
            if (cur->left) {
                q1.push(cur->left);
            }
        }
        int tmp = 0;
        for (auto it : s1) {
            tmp++;
            if (tmp == 2)
                res = it;
        }
        return res;
    }
};