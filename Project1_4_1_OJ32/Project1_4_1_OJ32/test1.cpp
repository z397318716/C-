/************************************************************************/
/* ■题目描述
NowCoder开了一家早餐店，这家店的客人都有个奇怪的癖好:他们只要来这家店
吃过一次早餐，就会每天都过来;并且，所有人在这家店吃了两天早餐后，接下
来每天都会带一位新朋友一起来品尝。
于是，这家店的客人从最初一个人发展成浩浩荡荡成百上千人: 1、1、2、3、
现在，NowCoder想请你帮忙统计一下，某-段时间范围那他总共卖出多少份早餐
(假设每位客人只吃一份早餐)。
输入描述:
测试数据包括多组。
每组数据包含两个整数from和to (1≤fromSto≤80)，分别代表开店的第
from天和第to天。
输出描述:
对应每-组输入，输出从frcm到to这些天里(包含from和to两天)，需要
做多少份早餐。
                                                                     */
/************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

// 根据顾客数量变化的规则,顾客数量增长其实就是斐波那锲数列

// 注意点:  32位的数位数不够,需要使用大数
vector<long long> FeiBo()
{
	vector<long long> v1;
	v1.resize(80);
	v1[0] = 1;
	v1[1] = 1;
	for (int i = 2; i < 80; i++)
	{
		v1[i] = v1[i - 1] + v1[i - 2];
	}
	return v1;
}
int main()
{
	vector<long long> v1(FeiBo());
	int from, to;
	while (cin >> from >> to)
	{
		int tmp = from - 1;
		long long num = 0;
		for (; tmp < to; tmp++)
		{
			num += v1[tmp];
		}
		cout << num << endl;
	}



	return 0;
}