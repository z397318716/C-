//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int findDuplicate(vector<int>& nums) {
//		/*
//		int res = 0;
//		// �������� ���һ������������ʱ��
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
//		// ���ַ�����, 
//		// ����������, ָ���� �����е���num����   1 <= num <= num.size()
//		/*
//		����ȡ 1 �� nums.size() ���м�ֵ mid
//		ѭ������, С�ڵ��� mid ��Ԫ�ظ���Ϊ k,��� k >= mid , �ظ������� [left, mid]��
//		�ظ���������, �ҵ��ظ���
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