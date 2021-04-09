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
            // ˼·һ: ��������, �������ŵ�������ǰ��, ż���ŵ��������
            // ˼·��: ˫ָ�뷨, ��ָ���ǰ���,����ż��ͣ��, ��ָ��Ӻ���ǰ,��������ͣ��,����
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
            // ����1: ԭ�ط�ת, 
            // ��Ҫά�� �����ڵ�ָ��, �ֱ�ָ�� ��ǰ�ڵ�, ��ǰ�ڵ����һ������һ���ڵ�
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
    // ��������ڵ�
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