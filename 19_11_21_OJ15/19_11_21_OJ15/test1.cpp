// �������������ж�����1�ĸ���
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