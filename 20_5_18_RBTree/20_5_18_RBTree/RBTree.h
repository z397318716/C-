#pragma once
#include <iostream>

using namespace std;
enum Colour
{
	red,
	black
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T> *_left;
	RBTreeNode<T> *_right;
	RBTreeNode<T> *_parent;
	T _data;
	Colour _col;
	RBTreeNode(const T& data) :
		_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(red)
	{}
};
template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
private:
	Node *_root;
	Node *_Nil;
public:
	RBTree()
		:_root(nullptr)
	{}
	~RBTree()
	{
		//Destory();
	}
	RBTree(const RBTree& t)
	{
		return t;
	}

	void PreOrder()
	{
		_PreOrder(_root);
	}
	void Inorder()
	{
		_Inorder(_root);
	}
	void PostOrder()
	{
		_PostOrder(_root);
	}


	bool Insert(const T &val)
	{
		// 如果根节点为 null
		if (_root == nullptr)
		{
			_root = new Node(val);
			_root->_col = black;
			return true;
		}
		// 根结点不为 null
		else
		{
			/************************************************************************/
			/* 按照二叉搜索树的方式插入新结点                                          */
			/************************************************************************/
			Node *cur = _root;
			Node *parent = _root;
			while (cur)
			{
				if (cur->_data < val)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_data > val)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			// 此时, cur结点应为null, 处于要插入的位置
			Node *newNode = new Node(val);
			cur = newNode;

			cur->_parent = parent;
			if (cur->_data < parent->_data)
				parent->_left = cur;
			else
				parent->_right = cur;

			/* 检测新结点插入后, 红黑树的性质是否被破坏
			 未破坏红黑树性质, 则直接退出, 否则进行旋转,着色处理
			*/
			// 如果新插入结点的父结点是黑色结点, 红黑树的性质未被破坏可以直接退出
			if (parent->_col == black)
				return true;
			/* 新插入结点默认颜色为红色, 如果其父结点也为红色, 则会破坏红黑树的性质---不能有连续的红结点
				此时会有多种情况可能发生, 此处我们约定: 
				cur 表示当前结点(红色)
				parent 表示 cur 的父结点
				gparent 表示 parent 的父结点, 即 cur 的祖父结点
				uncle 表示 parent 的兄弟结点, 即 cur 的叔叔结点
			*/
			
			while (parent != nullptr && parent->_col == red)
			{
				Node *gparent = parent->_parent;	// 因为parent存在, 且不是黑色结点, 则parent不是根, 所以 parent 肯定存在父结点 gparent
				Node *uncle = nullptr;
				if (parent == gparent->_left)
				{
					uncle = gparent->_right;
				} else
				{
					uncle = gparent->_left;
				}

				// 情况一: parent 为红色结点, gparent 为黑色结点, uncle结点存在且为红色结点
				if (uncle != nullptr && uncle->_col == red)
				{
					// 将 parent 与 uncle 结点变黑, gparent 变红, 因为gparent变红可能会与它的根结点颜色发生冲突, 所以继续向上调整
					parent->_col = black;
					uncle->_col = black;
					gparent->_col = red;
					// 继续向上调整
					cur = gparent;
					parent = cur->_parent;
				}
				// 情况二: cur 为红结点, parent 为红结点, gparent 为黑结点, uncle结点为黑色结点, 或者不存在
				// 情况三: cur 为红结点, parent 为红结点, gparent 为黑结点, uncle结点为黑色结点, 或者不存在
				else 
				{
					// 如果parent是 gparent 的左孩子结点, 则对 gparent 进行 右单旋----
					// 如果parent是 gparent 的右孩子结点, 则对 gparent 进行 左单旋----
					// 最后将parent 变为黑色, gparent 变为红色
					if (parent == gparent->_left)
					{
						// 情况三,  操作完成后变成操作二的情况
						if (cur == parent->_right)
						{
							RotateL(parent);
							swap(cur, parent);	// 变成了情况二的情况后, 重新标记 cur parent 位置使之与情况二一样
						}
						parent->_col = black;
						gparent->_col = red;
						RotateR(gparent);
						break;
					}
					else
					{
						if (cur == parent->_left)
						{
							RotateR(parent);
							swap(cur, parent);	
						}
						parent->_col = black;
						gparent->_col = red;
						RotateL(gparent);
						break;
					}
					
				}

				
			}


		}

		_root->_col = black;
		return true;
	}
	bool IsRBTree()
	{
		if (_root == nullptr)
			return true;
		if (_root->_col != black)
		{
			cout << "根节点不为黑色" << endl;
			return false;
		}
		// 统计出一条路径上黑色结点的数量
		size_t blackcount = 0;
		Node *cur = _root;
		while (cur != nullptr)
		{
			if (black == cur->_col)
				blackcount++;
			cur = cur->_left;
		}
		size_t k = 0;
		return _IsRBTree(_root, k, blackcount);
	}
private:
	// 销毁红黑树
	void Destory()
	{
		if (_root == nullptr)
			return;
		if (_root->_left != nullptr)
			return Destory(_root->_left);
		if (_root->_right != nullptr)
			return Destory(_root->_right);

		delete _root;
		_root = nullptr;
	}
	// 前序遍历红黑树
	void _PreOrder(RBTreeNode<T> *root)
	{
		if (root != nullptr)
		{
			cout << root->_data << ' ';
			_PreOrder(root->_left);
			_PreOrder(root->_right);
		}
	}
	// 中序遍历红黑树
	void _Inorder(RBTreeNode<T> *root)
	{
		if (root != nullptr)
		{
			_Inorder(root->_left);
			cout << root->_data << ' ';
			_Inorder(root->_right);
		}
	}

	// 后序遍历红黑树
	void _PostOrder(RBTreeNode<T> *root)
	{
		if (root != nullptr)
		{
			_PostOrder(root->_left);
			_PostOrder(root->_right);
			cout << root->_data << ' ';
		}
	}
	// 左单旋
	void RotateL(Node *parent)
	{
		Node* sub = parent->_right;
		Node* subL = sub->_left;
		
		parent->_right = subL;
		if (subL != nullptr)
			subL->_parent = parent;

		sub->_left = parent;

		if (parent == _root)
		{
			parent->_parent = sub;
			_root = sub;
			sub->_parent = nullptr;
		}
		else
		{
			Node *parentparent = parent->_parent;
			parent->_parent = sub;
			if (parent == parentparent->_left)
				parentparent->_left = sub;
			else
				parentparent->_right = sub;
			sub->_parent = parentparent;
		}
	}
	// 右单旋
	void RotateR(Node *parent)
	{
		Node *sub = parent->_left;
		Node *subR = sub->_right;
		
		parent->_left = subR;
		if (subR != nullptr)
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
			parent->_parent = sub;
			if (parent == parentparent->_left)
				parentparent->_left = sub;
			else
				parentparent->_right = sub;
			sub->_parent = parentparent;
		}
	}

	bool _IsRBTree(RBTreeNode<T> *root, size_t k, const size_t blackcount)
	{
		if (root == nullptr)
		{
			if (k != blackcount)
			{
				cout << "不满足每条路径中的黑色结点数目相同" << endl;
				return false;
			}
			return true;
		}
		// 统计当前路径黑色结点数量
		if (root->_col == black)
			k++;

		// 检测是否有连续的红色结点出现
		Node *parent = root->_parent;
		if (parent != nullptr && parent->_col == red && root->_col == red)
		{
			cout << "出现连续的红色结点" << endl;
			return false;
		}

		return _IsRBTree(root->_left, k, blackcount) && _IsRBTree(root->_right, k, blackcount);
	}
};

// 测试程序
void Test()
{
	RBTree<int> test1;
	int a[] = { 10, 40, 30, 60, 90, 70, 20, 50, 80 };
	for (auto &e : a)
	{
		test1.Insert(e);
	}
	test1.PreOrder();
	cout << endl;
	test1.Inorder();
	endl(cout);
	test1.PostOrder();
	test1.IsRBTree();

}