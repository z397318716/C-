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
    int kthLargest(TreeNode* root, int k) {
        if (root == nullptr)
            return 0;
        // 中序遍历进行排序， 取第k大
        // 非递归方式， 中序是  左根右， 反向是  右根左， 反向遍历到 第k个
        stack<TreeNode*> st;
        TreeNode* cur = root;
        int count = 1;
        int res = 0;
        while (cur != nullptr || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->right;
            }
            cur = st.top();
            st.pop();
            k--;
            if (k == 0) {
                res = cur->val;
                break;
            }
            cur = cur->left;
        }
        return res;
    }
};