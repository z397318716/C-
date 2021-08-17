#include "test.hpp"
/*����
��ʵ�����ظ����ֵ���������Ķ��ֲ���
����һ�� Ԫ������ģ������������� nums ��һ��Ŀ��ֵ target  ��дһ���������� nums �еĵ�һ�����ֵ�target��
���Ŀ��ֵ���ڷ����±꣬���򷵻� -1*/
using namespace std;
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * ���Ŀ��ֵ���ڷ����±꣬���򷵻� -1
     * @param nums int����vector
     * @param target int����
     * @return int����
     */
    int search(vector<int>& nums, int target) {
        // write code here
        // �����������ҵĻ����ϣ� ���� �ұ߽�Ļ��ָ���ϸ��
        // �� target > nums[mid] r = mid
        // ����� �� target == nums[mid] ʱ��������� mid == 0 ���� mid-1>0 && nums[mid-1] != target
        // ʱ����ֹͣ����
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target && (mid - 1 >= 0 && nums[mid - 1] != target) ||
                (mid == 0 && nums[mid] == target)) {
                return mid;
            }
            else if (nums[mid] >= target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return -1;
    }
};

/*
����
������ջ��ʵ��һ�����У��ֱ�����ڶ���β����������(push)���ڶ���ͷ��ɾ������(pop)�Ĺ��ܡ� 
�����е�Ԫ��Ϊint���͡���֤�����Ϸ�������֤pop����ʱ����������Ԫ�ء�
*/
class Solution1
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int tmp = stack2.top();
        stack2.pop();
        return tmp;

    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

/*�жϸ������������Ƿ��л�������л��򷵻�true�����򷵻�false��
���ܸ����ռ临�ӶȵĽⷨô��
�����Ϊ2���֣���һ����Ϊ�����ڶ����ִ����Ƿ��л���Ȼ������headͷ��㴫�뵽�������档
-1�����޻������������ִ����л�����Щ�������ͽ�����Ϊ�˷�������Բ����*/

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution2 {
public:
    bool hasCycle(ListNode* head) {
        // ��ϣ��
        /*
        set<ListNode*> s1;
        while(head != nullptr){
            if(s1.count(head) == 0){
                s1.insert(head);
                head = head->next;
            }else{
                return true;
            }

        }
        return false;
        */
        // ����ָ��
        if (head == nullptr)
            return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};