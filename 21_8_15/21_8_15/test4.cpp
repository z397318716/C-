#include "test.hpp"
/*描述
请实现有重复数字的升序数组的二分查找
给定一个 元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的第一个出现的target，
如果目标值存在返回下标，否则返回 -1*/
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 如果目标值存在返回下标，否则返回 -1
     * @param nums int整型vector
     * @param target int整型
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        // write code here
        // 在正常二分找的基础上， 对于 右边界的划分更加细致
        // 当 target > nums[mid] r = mid
        // 特殊的 当 target == nums[mid] 时，如果满足 mid == 0 或者 mid-1>0 && nums[mid-1] != target
        // 时，在停止检索
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
描述
用两个栈来实现一个队列，分别完成在队列尾部插入整数(push)和在队列头部删除整数(pop)的功能。 
队列中的元素为int类型。保证操作合法，即保证pop操作时队列内已有元素。
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

/*判断给定的链表中是否有环。如果有环则返回true，否则返回false。
你能给出空间复杂度的解法么？
输入分为2部分，第一部分为链表，第二部分代表是否有环，然后回组成head头结点传入到函数里面。
-1代表无环，其他的数字代表有环，这些参数解释仅仅是为了方便读者自测调试*/

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution2 {
public:
    bool hasCycle(ListNode* head) {
        // 哈希表
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
        // 快慢指针
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