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
	int _bf;	// ƽ������

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
				//parent->_bf++;	// �����丸�ڵ��ƽ������
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
		// ��¼�²���Ľڵ�
		Node *newnode = new Node(kv);
		// �ж��²���Ľ�����丸�������ӻ����Һ��ӽڵ�
		cur = newnode;
		cur->_bf = 0;
		if (parent->_kv.first > kv.first)
			parent->_left = cur;
		else
			parent->_right = cur;
		// �²���ڵ������丸�ڵ�(������ ���������ӹ�ϵ)
		cur->_parent = parent;

		/* ƽ������
			�����ڵ��ƽ��������0, �����ڵ������ƽ�����ӿ��ܻ��ܵ�Ӱ��
			1. �߶ȱ仯�� parent��������, parent->_bf += 1;
			2. �߶ȱ仯�� parent��������, parent->_bf -= 1;

			ͨ�� cur ��λ�ø��� parent ��ƽ������, ������ɺ�
			1. ��� parent->_bf == 1 || -1, ˵��parentΪ���������ĸ߶�Ҳ����, �������ϸ���
			2. ��� parent->_bf == 2 || -2, ˵��parentΪ���������Ѿ���ƽ��, ��Ҫ��ת����
			3. ���parent->_bf == 0, ˵��parent���ڵ�����ԭ���ĸ߶���1/-1. ���ڰѰ����Ǳ߸�������, parent���ڵ������߶Ȳ���, ֹͣ����.
		*/

		// ����ƽ������
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
				// ��ת����------�����ƻ�������������ԭ��
				
				// �ҵ���
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				// ����
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				// ˫��
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					// �ȶ� cur ��������-�ڶ� parent �����ҵ���
					// �˴���Ҫ���� ˫�������µ�ƽ�����Ӹ�������
					
					RotateL(cur);
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					// ������ ������
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

	// ��������
	void RotateL(Node *parent)
	{
		// ��¼��ǰ�����Һ��ӽ��---(��ǰ���ָƽ������Ϊ2�Ľ��,��Ҫ������������
		Node *subR = parent->_right;
		Node *subRL = subR->_left;

		// ��ǰ�����Һ��ӵ����ӽڵ��� ��ǰ��㽨����ϵ
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
	// ��������
	void RotateR(Node *parent)
	{
		// ��¼��ǰ�ڵ�����ӽڵ� -- (��ǰ�ڵ�Ϊƽ������Ϊ -2 �Ľ��)
		Node *subL = parent->_left;
		Node *subLR = subL->_right;

		// ��ǰ�������ӵ��Һ��ӽ�� �� ��ǰ��� ��������
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		// ��ǰ�������ӽ���뵱ǰ��� ������������
		// ��ǰ��� ��Ϊ�����ӽ����Һ��ӽ��
		// �˴���Ҫ���� ��ǰ����Ƿ�Ϊ��
		subL->_right = parent;
		if (parent == _root)
		{
			_root = subL;
			parent->_parent = subL;
			subL->_parent = nullptr;
		}
		else
		{
			// ��ǰ��㲻Ϊ��
			// ��Ҫ��¼��ǰ���ĸ����, ��ʹ���ڵ���subL��������
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
			cout << root->_kv.first << "ƽ�������쳣" << root->_bf << endl;
		}

		// �ݹ��ж�AVL���Ƿ�ƽ��
		return abs(leftHeight - rightHeight) < 2 
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}
	bool IsBalance()
	{
		return _IsBalance(_root);
	}
private:
	Node* _root = nullptr;		// �˴����ǳ�ʼ��, ��ȱʡֵ----�����������ʱ��ȱʡֵ
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
