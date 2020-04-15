// 牛客网 -- 查找兄弟单词   此题牛客网描述有问题
/************************************************************************/
/* 正确描述:
输入描述:
先输入字典中单词的个数n，再输入n个单词作为字典单词。
再输入一个单词，查找其在字典中兄弟单词的个数m
再输入数字k

输出描述:
根据输入，输出查找到的兄弟单词的个数m
然后输出查找到的兄弟单词的第k个单词。 数字和字符各占一行, 牛客所给的用例为一行输出, 误导人
************************************************************************/
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

// 判断两个单词是否是兄弟单词--->使用map判断
bool IsXD(string s1, string s2)
{
	map<char, int> m1;
	map<char, int> m2;

	for (int i = 0; i < s1.size(); i++)
	{
		m1[s1[i]]++;
	}
	for (int i = 0; i < s2.size(); i++)
	{
		m2[s2[i]]++;
	}
	// 判断 s1 中是否包含s2中所有的元素
	for (int i = 0; i < s2.size(); i++)
	{
		m1[s2[i]]--;
		if (m1[s2[i]] < 0)
			return false;
	}
	// 判断 s2 中是否包含s1中所有的元素
	for (int i = 0; i < s1.size(); i++)
	{
		m2[s1[i]]--;
		if (m2[s1[i]] < 0)
			return false;
	}
	return true;
}
void dict(vector<string> v1, string find, int n)
{
	vector<string> tmp;
	for (int i = 0; i < v1.size(); i++)
	{
		if (find == v1[i])
			continue;
		if (IsXD(find, v1[i]))
		{
			tmp.push_back(v1[i]);
		}

	}
	sort(tmp.begin(), tmp.end());
	if (!tmp.empty())
	{
		cout << tmp.size() << endl;
		if (n <= tmp.size())
		{
			cout << tmp[n - 1] << endl;
		}
	} else
	{
		cout << 0 << endl;
	}
}

int main()
{
	int num;
	while (cin >> num)
	{
		vector<string> v1;
		v1.resize(num);
		for (int i = 0; i < num; i++)
		{
			cin >> v1[i];
		}
		string find;
		int n;
		cin >> find;
		cin >> n;
		dict(v1, find, n);
	}



	return 0;
}