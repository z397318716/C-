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
		// ʹ���ĸ�ָ��, 
		// a������0 ��ʼ����, b = a + 1
		// c = b + 1; d = nums.size() - 1
		// �ĸ�ֵ��Ӵ��� targetʱ, d--; С��ʱ c++,
		// c d ����ʱ, ��ʾ��ǰ a b ����λ�õĽ�������, ���� b ��ѭ��
		// b��ѭ��������, a++, ������һ��ѭ��
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