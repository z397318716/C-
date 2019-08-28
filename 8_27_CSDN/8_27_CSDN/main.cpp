#include <iostream>
using namespace std;
// namespace关键字后接 命名空间的名字
namespace N1	// N1为命名空间的名字
{
	// 命名空间中的内容,既可以是变量也可以是函数
	int a = 20;
	int b = 10;
	int add(int a, int b)
	{
		return a + b;
	}
	// 命名空间允许嵌套
	namespace N2
	{
		int n = 1;
		int sub(int a, int b)
		{
			return a - b;
		}
	}
}


using N1::b;
using namespace N2;
int main()
{

	//cout << a << endl;

	cout << N1::a;
	cout << b;
	cout << n;
	return 0;
}