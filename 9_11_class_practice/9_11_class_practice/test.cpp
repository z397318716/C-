//#include <iostream>
//
//using namespace std;
//
//class Test{
//	int a, b;
//	friend Test & operator--(Test &obj);
//	friend Test &operator--(Test &obj, int);
//public:
//	Test(int a = 0, int b = 0)
//	{
//		this->a = a;
//		this->b = b;
//	}
//	void Display()
//	{
//		cout << 'a:' << a << 'b:'  << b << endl;
//	}
//
//	// 前置 ++
//	Test &operator++()
//	{
//		this->a++;
//		this->b++;
//		return *this;
//	}
//	// 后置 ++
//	Test &operator++(int)
//	{
//		Test tmp = *this;
//		this->a++;
//		this->b++;
//		return tmp;
//	}
//	
//
//	
//};
//
//// 前置 --
//Test &operator--(Test &obj)
//{
//	obj.a--;
//	obj.b--;
//	return obj;
//}
////后置 --
//Test &operator--(Test &obj, int)
//{
//	Test tmp = obj;
//	obj.a--;
//	obj.b--;
//		return tmp;
//}
//
//int main1()
//{
//	Test t1(1, 2);
//	t1.Display();
//	++t1;
//	t1.Display();
//	--t1;
//	t1.Display();
//	Test t2(3, 4);
//	t2.Display();
//	t2++;
//	t2.Display();
//	t2--;
//	t2.Display();
//	cout << "hello world!\n";
//	return 0;
//
//
//	return 0;
//}