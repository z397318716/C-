///************************************************************************/
///* 3*N 个选手,N个队伍,每队3人,每个选手都有一个水平值 _i
//	每个队伍的水平值等于该队伍队员的第二高水平值
//	输入:第一行为整数N(1-10^5)
//		第二行输入3*N个整数(1-10^10)
//		求如何安排队伍,使得队伍的水平值之和最大,输出该最大值*/
///************************************************************************/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//int Max_Level(int n, vector<int> v1)
//{
//	if (n == 0)
//		return 0;
//	sort(v1.begin(), v1.end());
//	vector<int>::reverse_iterator it = v1.rbegin();
//	size_t max_level = 0;
//	for (int i = 0 ,j = 1; i < n; i++,j += 2)
//	{
//		max_level += *(v1.rbegin()+j);
//	}
//	
//	return max_level;
//}
//
//
//int main()
//{
//	size_t n;
//	cin >> n;
//	//cout << n;
//	vector<int> v1;
//	for (int i = 0; i < 3 * n; i++)
//	{
//		size_t tmp;
//		cin >> tmp;
//		v1.push_back(tmp);
//	}
//	size_t a = Max_Level(n, v1);
//	cout << a;
//	return 0;
//}