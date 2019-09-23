#include <iostream>
#include <vector>
using namespace std;

/*给定一个整数数组 nums，其中恰好有1个元素只出现一次，其余所有元素均出现三次。 找出只出现一次的那一个元素。
* 思路1: 所有数的二进制形式的第一位出现1的个数 如果是3的倍数,表示只出现一次的元素该位为0 否则为1,遍历执行其他位,时间复杂度 O(n)
* 思路2: sum = (sum ^ n) & ~tmp
*		tmp = (tmp ^ n) & ~sum
*/

// 思路2  难理解 不具备通用性
int SingNumber1(vector<int>& nums)
{
	int sum = 0, tmp = 0;
	for (auto &i : nums)
	{
		sum = (sum ^ i) & ~tmp;
		tmp = (tmp ^ i) & ~sum;
	}
	return sum;
}
int SingNumber2(vector<int>& nums)
{
	int sum = 0, count = 0;
	int i;
	for (i = 0; i < 32; i++)
	{
		
		for (auto j : nums)
		{
			count += j >> i & 1;
		}
		if (count % 3)
		{
			sum |= 1 << i;
		}
		count = 0;
	}

	return sum;
}

int main4()
{
	int nums[10] = { 2, 2, 2, 3, 4, 4, 4, 6, 6, 6 };
	vector<int> v;
	v.insert(v.begin(), nums, nums + 10);

	cout << SingNumber1(v) << endl;
	cout << SingNumber2(v) << endl;
	return 0;
}