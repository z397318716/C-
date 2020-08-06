//#include<iostream>
//#include<stack>
//using namespace std;
//
///*
//题目描述:力扣 230
//给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
//
//说明：
//你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst
//*/
//
////Definition for a binary tree node.
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
//
//int kthSmallest(TreeNode* root, int k) {
//	// 根据二叉搜索树的性质, 其中序遍历就是一个升序序列
//	int i = 1;
//	// 非递归中序遍历
//	//queue<TreeNode*> q1;
//	stack<TreeNode*> s1;
//	TreeNode* ptr = root;
//	//s1.push(ptr);
//	while (!s1.empty() || ptr != nullptr)
//	{
//		while (ptr)
//		{
//			s1.push(ptr);
//			ptr = ptr->left;
//		}
//		ptr = s1.top();
//		s1.pop();
//		if (i == k)
//		{
//			//return ptr->val;
//			break;
//		}
//		i++;
//
//		ptr = ptr->right;
//		//if(ptr != nullptr)
//		//s1.push(ptr);
//
//	}
//	return ptr->val;
//}