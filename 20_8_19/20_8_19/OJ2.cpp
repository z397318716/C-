/************************************************************************/
/* ����1032
   ������Ҫ��ʵ�� StreamChecker �ࣺ

   StreamChecker(words)�����캯�����ø������ִʳ�ʼ�����ݽṹ��
   query(letter)���������ĳЩ k >= 1�������ò�ѯ����� k���ַ������Ӿɵ���˳�򣬰����ող�ѯ����ĸ��ƴд�������ִʱ��е�ĳһ�ִ�ʱ������ true�����򣬷��� false��

   ��Դ�����ۣ�LeetCode��
   ���ӣ�https://leetcode-cn.com/problems/stream-of-characters
   ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע�������� */
/************************************************************************/
#include<iostream>
#include<vector>
#include<string>
using namespace std;


class StreamChecker {
public:

	/*//��ʱ
	vector<string> tmp;
	string s2;
	// ������ĵ��ʳ���
	int max_len;
	StreamChecker(vector<string>& words) {
	for(int i = 0; i < words.size(); ++i)
	{
	string s1;
	int len = 0;
	for(int j = words[i].size()-1; j >= 0; --j)
	{
	s1 += words[i][j];
	}
	len = s1.size();
	if(len > max_len)
	max_len = len;
	tmp.push_back(s1);
	}
	}
	bool query(char letter) {
	string fi;
	s2 += letter;
	int count = 0;
	for(int i = s2.size()-1; i >= 0 && count <= max_len; --i)
	{

	fi += s2[i];
	for(auto e: tmp)
	{
	if(fi == e)
	return true;
	}
	count++;
	}
	return false;
	}
	*/
	struct TrieNode {
		bool flag;
		TrieNode* next[26] = { nullptr };
		TrieNode()
			:flag(false)
		{}
	};
	TrieNode* root;
	string s;
	StreamChecker(vector<string>& words) {
		root = new TrieNode();
		for (const auto& w : words) {
			auto node = root;
			for (int i = w.size() - 1; i >= 0; i--) {
				int k = w[i] - 'a';
				if (node->next[k] == nullptr) {
					node->next[k] = new TrieNode();
				}
				node = node->next[k];
			}
			node->flag = true;
		}
	}

	bool query(char letter) {
		s += letter;
		auto node = root;
		for (int i = s.size() - 1; i >= 0; --i) {
			int k = s[i] - 'a';
			if (node->next[k] != NULL) {
				node = node->next[k];
				if (node->flag) return true;
			} else {
				return false;
			}
		}
		return false;
	}
};

/**
* Your StreamChecker object will be instantiated and called as such:
* StreamChecker* obj = new StreamChecker(words);
* bool param_1 = obj->query(letter);
*/

/**
* Your StreamChecker object will be instantiated and called as such:
* StreamChecker* obj = new StreamChecker(words);
* bool param_1 = obj->query(letter);
*/

int main()
{

	vector<string> v1;
	v1.push_back("cd");
	v1.push_back("f");
	v1.push_back("kl");

	StreamChecker tmp(v1);
	auto k = tmp.query('a');
	k = tmp.query('b');
	k = tmp.query('c');
	k = tmp.query('d');
	k = tmp.query('e');
	k = tmp.query('f');
	k = tmp.query('g');
	k = tmp.query('h');
	k = tmp.query('i');
	k = tmp.query('j');
	k = tmp.query('k');
	k = tmp.query('l');
	




	return 0;
}