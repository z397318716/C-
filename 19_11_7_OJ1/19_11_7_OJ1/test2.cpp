/************************************************************************/
/* 输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”                                                                     */
/************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>

using namespace std;

// 方案一:暴力查找--  O(N^2)
// 判断第二个串的字符是否在第一个中,在就删除
std::string Del_Str(std::string &str1, std::string str2)
{
	for (int i = 0; i < str1.size(); i++)
	{
		for (int j = 0; j < str2.size(); j++)
		{
			if (str2[j] == ' ')
			{
				continue;
			}
			if (str1[i] == str2[j])
			{
				str1.erase(str1.begin() + i);
			}
		}
	}
	return str1;
}

// 方案二: hash映射的方式
// ---1.将第二个字符串中的字符都映射到一个 hashtable中,用来判断一个字符是否在字符串中
// ---2.如果一个字符在字符串中,不使用删除,因为效率太低,-->将不再字符串中的字符添加进新的字符串中,最后返回这个字符串
std::string Del_Str_Harsh(string s1, string s2)
{
	//int harshtable[256] = { 0 };
	map<char, int> m1;
	string tmp;
	for (int i = 0; i < s2.size(); i++)
	{
		++m1[s2[i]];
	}
	for (int i = 0; i < s1.size(); i++)
	{
		if (m1[s1[i]] == 0)
		{
			tmp.push_back(s1[i]);
		}
	}
	return tmp;
}

int main()
{
	std::string s1;
	std::string s2;
	getline(cin, s1);
	getline(cin, s2);

	cout << Del_Str_Harsh(s1, s2);

	//Del_Str(s1, s2);
	//cout << s1 << endl;

	return 0;
}