#include<iostream>
#include<string>
using namespace std;

string Str(string s1, string s2)
{

	string max;
	if (s1.size() > s2.size())
	{
		swap(s1, s2);
	}
	string::iterator it1 = s1.begin();
	for (int i = 0; i < s1.size(); i++)
	{
		for (int j = 0; i + j < s1.size(); j++)
		{
			string tmp(it1 + i, it1 + i + j + 1);
			if (int(s2.find(tmp)) < 0)
				break;
			else if (max.size() < tmp.size())
				max = tmp;
		}
	}


	return max;
}

int main()
{
	string s1, s2;

	while (cin >> s1 >> s2)
	{
		cout << Str(s1, s2) << endl;
	}



	return 0;
}