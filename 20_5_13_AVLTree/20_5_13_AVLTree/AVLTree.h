#pragma once
#include<iostream>
#include<assert.h>
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
		// 记录新插入的节点
		Node *newnode = new Node(kv);
		// 判断新插入的结点是其父结点的左孩子还是右孩子节点
		cur = newnode;
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
			2. 如果 parent->_bf == 2 || -2, 说明parent为根的子树已经不平衡, 需要旋转处理
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

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 旋转处理------不能破坏二叉搜索树的原则
				
				// 右单旋
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				// 左单旋
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				// 双旋
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					// 先对 cur 进行左单旋-在对 parent 进行右单旋
					// 此处需要处理 双旋所导致的平衡因子更新问题
					
					RotateL(cur);
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					// 先右旋 后左旋
					Node *subR = parent->_right;
					Node *subRL = subR->_left;
					int bf = subRL->_bf;

					RotateR(cur);
					RotateL(parent);
					if (bf == 1)
					{
						subRL->_bf = 0;
						parent->_bf = -1;
						subR->_bf = 0;
					}
					else if (bf == -1)
					{
						subRL->_bf = 0;
						parent->_bf = 0;
						subR->_bf = 1;
					}
					else if (bf == 0)
					{
						subRL->_bf = 0;
						parent->_bf = 0;
						subR->_bf = 0;
					}
				}
				else
				{
					assert(false);
				}

				break;
			}
		}

		return make_pair(newnode, true);
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
			parent->_parent = subR;
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
			subL->_parent = nullptr;
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
				parentparent->_right = subL;
			}
			parent->_parent = subL;
			subL->_parent = parentparent;
		}
		parent->_bf = 0;
		subL->_bf = 0;
	}

	int Height(Node *root)
	{
		if (root == nullptr)
			return 0;
		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
	bool _IsBalance(Node *root)
	{
		if (root == nullptr)
			return true;

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);
		if (rightHeight - leftHeight != root->_bf)
		{
			cout << root->_kv.first << "平衡因子异常" << root->_bf << endl;
		}

		// 递归判断AVL树是否平衡
		return abs(leftHeight - rightHeight) < 2 
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}
	bool IsBalance()
	{
		return _IsBalance(_root);
	}
private:
	Node* _root = nullptr;		// 此处不是初始化, 是缺省值----可以替代构造时给缺省值
};

void Test()
{
	AVLTree<int, int> test;
	//test.Insert(make_pair(2, 1));
	//test.Insert(make_pair(1, 2));
	//test.Insert(make_pair(13, 3));
	//test.Insert(make_pair(3, 4));
	//test.Insert(make_pair(12, 4));
	//test.Insert(make_pair(2, 2));

	//test.Insert(make_pair(13, 13));
	
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (auto &e : a)
	{
		test.Insert(make_pair(e, e));
	}
	
	//test.Insert(make_pair(12, 12));
	cout << test.IsBalance() << endl;
}
