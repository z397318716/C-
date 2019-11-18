// 满二叉树找最近祖先节点,层序遍历排号,根节点为1号节点
#include<iostream>
#include<algorithm>
using namespace std;

int RootNum(int a, int b)
{
	int m1 = max(a, b);
	int m2 = min(a, b);
	while (m1 != m2)
	{
		int tmp = 0;
		m1 /= 2;
		tmp = max(m1, m2);
		m2 = min(m1, m2);
		m1 = tmp;
	}
	return m1;
}

int main()
{
	int a, b;
	cin >> a >> b;

	return 0;
}