#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    // 剑指offer 05. 替换空格
    // https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
    string replaceSpace(string s) {
        // 解法一: 双指针原地修改---------------------------------
        /*
        int count = 0;
        int len = s.size();
        // 记录原字符串 空格 个数
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ' '){
                count++;
            }
        }
        if(count == 0)
            return s;
        // 扩容 原数组
        s.resize(s.size() + count * 2);
        // 从后向前原地修改
        for(int i = len-1, j = s.size()-1; i < j; i--,j--){
            if(s[i] != ' ')
                s[j] = s[i];
            else{
                s[j] = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                j -= 2;
            }
        }
        return s;
        */
        //  解法二:
        string res;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ')
                res.push_back(s[i]);
            else
                res.append("%20");
        }
        return res;
    }
    // 剑指offer 06. 从头到尾打印链表
    // https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
    // 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
        
    };
    void moth(ListNode* head, vector<int>& res) {
        if (head == nullptr)
            return;
        moth(head->next, res);
        res.push_back(head->val);
    }
    vector<int> reversePrint(ListNode* head) {
        // 方法一: 遍历链表, 元素存放在数组中, 最后倒转数组
        /*
        vector<int> v1;
        while(head != nullptr){
            v1.push_back(head->val);
            head = head->next;
        }
        vector<int> res(v1.rbegin(), v1.rend());
        return res;
        */
        // 方法二: 递归
        /*
        vector<int> res;
        moth(head, res);
        return res;
        */
        // 方法三: 栈 (陷入后出的特性) 感觉和方法一差不多, 只是方法一最后的倒转是用构造函数实现的
        /*
        stack<int> s1;
        vector<int> res;
        while(head){
            s1.push(head->val);
            head = head->next;
        }
        while(!s1.empty()){
            res.push_back(s1.top());
            s1.pop();
        }
        return res;
        */
        // 方法四: 利用vector的insert实现, 每次向首部插入元素
        vector<int> res;
        while (head) {
            res.insert(res.begin(), head->val);
            head = head->next;
        }
        return res;
    }
};

class CQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    CQueue() {}
    void appendTail(int value) {
        s1.push(value);
    }
    int deleteHead() {
        if (s2.empty() && s1.empty())
            return -1;
        else if (s2.empty() && !s1.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main() {


	return 0;
}