//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//struct Node {
//    int key;
//    int val;
//    struct Node* prev;
//    struct Node* next;
//    Node() :key(0), val(0), prev(nullptr), next(nullptr) {}
//    Node(int _key, int _val) :key(_key), val(_val), prev(NULL), next(NULL) {}
//};
//class Solution {
//private:
//    // ����˫�������ͷβָ�룬����С����
//    struct Node* pHead;
//    struct Node* pTail;
//    int size, capacity;
//    unordered_map<int, Node*> m1;
//public:
//    /**
//     * lru design
//     * @param operators int����vector<vector<>> the ops
//     * @param k int���� the k
//     * @return int����vector
//     */
//
//    vector<int> LRU(vector<vector<int> >& operators, int k) {
//        // ʹ��˫������͹�ϣ����ʵ��
//        // ��ʼ�� ˫������Ĳ���
//        pHead = new Node();
//        pTail = new Node();
//        size = 0, capacity = k;
//        pHead->next = pTail;
//        pTail->prev = pHead;
//        vector<int> res;
//        for (int i = 0; i < operators.size(); ++i) {
//            // ��������
//            if (operators[i].size() == 3) {
//                // ���Ȳ�ѯ�Ƿ��Ѿ����ڸýڵ㣬������ڣ������ֵ
//                if (m1.count(operators[i][1])) {
//                    Node* tmp = m1[operators[i][1]];
//                    tmp->val = operators[i][2];
//                    movetoHead(tmp);
//                    continue;
//                }
//                // �½����
//                Node* tmp = new Node();
//                tmp->key = operators[i][1];
//                tmp->val = operators[i][2];
//                // �����ϣ
//                m1[tmp->key] = tmp;
//                // ��������ͷ��
//                addHead(tmp);
//                ++size;
//                // ��������
//                if (size > capacity) {
//                    // ɾ��β�ڵ�ǰ�Ľڵ�
//                    Node* tmp = delNode();
//                    m1.erase(tmp->key);
//                    delete tmp;
//                    size--;
//                }
//            }
//            else {// ��ѯ����
//                if (m1.count(operators[i][1])) {
//                    res.push_back(m1[operators[i][1]]->val);
//                    // �ƶ��ýڵ㵽ͷ�ڵ��
//                    movetoHead(m1[operators[i][1]]);
//
//                }
//                else {
//                    res.push_back(-1);
//                }
//            }
//        }
//
//
//        return res;
//    }
//    // �ƶ��ڵ㵽ͷ�ڵ��
//    void movetoHead(Node* n) {
//        moveNode(n);
//        addHead(n);
//    }
//    // ��ͷ�ڵ����
//    void addHead(Node* n) {
//        n->prev = pHead;
//        n->next = pHead->next;
//        pHead->next->prev = n;
//        pHead->next = n;
//    }
//    // �Ƴ��ڵ㣬��ɾ��
//    void moveNode(Node* n) {
//        Node* l = n->prev;
//        Node* r = n->next;
//        l->next = r;
//        r->prev = l;
//    }
//    // ɾ���ڵ�
//    Node* delNode() {
//        Node* n = pTail->prev;
//        moveNode(n);
//        return n;
//    }
//};
//int main() {
//    vector<vector<int>> arr({ {1, 1, 1},{1, 2, 2},{1, 3, 2},{2, 1},{1, 4, 4},{2, 2} });
//    Solution A;
//    A.LRU(arr, 3);
//
//
//
//	return 0;
//}