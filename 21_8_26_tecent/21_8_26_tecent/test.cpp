#include <iostream>


using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int x):val(x),next(nullptr){
		
	}
};




void Nodeerase(Node* head, int x) {
	if (head == nullptr)
		return;
	// 如果删除的是头节点
	if (head->val == x) {
		head = head->next;
		return;
	}
	Node* cur = head;
	Node* father = head;
	// 删除非 头节点
	while (cur->val != x) {
		father = cur;
		cur = cur->next;
	}
	father->next = cur->next;
}
int main() {

	struct Node* head = new Node(1);
	
	Node* head1 = new Node(2);
	Node* head2 = new Node(3);
	head->next = head1;
	head1->next = head2;
	
	Nodeerase(head, 2);

	while (head != nullptr) {
		cout << head->val << '-';
		head = head->next;
	}

	return 0;
}