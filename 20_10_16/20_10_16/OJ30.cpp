#include<iostream>
#include<string>
#include<vector>
#include<map>


//    172 / 176 ��ͨ����������---------����ʱ������
using namespace std;
class Solution {
public:
	// �ж�words�����Ƿ�������
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
		int ptr = 0;    // ����s����ʼ����λ��
		while (cur + len <= s.size())
		{

			int tmp = cur;  // ������s�жԱ�ÿ�����ʵ���ʼλ�ã� ���ڱȽ��ж��Ƿ��ҵ��е�����s�е��Ӵ����
			for (auto &k : m1)
			{
				if (k.second != 0 && s.compare(cur, len, k.first) == 0)
				{
					k.second--;
					cur += len;
					break;
				}
			}
			// ��λ��û���ҵ�words�еĵ��ʣ� ���m1���б�־��
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
