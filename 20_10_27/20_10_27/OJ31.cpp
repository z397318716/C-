#include<iostream>
#include<vector>

using namespace std;
/************************************************************************/
/* �� 1-3-5-4-2Ϊ��:
1. ������Ӻ���ǰ����, �ҵ�һ������� nums[i] = 3 ���� nums[i] < nums[i+1]
2. ���±�Ϊi֮������������������ sort(nums.begin()+i+1, nums.end())
3. ��i ��ʼ����, �ҵ���һ�� �� nums[i] �����  ������������
   ���õ� 1-4-2-3-5
   
   ���ñ�־λ�ж� �����ȫ��������� ֱ�ӷ�ת����*/
/************************************************************************/
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		// �Ӻ���ǰ�������ҵ�һ�������
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
		// �Ӻ���ǰ ���� ���ҵ�һ�������
		//vector<int>::iterator i = nums.begin();
		auto i = is_sorted_until(nums.rbegin(), nums.rend());
		if(i != nums.rend())
		{
		//vector<int>::iterator it;
		// �ҵ���һ������ *i ��Ԫ��
		auto it = upper_bound(nums.rbegin(), i, *i);
		iter_swap(it, i);
		// �����һ������α�Ϊ�����
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