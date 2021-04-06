#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    // ��ָoffer 05. �滻�ո�
    // https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
    string replaceSpace(string s) {
        // �ⷨһ: ˫ָ��ԭ���޸�---------------------------------
        /*
        int count = 0;
        int len = s.size();
        // ��¼ԭ�ַ��� �ո� ����
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ' '){
                count++;
            }
        }
        if(count == 0)
            return s;
        // ���� ԭ����
        s.resize(s.size() + count * 2);
        // �Ӻ���ǰԭ���޸�
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
        //  �ⷨ��:
        string res;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ')
                res.push_back(s[i]);
            else
                res.append("%20");
        }
        return res;
    }
    // ��ָoffer 06. ��ͷ��β��ӡ����
    // https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
    // ����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���
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
        // ����һ: ��������, Ԫ�ش����������, ���ת����
        /*
        vector<int> v1;
        while(head != nullptr){
            v1.push_back(head->val);
            head = head->next;
        }
        vector<int> res(v1.rbegin(), v1.rend());
        return res;
        */
        // ������: �ݹ�
        /*
        vector<int> res;
        moth(head, res);
        return res;
        */
        // ������: ջ (������������) �о��ͷ���һ���, ֻ�Ƿ���һ���ĵ�ת���ù��캯��ʵ�ֵ�
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
        // ������: ����vector��insertʵ��, ÿ�����ײ�����Ԫ��
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