#include<iostream>
#include<stack>
using namespace std;

/************************************************************************/
/*  ����234
	���ж�һ�������Ƿ�Ϊ��������
	���ܷ��� O(n) ʱ�临�ӶȺ� O(1) �ռ临�ӶȽ�����⣿*/
/************************************************************************/

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
bool isPalindrome(ListNode* head) {
	// ����1: �����нڵ�������ջ, Ȼ�������γ�ջ�Ƚ�ÿ������ֵ
	// ʱ�临�Ӷ� O(n)  �ռ临�Ӷ�O(n)
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

	// ����2: ˫ָ�뷨, 
	// 1. ��ָ��һ����һ���ڵ�, ��ָ��һ���������ڵ�,�Ӷ������ҵ�������м�λ��
	// 2. ��ת�����벿��,
	// 3. �Ӷ���ʼ�Ƚ�, ʱ�临�Ӷ� O(n) �ռ临�Ӷ�O(1)

	ListNode* fast = head;
	ListNode* slow = head;

	// �б�ڵ�Ϊ����, fast->next Ϊ��ʱ, slowΪ�м���
	// �б�ڵ�Ϊż��ʱ, fastΪ��ʱ, slowΪ������ص���ʼ���
	while (fast == nullptr || fast->next == nullptr)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	// ��ת�����б�

}