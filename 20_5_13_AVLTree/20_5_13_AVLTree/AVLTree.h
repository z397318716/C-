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
		// �ж��²���Ľ�����丸�������ӻ����Һ��ӽڵ�
		cur = new Node(kv);
		if (parent->_kv.first > kv.first)
			parent->_left = cur;
		else
			parent->_right = cur;
		// �²���ڵ������丸�ڵ�(������ ���������ӹ�ϵ)
		cur->_parent = parent;

		// ƽ������


		return make_pair(cur, true);
	}
private:
	Node* _root = nullptr;		// �˴����ǳ�ʼ��, ��ȱʡֵ----�����������ʱ��ȱʡֵ
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
