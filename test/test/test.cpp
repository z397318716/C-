/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // ≤„–Ú±È¿˙–Ú¡–ªØ
        string res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> q1;
        q1.push(root);
        while (!q1.empty()) {
            TreeNode* tmp = q1.front();
            q1.pop();
            if (tmp) {
                q1.push(tmp->left);
                q1.push(tmp->right);
                res += to_string(tmp->val) + " ";
            }
            else {
                res += "x ";
            }

        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
            return nullptr;
        vector<string> v1;
        string str;
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] == ' ') {
                v1.push_back(str);
                str.clear();
            }
            else {
                str.push_back(data[i]);
            }
        }
        TreeNode* root = new TreeNode(atoi(v1[0].c_str()));
        int i = 0;
        queue<TreeNode*> q1;
        q1.push(root);
        while (!q1.empty()) {
            TreeNode* tmp = q1.front();
            q1.pop();
            if (v1[i * 2 + 1] != "x") {
                tmp->left = new TreeNode(atoi(v1[i * 2 + 1].c_str()));
                q1.push(tmp->left);
            }
            if (v1[i * 2 + 2] != "x") {
                tmp->right = new TreeNode(atoi(v1[i * 2 + 2].c_str()));
                q1.push(tmp->right);

            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));