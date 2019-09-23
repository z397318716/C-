//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//#define DEFAULTCAPA 16
//#define COUNTCAPA(size) (((size) / DEFAULTCAPA + 1) * DEFAULTCAPA)
//
//void PrintVector(vector<int>  v)
//{
//	vector<int> first;									// 无参构造
//	vector<int> second(2, 3);							// 构造并初始化 2个3
//	//vector<int> third(2, 1.2);							// 
//	vector<int> fourth(second);							// 拷贝构造
//	vector<int> fifth(second.begin(), second.end());	// 使用迭代器进行初始化构造
//
//
//	//// 迭代器初始化
//	//int str[] = { 1, 2, 3, 4, 5, 6 };
//	//vector<int>sixth(str, str + sizeof(str) / sizeof(str[0]));
//	//for (vector<int>::iterator it = sixth.begin(); it != sixth.end(); ++it)
//	//{
//	//	cout << *it << ' ';
//	//}
//
//	vector<int>::iterator it = v.begin();
//	//auto it2 = v.begin();
//	/*-------------------------------------------------------------------------------------------------------
//	* 使用了迭代器的循环体,不能向迭代器所属的容器添加元素
//	* 错误原因: 如果容器是 string或 vector.
//	*  1.若存储空间被重新分配.则指向容器的迭代器,指针,引用都会失效
//	*  2.若存储空间没有被重新分配,则指向插入元素之前的迭代器,指针,引用仍然有效,指向插入元素之后的迭代器,指针,引用则会失效
//	--------------------------------------------------------------------------------------------------------*/
//	//v.push_back(1);						
//	//v.push_back(2);
//
//	for (; it != v.end();++it)
//	{
//		cout << *it << " ";
//		
//	}
//	cout << endl;
//	// 迭代器修改
//	auto it2 = v.begin();
//	while (it2 != v.end())
//	{
//		*it2 *= 2;
//		++it2;
//		//cout << *it << ' ';
//	}
//	// 反向迭代器打印
//	vector<int>::reverse_iterator rit = v.rbegin();
//	while (rit != v.rend())
//	{
//		cout << *rit << ' ';
//		++rit;
//	}
//	v.insert(it,3);
//}
//class Vector
//{
//	int *_arr;
//	size_t _size;
//	size_t _capacity;
//public:
//	
//};
//iterator My_insert(
//const_iterator _Where,
//const Type& _Val
//);
//iterator My_insert(
//	const_iterator _Where,
//	Type&& _Val
//	);
//void My_insert(
//	const_iterator _Where,
//	size_type _Count,
//	const Type& _Val
//	);
//template<class InputIterator>
//void insert(
//	const_iterator _Where,
//	InputIterator _First,
//	InputIterator _Last
//	);
//
//
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4 };
//	vector<int> first(arr,arr + sizeof(arr)/sizeof(arr[0])-1);
//
//	PrintVector(first);
//
//	system("pause");
//	return 0;
//}