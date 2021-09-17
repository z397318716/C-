///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode(int x) : val(x), next(NULL) {}
// * };
// */
//class Solution {
//public:
//    ListNode* deleteNode(ListNode* head, int val) {
//        if (head && head->val == val)
//            return head->next;
//        ListNode* cur = head;
//        ListNode* prev = nullptr;
//        while (cur && cur->val != val) {
//            prev = cur;
//            cur = cur->next;
//        }
//        prev->next = cur->next;
//        return head;
//    }
//
//    ListNode* getKthFromEnd(ListNode* head, int k) {
//        // 使用 哈希表 进行存储，一次遍历即可
//        /*
//        unordered_map<int, ListNode*> m1;
//        ListNode* cur = head;
//        int pos = 1;
//        while(cur){
//            m1[pos++] = cur;
//            cur = cur->next;
//        }
//        return m1[pos - k];
//        */
//        ListNode* slow = head, * fast = head;
//        while (k--) {
//            fast = fast->next;
//        }
//        while (fast != nullptr) {
//            slow = slow->next;
//            fast = fast->next;
//        }
//        return slow;
//    }
//};