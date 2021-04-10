#include<iostream>
#include<stack>

using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        // 方法1: 层序遍历的思想, 左右孩子入栈, 并交换
        /*
        stack<TreeNode*> st;
        if(root)
            st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            if(cur->right)
                st.push(cur->right);
            if(cur->left)
                st.push(cur->left);
            TreeNode* tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
        }
        return root;
        */
        // 方法2: 递归
        if (root == nullptr)
            return nullptr;
        TreeNode* tmp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(tmp);
        return root;
    }

    // 递归比较两个树是否相同
    bool isjing(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr)
            return true;
        if (t1 == nullptr || t2 == nullptr || t1->val != t2->val)
            return false;
        return isjing(t1->left, t2->right) && isjing(t2->left, t1->right);
    }
    bool isSymmetric(TreeNode* root) {
        // 递归判断
        if (root == nullptr)
            return true;
        return isjing(root->left, root->right);
    }
};