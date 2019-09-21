//// 统计单词出现的频率.cpp : 定义控制台应用程序的入口点。
////
//
//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<sstream>
//#include<map>
//using namespace std;
//
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		stringstream ss(str);
//		string s;
//		vector<string>vt;
//		while (getline(ss, s, ' '))
//		{
//			vt.push_back(s);
//		}
//		map<string, int>m1;
//		for (int i = 0; i < vt.size(); i++)
//		{
//			m1[vt[i]] += 1;
//		}
//		map<string, int>::iterator it;
//		cout << "字符串单词总个数 : " << vt.size() << endl;
//		cout << "不同单词的个数 : " << m1.size() << endl;
//		cout << "不同单词出现的频率 :" << endl;
//		for (it = m1.begin(); it != m1.end(); it++)
//		{
//			cout << it->first << ":" << it->second << endl;
//		}
//	}
//	return 0;
//}
