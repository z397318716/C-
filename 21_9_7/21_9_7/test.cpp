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
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        TreeNode* tmp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(tmp);
        return root;
        /*
        if(root == nullptr)
            return root;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* tmp = st.top();
            st.pop();
            if(tmp->left)
                st.push(tmp->left);
            if(tmp->right)
                st.push(tmp->right);
            TreeNode* cur = tmp->left;
            tmp->left = tmp->right;
            tmp->right = cur;
        }
        return root;
        */
    }

    bool equal(TreeNode* A, TreeNode* B) {
        if (B == nullptr)
            return true;
        if (A == nullptr)
            return false;
        if (A->val != B->val)
            return false;
        return equal(A->left, B->left) && equal(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (B == nullptr || A == nullptr)
            return false;
        if (A->val == B->val && equal(A, B)) {
            return true;
        }
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> q1;
        q1.push(root);
        int level = 0;
        while (!q1.empty()) {
            int size = q1.size();
            vector<int> tmp;
            for (int i = 0; i < size; ++i) {
                TreeNode* cur = q1.front();
                q1.pop();
                tmp.emplace_back(cur->val);
                if (cur->left)
                    q1.push(cur->left);
                if (cur->right)
                    q1.push(cur->right);
            }
            if (level % 2 != 0)
                reverse(tmp.begin(), tmp.end());
            res.emplace_back(tmp);
            level += 1;
        }
        return res;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        // ≤„–Ú±È¿˙
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> q1;
        q1.push(root);
        while (!q1.empty()) {
            int size = q1.size();
            vector<int> temp;
            for (int i = 0; i < size; ++i) {
                TreeNode* tmp = q1.front();
                q1.pop();
                temp.push_back(tmp->val);
                if (tmp->left)
                    q1.push(tmp->left);
                if (tmp->right)
                    q1.push(tmp->right);
            }
            res.emplace_back(temp);
        }
        return res;
    }
};