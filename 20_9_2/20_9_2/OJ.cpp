#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int movesToMakeZigzag(vector<int>& nums) {
		// 将奇,偶索引元素分别取出记为 a, b, 按位进行比较
		// 情况一: 奇数索引 a[i] < b[i] && a[i] < b[i+1]
		// 情况二: 奇数索引 a[i] > b[i] && a[i] > b[i+1]
		// 将满足两种情况的操作次数记录, 返回最小的

		vector<int> odd_index;  // 奇数索引
		vector<int> even_index; // 偶数索引
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i % 2 == 0)
				even_index.push_back(nums[i]);
			else
				odd_index.push_back(nums[i]);
		}
		// 奇数索引元素数量 <= 偶数索引元素数量
		int odd_size = odd_index.size();
		int even_size = even_index.size();
		int count1 = 0;
		int count2 = 0;
		for (int i = 0; i < odd_size; ++i)
		{
			if (i == even_size - 1 && odd_index[i] <= even_index[i])
			{
				int tmp = even_index[i] - odd_index[i] + 1;
				even_index[i] -= tmp;
				count1 += tmp;
				break;
			}
			if (odd_index[i] <= even_index[i])
			{
				int tmp = even_index[i] - odd_index[i] + 1;
				even_index[i] -= tmp;
				count1 += tmp;
			}
			if (i + 1 < even_size && odd_index[i] <= even_index[i + 1])
			{
				int tmp = even_index[i + 1] - odd_index[i] + 1;
				even_index[i + 1] -= tmp;
				count1 += tmp;
			}
		}
		odd_index.clear();
		even_index.clear();
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i % 2 == 0)
				even_index.push_back(nums[i]);
			else
				odd_index.push_back(nums[i]);
		}
		for (int i = 0; i < odd_size; ++i)
		{
			if (i == even_size - 1 && odd_index[i] >= even_index[i])
			{
				int tmp = odd_index[i] - even_index[i] + 1;
				odd_index[i] -= tmp;
				count2 += tmp;
				break;
			}
			if (odd_index[i] >= even_index[i])
			{
				int tmp = odd_index[i] - even_index[i] + 1;
				odd_index[i] -= tmp;
				count2 += tmp;
			}
			if (i + 1 < even_size && odd_index[i] >= even_index[i + 1])
			{
				int tmp = odd_index[i] - even_index[i + 1] + 1;
				odd_index[i] -= tmp;
				count2 += tmp;
			}
		}

		return min(count1, count2);
	}
};

int main()
{
	vector<int> nums({ 7, 4, 8, 9, 7, 7, 5 });
	Solution s1;
	cout << s1.movesToMakeZigzag(nums);
	

	return 0;
}