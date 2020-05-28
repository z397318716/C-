/************************************************************************/
/* https://leetcode-cn.com/problems/intersection-of-two-arrays/
力扣:   给定两个数组，编写一个函数来计算它们的交集。*/
/************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> m1;
		vector<int> v1;
		for (auto &e : nums1)
		{
			m1[e]++;
		}
		for (auto &i : nums2)
		{
			if (m1[i] > 0)
			{
				v1.push_back(i);
				m1[i] = 0;
			}
		}
		return v1;

	}
};