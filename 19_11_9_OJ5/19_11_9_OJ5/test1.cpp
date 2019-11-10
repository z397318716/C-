//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int InsertStrHuiWen(string s1, string s2)
//{
//	int count = 0;
//
//	//string::iterator first, end;
//	string::reverse_iterator rfirst, rend;
//	for (int i = 0; i < s1.size() + 1; i++)
//	{
//		string tmp1(s1);
//		tmp1.insert(i, s2);
//		rfirst = tmp1.rbegin();
//		rend = tmp1.rend();
//		string tmp2(rfirst, rend);
//		if (tmp1 == tmp2)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//
//
//int main()
//{
//	string s1, s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	cout << InsertStrHuiWen(s1, s2);
//
//	return 0;
//}