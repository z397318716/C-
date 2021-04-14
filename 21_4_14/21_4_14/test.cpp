#include<iostream>
#include<stack>
#include<vector>

using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        // 中序遍历就是二叉搜索数的递增排序    左 根 右
        // 则 右 根 左 就是其倒序, 也就是求第K个数
        vector<int> res;
        stack<TreeNode*> st;
        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root->right;
            }
            root = st.top();
            res.push_back(root->val);
            st.pop();
            root = root->left;
        }
        return res[k - 1];
    }
    int maxDepth(TreeNode* root) {
        // 方法一: 层序遍历记录层数
        // 1. 栈实现(右子树先入栈)  2. 队列实现(左子树先入栈)
        if (!root)
            return 0;
        queue<TreeNode*> q1;
        q1.push(root);
        int res = 0;
        while (!q1.empty()) {
            int len = q1.size();
            for (int i = 0; i < len; ++i) {
                root = q1.front();
                q1.pop();
                if (root->left)
                    q1.push(root->left);
                if (root->right)
                    q1.push(root->right);
            }
            res++;
        }
        return res;
    }
};