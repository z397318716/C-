// 给一个数组，返回它的最大连续子序列的和(子向量的长度至少是1)
#include <iostream>
#include <vector>

using namespace std;
/*
* 思路1:
* 从头开始累加数组的元素,每加一位将已累加的和 sum 与当前位置元素的值比较,
* 如果sum小于当前元素值,则将当前元素值赋给sum,继续向后累加
*
*/

class solulation{
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sum = array[0];
		int tmp = array[0];
		for (int i = 1; i < array.size(); i++)
		{
			if (tmp < 0)						// 如果首元素小于0 则 从第二个元素开始加
			{
				tmp = 0;
			}
			tmp += array[i];
			if (sum < tmp)
			{
				sum = tmp;
			}
		}
		return sum;
	}
};
//int FindGreatestSumOfSubArray(vector<int> array) {
//	int sum = array[0];
//	int tmp = array[0];
//	for (int i = 1; i < array.size();i++)
//	{
//		if (tmp < 0)						// 如果首元素小于0 则 从第二个元素开始加
//		{
//			tmp = 0;
//		}
//		tmp += array[i];
//		if (sum < tmp)
//		{
//			sum = tmp;
//		}
//	}
//	return sum;
//}


int main()
{
	int arr[4] = { -1, -2, -3, -4 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
	solulation s;
	cout <<s. FindGreatestSumOfSubArray(v);


	return 0;
}