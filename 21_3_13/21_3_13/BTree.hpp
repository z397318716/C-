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
// 根据前序遍历+中序遍历 构造一个二叉树
template<class T>
BTNode<T>* ConstructBTree(T* preOrder, T* midOrder, int len) {
	if (preOrder == nullptr || midOrder == nullptr || len == 0)
		return nullptr;
	//先根遍历（前序遍历）的第一个值就是根节点的键值
	T rootkey = preOrder[0];
	BTNode<int>* root = new BTNode<int>(rootkey);
	// 只有一个结点
	if (len == 1) {
		if (*preOrder == *midOrder) {
			return root;
		}
		else {
			return nullptr;
		}
	}
	// 在中序序列中找到根结点
	T* rootMidOrder = midOrder;
	// 左子树结点数
	int leftLen = 0;
	while (*rootMidOrder != rootkey && leftLen < len) {
		++rootMidOrder;
		++leftLen;
	}
	// 在中序序列未找到根结点，输入错误
	if (*rootMidOrder != rootkey)
		return nullptr;
	// 构建左子树	
	if (leftLen > 0) {
		root->_lchild = ConstructBTree(preOrder + 1, midOrder, leftLen);
	}

	// 构建右子树
	if (len - leftLen - 1 > 0) {
		root->_rchild = ConstructBTree(preOrder + leftLen + 1, rootMidOrder + 1, len - leftLen - 1);
	}
	return root;
}

