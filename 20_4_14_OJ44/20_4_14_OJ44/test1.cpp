// [中级]单词倒排  牛客网

#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 整体翻转,并将单词之间的间隔符换为一个空格
string flip1(string s1)
{
	string tmp;
	int flag = 0;
	size_t size = s1.size() - 1;
	for (int i = size; i >= 0; i--)
	{
		if ((s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= 'A' && s1[i] <= 'Z'))
		{
			tmp.push_back(s1[i]);
			flag = 0;
		} else
		{
			if (flag == 0)
			{
				tmp.push_back(' ');
				flag = 1;
			}
		}
	}
	return tmp;
}
// 处理整体翻转之后的字符串,对每个单词进行翻转
string flip2(string s1)
{
	string s2;
	string tmp;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == ' ')
		{
			for (int j = s2.size() - 1; j >= 0; j--)
			{
				tmp.push_back(s2[j]);
			}
			tmp.push_back(' ');
			s2.clear();
		} else
		{
			s2.push_back(s1[i]);
		}
	}
	for (int j = s2.size() - 1; j >= 0; j--)
	{
		tmp.push_back(s2[j]);
	}
	if (tmp[0] == ' ')
	{
		tmp.erase(0, 1);
	}
	return tmp;
}

int main()
{
	string s1;
	while (getline(cin, s1))
	{
		cout << flip2(flip1(s1)) << endl;
	}



	return 0;
}