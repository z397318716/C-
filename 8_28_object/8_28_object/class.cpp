#include <iostream>
using namespace std;


class ct{
	// class 默认 访问限制符 是 private
public:						
	char a;
	int b;
	double c;

	void Print1()			// 成员函数中可以直接使用自己的成员变量
	{
		printf("%d", b);
	}

	void Print2()
	{

	}
};





int main()
{
	ct c;
	c.a = 2;
	c.Print1();

	cout << sizeof(ct);



	return 0;
}