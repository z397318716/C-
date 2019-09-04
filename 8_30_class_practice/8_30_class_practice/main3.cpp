#include <iostream>

using namespace std;

class TestSt
{
public:
	static int m_s_i;		// 静态成员变量必须在类外进行初始化



};

int TestSt::m_s_i = 0;		// 静态成员变量初始化


int main()
{



	return 0;
}