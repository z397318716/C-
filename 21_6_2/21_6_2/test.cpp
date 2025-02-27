#include<iostream>


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode* tmp = head->next;
        ListNode* pos = tmp;
        head->next = nullptr;
        while (tmp != nullptr) {
            pos = tmp->next;
            tmp->next = head;
            head = tmp;
            tmp = pos;
        }
        return head;
    }
};