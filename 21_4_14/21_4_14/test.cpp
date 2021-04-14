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
        // ����������Ƕ����������ĵ�������    �� �� ��
        // �� �� �� �� �����䵹��, Ҳ�������K����
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
        // ����һ: ���������¼����
        // 1. ջʵ��(����������ջ)  2. ����ʵ��(����������ջ)
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