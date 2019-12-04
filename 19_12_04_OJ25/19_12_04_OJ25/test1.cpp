// ĞÇ¼ÊÃÜÂë, 
#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 10000
int passward(int n)
{
	int left = 0;
	int right = 1;
	int cur = 1;
	for (int i = 0; i < n; i++)
	{
		cur = left + right;
		left = right%MAX;
		right = cur%MAX;
	}
	return cur%MAX;
}
int main()
{
	int n, temp;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			printf("%04d", passward(temp));
		}
		cout << endl;
	}
	return 0;
}