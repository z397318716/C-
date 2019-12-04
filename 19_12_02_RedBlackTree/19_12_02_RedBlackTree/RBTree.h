#pragma once

enum Color {RED, BLACK};

template<class T>
class RBTreeNode
{
	T m_data;
	RBTreeNode<T> *m_left;
	RBTreeNode<T> *m_right;
	RBTreeNode<T> *m_parent;
	//bool m_color;
	Color m_color;				// 课件中的写法

public:
	RBTreeNode(const T & val = T(), Color = RED) :
		m_left(nullptr),
		m_right(nullptr),
		m_parent(nullptr),
		m_data(val),
		m_color(color)
	{

	}
};

template <class T>
class RBTree
{
	RBTreeNode<T> *m_head;

public:
	
};