///*
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) :
//            val(x), next(NULL) {
//    }
//};*/
//class Solution {
//public:
//    ListNode* ReverseList(ListNode* pHead) {
//        if (!pHead)
//            return nullptr;
//
//        ListNode* cur = pHead;
//
//        ListNode* next = cur->next;
//        ListNode* nnext;
//        if (next)
//            nnext = next->next;
//        pHead->next = nullptr;
//        while (next) {
//            next->next = cur;
//            cur = next;
//            next = nnext;
//            if (nnext) {
//                nnext = nnext->next;
//            }
//        }
//        return cur;
//
//
//    }
//};