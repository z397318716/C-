#include<iostream>
#include<string>
using namespace std;

int LengthStr(string s1, string s2)
{
	int count = 0;
	int tmp = 0;
	if (s1.size() > s2.size())
		swap(s1, s2);
	for (int i = 0; i < s1.size(); i++)
	{
		for (int j = 0; i + j < s2.size(); j++)
		{
			string str(s1.begin() + i, s1.begin() + i + j);
			if (int(s2.find(str)) < 0)
				break;
			else if (count < str.size())
			{
				count = str.size();
			}
				
		}
	}
	return count;
}

int main()
{
	string s1, s2;

	while (cin >> s1 >> s2)
	{
		cout << LengthStr(s1, s2) << endl;
	}




	return 0;
}