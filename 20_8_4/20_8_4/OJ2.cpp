#include<iostream>
#include<stack>
using namespace std;

/************************************************************************/
/*  力扣234
	请判断一个链表是否为回文链表。
	你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？*/
/************************************************************************/

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
bool isPalindrome(ListNode* head) {
	// 方法1: 将所有节点依次入栈, 然后在依次出栈比较每个结点的值
	// 时间复杂度 O(n)  空间复杂度O(n)
	if (head == nullptr)
		return true;
	stack<ListNode*> s1;
	ListNode* ptr = head;
	while (ptr != nullptr)
	{
		s1.push(ptr);
		ptr = ptr->next;
	}
	ListNode* tmp = s1.top();
	while (head != nullptr)
	{
		tmp = s1.top();
		if (tmp->val != head->val)
			return false;
		s1.pop();
		head = head->next;
	}
	return true;

	// 方法2: 双指针法, 
	// 1. 慢指针一个走一个节点, 快指针一次走两个节点,从而可以找到链表的中间位置
	// 2. 翻转链表后半部分,
	// 3. 从而开始比较, 时间复杂度 O(n) 空间复杂度O(1)

	ListNode* fast = head;
	ListNode* slow = head;

	// 列表节点为奇数, fast->next 为空时, slow为中间结点
	// 列表节点为偶数时, fast为空时, slow为链表后半截的起始结点
	while (fast == nullptr || fast->next == nullptr)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	// 翻转后半段列表

}