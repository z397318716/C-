/*
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
*/
class Solution {
    Node* head, * pre;
public:
    void order(Node* root) {
        if (root == nullptr)
            return;
        order(root->left);
        //
        if (head == nullptr) {
            head = root;
        }
        root->left = pre;
        if (pre != nullptr)
            pre->right = root;
        pre = root;
        //
        order(root->right);
    }
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)
            return nullptr;

        order(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};