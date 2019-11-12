//#include<iostream>
//#include<string>
//
//
//using namespace std;
//
//int str_to_num(string str)
//{
//	
//		int tmp = 0;
//		int num = 0;
//		int flag = 0;
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (str[i] == '+' && i == 0)
//			{
//				flag = 1;
//				continue;
//			} else if (str[i] == '-' && i == 0)
//			{
//				flag = -1;
//				continue;
//			}
//			if (str[i] < '0' || str[i] > '9')
//			{
//				return 0;
//			} else
//			{
//				if (num > INT_MAX / 10 || num < INT_MIN /10)
//				{
//					return 0;
//				}else if (num == (INT_MAX / 10) && (str[i] - '0') > 7)
//				{
//					return 0;
//				}
//				else if (num == (INT_MIN / 10) && (str[i] - '0') > 8)
//				{
//					return 0;
//				}
//				
//				if (flag == -1)
//				{
//					tmp = flag * (str[i] - '0');
//					num = num * 10 + tmp;
//				}
//				else
//				{
//					tmp = (str[i] - '0');
//					num = num * 10 + tmp;
//				}
//			}
//		}
//		return num;
//}
//
//int main()
//{
//
//	cout << INT_MAX << endl;
//	cout << INT_MIN << endl;
//	string s1;
//	getline(cin, s1);
//	cout << str_to_num(s1);
//
//
//	return 0;
//}