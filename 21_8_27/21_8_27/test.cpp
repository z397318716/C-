class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k == 0 || k > input.size())
            return res;
        priority_queue<int, vector<int>, less<int>> heap;
        for (const auto e : input) {
            if (heap.size() < k)
                heap.push(e);
            else {
                if (e < heap.top()) {
                if (e < heap.top()) {
                    heap.pop();
                    heap.push(e);
                }
            }
        }
        while (!heap.empty()) {
            res.push_back(heap.top());
            heap.pop();
        }
        return res;
    }
};


/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @param o1 int整型
     * @param o2 int整型
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        return rever(root, o1, o2)->val;
    }
    TreeNode* rever(TreeNode* root, int o1, int o2) {
        if (root == nullptr || root->val == o1 || root->val == o2) {
            return root;
        }
        TreeNode* left = rever(root->left, o1, o2);
        TreeNode* right = rever(root->right, o1, o2);
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;
        return root;
    }
};