/************************************************************************/
/* 一个数组中存在一个数字,该数字出现次数超过数组长度的一半,返回该数字,不存在则返回0                                                                     */
/************************************************************************/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {
	vector<int> v1;
	int tmp = 0;
	int num = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		tmp = 1;
		num = numbers[i];
		for (int j = 0; j < numbers.size(); j++)
		{
			if (i == j)
			{
				continue;
			}
			if (numbers[j] == num)
			{
				tmp++;
			}
		}
		if (tmp > numbers.size() / 2)
		{
			return num;
		}
	}
	return 0;
}

int main()
{
	vector<int> v1{ 1, 2, 3, 4, 2, 2, 2, 2 };
	string s1;
	

	cout << MoreThanHalfNum_Solution(v1);


	return 0;
}