#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;


class A
{
private:
	static int _scount;
	int _z1;
public:
	A()
	{
		++_scount;
	}
	A(const A&t)
	{
		++_scount;
	}
	static int GetScount()
	{
		//_z1++;	// 静态成员函数 不能 调用 非静态成员
		return _scount;
	}
};

int A::_scount = 0;		// 静态成员变量必须在类外初始化,被所有的类对象共享

int StrToInt(string str) {

	int num = 0;
	int t1 = 0;    // 置位标记,判断第一个字符是 +/-

	for (int i = 0; i < str.size(); i++)
	{
		if (str.front() == '+')
		{
			t1 = 1;
		}

		else if (str.front() == '-')
		{
			t1 = -1;
		}

		if (t1 != 0 && i == 0)    // 如果标记不为0,表示str第一位是 +/- 号
		{
			continue;
		}

		if (str[i] <'0' || str[i] >'9')
		{
			return 0;
		} else
		{
			int tmp = str[i] - '0';
			num = num * 10 + tmp;
		}
	}
	if (num > 2147483647)
	{
		return 0;
	}
	if (t1 != 0)
		return num * t1;
	else
		return num;
}


int main()
{
	/*string a;
	
	cout << A::GetScount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetScount() << endl;*/
	/*size_t a = -1;
	printf("%d\n", sizeof(int) / 4);
	printf("%ud\n", a);*/

	string str("-2147483649");
	int a = StrToInt(str);
	cout << a << endl;
	printf("%d\n", INT_MIN);
	return 0;
}