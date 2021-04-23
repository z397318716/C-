#include<iostream>
#include<vector>
#include<queue>
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
    vector<int> levelOrder(TreeNode* root) {
        // 层序遍历--借助队列实现
        queue<TreeNode*> q1;
        vector<int> res;
        if (root)
            q1.push(root);
        while (!q1.empty()) {
            root = q1.front();
            q1.pop();
            res.push_back(root->val);
            if (root->left)
                q1.push(root->left);
            if (root->right)
                q1.push(root->right);
        }
        return res;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        // 层序遍历, 将每层结果记录,奇数层顺序存储,偶数层逆序存储
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode*> q1;
        q1.push(root);
        int floor = 0;
        while (!q1.empty()) {
            int len = q1.size();
            vector<int> tmp;
            for (int i = 0; i < len; ++i) {
                root = q1.front();
                q1.pop();
                tmp.push_back(root->val);
                if (root->left)
                    q1.push(root->left);
                if (root->right)
                    q1.push(root->right);
            }
            if (floor % 2 == 1)
            {
                vector<int> rtmp(tmp.rbegin(), tmp.rend());
                tmp = rtmp;
            }
            res.push_back(tmp);
            floor++;
        }
        return res;
    }
};
// 根据层序遍历构建一颗二叉树,若左子节点没有用 -1表示
TreeNode* Cbtree(vector<int> v1) {
    int pos = 0;
    int tmp = v1[pos++];
    TreeNode* root = new TreeNode(tmp);
    TreeNode* res = root;
    queue<TreeNode*> q1;
    q1.push(root);
    while (!q1.empty()) {
        root = q1.front();
        q1.pop();
        if (pos < v1.size()) {
            if (pos < v1.size() && v1[pos] != -1) {
                TreeNode* left = new TreeNode(v1[pos]);
                root->left = left;
                q1.push(root->left);
            }
            pos++;
            if (pos < v1.size() && v1[pos] != -1) {
                TreeNode* right = new TreeNode(v1[pos]);
                root->right = right;
                q1.push(root->right);
            } 
            pos++;
        }
    }
    return res;
}

int main() {
    vector<int> v1({ 1,2,3,4,-1,-1,5 });
    TreeNode* root = Cbtree(v1);
    Solution A;
    A.levelOrder1(root);

    return 0;
}