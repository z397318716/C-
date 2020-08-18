#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool cmp(const string s1, const string s2)
	{
		return false;
	}
	vector<string> removeSubfolders(vector<string>& folder) {
		vector<string> res;
		sort(folder.begin(), folder.end());
		//stack<string> s1;
		//s1.push(folder[0]);

		/*
		// O(n^2) ³¬Ê±
		for(int i = 0; i < folder.size() - 1; ++i)
		{
		if(folder[i] == "-")
		continue;
		folder[i] += '/';
		for(int j = i + 1; j < folder.size(); ++j)
		{
		if(folder[j].find(folder[i]) != string::npos)
		{
		folder[j] = '-';
		}

		}
		}
		for(int i = 0; i < folder.size(); ++i)
		{
		if(folder[i] != "-")
		{
		if(folder[i][folder[i].size() - 1] == '/')
		folder[i].erase(folder[i].size() - 1, 1);
		res.push_back(folder[i]);
		}
		}
		*/
		string tmp = folder[0];
		res.push_back(tmp);
		for (int i = 1; i < folder.size(); ++i)
		{
			if (folder[i].find(tmp) == string::npos)
			{
				res.push_back(folder[i]);
				tmp = folder[i];
			} else
			{
				auto it = folder[i].find(tmp);
				it += tmp.size();
				if (folder[i][it] != '/')
				{
					res.push_back(folder[i]);
					tmp = folder[i];
				}
			}

		}
		return res;

	}
};


int main()
{
	vector<string> v1{ "/a", "/a/b", "/c/d", "/c/d/e", "/c/f" };
	Solution s1;
	s1.removeSubfolders(v1);


	return 0;
}