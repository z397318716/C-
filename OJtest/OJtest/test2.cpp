///************************************************************************/
///* https://leetcode-cn.com/problems/palindrome-number/submissions/
//	判断整数是否 回文
///************************************************************************/
//#include<iostream>
//#include<string>
//
//
//using namespace std;
//
//class Solution {
//public:
//	bool isPalindrome(int x) {
//		if (x < 0)
//		{
//			return false;
//		} else if (x >= 0 && x < 10)
//			return true;
//		else
//		{
//			long long tmp = 0;
//			int a = 0;
//			int y = x;
//			while (y != 0)
//			{
//				a = y % 10;
//				tmp = tmp * 10 + a;
//				y = y / 10;
//			}
//			return tmp == x;
//		}
//	}
//};
//
//int main()
//{
//	Solution A;
//	if (A.isPalindrome(121))
//		cout << "true" << endl;
//
//
//	return 0;
//}

#include<iostream>
#define N 2
#define M N+1
#define NUM (M+1)*M/2
int main()
{
	printf("%d\n", NUM);
}