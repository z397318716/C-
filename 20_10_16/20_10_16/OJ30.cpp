#include<iostream>
#include<string>
#include<vector>
#include<map>


//    172 / 176 个通过测试用例---------超出时间限制
using namespace std;
class Solution {
public:
	// 判断words单词是否都用完了
	bool judge(map<string, int> &m1)
	{
		for (auto e : m1)
		{
			if (e.second != 0)
				return false;
		}
		return true;
	}
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		if (words.empty() || s.empty())
			return res;
		int len = words[0].size();
		int cur = 0;
		map<string, int> m;
		map<string, int> m1;
		for (auto &e : words)
		{
			m[e]++;
		}
		m1 = m;
		int ptr = 0;    // 保存s中起始遍历位置
		while (cur + len <= s.size())
		{

			int tmp = cur;  // 保存在s中对比每个单词的起始位置， 用于比较判断是否找到有单词与s中的子串相等
			for (auto &k : m1)
			{
				if (k.second != 0 && s.compare(cur, len, k.first) == 0)
				{
					k.second--;
					cur += len;
					break;
				}
			}
			// 该位置没有找到words中的单词， 清空m1所有标志，
			if (tmp == cur)
			{
				m1 = m;
				ptr++;
				cur = ptr;
			}
			if (judge(m1))
			{
				res.push_back(ptr);
				ptr++;
				cur = ptr;
				m1 = m;
			}
		}
		return res;
	}
};

int main()
{
	string s1("wordgoodgoodgoodbestword");
	
	vector<string> v1({ "word", "good", "best", "good" });
	Solution A;
	A.findSubstring(s1, v1);


	return 0;
}
