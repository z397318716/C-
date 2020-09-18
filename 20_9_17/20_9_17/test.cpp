//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//
//int main()
//{
//	// 1000-3999
//	string s1("absufdbua1234njiu4100123fs1234");
//	int count = 0;
//	vector<int> v1;
//	int res = 0;
//	char tmp;
//	int flag = 0;
//	for (int i = 0; i < s1.size(); ++i)
//	{
//		if (s1[i] <= '9' && s1[i] >= '0')
//		{
//			count++;
//			tmp = s1[i] - '0';
//			res = res * 10 + tmp;
//			if (count == 4 && i < s1.size() - 1 && (s1[i + 1] < '0' || s1[i + 1] > '9'))
//			{
//				if (res >= 1000 && res <= 3999)
//					v1.push_back(res);
//			}
//			if (count == 4 && i == s1.size() - 1)
//			{
//				if (res >= 1000 && res <= 3999)
//					v1.push_back(res);
//			}
//			
//			
//		}
//		else
//		{
//			tmp = '0';
//			res = 0;
//			count = 0;
//		}
//	}
//
//	for (auto e : v1)
//	{
//		cout << e << endl;
//	}
//	
//
//
//	return 0;
//}