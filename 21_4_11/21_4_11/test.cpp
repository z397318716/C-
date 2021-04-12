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
        // 方法1: 动态规划

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
        // 方法1: 哈希表
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
        // 方法2: 使用数组(因为s只包含 小写字母)
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
        // 方法1: 定义两个节点指针, 分别循环遍历各自链表, 相等时返回
        // 注意,如果没有相交节点, 都等于空时也相等 会返回
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