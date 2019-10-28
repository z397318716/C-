///************************************************************************/
///* 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。*/  
///* 时间限制：1秒 空间限制：32768K                                         */
///************************************************************************/
//#include<iostream>
//using namespace std;
//
//class Solution
//{
//public:
//
//	// 时间复杂度 O(n)
//	// 方法:递归 逻辑运算符短路
//	int Sum_Solution(int n)
//	{
//		/*
//		if (n == 1)
//		{
//			return 1;
//		}
//		else
//		{
//			return Sum_Solution(n - 1) + n;
//		}
//		*/
//
//		// 利用 逻辑运算符 短路原理 代替 if 判断
//		// 逻辑运算符短路原理: a && b a的结果为 false 则程序不在继续向后执行b
//		int a = 1;
//		(n > 1) && (a = n + Sum_Solution(n - 1));
//		//a = n + Sum_Solution(n - 1);
//		
//		return a;
//		
//	}
//};
//
//template<class T>
//bool IsEqual(T& left, T& right)
//{
//	return left == right;
//}
//void Test()
//{
//	char* p1 = "hello";
//	char* p2 = "world";
//	if (IsEqual(p1, p2))
//		cout << p1 << endl;
//	else
//		cout << p2 << endl;
//}
//
//
//
//int main()
//{
//	/*Solution t1;
//	int a = t1.Sum_Solution(100);
//	cout << a;
//	*/
//	Test();
//	system("pause");
//	return 0;
//}
////两个参数偏特化为指针类型
//template <typename T1, typename T2>
//class Data <T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//
