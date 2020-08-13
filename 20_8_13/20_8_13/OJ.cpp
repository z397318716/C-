#include<iostream>
#include<vector>
using namespace std;


/************************************************************************/
/* 力扣1171
	给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。
	删除完毕后，请你返回最终结果链表的头节点
	 链接：https://leetcode-cn.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list
	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
/************************************************************************/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* removeZeroSumSublists(ListNode* head) {
		if (head == nullptr)
			return head;
		vector<int>v;
		ListNode *h = head;
		while (h)
		{
			v.push_back(h->val);
			h = h->next;
		}
		for (int i = 0; i < v.size(); ++i)
		{
			int sum = 0;//从本身开始，防止结点有0本身出现。
			for (size_t j = i; j<v.size(); ++j)
			{
				sum += v[j];
				if (sum == 0)
				{
					v.erase(v.begin() + i, v.begin() + j + 1);
					i = -1;//删除后，需要重头开始
					break;
				}
			}
		}
		if (0 == v.size())
			return nullptr;//防止删完了，还有一个头结点的值
		h = head;
		for (size_t i = 0; i<v.size(); ++i)
		{
			//if(v[i] == 0)
			//    continue;
			h->val = v[i];
			if (i + 1 == v.size())
				break;
			h = h->next;
		}
		//if(h->val == 0)
		//    head = nullptr;

		h->next = nullptr;//尾指针置空
		if (head->val == 0 && head->next == nullptr)
			return nullptr;
		return head;
	}
};

int main()
{



	return 0;
}