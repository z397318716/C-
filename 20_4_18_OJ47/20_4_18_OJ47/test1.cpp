/************************************************************************/
/* m题目描述
搜狐员工小王最近利用假期在外地旅游，在某个小镇碰到一一个马戏团表演，精彩
的表演结束后发现团长正和大伙在帐篷前激烈讨论，小王打听了下了解到，马戏
团正打算出一个新节目“最高罗汉塔”，即马戏团员叠罗汉表演。考虑到安全因素，
要求叠罗汉过程中，站在某个人肩上的人应该既比自己矮又比自己瘦，或相等。
团长想要本次节目中的罗汉塔叠的最高，由于人数众多，正在头疼如何安排人员
的问题。小王觉得这个问题很简单，于是统计了参与最高罗汉塔表演的所有团员
的身高体重，并且很快找到曇最高罗汉塔的人员序列。现在你手上也拿到了这样
一份身高体重表，请找出可以叠出的最高罗汉塔的高度，这份表中马戏团员依次
编号为1到N。
输入描述:
首先一个正整数N，表示人员个数。
之后N行，每行三个数，分别对应马戏团员编号，体重和身高。
输出描述:
正整数m，表示罗汉塔的高度。
                                                                     */
/************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
bool cmp(pair<int, int> v1, pair<int, int> v2)
{
	if (v1.first < v2.first)
		return true;
	else if (v1.first == v2.first)
	{
		return v1.second > v2.second;
	}
	return false;
}

int main()
{
	int num;
	while (cin >> num)
	{
		int a, w, h;
		vector<pair<int, int>> v1;
		v1.resize(num);
		int id;
		for (int i = 0; i < num; i++)
		{
			cin >> id >> v1[i].first >> v1[i].second;
		}
		sort(v1.begin(), v1.end(), cmp);
		vector<int> dp;
		dp.resize(num, 1);
		int level = 1;
		for (int i = 1; i < num; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (v1[i].second >= v1[j].second)
				{
					dp[i] = max(dp[i], dp[j] + 1);
					level = max(dp[i], level);
				}
			}
		}
		cout << level << endl;

	}
	return 0;
}