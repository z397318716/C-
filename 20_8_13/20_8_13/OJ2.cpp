/************************************************************************/
/* 力扣200   
	给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

	岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

	此外，你可以假设该网格的四条边均被水包围。

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/number-of-islands
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
/************************************************************************/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
	struct Node{
		int x;
		int y;
	};
	int numIslands(vector<vector<char>>& grid) {
		//vector<vector<bool>> v1(grid.size(), vector<bool>(grid[0].size(), false));
		int res = 0;
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j] == '1')
				{
					res++;
					//v1[i][j] = true;
					// 广度优先遍历
					queue<Node> q1;
					Node tmp{ i, j };
					q1.push(tmp);
					while (!q1.empty())
					{
						Node n1 = q1.front();
						grid[n1.x][n1.y] = '0';
						//v1[n1.x][n1.y] = true;
						Node n2{ n1.x + 1, n1.y };
						Node n3{ n1.x - 1, n1.y };
						Node n4{ n1.x, n1.y + 1 };
						Node n5{ n1.x, n1.y - 1 };
						if (n2.x < grid.size() && grid[n2.x][n2.y] == '1')
						{
							q1.push(n2);
							grid[n2.x][n2.y] = '0';
						}
						if (n3.x >= 0 && grid[n3.x][n3.y] == '1')
						{
							q1.push(n3);
							grid[n3.x][n3.y] = '0';
						}
						if (n4.y < grid[0].size() && grid[n4.x][n4.y] == '1')
						{
							q1.push(n4);
							grid[n4.x][n4.y] = '0';
						}
						if (n5.y >= 0 && grid[n5.x][n5.y] == '1')
						{
							q1.push(n5);
							grid[n5.x][n5.y] = '0';
						}
						q1.pop();
					}
				}
			}
		}
		return res;
	}
};
