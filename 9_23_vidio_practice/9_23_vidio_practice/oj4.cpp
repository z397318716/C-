#include <iostream>
#include <vector>
using namespace std;

/*����һ���������� nums������ǡ����1��Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ� �ҳ�ֻ����һ�ε���һ��Ԫ�ء�
* ˼·1: �������Ķ�������ʽ�ĵ�һλ����1�ĸ��� �����3�ı���,��ʾֻ����һ�ε�Ԫ�ظ�λΪ0 ����Ϊ1,����ִ������λ,ʱ�临�Ӷ� O(n)
* ˼·2: sum = (sum ^ n) & ~tmp
*		tmp = (tmp ^ n) & ~sum
*/

// ˼·2  ����� ���߱�ͨ����
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