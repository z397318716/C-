#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void sortColors(vector<int>& nums) {
		/*
		vector<int> res(nums.size(), 0);
		int count_0 = 0, count_1 = 0, count_2 = 0;
		for(auto e: nums){
		if(e == 0)
		count_0++;
		else if(e == 1)
		count_1++;
		else if(e == 2)
		count_2++;
		}
		for(int i = count_0; i < count_0 + count_1; i++){
		res[i] = 1;
		}
		for(int i = count_0 + count_1; i < nums.size(); i++){
		res[i] = 2;
		}
		nums = res;
		*/
		// ˫ָ�뷨
		int ptr0 = 0;
		int ptr2 = nums.size() - 1;
		for (int i = 0; i < nums.size(); ++i){
			if (i > ptr2)
				return;
			if (nums[i] == 0){
				swap(nums[ptr0], nums[i]);
				ptr0++;
			} else if (nums[i] == 2){
				swap(nums[ptr2], nums[i]);
				if (nums[i] != 1)
					i--;
				ptr2--;
			}
		}
	}
};

int main(){
	Solution A;
	vector<int> arr({ 0, 1, 2, 0, 2, 1, 2, 0, 1 });
	A.sortColors(arr);

	return 0;
}