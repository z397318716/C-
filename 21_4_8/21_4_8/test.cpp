#include<iostream>
#include<string>
#include<vector>
namespace zxq {
    using namespace std;
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
        
    };
    class Solution {
    public:
        vector<int> exchange(vector<int>& nums) {
            // 思路一: 遍历数组, 将奇数放到新数组前面, 偶数放到数组后面
            // 思路二: 双指针法, 左指针从前向后,遇到偶数停下, 右指针从后向前,遇到奇数停下,交换
            if (nums.empty())
                return nums;
            vector<int>::iterator it1 = nums.begin(), it2 = nums.end()-1;
            while (it1 != it2) {
                while (it1 != it2 && (*it1) % 2 != 0)
                    it1++;
                while (it1 != it2 && (*it2) % 2 != 1)
                    it2--;
                auto tmp = *it1;
                *it1 = *it2;
                *it2 = tmp;
            }
            return nums;
        }
        ListNode* reverseList(ListNode* head) {
            // 方法1: 原地翻转, 
            // 需要维护 三个节点指针, 分别指向 当前节点, 当前节点的上一个及下一个节点
            if (head == nullptr)
                return head;
            ListNode* pre = head;
            ListNode* cur = head->next;
            ListNode* post = cur;
            if (cur != nullptr)
                post = cur->next;
            while (cur != nullptr) {
                cur->next = pre;

                pre = cur;
                cur = post;
                if (post)
                    post = post->next;
            }
            head->next = nullptr;
            return pre;
        }


    };
    // 插入链表节点
    void insert(ListNode* head, int val) {
        ListNode* cur = head;
        while (cur->next)
            cur = cur->next;
        cur->next = new ListNode(val);
    }
}


int main() {
    using namespace zxq;
    Solution A;
    vector<int> nums{ 1,3,2,4,8,5,6,7,9 };
    A.exchange(nums);

    ListNode *head = new ListNode(1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    A.reverseList(head);

	return 0;
}