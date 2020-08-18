//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int findDuplicate(vector<int>& nums) {
//		/*
//		int res = 0;
//		// 暴力遍历 最后一个测试用例超时了
//		for(int i = 0; i < nums.size() - 1; ++i)
//		{
//		for(int j = i + 1; j < nums.size(); ++j)
//		{
//		if(nums[i] == nums[j])
//		{
//		res = nums[i];
//		break;
//		}
//
//		}
//		}
//		return res;
//		*/
//		// 二分法查找, 
//		// 这个题很特殊, 指明了 数组中的数num满足   1 <= num <= num.size()
//		/*
//		首先取 1 到 nums.size() 的中间值 mid
//		循环计数, 小于等于 mid 的元素个数为 k,如果 k >= mid , 重复数字在 [left, mid]间
//		重复上述过程, 找到重复数
//		*/
//		int right = nums.size() - 1;
//		int left = 1;
//		int mid = (right + left) / 2;
//		for (; left < right - 1; mid = (left + right) / 2)
//		{
//			int tmp = 0;
//			for (auto e : nums)
//			{
//				if (e <= mid)
//					tmp++;
//			}
//			if (tmp > mid)
//			{
//				right = mid;
//			} else
//			{
//				left = mid;
//			}
//		}
//		return right;
//	}
//};
//
//int main()
//{
//	Solution s1;
//	int a1[] = { 1, 3, 4, 2, 2 };
//	vector<int> v1(a1 + 0, a1 + sizeof(a1)/sizeof(a1[0]));
//	s1.findDuplicate(v1);
//	return 0;
//}