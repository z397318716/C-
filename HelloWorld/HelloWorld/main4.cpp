#include <iostream>
#include <typeinfo>

using namespace std;



int main()
{
	int i = 0;
	auto j = i;

	cout << typeid(j).name() << endl;

	return 0;
}
