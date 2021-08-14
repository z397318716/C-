#include <iostream>
//#define aa 123;
using namespace std;
class A {
public:
	A() {
		++_n;
	}
	 void count() {
		cout << _n << endl;;
	}
	
private:
public:
	static int _n;
};
int A::_n = 0;
class B : public A {
public:
	B() {
		++_m;
	}
	void count() {
		cout << _n << endl;
	}
private:
	static int _m;
};
int B::_m = 0;
int main(void) {
	A a;
	a.count();
	A b;
	a.count();
	b.count();

	B a1;
	a1.count();
	B b1;
	a1.count();
	b1.count();
	//std::cout << aa << '\n';
	//int p = 2, a = 3;;
	//const int* p1 = &p;
	//int const* p2 = &p;
	//int* const p3 = &p;
	//
	//*p1 = 1;
	//*p2 = 1;
	//*p3 = 1;

	//p1 = &a;
	//p2 = &a;
	//p3 = &a;

	return 0;
}