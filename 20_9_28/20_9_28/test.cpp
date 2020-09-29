//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int fun(int score[], int m, int below[])
//{
//	int aver = 0;
//	int sum = 0;
//	//int size = sizeof(score) / sizeof(score[0]);
//	for (int i = 0; i < m; ++i)
//	{
//		sum += score[i];
//	}
//	aver = sum / m;
//	
//	below = (int*)malloc(sizeof(int)*m);
//	int count = 0;
//	for (int i = 0; i < m; ++i)
//	{
//		if (score[i] < aver)
//		{
//			below[count++] = score[i];
//		}
//	}
//	return count;
//}
//
//float fun1(int n)
//{
//	float s = 1.0;
//	int x = 0;
//	for (int i = 2; i <= n; i++)
//	{
//		for (int j = i; j > 0; j--)
//		{
//			x += j;
//		}
//		s += 1 / (float)x;
//		x = 0;
//	}
//	return s;
//}
//int main()
//{
//	int score[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
//	int below[] = {0};
//	cout << fun(score, 9, below);
//	cout << fun1(11);
//
//	return 0;
//}