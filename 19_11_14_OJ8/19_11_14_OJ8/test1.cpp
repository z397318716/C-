//#include<iostream>
//#include<string>
//#include<functional>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//// ◊÷µ‰–Ú≈≈–Ú
//template<class T>
//struct Mycompare1
//{
//	bool operator()(const T& _left, const T& _right) const
//	{
//		return _left < _right;
//	}
//};
//template<class T>
//struct Mycompare2
//{
//	bool operator()(const T&_left, const T&_right)
//	{
//		return _left.size() < _right.size();
//	}
//};
//
//
//string SortWay(vector<string> vs, int n)
//{
//	string way1("lexicographically");
//	string way2("length");
//	string way3("both");
//	string way4("none");
//
//	vector<string> tmp_vs1(vs);
//	vector<string> tmp_vs2(vs);
//	sort(tmp_vs1.begin(),tmp_vs1.end(), Mycompare1<string>());
//
//	sort(tmp_vs2.begin(), tmp_vs2.end(), Mycompare2<string>());
//	
//
//	if (tmp_vs1 == vs && tmp_vs2 == vs)
//	{
//		return way3;
//	}
//	else if (tmp_vs1 == vs)
//	{
//		return way1;
//	}
//	else if (tmp_vs2 == vs)
//	{
//		return way2;
//	}
//	else
//	{
//		return way4;
//	}
//
//}
//
//
//int main()
//{
//	size_t n;
//	cin >> n;
//	vector<string> vs;
//	
//	for (int i = 0; i <= n; i++)
//	{
//		string tmp;
//		getline(cin, tmp);
//		vs.push_back(tmp);
//	}
//
//	cout << SortWay(vs, n);
//	/*string s1("abc");
//	string s2("ad");
//	cout << compare1(s1, s2);
//	*/
//	return 0;
//}