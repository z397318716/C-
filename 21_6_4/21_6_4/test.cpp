#include<iostream>
#include<string>
#include<stack>
using std::string;
using std::stack;



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while (1) {
            if (a == b)
                return a;
            a = a->next;
            b = b->next;
            if (a == nullptr && b != nullptr || a != nullptr && b == nullptr) {
                if (a == nullptr)
                    a = headB;
                if (b == nullptr)
                    b = headA;
            }

        }
        return a;
    }
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (st.empty()) {
                st.push(s[i]);
                continue;
            }
            char tmp = st.top();
            if (tmp == '(' && s[i] == ')' ||
                tmp == '{' && s[i] == '}' ||
                tmp == '[' && s[i] == ']') {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};