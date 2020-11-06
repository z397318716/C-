#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
class Solution {
public:
	// �ж����������Ƿ�����λ��
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
		// ʹ��map ����λ�ʵ��ж�, ��λ�����������ͬ��, ��ζ����λ����key������ͬ��
		map<string, int> m1;
		vector<vector<string>> res;
		if (strs.empty())
			return res;
		int flag = 0;
		for (int i = 0; i < strs.size(); ++i){
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			if (m1.find(tmp) == m1.end()){
				//��ǰ����û�г�����λ��, ������ӽ� res ��
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
		// �������� 111/112  ��ʱ----˼·û��
		vector<vector<string>> res;
		if(strs.empty())
		return res;
		// ʹ�ñ�־λ�����ʾ��ǰԪ���Ƿ���Ҫ�ж�
		vector<bool> flag(strs.size(), false);
		for(int i = 0; i < strs.size(); ++i)
		{
		// ��ǰλ�ô��Ѿ��жϹ���
		if(flag[i])
		continue;
		else{
		vector<string> v1;
		v1.push_back(strs[i]);
		res.push_back(v1);
		}
		for(int j = 0; j < strs.size(); ++j)
		{
		// ��ǰλ�ô��Ѿ��жϹ���
		if(flag[j] || i == j)
		continue;
		else
		{
		if(judge_words(strs[i], strs[j]))
		{
		// strs[i] strs[j] ����λ��
		res[res.size()-1].push_back(strs[j]);
		// ���жϳɹ��Ĵʱ������
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