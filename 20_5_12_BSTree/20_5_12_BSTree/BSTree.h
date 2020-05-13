#pragma once
/************************************************************************/
/* ����������ģ��ʵ��                                                                     */
/************************************************************************/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
	: _pleft(nullptr), _pright(nullptr), _data(data)
	{
	}
	BSTNode<T>* _pleft;
	BSTNode<T>* _pright;
	T _data;
};

template<class T>
class BSTree
{
private:
	typedef BSTNode<T> Node;
	typedef Node* PNode;
public:
	PNode _proot;

public:
	// ����
	BSTree()
		: _proot(nullptr)
	{}
	// ����
	~BSTree()
	{
		Destory(_proot);
	};
	// �����������Ĳ���	
	PNode Find(const T& data)
	{
		
		// ˼·: ���Ƚ�㲻ӦΪ�� 
		// 1. ����ڵ��ֵ data = ���ҵ�ֵdata, ���ظýڵ�
		// 2. ����ڵ��ֵ data < ���ҵ�ֵdata, �ڸý����������в���
		// 3. ����ڵ��ֵ data > ���ҵ�ֵdata, �ڸý����������в���
		// 4. �������δ�ҵ��򷵻� nullptr;
		PNode cur = _proot;
		while (cur)
		{
			if (cur->_data == data)
				return cur;
			else if (cur->_data < data)
			{
				cur = cur->_pright;
			}  else
				cur = cur->_pleft;
		}
		return nullptr;
	}
	
	bool Insert(const T& data)
	{
		// ˼·:
		// 1. ������ڵ�Ϊ��,��ֱ�Ӳ���(�����ֱ�Ӹ�ֵ) ---����true
		// 2. �����Ϊ��, ���ն������������� ����Ӧ�ò����λ��,Ȼ�����
		if (_proot == nullptr)
		{
			_proot = new Node(data);
			return true;
		}
		PNode cur = _proot;
		PNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data < cur->_data)
				cur = cur->_pleft;
			else if (data > cur->_data)
				cur = cur->_pright;
			else
				return false;	// �������Ľ���Ѿ�����, �����ʧ��
		}
		cur = new Node(data);
		// ���²���Ľ�����ӵ�����
		if (data > parent->_data)
			parent->_pright = cur;
		else
			parent->_pleft = cur;
		return true;
	}
	bool Erase(const T& data)
	{
		// �����Ϊ��, ��ֱ�ӷ���false,ɾ��ʧ��
		if (_proot == nullptr)
			return false;
		
		// ��������Ҫɾ�����, ����¼�ýڵ�ĸ��ڵ�
		PNode parent = nullptr;
		PNode cur = _proot;
		while (cur)
		{
			if (data == cur->_data)
				break;
			else if (data > cur->_data)
			{
				parent = cur;
				cur = cur->_pright;
			}
			else
			{
				parent = cur;
				cur = cur->_pleft;
			}
		}
		// ���Ҫɾ����㲻����, ��ɾ��ʧ��
		if (cur == nullptr)
			return false;

		// �ҵ�Ҫɾ������, �����������
		// 1.�ý���޺��ӽ��
		// 2.�ý��ֻ�����ӽ��
		// 3.�ý��ֻ���Һ��ӽ��
		// 4.�ý�����Һ��ӽ�㶼����
		// ��һ����������� 2��3���һ������

		// ���1,2
		if (cur->_pright == nullptr)
		{
			// ���Ҫɾ���Ľ��Ϊ���ڵ�,����ֻ�����ӽ��
			if (cur == _proot)
			{
				_proot = cur->_pleft;
				//delete Node(cur);
			}
			else
			{
				if (cur == parent->_pleft)
					parent->_pleft = cur->_pleft;
				else
					parent->_pright = cur->_pleft;
			}
		}
		// ���3
		else if (cur->_pleft == nullptr)
		{
			if (cur == _proot)
				_proot = cur->_pright;
			else
			{
				if (cur == parent->_pleft)
					parent->_pleft = cur->_pright;
				else
					parent->_pright = cur->_pright;
			}
		}
		// ���4
		// �ý���������������ڵ����,����ֱ��ɾ��
		// ����1: �ڸý������������ҵ����ֵ(�����Ҳ�Ľ��)���ý���ֵ����Ҫɾ���Ľ��,Ȼ����ɾ������ڵ�
		// ����2: �ڸý������������ҵ���Сֵ---����ʽ�뷽��1����
		else
		{
			if (cur->_pleft != nullptr && cur->_pright != nullptr)
			{
				// �����������ڵ��滻Ҫɾ���Ľ��
				PNode replace = cur->_pleft;
				PNode parent = cur;
				while (replace->_pright)
				{
					parent = replace;
					replace = replace->_pright;
				}
				cur->_data = replace->_data;
				if (replace == parent->_pleft)
					parent->_pleft = replace->_pleft;
				else
					parent->_pright = replace->_pleft;
				delete replace;
				replace = nullptr;
			}
			return true;
		}
		return false;
	}
	private:
		void Destory(PNode _proot)
		{
			if (_proot)
			{
				Destory(_proot->_pleft);
				Destory(_proot->_pright);
			}
			_proot = nullptr;
		}
		void _InorderPrint(PNode root)
		{
			if (root)
			{
				_InorderPrint(root->_pleft);
				cout << root->_data << "->";
				_InorderPrint(root->_pright);
			}
		}
};
void Test()
{
	BSTree<int> BST1;
	for (int i = 0; i < 10; i++)
	{
		BST1.Insert(i);
	}
	BST1._InorderPrint(BST1._proot);
	cout << endl;

}