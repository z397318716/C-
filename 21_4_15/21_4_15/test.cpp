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

    vector<vector<int>> findContinuousSequence(int target) {
        // ����1: ˫ָ�뷨, 
        // ��Ϊ����������������, �������
        // 1. ����ָ�������� ��С�� target ��ָ�� �����ƶ� (���ӷ�Χ)
        // 2. ����ָ�������� �ʹ��� target ��ָ�� �����ƶ� (��С��Χ)
        // 3. ����ָ�������� �͵��� target ��ָ�� �����ƶ� ����¼��ǰԪ��
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
        // ����1: ���챻�ָ�������ַ���, Ȼ��append
        n %= s.size();
        string s1(s.begin(), s.begin() + n);
        string res(s.begin() + n, s.end());
        res.append(s1);
        return res;
    }
};