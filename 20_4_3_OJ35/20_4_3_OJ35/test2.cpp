#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string str, name;
	while (getline(cin, str))
	{
		getline(cin, name);
		//分割抄送列表
		vector<string>v;
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] == '\"'){//有引号的
				v.push_back(str.substr(i + 1, str.find('\"', i + 1) - i - 1));
				i = str.find('\"', i + 1) + 1;
			} else{//没有引号
				if (str.find(',', i) == str.npos){
					v.push_back(str.substr(i, str.size() - i));
					i = str.size();
				} else{//没到结束
					v.push_back(str.substr(i, str.find(',', i) - i));
					i = str.find(',', i);
				}
			}
		}
		if ((find(v.begin(), v.end(), name) != v.end()))
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}
	return 0;
}