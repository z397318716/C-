#include<iostream>
#include<algorithm>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int size1 = 0, size2 = 0;
		ListNode* ptr1 = l1;
		ListNode* ptr2 = l2;
		ListNode* res;
		while (ptr1 != nullptr || ptr2 != nullptr)
		{
			if (ptr1 != nullptr)
			{
				size1++;
				ptr1 = ptr1->next;
			}
			if (ptr2 != nullptr)
			{
				size2++;
				ptr2 = ptr2->next;
			}
		}
		if (size1 > size2)
			res = l1;
		else
			res = l2;
		ListNode* res1 = res;
		ptr1 = l1;
		ptr2 = l2;
		int tmp = 0;
		int flag = 0;
		int count = 0;
		for (int i = 0; i < max(size1, size2); ++i)
		{
			if (ptr1 != nullptr && ptr2 != nullptr)
				tmp = ptr1->val + ptr2->val + flag;
			if (ptr1 != nullptr && ptr2 == nullptr)
				tmp = ptr1->val + flag;
			if (ptr1 == nullptr && ptr2 != nullptr)
				tmp = ptr2->val + flag;
			count = tmp % 10;
			flag = tmp / 10;

			res1->val = count;
			if (ptr1 != nullptr)
				ptr1 = ptr1->next;
			if (ptr2 != nullptr)
				ptr2 = ptr2->next;
			if (res1->next != nullptr)
				res1 = res1->next;

		}
		if (flag != 0)
			res1->next = new ListNode(flag);
		return res;
	}
};