#include<iostream>
#include<unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        Node* res = head;
        unordered_map<Node*, Node*> m1;
        while (res != nullptr) {
            m1[res] = new Node(res->val);
            res = res->next;
        }
        res = head;
        while (res != nullptr) {
            m1[res]->next = m1[res->next];
            m1[res]->random = m1[res->random];
            res = res->next;
        }
        return m1[head];
    }
};