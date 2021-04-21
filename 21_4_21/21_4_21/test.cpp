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
    bool recur(TreeNode* p, TreeNode* q) {
        // 递归判断两棵树是否相同
        if (!q)
            return true;
        else if (!p)
            return false;
        else if (p->val != q->val)
            return false;
        else
            return recur(p->left, q->left) && recur(p->right, q->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B || !A)
            return false;
        // 遍历 A 树, 直至遇到和 B树根结点相同的节点,进行递归判断 两颗字数是否相同
        stack<TreeNode*> st;
        st.push(A);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            if (cur->val == B->val) {
                if (recur(cur, B))
                    return true;
            }
            st.pop();
            if (cur->right)
                st.push(cur->right);
            if (cur->left)
                st.push(cur->left);
        }
        return false;
    }
};

int main() {




	return 0;
}