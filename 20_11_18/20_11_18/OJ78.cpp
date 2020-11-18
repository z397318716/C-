#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void backtrack(vector<int> nums, vector<int> &tmp, vector<vector<int>> &res, int start){
		res.push_back(tmp);
		for (int i = start; i < nums.size(); i++){
			tmp.push_back(nums[i]);
			backtrack(nums, tmp, res, i + 1);
			tmp.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> tmp;
		int start = 0;
		backtrack(nums, tmp, res, start);

		return res;
	}
};
int main(){


	return 0;
}