///************************************************************************/
///* 3*N ��ѡ��,N������,ÿ��3��,ÿ��ѡ�ֶ���һ��ˮƽֵ _i
//	ÿ�������ˮƽֵ���ڸö����Ա�ĵڶ���ˮƽֵ
//	����:��һ��Ϊ����N(1-10^5)
//		�ڶ�������3*N������(1-10^10)
//		����ΰ��Ŷ���,ʹ�ö����ˮƽֵ֮�����,��������ֵ*/
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