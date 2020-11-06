#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
class Solution {
public:
	// 判断两个单词是否是异位词
	bool judge_words(string s1, string s2){
		if (s1.size() != s2.size())
			return false;
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		if (s1 != s2)
			return false;
		return true;
	}

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		// 使用map 做异位词的判断, 异位词排序后是相同的, 意味着异位词做key都是相同的
		map<string, int> m1;
		vector<vector<string>> res;
		if (strs.empty())
			return res;
		int flag = 0;
		for (int i = 0; i < strs.size(); ++i){
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			if (m1.find(tmp) == m1.end()){
				//当前单词没有出现异位词, 单独添加进 res 中
				m1[tmp] = flag++;
				vector<string> v1;
				v1.push_back(strs[i]);
				res.push_back(v1);
			} else{
				// 
				res[m1[tmp]].push_back(strs[i]);
			}
		}
		return res;

		/*
		// 测试用例 111/112  超时----思路没错
		vector<vector<string>> res;
		if(strs.empty())
		return res;
		// 使用标志位数组表示当前元素是否需要判断
		vector<bool> flag(strs.size(), false);
		for(int i = 0; i < strs.size(); ++i)
		{
		// 当前位置词已经判断过了
		if(flag[i])
		continue;
		else{
		vector<string> v1;
		v1.push_back(strs[i]);
		res.push_back(v1);
		}
		for(int j = 0; j < strs.size(); ++j)
		{
		// 当前位置词已经判断过了
		if(flag[j] || i == j)
		continue;
		else
		{
		if(judge_words(strs[i], strs[j]))
		{
		// strs[i] strs[j] 是异位词
		res[res.size()-1].push_back(strs[j]);
		// 将判断成功的词标记起来
		flag[j] = true;
		}
		}
		}
		}
		return res;
		*/
	}
};

int main(){

	vector<string> v1({ "eat", "tea", "tan", "ate", "nat", "bat" });
	Solution A;
	A.groupAnagrams(v1);

	return 0;
}