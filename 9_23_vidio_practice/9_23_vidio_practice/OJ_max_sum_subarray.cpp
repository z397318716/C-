// ��һ�����飬��������������������еĺ�(�������ĳ���������1)
#include <iostream>
#include <vector>

using namespace std;
/*
* ˼·1:
* ��ͷ��ʼ�ۼ������Ԫ��,ÿ��һλ�����ۼӵĺ� sum �뵱ǰλ��Ԫ�ص�ֵ�Ƚ�,
* ���sumС�ڵ�ǰԪ��ֵ,�򽫵�ǰԪ��ֵ����sum,��������ۼ�
*
*/

class solulation{
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sum = array[0];
		int tmp = array[0];
		for (int i = 1; i < array.size(); i++)
		{
			if (tmp < 0)						// �����Ԫ��С��0 �� �ӵڶ���Ԫ�ؿ�ʼ��
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
//		if (tmp < 0)						// �����Ԫ��С��0 �� �ӵڶ���Ԫ�ؿ�ʼ��
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