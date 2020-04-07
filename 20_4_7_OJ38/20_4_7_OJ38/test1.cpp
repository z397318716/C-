//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//// 使用相同大小的二维数组对遍历过的瓷砖进行标记
//vector<vector<bool>> tmp;
//// 堆栈溢出
//// 思路1:使用深度优先遍历对二维数组进行遍历,对遍历过的黑色瓷砖标记,最终统计标记的个数,即为可以访问到的黑色瓷砖个数
///*
//void Dfs(int is, int js, vector<vector<char>> v1)
//{
//if(is < 0 || js < 0 || is > v1.size() - 1|| js > v1[0].size() - 1)
//return;
//// 向上遍历
//if(v1[is][js] == '.' || v1[is][js] == '@')
//{
//tmp[is][js] = true;
//Dfs(is--,js,v1);
//}
//// 向下遍历
//if(v1[is][js] == '.' || v1[is][js] == '@')
//{
//tmp[is][js] = true;
//Dfs(is++,js,v1);
//}
//// 向左遍历
//if(v1[is][js] == '.' || v1[is][js] == '@')
//{
//tmp[is][js] = true;
//Dfs(is,js--,v1);
//}
//// 向右遍历
//if(v1[is][js] == '.' || v1[is][js] == '@')
//{
//tmp[is][js] = true;
//Dfs(is,js++,v1);
//}
//}
//*/
//// 思路2: 使用广度优先遍历
//struct node
//{
//	int x, y;
//};
//int bx[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
//void Bfs(int is, int js, vector<vector<char>> v1)
//{
//	queue<node> q;
//	int count = 0;
//	node cur;
//	cur.x = is;
//	cur.y = js;
//	q.push(cur);
//	while (!q.empty())
//	{
//		node tmp = q.front();
//		q.pop();
//		count++;
//		for (int i = 0; i < 4; i++)
//		{
//			node next;
//			next.x = tmp.x + bx[i][0];
//			next.y = tmp.y + bx[i][1];
//			if (next.x < v1.size() && next.y < v1[0].size() && next.x >= 0 && next.y >= 0 && v1[next.x][next.y] == '.')
//			{
//				q.push(next);
//				//count++;
//				v1[next.x][next.y] = '#'; // 走过的点不再走
//			}
//		}
//	}
//	cout << count << endl;
//}
//int main()
//{
//	int m, n;
//	while (cin >> m >> n)
//	{
//		tmp.resize(m);
//		for (auto & e : tmp)
//		{
//			e.resize(n, false);
//		}
//		// 定义一个二维数组,表示房间瓷砖
//		vector<vector<char>> v1;
//		// 表示初始点(最初所站瓷砖位置)
//		int is = 0;
//		int js = 0;
//		// 预设数组大小
//		v1.resize(m);
//		for (auto &e : v1)
//		{
//			e.resize(n, 'c');
//		}
//		// 将表示瓷砖颜色的符号填入数组中
//		for (int i = 0; i < m; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				cin >> v1[i][j];
//				if (v1[i][j] == '@')
//				{
//					is = i;
//					js = j;
//				}
//			}
//		}
//		Bfs(is, js, v1);
//	}
//	/*
//	Dfs(is, js, v1);
//	int count = 0;
//	for(int i = 0; i < m; i++)
//	{
//	for(int j = 0; j < n; j++)
//	{
//	if(tmp[i][j])
//	count++;
//	}
//	}
//	cout << count << endl;
//	}
//	*/
//
//
//
//	return 0;
//}