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

	// 由于 BTree 类 不能访问 TreeNode 的 private 成员
	template<class T>
	friend class BTree;
};

template<class T>
class BTree
{
	TreeNode<T> *m_root;
	/************************************************************************
	 * 静态函数在类中,称为静态成员函数
	 * 静态成员函数作用: 调用这个函数不会访问或者修改任何对象(非static)数据成员
	 *		类的静态成员(变量和方法)属于类的对象,在类加载的时候就会分配内存,可以通过类名直接去访问
	 *		非静态成员(变量和方法)属于类的对象,所以只有在类的对象产生(创建类的实例)时才会分配内存,然后通过类的对象(实例)去访问
	************************************************************************/
	static TreeNode<T> *MakeTree(const T *val, const T & end, int &i)		// 递归创建二叉树
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
	*----------前序遍历(非递归)--根左右----------
	* 借助栈实现,从根节点开始遍历,打印该节点,
	* 当前节点存在右节点,右节点入栈,
	* 如果当前节点存在左孩子节点,访问其左孩子节点,否则取栈顶
	*/
	void pre_order()
	{
		TreeNode<T> *cur = m_root;
		stack<TreeNode<T> *> st;

		// 当节点不存在 左孩子节点,且栈为空时,前序遍历结束
		while (cur)
		{
			// 打印当前节点
			cout << cur->m_val;
			// 如果当前节点存在右孩子节点,将其右孩子节点入栈
			if (cur->m_right)
			{
				st.push(cur->m_right);
			}
			// 如果当前节点存在左孩子节点,访问其左孩子节点
			if (cur->m_left)
			{
				cur = cur->m_left;
			}
			// 当前节点不存在左孩子节点,且当栈不为空时,取栈顶
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
	/* 中序遍历(非递归)-- 左=> 根=> 右																		*/
	/*		1.从当前节点开始,遍历其左子树,将所有节点入栈,直至左子树为空										*/
	/*		2.取栈顶,并打印,如果栈顶节点存在右孩子节点,访问其右孩子节点,重复过程1								*/
	/*		3.如果栈顶节点不存在右孩子节点,重复过程2														*/	
	/************************************************************************/
	void in_order()
	{
		TreeNode<T> *cur = m_root;
		stack<TreeNode<T> *> st;

		// 当前节点为空,同时栈为空,遍历结束
		while (cur || !st.empty())
		{
			// 从当前节点开始,遍历其左子树,将所有节点入栈
			while (cur)
			{
				st.push(cur);
				cur = cur->m_left;
			}
			// 左子树,为空后,取栈顶,并输出栈顶节点数据,访问栈顶节点右孩子,
			// 若不存在右孩子,则不会进入 上述访问左子树循环,继续取栈顶打印
			cur = st.top();
			cout << cur->m_val;
			cur = cur->m_right;
			st.pop();

		}

	}

	/************************************************************************/
	/* 后序遍历(非递归)---左=> 右=> 根
	/* */
	/************************************************************************/
	void post_order()
	{

	}

	/************************************************************************/
	/* 层序遍历(非递归)借助队列实现                                                                     */
	/* 1. 先将根入队,取队顶打印			*/
	/* 2.如果该节点有左孩子节点就入队左孩子,有右孩子节点就入队右孩子*/
	/* 3.队顶出队*/
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

	// roll 作业 返回每一层最大的值
	// 问题:  .  与 -> 混淆
	vector<int> largestValues(TreeNode* root) 
	{
		queue<TreeNode*> qu;

		vector<int> max;		// 保存每一层最大的数
		int len_lev = 1;		// 保存每层个数
		TreeNode* cur = root;
		qu.push(root);

		if (root == nullptr)
		{
			return max;
		}
		while (!qu.empty())
		{
			len_lev = qu.size();
			int max_lev = qu.front()->m_val;		// 保存每一层最大的数
			for (int i = 0; i < len_lev; i++)
			{
				cur = qu.front();
				//int max_lev = qu.front().m_val;		// 保存每一层最大的数
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



