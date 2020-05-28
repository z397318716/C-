/************************************************************************/
/*https://leetcode-cn.com/problems/n-repeated-element-in-size-2n-array/
�ڴ�СΪ 2N ������ A ���� N+1 ����ͬ��Ԫ�أ�������һ��Ԫ���ظ��� N �Ρ�

�����ظ��� N �ε��Ǹ�Ԫ�ء�
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