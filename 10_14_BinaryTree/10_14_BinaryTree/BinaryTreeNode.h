//#pragma once
//#include <iostream>
//#include <stack>
//#include <vector>
//#include <queue>
//
//using namespace std;
//// ����������,������ǰ����ֵ,��������ָ��,�Һ���ָ��
//template <class T>
//struct binary_tree_node
//{
//	T _data;
//	binary_tree_node<T> *_left;
//	binary_tree_node<T> *_right;
//
//	binary_tree_node(const T & x) :
//		_data(x),
//		_left(NULL),
//		_right(NULL)
//	{}
//
//};
//
//template<class T> 
//class binary_tree
//{
//	typedef binary_tree_node<T>node;
//public:
//	binary_tree(T* a, size_t n, const T&invalid)
//	{
//		size_t index = 0;
//		_root = _create_tree(a, n, invalid, index);
//	}
//	node*copy_tree(node* root)
//	{
//		if (root == NULL)
//		{
//			return NULL;
//		}
//		node* new_root = new node(root->_data);
//		new_root->_left = copy_tree(root->_left);
//		new_root->_right = copy_tree(root->_right);
//
//		return new_root;
//	}
//	binary_tree(const binary_tree<T>& t)
//	{
//		_root = copy_tree(t._root);
//	}
//	binary_tree<T>& operator=(binary_tree<T> t)
//	{
//		swap(_root, t._root);
//		return *this;
//	}
//	~binary_tree()
//	{
//		destory(_root);
//		_root = NULL;
//	}
//	void destory(node* root)
//	{
//		if (root == NULL)
//			return;
//		destory(root->_left);
//		destory(root->_right);
//
//		delete root;
//	}
//
//	//����һ�ö�����
//	node* _create_tree(T*a, size_t n, const T& invalid, size_t& index)
//	{
//		node* root = NULL;
//		if (a[index] != invalid)
//		{
//			root = new node(a[index]);
//			root->_left = _create_tree(a, n, invalid, ++index);
//			root->_right = _create_tree(a, n, invalid, ++index);
//		}
//		return root;
//	}
//
//	//ǰ�����
//	void prev_order()
//	{
//		_prev_order(_root);
//		cout << endl;
//	}
//	void _prev_order(node*root)
//	{
//		if (root == NULL)
//			return;
//		cout << root->_data << "  ";
//		_prev_order(root->_left);
//		_prev_order(root->_right);
//	}
//
//	//�ǵݹ��ǰ�����
//	void prev_order_no_r()
//	{
//		node* cur = _root;
//		stack<node*>s;
//		while (cur || !s.empty())
//		{
//			while (cur)
//			{
//				cout << cur->_data << "  ";
//				s.push(cur);
//				cur = cur->_left;
//			}
//			node* top = s.top();
//			s.pop();
//			//������
//			cur = top->_right;
//		}
//		cout << endl;
//	}
//
//	//�������
//	void in_order()
//	{
//		_in_order(_root);
//		cout << endl;
//	}
//	void _in_order(node* root)
//	{
//		//���������������->���ڵ�->������
//		if (root == NULL)
//			return;
//
//		_in_order(root->_left);
//		cout << root->_data << "  ";
//		_in_order(root->_right);
//	}
//
//	/*
//	* 
//	*
//	*
//	*/
//	//�ǵݹ���������
//	void in_order_no_r()
//	{
//		node* cur = _root;
//		stack<node*> s;
//		while (cur || !s.empty())
//		{
//			while (cur)						// �ӵ�ǰ�ڵ㿪ʼ������������,
//			{
//				s.push(cur);				// �����нڵ���ջ,ֱ��û����ڵ�
//				cur = cur->_left;
//			}
//											// 
//			node* top = s.top();			// ȡջ��,����ӡջ������
//			cout << top->_data << "  ";		
//			s.pop();						// ��ջ
//
//			cur = top->_right;				// ����ջ���ڵ��������,��������,
//		}
//		cout << endl;
//	}
//	
//};
//
//
