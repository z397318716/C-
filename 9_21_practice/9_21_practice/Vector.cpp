//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//#define DEFAULTCAPA 16
//#define COUNTCAPA(size) (((size) / DEFAULTCAPA + 1) * DEFAULTCAPA)
//
//void PrintVector(vector<int>  v)
//{
//	vector<int> first;									// �޲ι���
//	vector<int> second(2, 3);							// ���첢��ʼ�� 2��3
//	//vector<int> third(2, 1.2);							// 
//	vector<int> fourth(second);							// ��������
//	vector<int> fifth(second.begin(), second.end());	// ʹ�õ��������г�ʼ������
//
//
//	//// ��������ʼ��
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
//	* ʹ���˵�������ѭ����,������������������������Ԫ��
//	* ����ԭ��: ��������� string�� vector.
//	*  1.���洢�ռ䱻���·���.��ָ�������ĵ�����,ָ��,���ö���ʧЧ
//	*  2.���洢�ռ�û�б����·���,��ָ�����Ԫ��֮ǰ�ĵ�����,ָ��,������Ȼ��Ч,ָ�����Ԫ��֮��ĵ�����,ָ��,�������ʧЧ
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
//	// �������޸�
//	auto it2 = v.begin();
//	while (it2 != v.end())
//	{
//		*it2 *= 2;
//		++it2;
//		//cout << *it << ' ';
//	}
//	// �����������ӡ
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