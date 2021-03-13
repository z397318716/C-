// �������ı���
#include"BTree.hpp"

//---------------------------------------�ݹ��-------------------------------------------------------------
// ǰ�����
template<class T>
void RPreOrder(BTNode<T>* root) {
	if (root != nullptr) {
		std::cout << root->_data << '-';
		RPreOrder(root->_lchild);
		RPreOrder(root->_rchild);
	}
}
template<class T>
void RMidOrder(BTNode<T>* root) {
	if (root != nullptr) {
		RMidOrder(root->_lchild);
		std::cout << root->_data << ' ';
		RMidOrder(root->_rchild);
	}
}
template<class T>
void RPostOrder(BTNode<T>* root) {
	if (root) {
		RPostOrder(root->_lchild);
		RPostOrder(root->_rchild);
		std::cout << root->_data << ' ';
	}
}
//----------------------------------------------------------------------------------------------
// ------------------------------------------------�ǵݹ��-------------------------------------
// �ǵݹ�ǰ�����---���� stack ʵ�� 
// ǰ��ǵݹ�� ��1��
template<class T>
void PreOr(BTNode<T>* root) {
	std::stack<BTNode<T>*> tmp;
	while (root) {
		std::cout << root->_data << ' ';
		if (root->_rchild)
			tmp.push(root->_rchild);
		if (root->_lchild)
			root = root->_lchild;
		else {
			if (!tmp.empty()) {
				root = tmp.top();
				tmp.pop();
			}
			else
				break;
		}
	}
}
// ǰ��ǵݹ�� ��2��
template<class T>
void PreOr1(BTNode<T>* root) {
	std::stack<BTNode<T>*> tmp;
	if (root)
		tmp.push(root);
	while (!tmp.empty()) {
		root = tmp.top();
		std::cout << root->_data << ' ';
		tmp.pop();
		if (root->_rchild)
			tmp.push(root->_rchild);
		if (root->_lchild)
			tmp.push(root->_lchild);
	}
}
// ��������ǵݹ��
template<class T>
void MidOr(BTNode<T>* root) {
	std::stack<BTNode<T>*> tmp;
	while (root || !tmp.empty()) {
		while (root) {
			tmp.push(root);
			root = root->_lchild;
		}
		root = tmp.top();
		tmp.pop();
		std::cout << root->_data << ' ';
		root = root->_rchild;
	}
}
// �������--�ǵݹ��1
// ����ǰ�����ԭ��-------���������   ���Ҹ�  ��������  ������
// ���Կ��԰���  ���������   Ȼ�󽫱������ ������ʾ.
template<class T>
void PostOr(BTNode<T>* root) {
	std::stack<BTNode<T>*> tmp,res;
	if(root)
		tmp.push(root);
	while (!tmp.empty()) {
		root = tmp.top();
		tmp.pop();
		res.push(root);
		if (root->_lchild)
			tmp.push(root->_lchild);
		if (root->_rchild)
			tmp.push(root->_rchild);
	}
	while (!res.empty()) {
		std::cout << res.top()->_data << ' ';
		res.pop();
	}
}


int main() {
	
	int preorder[] = { 1,2,4,7,3,5,6,8 };
	int midorder[] = { 4,7,2,1,5,3,8,6 };
	int len = sizeof(preorder) / sizeof(preorder[0]);
	BTNode<int>* root = ConstructBTree<int>(preorder, midorder, len);

	RPreOrder(root);
	std::cout << std::endl;
	RMidOrder(root);
	std::cout << std::endl;
	RPostOrder(root);
	std::cout << std::endl;
	PreOr1(root);
	std::cout << std::endl;
	MidOr(root);
	std::cout << std::endl;
	PostOr(root);
	std::cout << std::endl;
	MYqian(root);
	return 0;
}