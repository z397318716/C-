//#include <iostream>
//
//using namespace std;
//
//class Test{
//	int m_a;
//public:
//	Test(int a = 0) :
//		m_a(a)
//	{
//	}
//
//	// ǰ�� ++
//	Test operator ++()
//	{
//		m_a++;
//		return *this;
//	}
//	// ���� ++
//	Test operator ++(int)
//	{
//		Test tmp = *this;
//		m_a++;
//		return tmp;
//	}
//	// ǰ�� --
//	Test operator --()
//	{
//		m_a--;
//		return *this;
//	}
//	friend ostream & operator << (ostream & os, Test & t);
//};
//
////ostream & operator << (ostream & os, Test & t)
////{
////	
////}
//
//int main2()
//{
//	Test t(7);
//
//	cout << t++ << endl;
//
//
//	return 0;
//}