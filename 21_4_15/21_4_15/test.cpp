#include<iostream>
#include<algorithm>
#include<vector>
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
    int recur(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = recur(root->left);
        if (left == -1)
            return -1;
        int right = recur(root->right);
        if (right == -1)
            return -1;
        return abs(left - right) < 2 ? max(left, right) + 1 : -1;
    }
    bool isBalanced(TreeNode* root) {
        return recur(root) != -1;
    }


    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        // 方法1: 使用 target 减去 当前值, 在剩余值中找该差值是否存在
        // 超时了
        /*
        for(int i = 0; i < nums.size(); ++i){
            int tmp = target - nums[i];
            if(find(nums.begin(), nums.end(), tmp) != nums.end()){
                res.push_back(nums[i]);
                res.push_back(tmp);
                break;
            }
        }
        return res;
        */
        // 方法二: 双指针法, 前后指针相加等于 返回, 大于后指针向前移动, 小于前指针向后移动
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] > target)
                j--;
            else if (nums[i] + nums[j] < target)
                i++;
            else {
                res.push_back(nums[i]);
                res.push_back(nums[j]);
                break;
            }
        }
        return res;
    }
};