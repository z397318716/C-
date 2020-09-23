#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:

	void backtrack(vector<string> &res, unordered_map<char, string> &m1, string &digits,
		int pos, string &tmp)
	{
		if (pos == digits.size())
			res.push_back(tmp);
		else
		{
			char num = digits[pos];
			const string &letter = m1.at(num);
			for (const char &word : letter)
			{
				tmp.push_back(word);
				backtrack(res, m1, digits, pos + 1, tmp);
				tmp.pop_back();
			}
		}
	}
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (digits.empty())
			return res;
		unordered_map<char, string> m1{
			{ '2', "abc" },
			{ '3', "def" },
			{ '4', "ghi" },
			{ '5', "jkl" },
			{ '6', "mno" },
			{ '7', "pqrs" },
			{ '8', "tuv" },
			{ '9', "wxyz" }
		};
		string tmp;
		backtrack(res, m1, digits, 0, tmp);
		return res;
	}
};