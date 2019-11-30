// 找出字符串中第一个只出现一次的字符
#include<iostream>
#include<string>
#include<map>
using namespace std;

void Str(string s1)
{

	map<char, int> m1;

	for (int i = 0; i < s1.size(); i++)
	{
		m1[s1[i]]++;
	}
	for (int i = 0; i < s1.size(); i++)
	{
		if (m1[s1[i]] == 1)
		{
			cout << s1[i] << endl;
			return;
		}

	}

	cout << -1 << endl;
}

int main()
{
	string s1;
	while (cin >> s1)
	{
		Str(s1);
	}
}