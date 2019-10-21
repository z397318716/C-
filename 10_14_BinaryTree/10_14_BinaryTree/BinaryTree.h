#pragma once
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template<class T>
class TreeNode
{
	T m_val;
	TreeNode<T> *m_left;
	TreeNode<T> *m_right;
	
public:
	TreeNode(const T &val) :
		m_val(val),
		m_left(nullptr),
		m_right(nullptr)
	{
	}

	// ���� BTree �� ���ܷ��� TreeNode �� private ��Ա
	template<class T>
	friend class BTree;
};

template<class T>
class BTree
{
	TreeNode<T> *m_root;
	/************************************************************************
	 * ��̬����������,��Ϊ��̬��Ա����
	 * ��̬��Ա��������: �����������������ʻ����޸��κζ���(��static)���ݳ�Ա
	 *		��ľ�̬��Ա(�����ͷ���)������Ķ���,������ص�ʱ��ͻ�����ڴ�,����ͨ������ֱ��ȥ����
	 *		�Ǿ�̬��Ա(�����ͷ���)������Ķ���,����ֻ������Ķ������(�������ʵ��)ʱ�Ż�����ڴ�,Ȼ��ͨ����Ķ���(ʵ��)ȥ����
	************************************************************************/
	static TreeNode<T> *MakeTree(const T *val, const T & end, int &i)		// �ݹ鴴��������
	{
		if (val[i] == end)
		{
			i++;
			return nullptr;
		}
		TreeNode<T> *root = new TreeNode<T>(val[i]);
		i++;

		root->m_left = MakeTree(val, end, i);
		root->m_right = MakeTree(val, end, i);

		return root;
	}
public:
	BTree() :
		m_root(nullptr)
	{}
	BTree(const T *val, const T &end)
	{
		int i = 0;
		m_root = MakeTree(val, end, i);
	}

	/******************************************
	*----------ǰ�����(�ǵݹ�)--������----------
	* ����ջʵ��,�Ӹ��ڵ㿪ʼ����,��ӡ�ýڵ�,
	* ��ǰ�ڵ�����ҽڵ�,�ҽڵ���ջ,
	* �����ǰ�ڵ�������ӽڵ�,���������ӽڵ�,����ȡջ��
	*/
	void pre_order()
	{
		TreeNode<T> *cur = m_root;
		stack<TreeNode<T> *> st;

		// ���ڵ㲻���� ���ӽڵ�,��ջΪ��ʱ,ǰ���������
		while (cur)
		{
			// ��ӡ��ǰ�ڵ�
			cout << cur->m_val;
			// �����ǰ�ڵ�����Һ��ӽڵ�,�����Һ��ӽڵ���ջ
			if (cur->m_right)
			{
				st.push(cur->m_right);
			}
			// �����ǰ�ڵ�������ӽڵ�,���������ӽڵ�
			if (cur->m_left)
			{
				cur = cur->m_left;
			}
			// ��ǰ�ڵ㲻�������ӽڵ�,�ҵ�ջ��Ϊ��ʱ,ȡջ��
			else
			{
				if (!st.empty())
				{
					cur = st.top();
					st.pop();
				}
				else
				{
					cur = nullptr;
				}
			}
		}
	}

	/************************************************************************/
	/* �������(�ǵݹ�)-- ��=> ��=> ��																		*/
	/*		1.�ӵ�ǰ�ڵ㿪ʼ,������������,�����нڵ���ջ,ֱ��������Ϊ��										*/
	/*		2.ȡջ��,����ӡ,���ջ���ڵ�����Һ��ӽڵ�,�������Һ��ӽڵ�,�ظ�����1								*/
	/*		3.���ջ���ڵ㲻�����Һ��ӽڵ�,�ظ�����2														*/	
	/************************************************************************/
	void in_order()
	{
		TreeNode<T> *cur = m_root;
		stack<TreeNode<T> *> st;

		// ��ǰ�ڵ�Ϊ��,ͬʱջΪ��,��������
		while (cur || !st.empty())
		{
			// �ӵ�ǰ�ڵ㿪ʼ,������������,�����нڵ���ջ
			while (cur)
			{
				st.push(cur);
				cur = cur->m_left;
			}
			// ������,Ϊ�պ�,ȡջ��,�����ջ���ڵ�����,����ջ���ڵ��Һ���,
			// ���������Һ���,�򲻻���� ��������������ѭ��,����ȡջ����ӡ
			cur = st.top();
			cout << cur->m_val;
			cur = cur->m_right;
			st.pop();

		}

	}

	/************************************************************************/
	/* �������(�ǵݹ�)---��=> ��=> ��
	/* */
	/************************************************************************/
	void post_order()
	{

	}

	/************************************************************************/
	/* �������(�ǵݹ�)��������ʵ��                                                                     */
	/* 1. �Ƚ������,ȡ�Ӷ���ӡ			*/
	/* 2.����ýڵ������ӽڵ���������,���Һ��ӽڵ������Һ���*/
	/* 3.�Ӷ�����*/
	/************************************************************************/
	void level_order()
	{
		TreeNode<T> *cur = m_root;
		queue<TreeNode<T> *> qu;

		qu.push(cur);
		while (!qu.empty())
		{
			cur = qu.front();
			cout << cur->m_val << "->";
			if (cur->m_left)
			{
				qu.push(cur->m_left);
			}
			if (cur->m_right)
			{
				qu.push(cur->m_right);
			}
			qu.pop();
		}
	}

	// roll ��ҵ ����ÿһ������ֵ
	// ����:  .  �� -> ����
	vector<int> largestValues(TreeNode* root) 
	{
		queue<TreeNode*> qu;

		vector<int> max;		// ����ÿһ��������
		int len_lev = 1;		// ����ÿ�����
		TreeNode* cur = root;
		qu.push(root);

		if (root == nullptr)
		{
			return max;
		}
		while (!qu.empty())
		{
			len_lev = qu.size();
			int max_lev = qu.front()->m_val;		// ����ÿһ��������
			for (int i = 0; i < len_lev; i++)
			{
				cur = qu.front();
				//int max_lev = qu.front().m_val;		// ����ÿһ��������
				if (max_lev < qu.front()->m_val)
				{
					max_lev = qu.front()->m_val;
				}

				if (cur->m_left)
				{
					qu.push(cur->m_left);
				}
				if (cur->m_right)
				{
					qu.push(cur->m_right);
				}
				qu.pop();
				
			}
			max.push_back(max_lev);
			
		}
		return max;
	}
};



