//#include <iostream>
//#include <list>
//#include <cstring>
//
//using namespace std;
//
//
//
//
//int main1()
//{
//	int arr[] = { 1, 2, 3, 4, 5 };
//	list<int> l1;											// 构造空的 list
//	list<int> l2(arr, arr + sizeof(arr) / sizeof(arr[0]));	// 用arr 到 arr+n 间的元素实现构造,以数组为迭代器构造
//	list<int> l3(l2);										// 拷贝构造
//	list<int> l4(4, 2);										// 构造4个2 
//
//	list<int>::iterator it;
//	for (it = l2.begin(); it != l2.end(); it++)
//	{
//		cout << *it << ' ';
//	}
//	cout << endl;
//	for (auto &i : l4)
//	{
//		cout << i << ' ';
//	}
//	return 0;
//}