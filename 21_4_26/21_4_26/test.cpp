#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        // 中序遍历就是二叉搜索树的有序遍历
        // 1. 将有序节点先存放至vector 中, 最后改变指向即可
        // 2. 使用 pre 结点表示前驱结点

        if (!root)
            return nullptr;
        stack<Node*> st;
        //vector<Node*> tmp;
        Node* pre = nullptr;
        Node* head = nullptr;
        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            //tmp.push_back(root);
            if (head == nullptr)
                head = root;
            else
                pre->right = root;
            root->left = pre;
            pre = root;

            root = root->right;
        }
        /*
        for(int i = 0; i < tmp.size();++i){
            int j = i + 1;
            if(j < tmp.size()){
                tmp[i]->right = tmp[j];
                tmp[j]->left = tmp[i];
            }
            else if(j == tmp.size()){
                tmp[i]->right = tmp[0];
                tmp[0]->left = tmp[i];
            }
        }*/
        pre->right = head;
        head->left = pre;
        //return tmp[0];
        return head;
    }
};
// 根据层序遍历构建一颗二叉树,若左子节点没有用 -1表示
Node* Cbtree(vector<int> v1) {
    int pos = 0;
    int tmp = v1[pos++];
    Node* root = new Node(tmp);
    Node* res = root;
    queue<Node*> q1;
    q1.push(root);
    while (!q1.empty()) {
        root = q1.front();
        q1.pop();
        if (pos < v1.size()) {
            if (pos < v1.size() && v1[pos] != -1) {
                Node* left = new Node(v1[pos]);
                root->left = left;
                q1.push(root->left);
            }
            pos++;
            if (pos < v1.size() && v1[pos] != -1) {
                Node* right = new Node(v1[pos]);
                root->right = right;
                q1.push(root->right);
            }
            pos++;
        }
    }
    return res;
}

int main() {
    vector<int> v1({ 4,2,5,1,3 });
    Node* root = Cbtree(v1);
    Solution A;
    A.treeToDoublyList(root);

    return 0;
}