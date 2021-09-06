//#include <iostream>
//#include <string>
//using namespace std;
//
//class A {
//public:
//	A(const string& str):m_str(str)
//	{
//		cout << m_str << ", 构造\n" << endl;
//	}
//	~A() {
//		cout << m_str<< ",";
//	}
//private:
//	string m_str;
//};
////class B : public A {
////public:
////	B() {
////		cout << "B 构造\n" << endl;
////	}
////	~B() {
////		cout << "B 析构！\n" << endl;
////	}
////	void fun() {
////		cout << "B fun\n" << endl;
////	}
////};
////void test() {
////	A* a1 = new A;
////	B* b1 = new B;
////
////	delete a1;
////	delete b1;
////}
//
//A a1("A1");
//A a5("A5");
//int main() {
//
//	//test();
//	static A a2("A2");
//	A* a3 = new A("A3");
//	A a4("A4");
//	delete a3;
//
//
//	return 0;
//}