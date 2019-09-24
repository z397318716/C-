#include <iostream>
#include <vector>

using namespace std;

/*
* 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
* 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0
*
*/

int FindMaxTimesNum(const vector<int> & numbers)
{
	int i,icount = 0;
	int num = numbers[0];
	for (i = 1; i < numbers.size(); i++)
	{
		if (numbers[i] == numbers[i - 1])
		{
			icount++;
		}
		else
		{
			if (icount <= 1)
			{
				num = numbers[i];
			}
			else
			{
				icount--;
			}
		}
	}

	if (numbers.size() / 2 < count(numbers.begin(), numbers.end(), num));		// 返回v.begin() 到v.end() num出现的次数
	{
		return num;
	}
	return 0;
}


int main5()
{
	int num[9] = { 1, 2, 3, 2, 4, 2, 5, 2, 2 };
	vector<int> v(num,num+sizeof(num)/sizeof(num[0]));

	cout << FindMaxTimesNum(v);
	


	return 0;
}