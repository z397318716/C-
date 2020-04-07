#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;


int main()
{
	int m, n, k;
	while (cin >> m >> n >> k)
	{
		int x, y;
		// 表示一个点上是否有蘑菇,有则填充1
		vector<vector<int>> v1;
		v1.resize(m + 1);
		for (auto &e : v1)
		{
			e.resize(n + 1);
		}
		// 能够到达每个格子的概率
		vector<vector<double>> d1;
		d1.resize(m + 1);
		for (auto & e : d1)
		{
			e.resize(n + 1);
		}
		while (k--)
		{
			cin >> x >> y;
			v1[x][y] = 1;
		}
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == 1 && j == 1)
				{
					d1[i][j] = 1;
					continue;
				}
				// 某个格子有蘑菇,则经过该格不碰到蘑菇的概率为0
				else if (v1[i][j])
				{
					d1[i][j] = 0;
					continue;
				} else if (i == m && j == n)
				{
					d1[i][j] = d1[i - 1][j] + d1[i][j - 1];
					continue;
				}
				// 处于边界时,向下/向右的概率不在都是0.5了 (例如,处于下边界时,向右遍历的概率为1)
				else if (i == m)
				{
					d1[i][j] = d1[i - 1][j] * 0.5 + d1[i][j - 1];
					continue;
				} else if (j == n)
				{
					d1[i][j] = d1[i][j - 1] * 0.5 + d1[i - 1][j];
					continue;
				} else if (i == 1)
				{
					d1[i][j] = d1[i][j - 1] * 0.5;
					continue;
				} else if (j == 1)
				{
					d1[i][j] = d1[i - 1][j] * 0.5;
				} else
					d1[i][j] = d1[i - 1][j] * 0.5 + d1[i][j - 1] * 0.5;

			}
		}

		cout << fixed << setprecision(2) << d1[m][n] << endl;
	}
	return 0;
}