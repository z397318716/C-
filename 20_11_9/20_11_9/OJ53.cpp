#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		// ¶¯Ì¬¹æ»®, 
		vector<int> res(nums.size(), 0);
		res[0] = nums[0];
		int tmp = res[0];
		for (int i = 1; i < nums.size(); ++i){
			res[i] = max(nums[i], nums[i] + res[i - 1]);
			if (res[i] > tmp)
				tmp = res[i];
		}
		return tmp;
	}
};
int main(){


	return 0;
}