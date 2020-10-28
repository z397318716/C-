#include<iostream>
#include<vector>

using namespace std;
/************************************************************************/
/* 以 1-3-5-4-2为例:
1. 将数组从后向前遍历, 找第一个降序段 nums[i] = 3 符合 nums[i] < nums[i+1]
2. 对下标为i之后的数组进行升序排列 sort(nums.begin()+i+1, nums.end())
3. 从i 开始遍历, 找到第一个 比 nums[i] 大的数  将此两数交换
   最后得到 1-4-2-3-5
   
   利用标志位判断 如果是全升序的数组 直接反转即可*/
/************************************************************************/
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		// 从后向前遍历查找第一个降序段
		int ptr = nums.size() - 2;
		int flag = 1;
		for (; ptr >= 0; ptr--)
		{
			if (nums[ptr] < nums[ptr + 1])
			{
				flag = 0;
				break;
			}
		}
		if (ptr >= 0)
		{
			sort(nums.begin() + ptr + 1, nums.end());
			for (auto it = nums.begin() + ptr; it != nums.end(); ++it)
			{
				if (*it > nums[ptr])
				{
					iter_swap(it, nums.begin() + ptr);
					break;
				}
			}
		}
		if (flag)
		{
			reverse(nums.begin(), nums.end());
		}
		/*
		// 从后向前 遍历 查找第一个降序段
		//vector<int>::iterator i = nums.begin();
		auto i = is_sorted_until(nums.rbegin(), nums.rend());
		if(i != nums.rend())
		{
		//vector<int>::iterator it;
		// 找到第一个大于 *i 的元素
		auto it = upper_bound(nums.rbegin(), i, *i);
		iter_swap(it, i);
		// 将最后一个降序段变为升序段
		reverse(nums.rbegin(), i);
		}
		else
		reverse(nums.begin(), nums.end());
		}
		*/
	}
};
int main()
{
	Solution A;
	vector<int> v1({ 1, 2, 3 });
	A.nextPermutation(v1);

	return 0;
}