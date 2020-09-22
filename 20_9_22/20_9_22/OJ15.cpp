#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() < 3)
			return res;
		sort(nums.begin(), nums.end());
		int left = 0, right = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] > 0)
				return res;
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			left = i + 1;
			right = nums.size() - 1;
			while (left < right)
			{

				if (nums[i] + nums[left] + nums[right] == 0)
				{
					vector<int> tmp({ nums[i], nums[left], nums[right] });
					res.push_back(tmp);
					while (left < right && nums[left] == nums[left + 1])
					{
						left++;
					}
					while (left < right && nums[right] == nums[right - 1])
					{
						right--;
					}
					left++;
					right--;
				} else if (nums[i] + nums[left] + nums[right] > 0)
					right--;
				else
					left++;

			}

		}
		return res;

		// 暴力解法, 超时
		/*
		vector<vector<int>> res;
		for(int i = 0; i < nums.size(); ++i)
		{
		for(int j = i + 1; j < nums.size(); ++j)
		{
		for(int k = j + 1; k < nums.size(); ++k)
		{
		if(nums[i] + nums[j] + nums[k] == 0)
		{
		vector<int> tmp({nums[i], nums[j],nums[k]});
		sort(tmp.begin(),tmp.end());
		if(find(res.begin(),res.end(),tmp) == res.end())
		res.push_back(tmp);
		}
		}
		}
		}
		return res;
		*/
	}
};