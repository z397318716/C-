#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int res = 0;

		// 二分查找----注意判断target 在哪一段有序的空间里
		int size = (int)nums.size();
		if (!size)
		{
			return -1;
		} else if (size == 1)
			return target == nums[0] ? 0 : -1;
		int left = 0;
		int right = size - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (target == nums[mid])
				return mid;
			if (nums[0] <= nums[mid])
			{
				if (nums[0] <= target && nums[mid] > target)
				{
					right = mid - 1;
				} else
				{
					left = mid + 1;
				}
			} else
			{
				if (nums[mid] < target && nums[size - 1] >= target)
				{
					left = mid + 1;
				} else
					right = mid - 1;
			}
		}
		return -1;
		// 暴力解法, 直接遍历---时间复杂度O(N)  空间复杂度O(1)
		/*
		for(int i = 0; i < nums.size(); ++i)
		{
		if(nums[i] == target)
		{
		return i;
		}
		}
		return -1;
		*/
	}
};

int main()
{


	return 0;
}