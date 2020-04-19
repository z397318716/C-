//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class MaxGap {
//public:
//	int findMaxGap(vector<int> A, int n) {
//		// write code here
//		vector<int> tmp(A);
//		sort(tmp.begin(), tmp.end());
//		// 找到数组中的最大值
//		int max = tmp[n - 1];
//		// 如果最大值在数组首位,那减去末尾值即为左部分max减去右部分max 最大绝对值
//		// 如果最大值在数组末尾,同理
//		if (A[0] == max || A[n - 1] == max)
//		{
//			return abs(A[0] - A[n - 1]);
//		}
//		// 如果最大值不在首末尾, 则返回 max-A[0] 或max-A[n-1] 中最大的
//		else
//		{
//			return abs(max - A[n - 1]) > abs(max - A[0]) ? abs(max - A[n - 1]) : abs(max - A[0]);
//		}
//
//	}
//};
//
//int main()
//{
//	vector<int> v1{ 2, 7, 3, 1, 1 };
//	MaxGap a;
//	cout << a.findMaxGap(v1, 5) << endl;
//
//
//
//	return 0;
//}