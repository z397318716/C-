#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int trapRainWater(vector<vector<int>>& heightMap) {
	/*
	����,�� ����ˮ1  ˼·��ͬ, ֻ����1�Ļ�����
	���к��ж����б���, �ҳ�ÿһ����λ���ϴ洢ˮ�ĸ߶�
	*/
	int res = 0;
	vector<vector<int>> vv1(heightMap.size(),
		vector<int>(heightMap[0].size(), 0));





	// ������, ��¼ÿһ���� ÿ��λ�� ��Ӧ����С��ˮ�߶�
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
	// ������
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
			// �˴��Ƚ�ʱ, �Ѿ��������е���Сֵ��¼����vv1��, ���ԱȽ�ʱ,Ҫ�������ֵ
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