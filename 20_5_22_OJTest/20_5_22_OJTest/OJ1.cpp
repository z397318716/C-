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
		// �������
		queue<TreeNode*> q1;
		q1.push(root);
		int count = 1;        // ��¼��ǰ�� ������
		int nextcount = 0;    // ��¼��һ�� ������
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
				// ��ǰ�����, ��һ��ѭ���㿪ʼ��һ��
				v1.push_back(cur->val);
				count = nextcount;
				nextcount = 0;
			}

		}
		return v1;
	}

};