#include <iostream>
using namespace std;


class ct{
	// class Ĭ�� �������Ʒ� �� private
public:						
	char a;
	int b;
	double c;

	void Print1()			// ��Ա�����п���ֱ��ʹ���Լ��ĳ�Ա����
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