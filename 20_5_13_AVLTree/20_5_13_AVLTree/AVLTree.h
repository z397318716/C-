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
		cur->_bf = 0;
		if (parent->_kv.first > kv.first)
			parent->_left = cur;
		else
			parent->_right = cur;
		// 新插入节点连接其父节点(三叉树 有三条连接关系)
		cur->_parent = parent;

		/* 平衡问题
			新增节点的平衡因子是0, 新增节点的祖先平衡因子可能会受到影响
			1. 高度变化在 parent的右子树, parent->_bf += 1;
			2. 高度变化在 parent的左子树, parent->_bf -= 1;

			通过 cur 的位置更新 parent 的平衡因子, 更新完成后
			1. 如果 parent->_bf == 1 || -1, 说明parent为根的子树的高度也变了, 继续向上更新
			2. 如果 parent->_bf == 1 || -2, 说明parent为根的子树已经不平衡, 需要旋转处理
			3. 如果parent->_bf == 0, 说明parent所在的子树原来的高度是1/-1. 现在把矮的那边给填上了, parent所在的子树高度不变, 停止更新.
		*/

		// 更新平衡问题
		while (parent)
		{
			if (cur == parent->_right)
			{
				parent->_bf += 1;
			}
			else
			{
				parent->_bf -= 1;
			}

			if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 旋转处理------不能破坏二叉搜索树的原则
				
				// 右单旋
				if (parent->_bf == -2 || cur->_bf == -1)
				{
					RotateR(parent);
				}
				// 左单旋
				else if (parent->_bf == 2 || cur->_bf == 1)
				{
					RotateL(parent);
				}
				// 双旋

				break;
			}
		}

		return make_pair(cur, true);
	}

	// 左旋处理
	void RotateL(Node *parent)
	{
		// 记录当前结点的右孩子结点---(当前结点指平衡因子为2的结点,需要进行右旋处理
		Node *subR = parent->_right;
		Node *subRL = subR->_left;

		// 当前结点的右孩子的左孩子节点与 当前结点建立联系
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		if (parent == _root)
		{
			_root = subR;
			
			parent->_parent = subR;
			subR->_parent = nullptr;
		}
		else
		{
			Node *parentparent = parent->_parent;
			if (parent == parentparent->_left)
			{
				parentparent->_left = subR;
			}
			else
			{
				parentparent->_right = subR;
			}
			subR->_parent = parentparent;
		}
		parent->_bf = 0;
		subR->_bf = 0;
	}
	// 右旋处理
	void RotateR(Node *parent)
	{
		// 记录当前节点的左孩子节点 -- (当前节点为平衡因子为 -2 的结点)
		Node *subL = parent->_left;
		Node *subLR = subL->_right;

		// 当前结点的左孩子的右孩子结点 与 当前结点 建立连接
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		// 当前结点的左孩子结点与当前结点 进行右旋操作
		// 当前结点 变为其左孩子结点的右孩子结点
		// 此处需要考虑 当前结点是否为根
		subL->_right = parent;
		if (parent == _root)
		{
			_root = subL;
			parent->_parent = subL;
			subL->parent = nullptr;
		}
		else
		{
			// 当前结点不为根
			// 需要记录当前结点的父结点, 并使父节点与subL建立连接
			Node* parentparent = parent->_parent;
			if (parent == parentparent->_left)
			{
				parentparent->_left = subL;
			}
			else
			{
				parent->_right = subL;
			}
			subL->_parent = parentparent;
		}
		

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
