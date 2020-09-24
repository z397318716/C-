#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		if (nums.size() < 4)
			return res;
		// 使用四个指针, 
		// a从索引0 开始遍历, b = a + 1
		// c = b + 1; d = nums.size() - 1
		// 四个值相加大于 target时, d--; 小于时 c++,
		// c d 相遇时, 表示当前 a b 所处位置的解求解完毕, 进入 b 的循环
		// b的循环结束后, a++, 进入下一轮循环
		int a, b, c, d;

		for (int i = 0; i < nums.size() - 3; ++i)
		{
			a = i;
			//b = a + 1;

			if (a > 0 && nums[a] == nums[a - 1])
				continue;
			for (b = a + 1; b < nums.size() - 2; ++b)
			{
				if (b>a + 1 && nums[b] == nums[b - 1])
					continue;
				c = b + 1;
				d = nums.size() - 1;
				while (c < d)
				{
					if (nums[a] + nums[b] + nums[c] + nums[d] > target)
					{
						d--;
					} else if (nums[a] + nums[b] + nums[c] + nums[d] < target)
					{
						c++;
					} else
					{
						res.push_back({ nums[a], nums[b], nums[c], nums[d] });
						while (c < d && nums[c + 1] == nums[c])
							c++;
						while (c < d && nums[d - 1] == nums[d])
							d--;
						c++;
						d--;
					}
				}
			}
		}
		return res;
	}
};