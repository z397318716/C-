/************************************************************************/
/* ��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ
������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤��
��һ�룬������2����������������0��
                                                                     */
/************************************************************************/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		map<int, int> m1;
		for (auto &e : numbers)
		{
			m1[e]++;
			if (m1[e] > numbers.size() / 2)
				return e;
		}
		return 0;
	}
};