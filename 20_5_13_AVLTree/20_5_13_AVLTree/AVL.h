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

	// �������Һ��ӽ��͸����
	AVLTreeNode<T> *_left;	
	AVLTreeNode<T> *_right;
	AVLTreeNode<T> *_parent;
	T _data;
	int _bf;	// ����ƽ������
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

	// ����������ٶ�����
	// ������������, ������������
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
	// �ǵݹ����
	// �����д���Ҫ���ҵ�Ԫ��, ���ظ�Ԫ�����ڽ��, ���򷵻ؿ�
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
		// �Ȱ��ն����������ķ�ʽ�����½ڵ�
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
		// ��¼�²�����
		Node *newNode = new Node(data);
		// �ж��½�����丸�������ӽ�㻹���Һ��ӽ��, ����������
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

		// �²��������Ҫ ����ƽ������
		// �����ڵ������ƽ�����ӻᷢ���仯
		// �������Ϊ parent �����ӽ�� parent��ƽ������ -1;
		// �����ڵ�Ϊ parent ���Һ��ӽ�� parent��ƽ������ +1;
		
		while (parent)
		{
			// ��ǰ���������ڵ�, ƽ������ -1;
			if (cur == parent->_left)
				parent->_bf -= 1;
			// ��ǰ��������ҽڵ�, ƽ������ +1;
			else if (cur == parent->_right)
				parent->_bf += 1;
			
			// ������º�, parent ��ƽ������ Ϊ 0 , ˵�� parent δ����ǰƽ������Ϊ 1/-1 , �²�����ʹ parnet ���������߶���ͬ, ����Ҫ���ϸ���
			if (parent->_bf == 0)
				break;
			// ������º�, parent ��ƽ������Ϊ 1 ���� -1, ˵���� parent Ϊ�����������������˱仯, �Ӷ���Ӱ�����ȵ�ƽ������, ��Ҫ���ϼ�������
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			// ������º�, parent ��ƽ������Ϊ 2/-2, ˵���� parent Ϊ�������������߶��Ѿ���ƽ��, ��Ҫ������ת����
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// ��ת��Ϊ�������: ����, �ҵ���, ˫��(�ַ�Ϊ ������������, ������������)
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					// ����
					LRotate(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					// �ҵ���
					RRotate(parent);
				}
				// ˫���������Ҫ��ƽ�����ӽ��е�������
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					int bf = cur->_left->_bf;
					// �ȶ�cur��������, �ڶ� parent ��������
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
					// ������, ������
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
	// ����������, �޷�����˽�г�Ա _root, ���������ڽ��е���
	bool IsBalance()
	{
		return _IsBalance(_root);
	}
	private:
	// ������� ��ӡ
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
	// ����
	void LRotate(Node* parent)
	{
		// ��¼��ǰ���prent ���Һ��ӽ��sub �� �Һ��ӵ����ӽ��subL
		Node *sub = parent->_right;
		Node *subL = sub->_left;
		
		// parent �� subL ������ϵ
		parent->_right = subL;
		if (subL)
			subL->_parent = parent;
		// parent �� sub ������ϵ---�����ת
		// �������:
		// 1. parentΪ��---sub��Ϊ��, sub������ָ�� nullptr
		// 2. parent��Ϊ��---��¼parent�ĸ����parentparent ,��ʹ֮��sub��������
		
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
	// �ҵ���
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
	// ������ root Ϊ�� ���ĸ߶�
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
			cout << "���" << root->_data << "���������߶Ȳ�:" << diff << "ƽ������:" << root->_bf << endl;
			return false;
		}
		return abs(diff < 2) && _IsBalance(root->_left) && _IsBalance(root->_right);

	}

};

void Test()
{
	AVLTree<int> t;
	// �ᷢ��˫������������
	int a[] = { 30, 20, 60, 10, 25, 50, 80, 5, 15, 12};
	int b[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (auto &e : a)
	{
		t.Insert(e);
	}
	t.Insert(5);
	if (t.Find(99) != nullptr)
		cout << "�ҵ���" << endl;

	t.InOrder();
	
	cout << t.IsBalance();
}