#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() <= 1)
			return true;
		// 保存最远可到达位置
		int far_max = nums[0];
		for (int i = 1; i < nums.size(); ++i){
			int tmp = 0;
			if (far_max >= nums.size() - 1)
				return true;
			if (far_max >= i){
				tmp = i + nums[i];
				far_max = max(far_max, tmp);
			} else
				return false;
		}
		return true;
	}
};


int main(){


	return 0;
}