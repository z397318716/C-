//#include<iostream>
//#include<string>
//
//using namespace std;
//string Reverse(string &s1, int l1, int r1)
//{
//	char tmp = ' ';
//	while (l1 <= r1)
//	{
//		tmp = s1[l1];
//		s1[l1] = s1[r1];
//		s1[r1] = tmp;
//		l1++;
//		r1--;
//	}
//	return s1;
//}
//string Reverse_str(string &s1)
//{
//	string str(s1);
//	
//	//string::reverse_iterator it1 = s1.rbegin();
//	string::iterator it1 = s1.begin();
//	string::iterator it2;
//	int l1 = 0;
//	int r1 = 0;
//	
//	for (int i = 0; i < s1.size(); i++, r1++)
//	{
//		if (s1[i] == ' ')
//		{
//			Reverse(s1, l1, r1 - 1);
//			l1 = r1 + 1;
//		}
//		if (i == s1.size() - 1)
//		{
//			Reverse(s1, l1, i);
//		}
//	}
//
//	Reverse(s1, 0, s1.size()-1);
//	return s1;
//}
//
//
//
//
//
//int main()
//{
//	string s1;
//	getline(cin, s1);
//	cout << Reverse_str(s1);
//	
//
//	return 0;
//}