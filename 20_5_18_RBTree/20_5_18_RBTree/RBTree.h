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
		// ������ڵ�Ϊ null
		if (_root == nullptr)
		{
			_root = new Node(val);
			_root->_col = black;
			return true;
		}
		// ����㲻Ϊ null
		else
		{
			/************************************************************************/
			/* ���ն����������ķ�ʽ�����½��                                          */
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

			// ��ʱ, cur���ӦΪnull, ����Ҫ�����λ��
			Node *newNode = new Node(val);
			cur = newNode;

			cur->_parent = parent;
			if (cur->_data < parent->_data)
				parent->_left = cur;
			else
				parent->_right = cur;

			/* ����½������, ������������Ƿ��ƻ�
			 δ�ƻ����������, ��ֱ���˳�, ���������ת,��ɫ����
			*/
			// ����²�����ĸ�����Ǻ�ɫ���, �����������δ���ƻ�����ֱ���˳�
			if (parent->_col == black)
				return true;
			/* �²�����Ĭ����ɫΪ��ɫ, ����丸���ҲΪ��ɫ, ����ƻ������������---�����������ĺ���
				��ʱ���ж���������ܷ���, �˴�����Լ��: 
				cur ��ʾ��ǰ���(��ɫ)
				parent ��ʾ cur �ĸ����
				gparent ��ʾ parent �ĸ����, �� cur ���游���
				uncle ��ʾ parent ���ֵܽ��, �� cur ��������
			*/
			
			while (parent != nullptr && parent->_col == red)
			{
				Node *gparent = parent->_parent;	// ��Ϊparent����, �Ҳ��Ǻ�ɫ���, ��parent���Ǹ�, ���� parent �϶����ڸ���� gparent
				Node *uncle = nullptr;
				if (parent == gparent->_left)
				{
					uncle = gparent->_right;
				} else
				{
					uncle = gparent->_left;
				}

				// ���һ: parent Ϊ��ɫ���, gparent Ϊ��ɫ���, uncle��������Ϊ��ɫ���
				if (uncle != nullptr && uncle->_col == red)
				{
					// �� parent �� uncle �����, gparent ���, ��Ϊgparent�����ܻ������ĸ������ɫ������ͻ, ���Լ������ϵ���
					parent->_col = black;
					uncle->_col = black;
					gparent->_col = red;
					// �������ϵ���
					cur = gparent;
					parent = cur->_parent;
				}
				// �����: cur Ϊ����, parent Ϊ����, gparent Ϊ�ڽ��, uncle���Ϊ��ɫ���, ���߲�����
				// �����: cur Ϊ����, parent Ϊ����, gparent Ϊ�ڽ��, uncle���Ϊ��ɫ���, ���߲�����
				else 
				{
					// ���parent�� gparent �����ӽ��, ��� gparent ���� �ҵ���----
					// ���parent�� gparent ���Һ��ӽ��, ��� gparent ���� ����----
					// ���parent ��Ϊ��ɫ, gparent ��Ϊ��ɫ
					if (parent == gparent->_left)
					{
						// �����,  ������ɺ��ɲ����������
						if (cur == parent->_right)
						{
							RotateL(parent);
							swap(cur, parent);	// �����������������, ���±�� cur parent λ��ʹ֮�������һ��
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
			cout << "���ڵ㲻Ϊ��ɫ" << endl;
			return false;
		}
		// ͳ�Ƴ�һ��·���Ϻ�ɫ��������
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
	// ���ٺ����
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
	// ǰ����������
	void _PreOrder(RBTreeNode<T> *root)
	{
		if (root != nullptr)
		{
			cout << root->_data << ' ';
			_PreOrder(root->_left);
			_PreOrder(root->_right);
		}
	}
	// ������������
	void _Inorder(RBTreeNode<T> *root)
	{
		if (root != nullptr)
		{
			_Inorder(root->_left);
			cout << root->_data << ' ';
			_Inorder(root->_right);
		}
	}

	// ������������
	void _PostOrder(RBTreeNode<T> *root)
	{
		if (root != nullptr)
		{
			_PostOrder(root->_left);
			_PostOrder(root->_right);
			cout << root->_data << ' ';
		}
	}
	// ����
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
	// �ҵ���
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
				cout << "������ÿ��·���еĺ�ɫ�����Ŀ��ͬ" << endl;
				return false;
			}
			return true;
		}
		// ͳ�Ƶ�ǰ·����ɫ�������
		if (root->_col == black)
			k++;

		// ����Ƿ��������ĺ�ɫ������
		Node *parent = root->_parent;
		if (parent != nullptr && parent->_col == red && root->_col == red)
		{
			cout << "���������ĺ�ɫ���" << endl;
			return false;
		}

		return _IsRBTree(root->_left, k, blackcount) && _IsRBTree(root->_right, k, blackcount);
	}
};

// ���Գ���
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