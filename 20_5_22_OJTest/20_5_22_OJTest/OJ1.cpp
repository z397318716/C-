#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) 
		: val(x)
		, left(nullptr)
		, right(nullptr)
	{}
};


class solution
{
public:
	vector<int> rightSideView(TreeNode* root)
	{
		vector<int> v1;
		if (root == nullptr)
		{
			return v1;
		}
		//v1.push_back(root->val);
		// 层序遍历
		queue<TreeNode*> q1;
		q1.push(root);
		int count = 1;        // 记录当前层 结点个数
		int nextcount = 0;    // 记录下一层 结点个数
		while (!q1.empty())
		{
			TreeNode *cur = q1.front();
			q1.pop();
			count--;
			if (cur->left)
			{
				q1.push(cur->left);
				nextcount++;
			}
			if (cur->right)
			{
				q1.push(cur->right);
				nextcount++;
			}

			if (count == 0)
			{
				// 当前层结束, 下一次循环便开始下一层
				v1.push_back(cur->val);
				count = nextcount;
				nextcount = 0;
			}

		}
		return v1;
	}

};