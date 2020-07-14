#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
	int res = 0;
	int tmp = prices[0];
	int tmp1 = prices[0];
	int res1 = 0;
	int sum = 0;
	// ���ι����ȡ�������
	for (int i = 0; i < prices.size(); ++i)
	{
		res = max(res, prices[i] - tmp);
		tmp = min(tmp, prices[i]);
	}
	// ��ι�����������
	for (int i = 0; i < prices.size(); ++i)
	{
		res1 = max(res1, prices[i] - tmp1);
		if (res1 > 0)
		{
			sum += res1;
			res1 = 0;
			tmp1 = prices[i];
		}
		tmp1 = min(tmp1, prices[i]);
	}


	return res > sum ? res : sum;
}


int main()
{
	vector<int> v1({ 7, 1, 5, 3, 6, 4 });

	maxProfit(v1);


	return 0;
}