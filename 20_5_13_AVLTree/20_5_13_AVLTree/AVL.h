#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
	:_left(nullptr)
	, _right(nullptr)
	, _parent(nullptr)
	, _data(data)
	, _bf(0)
	{}

	// 结点的左右孩子结点和父结点
	AVLTreeNode<T> *_left;	
	AVLTreeNode<T> *_right;
	AVLTreeNode<T> *_parent;
	T _data;
	int _bf;	// 结点的平衡因子
};

template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;

public:
	AVLTree()
		: _root(nullptr)
	{}
	~AVLTree()
	{
		Destory(_root);
	}
	AVLTree(const AVLTree &t)
	{
		return t;
	}
	/*
	T &operator [](const T& data)
	{
		Node* ret = Insert(data);
		return ret->_data;
	}
	*/
private:
	Node *_root;	

	// 后序遍历销毁二叉树
	// 先销毁左子树, 在销毁右子树
	void Destory(Node* &root)
	{
		if (root != nullptr)
		{
			Destory(root->_left);
			Destory(root->_right);
			delete root;
			root = nullptr;
		}
	}
public:
	// 非递归查找
	// 若树中存在要查找的元素, 返回该元素所在结点, 否则返回空
	Node* Find(T data)
	{
		Node *cur = this->_root;
		while (cur != nullptr)
		{
			if (cur->_data == data)
				return cur;
			else if (cur->_data > data)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		return nullptr;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	Node* Insert(const T& data)
	{
		// 先按照二叉搜索树的方式插入新节点
		if (_root == nullptr)
		{
			_root = new Node(data);
			return _root;
		}
		Node *cur = _root;
		Node *parent = nullptr;
		while (cur)
		{
			if (cur->_data == data)
				return cur;
			else if (cur->_data < data)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				parent = cur;
				cur = cur->_left;
			}
		}
		// 记录新插入结点
		Node *newNode = new Node(data);
		// 判断新结点是其父结点的左孩子结点还是右孩子结点, 并插入树中
		cur = newNode;
		if (cur->_data > parent->_data)
		{
			parent->_right = cur;
		}
		else if (cur->_data < parent->_data)
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		// 新插入结点后需要 更新平衡因子
		// 新增节点的祖先平衡因子会发生变化
		// 新增结点为 parent 的左孩子结点 parent的平衡因子 -1;
		// 新增节点为 parent 的右孩子结点 parent的平衡因子 +1;
		
		while (parent)
		{
			// 当前结点新增左节点, 平衡因子 -1;
			if (cur == parent->_left)
				parent->_bf -= 1;
			// 当前结点新增右节点, 平衡因子 +1;
			else if (cur == parent->_right)
				parent->_bf += 1;
			
			// 如果更新后, parent 的平衡因子 为 0 , 说明 parent 未更新前平衡因子为 1/-1 , 新插入结点使 parnet 左右子树高度相同, 不需要向上更新
			if (parent->_bf == 0)
				break;
			// 如果更新后, parent 的平衡因子为 1 或者 -1, 说明以 parent 为根的左右子树发生了变化, 从而会影响祖先的平衡因子, 需要向上继续更新
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			// 如果更新后, parent 的平衡因子为 2/-2, 说明以 parent 为根的左右子树高度已经不平衡, 需要进行旋转处理
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 旋转分为三种情况: 左单旋, 右单旋, 双旋(又分为 先左旋后右旋, 先右旋后左旋)
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					// 左单旋
					LRotate(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					// 右单旋
					RRotate(parent);
				}
				// 双旋的情况需要对平衡因子进行调整操作
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					int bf = cur->_left->_bf;
					// 先对cur进行右旋, 在对 parent 进行左旋
					RRotate(cur);
					LRotate(parent);

					if (bf == -1)
					{
						parent->_bf = 0;
						cur->_bf = 1;
					}
					if (bf == 1)
					{
						parent->_bf = -1;
						cur->_bf = 0;
					}
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					int bf = cur->_right->_bf;
					// 先左旋, 后右旋
					LRotate(cur);
					RRotate(parent);
					
					if (bf == -1)
					{
						parent->_bf = 1;
						cur->_bf = 0;
					}
					else if (bf == 1)
					{
						parent->_bf = 1;
						cur->_bf = -1;
					}
					
				}
				else
				{
					assert(false);
				}
				break; 
			}
			
		}
		return newNode;
	}
	// 由于在类外, 无法访问私有成员 _root, 所以在类内进行调用
	bool IsBalance()
	{
		return _IsBalance(_root);
	}
	private:
	// 中序遍历 打印
	void _InOrder(Node* root)
	{
		//Node *root = this->_root;
		if (root != nullptr)
		{
			_InOrder(root->_left);
			cout << root->_data << " ";
			_InOrder(root->_right);
		}
	}
	// 左单旋
	void LRotate(Node* parent)
	{
		// 记录当前结点prent 的右孩子结点sub 和 右孩子的左孩子结点subL
		Node *sub = parent->_right;
		Node *subL = sub->_left;
		
		// parent 与 subL 建立联系
		parent->_right = subL;
		if (subL)
			subL->_parent = parent;
		// parent 与 sub 建立联系---完成旋转
		// 两种情况:
		// 1. parent为根---sub变为根, sub的祖先指向 nullptr
		// 2. parent不为根---记录parent的根结点parentparent ,并使之与sub建立连接
		
		sub->_left = parent;
		if (parent == _root)
		{
			_root = sub;
			sub->_parent = nullptr;
			parent->_parent = sub;
		}
		else
		{
			Node *parentparent = parent->_parent;
			sub->_parent = parentparent;
			parent->_parent = sub;
			if (parent == parentparent->_left)
				parentparent->_left = sub;
			else
				parentparent->_right = sub;	
		}
		parent->_bf = 0;
		sub->_bf = 0;
	}
	// 右单旋
	void RRotate(Node *parent)
	{
		Node *sub = parent->_left;
		Node *subR = sub->_right;

		parent->_left = subR;
		if (subR)
			subR->_parent = parent;

		sub->_right = parent;
		
		if (parent == _root)
		{
			_root = sub;
			sub->_parent = nullptr;
			parent->_parent = sub;
		}
		else
		{
			Node *parentparent = parent->_parent;
			sub->_parent = parentparent;
			parent->_parent = sub;
			if (parent == parentparent->_left)
				parentparent->_left = sub;
			else
				parentparent->_right = sub;
		}
		parent->_bf = 0;
		sub->_bf = 0;
	}
	// 计算以 root 为根 树的高度
	int Highly(Node *root)
	{
		if (root == nullptr)
			return 0;
		int lefthigh = Highly(root->_left);
		int righthigh = Highly(root->_right);

		if (lefthigh > righthigh)
			return lefthigh + 1;
		else
			return righthigh + 1;
	}
	bool _IsBalance(Node *root)
	{
		if (root == nullptr)
			return true;
		int lefthigh = Highly(root->_left);
		int righthigh = Highly(root->_right);
		int diff = righthigh - lefthigh;
		if (diff != root->_bf)
		{
			cout << "结点" << root->_data << "左右子树高度差:" << diff << "平衡因子:" << root->_bf << endl;
			return false;
		}
		return abs(diff < 2) && _IsBalance(root->_left) && _IsBalance(root->_right);

	}

};

void Test()
{
	AVLTree<int> t;
	// 会发生双旋的两组数据
	int a[] = { 30, 20, 60, 10, 25, 50, 80, 5, 15, 12};
	int b[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (auto &e : a)
	{
		t.Insert(e);
	}
	t.Insert(5);
	if (t.Find(99) != nullptr)
		cout << "找到了" << endl;

	t.InOrder();
	
	cout << t.IsBalance();
}