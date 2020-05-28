/************************************************************************/
/*https://leetcode-cn.com/problems/n-repeated-element-in-size-2n-array/
在大小为 2N 的数组 A 中有 N+1 个不同的元素，其中有一个元素重复了 N 次。

返回重复了 N 次的那个元素。
/************************************************************************/

#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
	int repeatedNTimes(vector<int>& A) {
		size_t N = A.size() / 2;
		unordered_map<int, int> m1;
		for (auto &e : A)
		{
			m1[e]++;
		}
		for (auto &i : m1)
		{
			if (i.second == N)
				return i.first;
		}
		return 0;
	}
};