#include<iostream>
#include<vector>
#include<algorithm>
#include<map>


using namespace std;

 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // ����1: ��̬�滮

        if (nums.empty())
            return 0;
        vector<int> tmp(nums.size());
        int res = nums[0];
        tmp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            tmp[i] = max(nums[i], tmp[i - 1] + nums[i]);
            if (res < tmp[i])
                res = tmp[i];
        }
        return res;
    }

    char firstUniqChar(string s) {
        // ����1: ��ϣ��
        /*
        unordered_map<char, int> m1;
        for(auto e : s){
            m1[e]++;
        }
        for(auto e : s){
            if(m1[e] == 1)
                return e;
        }
        return ' ';
        */
        // ����2: ʹ������(��Ϊsֻ���� Сд��ĸ)
        vector<char> res(26);
        map<char, int> m1;
        for (auto e : s) {
            if (m1.find(e) == m1.end())
                res.push_back(e);
            m1[e]++;
        }
        for (auto e : res) {
            if (m1[e] == 1)
                return e;
        }
        return ' ';
    }



    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // ����1: ���������ڵ�ָ��, �ֱ�ѭ��������������, ���ʱ����
        // ע��,���û���ཻ�ڵ�, �����ڿ�ʱҲ��� �᷵��
        ListNode* tmp1 = headA;
        ListNode* tmp2 = headB;
        while (tmp1 != tmp2) {
            tmp1 = tmp1 == nullptr ? headA : tmp1->next;
            tmp2 = tmp2 == nullptr ? headB : tmp2->next;
        }
        return tmp1;
    }
};
int main() {



	return 0;
}