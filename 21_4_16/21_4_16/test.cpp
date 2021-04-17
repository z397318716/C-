#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using std::vector;
using std::unordered_map;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_map<int, int> m1;
public:
    TreeNode* recur(int root, const vector<int> preorder, const vector<int> inorder,
        int in_l, int in_r) {
        /* roor 表示根所在元素在前序数组中的索引
         _l,_r 分别是对应前序/中序 的左右边界*/
        if (in_l > in_r)
            return nullptr;
        // 构建根结点
        TreeNode* node = new TreeNode(preorder[root]);
        // 确定根节点在 中序遍历的位置
        int pos = m1[preorder[root]];
        // 构建左子树
        node->left = recur(root + 1, preorder, inorder, in_l, pos - 1);
        // 构建右子树
        node->right = recur(root + pos - in_l + 1, preorder, inorder, pos + 1, in_r);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /* 根据前序确定根, 根据中序确定左右子树 */
        // 构建 中序 结点与索引的哈希表
        for (int i = 0; i < inorder.size(); ++i) {
            m1[inorder[i]] = i;
        }
        // 递归构建树
        return recur(0, preorder, inorder, 0, inorder.size() - 1);
    }


    vector<vector<char>> Board;
    string Word;
public:
    bool DFS(int row, int col, int k) {
        if (row < 0 || col < 0 || row >= Board.size() || col >= Board[0].size() ||
            Board[row][col] != Word[k])
            return false;
        if (k == Word.size() - 1)
            return true;
        Board[row][col] = '\0';
        int flag[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
        bool res = DFS(row + 1, col, k + 1) || DFS(row - 1, col, k + 1) || DFS(row, col + 1, k + 1) ||
            DFS(row, col - 1, k + 1);
        Board[row][col] = Word[k];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        /* DFS
            遍历数组, 遇到单词首字母, 以此字母向四周进行遍历, 以辅助数组进行标记遍历过的位置 */
        this->Board = board;
        this->Word = word;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (DFS(i, j, 0))
                    return true;
            }
        }
        return false;
    }
};