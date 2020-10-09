/************************************************************************/
/* ����һ���������飬����Ҫ�� ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������                                                                     */
/************************************************************************/
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int res = 0;
		if (nums.size() < 2)
			return nums.size();
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] == nums[res])
			{
				continue;
			} else
			{
				//res++;
				nums[++res] = nums[i];
			}
		}
		return res + 1;
	}
};
