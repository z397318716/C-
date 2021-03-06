#include<iostream>
#include<vector>
using namespace std;
class Solution{
    void backTrack(vector<int> nums, vector<vector<int>>& res, vector<int>& tmp, int pos) {
        res.push_back(tmp);
        for (int i = pos; i < nums.size(); ++i) {
            tmp.push_back(nums[i]);
            backTrack(nums, res, tmp, i + 1);
            tmp.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<vector<int>>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        //res.push_back(tmp);
        backTrack(nums, res, tmp, 0);
        return res;
    }
};

