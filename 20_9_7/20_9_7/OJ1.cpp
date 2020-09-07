#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		// ����һ: ������,����ѭ������   O(n2)  O(1)
		/*
		vector<int> res;
		res.resize(2);
		int tmp = 0;
		for (int i = 0; i < nums.size(); ++i)
		{

			tmp = target - nums[i];
			for (int j = 0; j < nums.size(); ++j)
			{
				if (i == j)
					continue;
				if (tmp == nums[j])
				{
					res[0] = i;
					res[1] = j;
					return res;
				}
			}
		}
		return res;
		*/

		// ������: ���߹�ϣ����   O(n)   O(n)
		vector<int> res;
		res.resize(2);
		map<int, int> m1;
		int tmp = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			tmp = target - nums[i];
			if (m1.find(tmp) != m1.end())
			{
				res[0] = m1[tmp];
				res[1] = i;
				return res;
			}
			m1[nums[i]] = i;
		}

		return res;
	}
};


int main()
{




	return 0;
}