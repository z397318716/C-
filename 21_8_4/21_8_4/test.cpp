#include <iostream>

using namespace std;
class Base {
public:
	virtual void func() {
		++a;
		++b;
	}
	int a = 1;
	int b = 1;
};
class Derived :public Base {
public:
	virtual void func() {
		--a;
		--b;
	cout << a << b;
	}
	int a = 1;
};
void test1() {
	Base* pBase = new Base();
	pBase->func();
	cout << pBase->a << pBase->b;
	pBase = new Derived();
	pBase->func();
	cout << pBase->a << pBase->b;
	
}


//class A {
//public:
//	void print() {
//		std::cout << "A";
//	}
//};
//class B:public A {
//public:
//	void print() {
//		std::cout << "B";
//	}
//};
//void test2() {
//	A* pa = new A;
//	B* pb = new B;
//	B* pb1 = static_cast<B*>(pa);
//	B* pb2 = dynamic_cast<B*>(pb);
//	if (pb1)
//		pb1->print();
//	if (pb2)
//		pb2->print();
//}

void func1(int* a) {
	a = 0;
}
void func2(int* a) {
	*a = 1;
}
void func3(int& a) {
	a = 2;
}
void test3() {
	int a = -1;
	func1(&a);
	std::cout << a;
	func2(&a);
	std::cout << a;
	func3(a);
	std::cout << a;
}
int main() {
	test1();
	//test2();
	//test3();
}