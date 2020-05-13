#pragma once
/************************************************************************/
/* 二叉搜索树模拟实现                                                                     */
/************************************************************************/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
	: _pleft(nullptr), _pright(nullptr), _data(data)
	{
	}
	BSTNode<T>* _pleft;
	BSTNode<T>* _pright;
	T _data;
};

template<class T>
class BSTree
{
private:
	typedef BSTNode<T> Node;
	typedef Node* PNode;
public:
	PNode _proot;

public:
	// 构造
	BSTree()
		: _proot(nullptr)
	{}
	// 析构
	~BSTree()
	{
		Destory(_proot);
	};
	// 二叉搜索树的查找	
	PNode Find(const T& data)
	{
		
		// 思路: 首先结点不应为空 
		// 1. 如果节点的值 data = 查找的值data, 返回该节点
		// 2. 如果节点的值 data < 查找的值data, 在该结点的右子树中查找
		// 3. 如果节点的值 data > 查找的值data, 在该结点的左子树中查找
		// 4. 遍历完成未找到则返回 nullptr;
		PNode cur = _proot;
		while (cur)
		{
			if (cur->_data == data)
				return cur;
			else if (cur->_data < data)
			{
				cur = cur->_pright;
			}  else
				cur = cur->_pleft;
		}
		return nullptr;
	}
	
	bool Insert(const T& data)
	{
		// 思路:
		// 1. 如果根节点为空,则直接插入(根结点直接赋值) ---返回true
		// 2. 如果不为空, 则按照二叉搜索树性质 查找应该插入的位置,然后插入
		if (_proot == nullptr)
		{
			_proot = new Node(data);
			return true;
		}
		PNode cur = _proot;
		PNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data < cur->_data)
				cur = cur->_pleft;
			else if (data > cur->_data)
				cur = cur->_pright;
			else
				return false;	// 如果插入的结点已经存在, 则插入失败
		}
		cur = new Node(data);
		// 将新插入的结点连接到树上
		if (data > parent->_data)
			parent->_pright = cur;
		else
			parent->_pleft = cur;
		return true;
	}
	bool Erase(const T& data)
	{
		// 如果树为空, 则直接返回false,删除失败
		if (_proot == nullptr)
			return false;
		
		// 遍历查找要删除结点, 并记录该节点的父节点
		PNode parent = nullptr;
		PNode cur = _proot;
		while (cur)
		{
			if (data == cur->_data)
				break;
			else if (data > cur->_data)
			{
				parent = cur;
				cur = cur->_pright;
			}
			else
			{
				parent = cur;
				cur = cur->_pleft;
			}
		}
		// 如果要删除结点不存在, 则删除失败
		if (cur == nullptr)
			return false;

		// 找到要删除结点后, 共有四种情况
		// 1.该结点无孩子结点
		// 2.该结点只有左孩子结点
		// 3.该结点只有右孩子结点
		// 4.该结点左右孩子结点都存在
		// 第一种情况可以与 2或3情况一并处理

		// 情况1,2
		if (cur->_pright == nullptr)
		{
			// 如果要删除的结点为根节点,且其只有左孩子结点
			if (cur == _proot)
			{
				_proot = cur->_pleft;
				//delete Node(cur);
			}
			else
			{
				if (cur == parent->_pleft)
					parent->_pleft = cur->_pleft;
				else
					parent->_pright = cur->_pleft;
			}
		}
		// 情况3
		else if (cur->_pleft == nullptr)
		{
			if (cur == _proot)
				_proot = cur->_pright;
			else
			{
				if (cur == parent->_pleft)
					parent->_pleft = cur->_pright;
				else
					parent->_pright = cur->_pright;
			}
		}
		// 情况4
		// 该结点左右子树都存在的情况,不能直接删除
		// 方法1: 在该结点的左子树中找到最大值(即最右侧的结点)将该结点的值赋给要删除的结点,然后在删除代替节点
		// 方法2: 在该结点的右子树中找到最小值---处理方式与方法1类似
		else
		{
			if (cur->_pleft != nullptr && cur->_pright != nullptr)
			{
				// 找左子树最大节点替换要删除的结点
				PNode replace = cur->_pleft;
				PNode parent = cur;
				while (replace->_pright)
				{
					parent = replace;
					replace = replace->_pright;
				}
				cur->_data = replace->_data;
				if (replace == parent->_pleft)
					parent->_pleft = replace->_pleft;
				else
					parent->_pright = replace->_pleft;
				delete replace;
				replace = nullptr;
			}
			return true;
		}
		return false;
	}
	private:
		void Destory(PNode _proot)
		{
			if (_proot)
			{
				Destory(_proot->_pleft);
				Destory(_proot->_pright);
			}
			_proot = nullptr;
		}
		void _InorderPrint(PNode root)
		{
			if (root)
			{
				_InorderPrint(root->_pleft);
				cout << root->_data << "->";
				_InorderPrint(root->_pright);
			}
		}
};
void Test()
{
	BSTree<int> BST1;
	for (int i = 0; i < 10; i++)
	{
		BST1.Insert(i);
	}
	BST1._InorderPrint(BST1._proot);
	cout << endl;

}