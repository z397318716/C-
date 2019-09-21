//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//void ReverseString(string &s)
//{
//	int i, j;
//	for (i = 0, j = s.size() - 1; i < j; i++, j--)
//	{
//		swap(s[i], s[j]);
//	}
//}
//
//int main1()
//{
//	string s1("ikun");
//	ReverseString(s1);
//	cout << s1;
//
//	return 0;
//}
//
//int FirstUniqChar(string s)
//{
//	int count[26] = { 0 };
//	for (auto &i : s)
//	{
//		count[i - 'a']++;
//	}
//	/*int j = 0;
//	for (auto &i : count)
//	{
//		cout << (char)('a' + j++) << ' ' << i << endl;
//	}*/
//
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (count[s[i] - 'a'] == 1)
//		{
//			return i;
//		}
//
//	}
//	return -1;
//}
//
//int LastWordLength(string s)
//{
//	size_t count = s.rfind(' ');
//
//	return s.size() - count - 1;
//}
//
//int main2()
//{
//	string s("hello world");
//	//cin >> s;
//	//FirstUniqChar(s);
//	
//	getline(cin, s);
//	cout <<"Last Word Length:" << LastWordLength(s) << endl;
//	return 0;
//}
//
//bool IsLetterOrNumber(char ch)
//{
//	return (ch >= 'a' && ch <= 'z') ||
//		(ch >= 'A' && ch <= 'Z');
//}
//bool IsSame(char a, char b)
//{
//	return a == b ||
//  (a | 1 << 5) == (b | 1 << 5);			// 大写字母变成小写字母,小写字母不变,然后比较-----左/右移优先级仅次于 + - * /
//									// 或者 a 异或 b == 32 也可以判断
//}
//bool IsPalindrome(string s)
//{
//	string tmp;
//	for (auto &ch : s)
//	{
//		if (IsLetterOrNumber(ch))
//		{
//			tmp.push_back(ch);
//		}
//	}
//	int i, j;
//	for (i = 0, j = tmp.size() - 1; i < j; i++, j--)
//	{
//		if (!IsSame(tmp[i], tmp[j]))
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	string s("da");
//
//	return 0;
//}