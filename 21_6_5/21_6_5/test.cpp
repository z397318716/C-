/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 构造一个头节点, 指向原头节点,
        ListNode* tmp = new ListNode(0, head);
        ListNode* left = tmp;
        while (left->next != nullptr) {
            if (left->next->val != val) {
                left = left->next;
            }
            else {
                left->next = left->next->next;
            }
        }
        return tmp->next;

    }
};