//#include<iostream>
//#include<string>
//
//using namespace std;
//
//
//class Solution {
//public:
//	int myAtoi(string str) {
//		// 记录第一个数字出现的位置
//		int ptr = 0;
//		int res = 0;
//		int flag = 1;
//
//		for (int i = 0; i < str.size(); ++i)
//		{
//			if (str[i] == ' ')
//				continue;
//			else
//			{
//				if (str[i] == '-' || str[i] == '+')
//				{
//					ptr = i + 1;
//					if (str[i] == '-')
//						flag = -1;
//					break;
//				} else if (str[i] >= '0' && str[i] <= '9')
//				{
//					ptr = i;
//					break;
//				} else
//				{
//					return 0;
//				}
//			}
//		}
//		int tmp = 0;
//		long long res1, res2;
//		for (int i = ptr; i < str.size(); ++i)
//		{
//			if (str[i] >= '0' && str[i] <= '9')
//			{
//				tmp = str[i] - '0';
//				tmp *= flag;
//				if (res > INT_MAX / 10)
//					return INT_MAX;
//				if (res < INT_MIN / 10)
//					return INT_MIN;
//				res1 = (long long)INT_MAX - tmp;
//				res2 = (long long)INT_MIN - tmp;
//				if (res1 < res * 10)
//					return INT_MAX;
//				if (res2 > res * 10)
//					return INT_MIN;
//				res = res * 10 + tmp;
//				tmp = 0;
//			} else
//			{
//				break;
//			}
//
//		}
//
//		return res;
//
//
//	}
//};
//
//int main()
//{
//	Solution s1;
//	s1.myAtoi(" +-2");
//
//	return 0;
//}