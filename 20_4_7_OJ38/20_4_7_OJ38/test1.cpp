//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//// ʹ����ͬ��С�Ķ�ά����Ա������Ĵ�ש���б��
//vector<vector<bool>> tmp;
//// ��ջ���
//// ˼·1:ʹ��������ȱ����Զ�ά������б���,�Ա������ĺ�ɫ��ש���,����ͳ�Ʊ�ǵĸ���,��Ϊ���Է��ʵ��ĺ�ɫ��ש����
///*
//void Dfs(int is, int js, vector<vector<char>> v1)
//{
//if(is < 0 || js < 0 || is > v1.size() - 1|| js > v1[0].size() - 1)
//return;
//// ���ϱ���
//if(v1[is][js] == '.' || v1[is][js] == '@')
//{
//tmp[is][js] = true;
//Dfs(is--,js,v1);
//}
//// ���±���
//if(v1[is][js] == '.' || v1[is][js] == '@')
//{
//tmp[is][js] = true;
//Dfs(is++,js,v1);
//}
//// �������
//if(v1[is][js] == '.' || v1[is][js] == '@')
//{
//tmp[is][js] = true;
//Dfs(is,js--,v1);
//}
//// ���ұ���
//if(v1[is][js] == '.' || v1[is][js] == '@')
//{
//tmp[is][js] = true;
//Dfs(is,js++,v1);
//}
//}
//*/
//// ˼·2: ʹ�ù�����ȱ���
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
//				v1[next.x][next.y] = '#'; // �߹��ĵ㲻����
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
//		// ����һ����ά����,��ʾ�����ש
//		vector<vector<char>> v1;
//		// ��ʾ��ʼ��(�����վ��שλ��)
//		int is = 0;
//		int js = 0;
//		// Ԥ�������С
//		v1.resize(m);
//		for (auto &e : v1)
//		{
//			e.resize(n, 'c');
//		}
//		// ����ʾ��ש��ɫ�ķ�������������
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