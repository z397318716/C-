/************************************************************************/
/* https://leetcode-cn.com/problems/first-unique-character-in-a-string/submissions/
����:   ����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��
/************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int> m1;
		for (auto &e : s)
		{
			m1[e]++;
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (m1[s[i]] == 1)
				return i;

		}
		return -1;
	}
};