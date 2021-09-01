///*
//// Definition for a Node.
//class Node {
//public:
//    int val;
//    Node* next;
//    Node* random;
//
//    Node(int _val) {
//        val = _val;
//        next = NULL;
//        random = NULL;
//    }
//};
//*/
//class Solution {
//public:
//    Node* copyRandomList(Node* head) {
//        // ������ÿ������ ���һ�� �µĽڵ㣬��������½ڵ����������������
//        if (head == nullptr)
//            return nullptr;
//        Node* cur = head;
//        // ����ƴ������
//        while (cur != nullptr) {
//            Node* tmp = new Node(cur->val);
//            tmp->next = cur->next;
//            cur->next = tmp;
//            cur = cur->next->next;
//        }
//        // Ϊ�½ڵ� �������ָ��
//        cur = head;
//        while (cur != nullptr) {
//            if (cur->random != nullptr)
//                cur->next->random = cur->random->next;
//            cur = cur->next->next;
//        }
//        // �������
//        Node* res = head->next; // ��¼������ͷ�ڵ�
//        cur = head;             // ��¼ԭ����ǰ�ڵ�
//        Node* tmp = res;        // ��¼������ǰ�ڵ�
//        // Node* tmp, res = cur->next;
//        while (cur != nullptr) {
//            cur->next = cur->next->next;
//            cur = cur->next;
//            if (tmp->next != nullptr)
//                tmp->next = tmp->next->next;
//            tmp = tmp->next;
//        }
//        return res;
//
//        /* // ��ϣʵ��
//        if(head == nullptr)
//            return nullptr;
//        map<Node*, Node*> m1;
//        Node* cur = head;
//        while(cur != nullptr){
//            m1[cur] = new Node(cur->val);
//            cur = cur->next;
//        }
//        cur = head;
//        while(cur != nullptr){
//            m1[cur]->next = m1[cur->next];
//            m1[cur]->random = m1[cur->random];
//            cur = cur->next;
//        }
//        return m1[head];
//        */
//    }
//};
//class CQueue {
//    stack<int> s1, s2;
//public:
//    CQueue() {
//
//    }
//
//    void appendTail(int value) {
//        s1.push(value);
//    }
//
//    int deleteHead() {
//        if (s1.empty() && s2.empty())
//            return -1;
//
//        if (s2.empty()) {
//            while (!s1.empty()) {
//                s2.push(s1.top());
//                s1.pop();
//            }
//        }
//        int tmp = s2.top();
//        s2.pop();
//        return tmp;
//    }
//public:
//    /** initialize your data structure here. */
//    MinStack() {
//
//    }
//
//    void push(int x) {
//        s1.push(x);
//        if (s2.empty() || s2.top() >= x)
//            s2.push(x);
//    }
//
//    void pop() {
//        if (s1.top() == s2.top())
//            s2.pop();
//        s1.pop();
//    }
//
//    int top() {
//        return s1.top();
//    }
//
//    int min() {
//        return s2.top();
//    }
//
//};
//
///**
// * Your CQueue object will be instantiated and called as such:
// * CQueue* obj = new CQueue();
// * obj->appendTail(value);
// * int param_2 = obj->deleteHead();
// */