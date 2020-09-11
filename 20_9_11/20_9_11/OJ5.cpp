#include<iostream>
#include<string>

using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		string res;
		string tmp;
		int left1 = 0, left2 = 0;
		int right1 = 0, right2 = 0;
		int left = 0, right = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			// 判断奇数字符回文
			left1 = i;
			right1 = i;
			left2 = i;
			right2 = i + 1;
			while (left1 >= 0 && right1 < s.size())
			{
				if (s[left1] == s[right1])
				{
					left1--;
					right1++;
				} else
				{
					left1++;
					right1--;
					break;
				}
			}
			while (left2 >= 0 && right2 < s.size())
			{
				if (s[left2] == s[right2])
				{
					left2--;
					right2++;
				} else if (left2 + 1 == right2 && s[left2] != s[right2])
				{
					right2--;
					break;
				}
				else
				{
					left2++;
					right2--;
					break;
				}
			}
			if (right1 - left1 > right - left)
			{
				left = left1 + 1;
				right = right1 - 1;
			}
			if (right2 - left2 > right - left)
			{
				left = left2;
				right = right2;
			}
		}

		return s.substr(left, right - left + 1);

		/*
		// 中心扩散, 超时  测试用例 102/103
		string res;
		string tmp;
		if(s.empty())
		return res;
		for(int i = 0; i < s.size(); ++i)
		{
		int pos1 = i;
		int pos2 = i;
		while(pos1 >= 0 && pos2 < s.size())
		{
		// 起初是一个字符的递增
		if(pos1 == pos2)
		{
		tmp.push_back(s[pos1]);
		if(res.size() < tmp.size())
		res = tmp;
		}
		else
		{
		if(s[pos1] == s[pos2])
		{
		//int c = s[pos1] - 'a';

		tmp.insert(0, 1, s[pos1]);
		tmp.push_back(s[pos2]);
		if(res.size() < tmp.size())
		res = tmp;
		}
		else
		{
		tmp.clear();
		break;
		}
		}
		pos1--;
		pos2++;
		}
		tmp.clear();
		}
		tmp.clear();
		for(int i = 0; i < s.size(); ++i)
		{
		int pos1 = i;
		int pos2 = i;
		while(pos1 >= 0 && pos2 < s.size())
		{
		// 起初是一个字符的递增
		if(pos1 == pos2 && i + 1 < s.size() && s[i] == s[i+1])
		{
		tmp.push_back(s[i]);
		tmp.push_back(s[i]);
		pos2++;
		if(res.size() < tmp.size())
		res = tmp;
		}
		else
		{
		if(pos1 == pos2)
		{
		tmp.push_back(s[pos1]);
		}
		else if(pos1 != pos2 && s[pos1] == s[pos2])
		{
		//int c = s[pos1] - 'a';

		tmp.insert(0, 1, s[pos1]);
		tmp.push_back(s[pos2]);
		if(res.size() < tmp.size())
		res = tmp;
		}
		else
		{
		tmp.clear();
		break;
		}
		}
		pos1--;
		pos2++;
		}
		tmp.clear();
		}
		*/
		//return res;
	}
};
int main()
{
	string s1("cbbd");
	Solution s;
	s.longestPalindrome(s1);


	return 0;
}