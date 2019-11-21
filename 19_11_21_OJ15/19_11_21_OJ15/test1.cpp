// 查找输入整数中二进制1的个数
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int num;

	while (cin >> num)
	{
		int count = 0;
		while (num > 0)
		{
			if (num & 1)
			{
				count++;
			}
			num = num >> 1;
		}
		cout << count << endl;
	}
	return 0;
}