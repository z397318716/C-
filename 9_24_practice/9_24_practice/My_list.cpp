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
//	list<int> l1;											// ����յ� list
//	list<int> l2(arr, arr + sizeof(arr) / sizeof(arr[0]));	// ��arr �� arr+n ���Ԫ��ʵ�ֹ���,������Ϊ����������
//	list<int> l3(l2);										// ��������
//	list<int> l4(4, 2);										// ����4��2 
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