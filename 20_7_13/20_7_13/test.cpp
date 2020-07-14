//#include<iostream>
//#include<cmath>
//#include<vector>
//#include<algorithm>
//
//
//using namespace std;
//int maxProfit(vector<int>& prices) {
//	if (prices.size() <= 1)
//		return 0;
//	int res = 0;
//	int tmp = prices[0];
//
//	for (int i = 0; i < prices.size(); i++)
//	{
//		res = max(prices[i] - tmp, res);
//		tmp = min(tmp, prices[i]);
//
//	}
//	/*
//	for(int i = prices.size() - 1; i >= 0; --i)
//	{
//	for(int j = i; j >= 0; --j)
//	{
//
//	if(i == j)
//	continue;
//	tmp = prices[i] - prices[j];
//	if(tmp <= 0)
//	continue;
//	else
//	{
//	res = max(res, tmp);
//	}
//	}
//	}
//	return res;
//	*/
//	return res;
//}
//
//int main()
//{
//	vector<int> v1({ 1, 2 });
//	maxProfit(v1);
//
//
//}