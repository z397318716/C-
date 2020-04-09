#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;



int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int sum = 0;
		map<char, char> m1;
		map<char, char> m2;
		for (int i = 0; i < s1.size(); i++)
		{
			m1[s1[i]] = s1[i];
		}
		for (int i = 0; i < s2.size(); i++)
		{
			m2[s2[i]] = s2[i];
		}

		for (int i = 0; i < 26; i++)
		{
			if (m1.count((char)('a' + i)) && m2.count((char)('a' + i)))
				sum++;
		}
		cout << sum << endl;
	}




	return 0;
}