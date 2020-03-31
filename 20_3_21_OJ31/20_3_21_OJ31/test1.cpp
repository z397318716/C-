//#include<iostream>
//#include<vector>
//using namespace std;
//vector<int> v1{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//vector<int> v2{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//// 判断是否是闰年
//bool IsYear(int year)
//{
//	if (year / 4 == 0 && year % 100 != 0)
//		return true;
//	else if (year % 400 == 0)
//		return true;
//	return false;
//}
//bool IsPrime(int month)
//{
//	if (month == 1 || month == 4 || month == 6 || month == 8 || month == 9 || month == 10 || month == 12)
//		return false;
//	return true;
//}
//// 同年同月
//int Earn1(vector<int> d1, vector<int> d2)
//{
//	int earn = 0;
//	int tag = 0;
//	// 当前月为素数
//	if (IsPrime(d2[1]))
//	{
//		tag = 1;
//	} else
//	{
//		tag = 2;
//	}
//	earn = tag * (d2[2] - d1[2] + 1);
//	return earn;
//}
//// 同年不同月
//int Earn2(vector<int> d1, vector<int> d2)
//{
//	int earn = 0;
//	int tag = 0;
//	if (d2[1] - d1[1] == 0)
//	{
//		earn = Earn1(d1, d2);
//		return earn;
//	}
//	// 如果该年是闰年
//	if (IsYear(d1[0]))
//	{
//		if (IsPrime(d1[1]))
//		{
//			tag = 1;
//		} else
//		{
//			tag = 2;
//		}
//		earn += tag *(v2[d1[1] - 1] - d1[2] + 1);
//		if (IsPrime(d2[1]))
//		{
//			tag = 1;
//		} else
//		{
//			tag = 2;
//		}
//		earn += tag * (d2[2] - v2[d2[1] - 1] + 1);
//		int a = d1[1] + 1;
//		int b = d2[1];
//		while (a < b)
//		{
//			if (IsPrime(a))
//				tag = 1;
//			else
//				tag = 2;
//			earn += tag * (v2[a - 1]);
//			a++;
//		}
//	} else
//	{
//		if (IsPrime(d1[1]))
//		{
//			tag = 1;
//		} else
//		{
//			tag = 2;
//		}
//		earn += tag *(v1[d1[1] - 1] - d1[2] + 1);
//		if (IsPrime(d2[1]))
//		{
//			tag = 1;
//		} else
//		{
//			tag = 2;
//		}
//		earn += tag * (d2[2] - v1[d2[1] - 1] + 1);
//		int a = d1[1] + 1;
//		int b = d2[1];
//		while (a < b)
//		{
//			if (IsPrime(a))
//				tag = 1;
//			else
//				tag = 2;
//			earn += tag * (v1[a - 1]);
//			a++;
//		}
//	}
//	return earn;
//}
//int Earn(vector<int> d1, vector<int> d2)
//{
//	int earn = 0;
//	int tag = 0;
//	// 如果同一年
//	if (d2[0] - d1[0] == 0)
//	{
//		// 如果同一月
//		if (d2[1] - d1[1] == 0)
//		{
//			earn = Earn1(d1, d2);
//		}
//		// 同年不同月
//		else
//		{
//			earn = Earn2(d1, d2);
//		}
//	}
//	// 如果不同年
//	else
//	{
//		vector<int> tmp1{ d1[0], 12, 31 };
//		vector<int> tmp2{ d2[0], 1, 1 };
//		earn += Earn2(d1, tmp1);
//		earn += Earn2(tmp2, d2);
//		int a = d1[0] + 1;
//		int b = d2[0];
//		while (a < b)
//		{
//			vector<int> tmp3{ a, 1, 1 };
//			vector<int> tmp4{ a, 12, 31 };
//			earn += Earn2(tmp3, tmp4);
//		}
//	}
//	return earn;
//}
//void Print(int earn)
//{
//	cout << earn << endl;
//}
//int main()
//{
//	vector<int> d1;
//	vector<int> d2;
//	vector<int> tmp;
//	int num;
//	int year1, month1, day1;
//	int year2, month2, day2;
//	while (cin>>year1>>month1>>day1>>year2>>month2>>day2)
//	{
//		d1.push_back(year1);
//		d1.push_back(month1);
//		d1.push_back(day1);
//		d2.push_back(year2);
//		d2.push_back(month2);
//		d2.push_back(day2);
//		Print(Earn(d1, d2));
//		d1.clear();
//		d2.clear();
//	}
//	for (auto&e : tmp)
//	{
//		cout << e << endl;
//	}
//
//
//
//
//	return 0;
//}