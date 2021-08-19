/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     *
     * @param root TreeNode¿‡
     * @return int’˚–Õvector<vector<>>
     */
    vector<vector<int> > levelOrder(TreeNode* root) {
        // write code here
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> q1;
        q1.push(root);
        while (!q1.empty()) {
            int size = q1.size();
            vector<int> tmp;
            for (int i = 0; i < size; ++i) {
                TreeNode* cur = q1.front();
                tmp.push_back(cur->val);
                q1.pop();
                if (cur->left)
                    q1.push(cur->left);
                if (cur->right)
                    q1.push(cur->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};