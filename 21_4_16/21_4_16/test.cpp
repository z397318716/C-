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
        /* roor ��ʾ������Ԫ����ǰ�������е�����
         _l,_r �ֱ��Ƕ�Ӧǰ��/���� �����ұ߽�*/
        if (in_l > in_r)
            return nullptr;
        // ���������
        TreeNode* node = new TreeNode(preorder[root]);
        // ȷ�����ڵ��� ���������λ��
        int pos = m1[preorder[root]];
        // ����������
        node->left = recur(root + 1, preorder, inorder, in_l, pos - 1);
        // ����������
        node->right = recur(root + pos - in_l + 1, preorder, inorder, pos + 1, in_r);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /* ����ǰ��ȷ����, ��������ȷ���������� */
        // ���� ���� ����������Ĺ�ϣ��
        for (int i = 0; i < inorder.size(); ++i) {
            m1[inorder[i]] = i;
        }
        // �ݹ鹹����
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
            ��������, ������������ĸ, �Դ���ĸ�����ܽ��б���, �Ը���������б�Ǳ�������λ�� */
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