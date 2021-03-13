#pragma once
#include<iostream>
#include<stack>

template<class T>
struct BTNode {
	BTNode(T data = T())
		: _data(data),
		_lchild(nullptr),
		_rchild(nullptr) {}
	
	BTNode<T>* _lchild;
	BTNode<T>* _rchild;
	T _data;
};
template<class T>
class BTree {
public:
	typedef BTNode<T> Node;

	Node* _root;
public:
	// ����
	BTree()
		:_root(nullptr) {}
	// ����
	~BTree() {
		Destory(_root);
	}
	void Destory(Node* _root) {
		if (_root) {
			Destory(_root->_lchild);
			Destor(_root->_rchild);
		}
		_root = nullptr;
	}
};
// ����ǰ�����+������� ����һ��������
template<class T>
BTNode<T>* ConstructBTree(T* preOrder, T* midOrder, int len) {
	if (preOrder == nullptr || midOrder == nullptr || len == 0)
		return nullptr;
	//�ȸ�������ǰ��������ĵ�һ��ֵ���Ǹ��ڵ�ļ�ֵ
	T rootkey = preOrder[0];
	BTNode<int>* root = new BTNode<int>(rootkey);
	// ֻ��һ�����
	if (len == 1) {
		if (*preOrder == *midOrder) {
			return root;
		}
		else {
			return nullptr;
		}
	}
	// �������������ҵ������
	T* rootMidOrder = midOrder;
	// �����������
	int leftLen = 0;
	while (*rootMidOrder != rootkey && leftLen < len) {
		++rootMidOrder;
		++leftLen;
	}
	// ����������δ�ҵ�����㣬�������
	if (*rootMidOrder != rootkey)
		return nullptr;
	// ����������	
	if (leftLen > 0) {
		root->_lchild = ConstructBTree(preOrder + 1, midOrder, leftLen);
	}

	// ����������
	if (len - leftLen - 1 > 0) {
		root->_rchild = ConstructBTree(preOrder + leftLen + 1, rootMidOrder + 1, len - leftLen - 1);
	}
	return root;
}

