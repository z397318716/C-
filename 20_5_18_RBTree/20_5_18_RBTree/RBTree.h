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
template<class K, class V>
class RBTree
{
	typedef RBTreeNode<pair<K, V>> Node;
private:
	Node *_root;
	Node *_Nil;
public:
	RBTree()
		:_root(nullptr)
	{}

	bool Insert(const pair<K, V> &kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
		}


		return true;
	}
};