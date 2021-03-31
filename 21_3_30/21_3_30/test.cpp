#include<iostream>
#include<string>
#include<stack>

using namespace std;

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
    Node(char c) :
        data(c), left(nullptr), right(nullptr) {}
};
int i;
string s1;
Node* PreConstruct() {
    char tmp = s1[i];
    i++;
    if (tmp == '#')
        return nullptr;
    Node* root = new Node(tmp);
    root->left = PreConstruct();
    root->right = PreConstruct();
    return root;

}
void Order(Node* root) {
    if (!root)
        return;
    stack<Node*> st1;
    while (!st1.empty() || root) {
        while (root) {
            st1.push(root);
            root = root->left;
        }
        root = st1.top();
        st1.pop();
        cout << root->data << ' ';
        root = root->right;
    }
    cout << endl;
}
int main() {
    while (cin >> s1) {
        i = 0;
        // 调用先序遍历进行构造
        struct Node* root = PreConstruct();
        Order(root);
    }


    return 0;
}