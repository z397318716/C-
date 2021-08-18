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
//    // 定义双向链表的头尾指针，及大小参数
//    struct Node* pHead;
//    struct Node* pTail;
//    int size, capacity;
//    unordered_map<int, Node*> m1;
//public:
//    /**
//     * lru design
//     * @param operators int整型vector<vector<>> the ops
//     * @param k int整型 the k
//     * @return int整型vector
//     */
//
//    vector<int> LRU(vector<vector<int> >& operators, int k) {
//        // 使用双向链表和哈希表来实现
//        // 初始化 双向链表的参数
//        pHead = new Node();
//        pTail = new Node();
//        size = 0, capacity = k;
//        pHead->next = pTail;
//        pTail->prev = pHead;
//        vector<int> res;
//        for (int i = 0; i < operators.size(); ++i) {
//            // 插入数据
//            if (operators[i].size() == 3) {
//                // 首先查询是否已经存在该节点，如果存在，则更新值
//                if (m1.count(operators[i][1])) {
//                    Node* tmp = m1[operators[i][1]];
//                    tmp->val = operators[i][2];
//                    movetoHead(tmp);
//                    continue;
//                }
//                // 新建结点
//                Node* tmp = new Node();
//                tmp->key = operators[i][1];
//                tmp->val = operators[i][2];
//                // 插入哈希
//                m1[tmp->key] = tmp;
//                // 插入链表头部
//                addHead(tmp);
//                ++size;
//                // 容量已满
//                if (size > capacity) {
//                    // 删除尾节点前的节点
//                    Node* tmp = delNode();
//                    m1.erase(tmp->key);
//                    delete tmp;
//                    size--;
//                }
//            }
//            else {// 查询数据
//                if (m1.count(operators[i][1])) {
//                    res.push_back(m1[operators[i][1]]->val);
//                    // 移动该节点到头节点后
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
//    // 移动节点到头节点后
//    void movetoHead(Node* n) {
//        moveNode(n);
//        addHead(n);
//    }
//    // 向头节点添加
//    void addHead(Node* n) {
//        n->prev = pHead;
//        n->next = pHead->next;
//        pHead->next->prev = n;
//        pHead->next = n;
//    }
//    // 移除节点，不删除
//    void moveNode(Node* n) {
//        Node* l = n->prev;
//        Node* r = n->next;
//        l->next = r;
//        r->prev = l;
//    }
//    // 删除节点
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