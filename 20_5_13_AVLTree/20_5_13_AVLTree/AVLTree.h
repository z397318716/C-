#pragma once
#include<iostream>
using namespace std;



template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V> *_left;
	AVLTreeNode<K, V> *_right;
	AVLTreeNode<K, V> *_parent;

	pair<K, V> _kv;
	int _bf;	// 平衡因子

	AVLTreeNode(const pair<K, V> &kv)
		:_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_kv(kv),
		_bf(0)
	{

	}

};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;

public:
	AVLTree()
		:_root(nullptr)
	{}
	~AVLTree()
	{
		
	}
	AVLTree(const AVLTree & t)
	{
		return t;
	}
	V &operator [](const K &key)
	{
		pair<Node*, bool> ret = Insert(make_pair(key, V()));
		return ret.first->_kv.second;
	}

	pair<Node*, bool> Insert(const pair<K, V> &kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return make_pair(_root, true);
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
				//parent->_bf++;	// 调整其父节点的平衡因子
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
				
			}
			else
			{
				return make_pair(cur, false);
			}
		}
		// 判断新插入的结点是其父结点的左孩子还是右孩子节点
		cur = new Node(kv);
		if (parent->_kv.first > kv.first)
			parent->_left = cur;
		else
			parent->_right = cur;
		// 新插入节点连接其父节点(三叉树 有三条连接关系)
		cur->_parent = parent;

		// 平衡问题


		return make_pair(cur, true);
	}
private:
	Node* _root = nullptr;		// 此处不是初始化, 是缺省值----可以替代构造时给缺省值
};

void Test()
{
	AVLTree<int, int> test;
	test.Insert(make_pair(1, 1));
	test.Insert(make_pair(2, 2));
	test.Insert(make_pair(3, 3));
	test[3];
	test[2] = 0;
	test[4] = 4;
	test[5];
}
