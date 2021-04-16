#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
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

    vector<vector<int>> findContinuousSequence(int target) {
        // 方法1: 双指针法, 
        // 因为是连续正整数序列, 三种情况
        // 1. 左右指针区间内 和小于 target 右指针 向右移动 (增加范围)
        // 2. 左右指针区间内 和大于 target 左指针 向右移动 (减小范围)
        // 3. 左右指针区间内 和等于 target 左指针 向右移动 并记录当前元素
        int i = 1, j = 2;
        vector<vector<int>> res;
        while (i < j) {
            if ((i + j) * (j - i + 1) / 2 < target)
                j++;
            else if ((i + j) * (j - i + 1) / 2 > target)
                i++;
            else if ((i + j) * (j - i + 1) / 2 == target) {
                vector<int> tmp;
                for (int k = i; k <= j; ++k)
                    tmp.push_back(k);
                res.push_back(tmp);
                i++;
            }
        }
        return res;
    }
    string reverseLeftWords(string s, int n) {
        // 方法1: 构造被分割的两个字符串, 然后append
        n %= s.size();
        string s1(s.begin(), s.begin() + n);
        string res(s.begin() + n, s.end());
        res.append(s1);
        return res;
    }
};