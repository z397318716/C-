#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int trapRainWater(vector<vector<int>>& heightMap) {
	/*
	首先,和 接雨水1  思路相同, 只是在1的基础上
	对行和列都进行遍历, 找出每一个点位置上存储水的高度
	*/
	int res = 0;
	vector<vector<int>> vv1(heightMap.size(),
		vector<int>(heightMap[0].size(), 0));





	// 遍历列, 记录每一列中 每个位置 对应的最小储水高度
	for (int i = 0; i < heightMap.size(); ++i)
	{
		vector<int> col_max_l(heightMap[0].size(), 0);
		//col_max_l.resize(0, heightMap[0].size());
		vector<int> col_max_r(heightMap[0].size(), 0);
		//col_max_r.resize(0, heightMap[0].size());
		int max_l = 0, max_r = 0;
		for (int j = 0; j < heightMap[0].size(); ++j)
		{
			max_l = max(heightMap[i][j], max_l);
			col_max_l[j] = max_l;
			max_r = max(heightMap[i][heightMap[0].size() - 1 - j], max_r);
			col_max_r[heightMap[0].size() - 1 - j] = max_r;
		}
		for (int j = 0; j < heightMap[0].size(); ++j)
		{
			vv1[i][j] = min(col_max_l[j], col_max_r[j]);
		}
	}
	// 遍历行
	for (int j = 0; j < heightMap[0].size(); ++j)
	{
		vector<int> row_max_l(heightMap.size(), 0);
		//row_max_l.resize(0, heightMap.size());
		vector<int> row_max_r(heightMap.size(), 0);
		//row_max_r.resize(0, heightMap.size());

		int max_l = 0; int max_r = 0;
		for (int i = 0; i < heightMap.size(); ++i)
		{
			max_l = max(heightMap[i][j], max_l);
			row_max_l[i] = max_l;
			max_r = max(heightMap[heightMap.size() - 1 - i][j], max_r);
			row_max_r[heightMap.size() - 1 - i] = max_r;
		}
		for (int i = 0; i < heightMap.size(); ++i)
		{
			// 此处比较时, 已经将遍历列的最小值记录到了vv1中, 所以比较时,要考虑这个值
			vv1[i][j] = min(min(row_max_l[i], row_max_r[i]), vv1[i][j]);
			res += vv1[i][j] - heightMap[i][j];
		}
	}
	return res;
}


int main()
{
	int a[][4] = {
		{ 12, 13, 1, 12 }, { 13, 4, 13, 12 }, { 13, 8, 10, 12 }, { 12, 13, 12, 12 }, { 13, 13, 13, 13 } };

	vector<vector<int>> vv1(5, vector<int>(4, 0));
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			vv1[i][j] = a[i][j];
		}

	}
	trapRainWater(vv1);

	return 0;
}