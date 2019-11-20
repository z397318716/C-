#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string str;
	string tmp;
	vector<string> vs;
	getline(cin, str);
	int flag = 0;    // 
	for (int i = 0; i < str.size(); i++)
	{
		flag = flag % 2;
		if (str[i] == '"')
		{
			flag += 1;
			continue;
		}
		if (str[i] == ' ' && flag == 0)
		{
			vs.push_back(tmp);
			tmp.clear();
			continue;
		}
		tmp.push_back(str[i]);
		if (i == str.size() - 1)
		{
			vs.push_back(tmp);
		}
	}
	cout << vs.size() << endl;
	int i = 0;
	while (i < vs.size())
	{
		cout << vs[i] << endl;
		i++;
	}

	return 0;
}