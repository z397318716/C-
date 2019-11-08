/************************************************************************/
/* 一个字符串中存在数字字符,返回其中最长的一串连续数字字符                                                                     */
/************************************************************************/
#include<iostream>
#include<string>
#include<vector>

using namespace std;
string Max_Lenth_Str(string s1)
{
	string tmp;
	string max_str;
	int size = 0;
	int max_size = 0;
	string::iterator first = s1.begin();
	string::iterator end = s1.begin();

	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] <= '9' && s1[i] >= '0')
		{
			tmp.push_back(s1[i]);
		}
		else
		{
			tmp.clear();
		}
		if (max_str.size() < tmp.size())
		{
			max_str = tmp;
		}
	}
	return max_str;

	/*for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] >= '0' && s1[i] <= '9')
		{
			tmp.push_back(s1[i]);
		} else
		{
			size = tmp.size();
			if (max_size < size)
			{
				max_size = size;
			}
			tmp.clear();
		}
	}*/

}


int main()
{

	string s1;
	getline(cin, s1);

	cout << Max_Lenth_Str(s1);


	return 0;
}