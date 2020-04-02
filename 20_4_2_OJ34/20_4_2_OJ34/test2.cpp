/************************************************************************/
/* 链接：https://www.nowcoder.com/questionTerminal/71d3849a19f04a1591c415964ac148f1
来源：牛客网
一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。 某人领养了一只小兔子，请问第N天以后，他将会得到多少只兔子。
输入描述:
测试数据包括多组，每组一行，为整数n(1≤n≤90)。
输出描述:
对应输出第n天有几只兔子(假设没有兔子死亡现象)。                                                                     */
/************************************************************************/
#include<iostream>
#include<vector>

using namespace std;

vector<long long> Num()
{
	vector<long long> v1;
	v1.resize(91);
	v1[0] = 1;
	v1[1] = 1;
	for (int i = 2; i < 91; i++)
	{
		v1[i] = v1[i - 1] + v1[i - 2];
	}
	return v1;
}

int main()
{
	int tmp;
	vector<long long> v1(Num());
	while (cin >> tmp)
	{
		cout << v1[tmp] << endl;
	}



	return 0;
}