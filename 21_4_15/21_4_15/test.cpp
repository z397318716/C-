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
        // ����1: ʹ�� target ��ȥ ��ǰֵ, ��ʣ��ֵ���Ҹò�ֵ�Ƿ����
        // ��ʱ��
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
        // ������: ˫ָ�뷨, ǰ��ָ����ӵ��� ����, ���ں�ָ����ǰ�ƶ�, С��ǰָ������ƶ�
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