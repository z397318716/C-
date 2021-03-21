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
    bool is(TreeNode* s, TreeNode* t) {
        // �ж��������Ƿ���ͬ
        if (s == nullptr && t == nullptr)
            return true;
        if (!s || !t)
            return false;
        if (s->val != t->val)
            return false;
        return is(s->left, t->left) && is(s->right, t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        stack<TreeNode*> s1;
        // ʹ��ǰ���������ȵĽ��
        if (s)
            s1.push(s);
        while (!s1.empty()) {
            s = s1.top();

            if (s->val == t->val) {
                if (is(s, t))
                    return true;
            }
            s1.pop();
            if (s->right)
                s1.push(s->right);
            if (s->left)
                s1.push(s->left);
        }
        return false;
    }
};