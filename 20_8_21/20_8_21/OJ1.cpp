#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	string res = "z";
	void Reverse(string &s)
	{
		if (s.size() == 0)
			return;
		char tmp = ' ';
		//string::iterator it1 = s.begin();
		//string::iterator it2 = s.end();
		int i = 0;
		int j = s.size()-1;
		while (i <= j)
		{
			swap(s[i], s[j]);
			i++;
			j--;
		}
	}
	void dfs(TreeNode* root, string s)
	{
		s += (char)(root->val + 'a');
		if (root->left == nullptr && root->right == nullptr)
		{

			Reverse(s);
			if (res > s)
				res = s;
		}
		if (root->left != nullptr)
			dfs(root->left, s);
		if (root->right != nullptr)
			dfs(root->right, s);

	}
	string smallestFromLeaf(TreeNode* root) {
		if (!root)
			return nullptr;
		dfs(root, "");
		return res;

	}
};


int main()
{
	string s("asdfa");
	Solution a;
	a.Reverse(s);
	cout << s << endl;
	TreeNode *root(0);
	


	return 0;
}