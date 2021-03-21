#pragma once
#include<iostream>
#include<stack>
#include<queue>

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

