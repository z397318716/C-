//#include<iostream>
//#include<string>
//using namespace std;
//string Add(string num1, string num2)
//{
//	// 大数相加
//	if (num1.size() < num2.size())
//		swap(num1, num2);
//	// 长度补齐
//	num2.insert(0, num1.size() - num2.size(), '0');
//	int tag = 0;
//	string res(num1);
//	for (int i = num1.size() - 1; i >= 0; --i)
//	{
//		tag += (num1[i] - '0') + (num2[i] - '0');
//		res[i] = (tag % 10) + '0';
//		tag /= 10;
//	}
//	if (tag != 0)
//		res.insert(0, 1, tag + '0');
//	return res;
//}
//string multiply(string num1, string num2) {
//	string res("0");
//	if (num1 == "0" || num2 == "0")
//		return res;
//	// 大数相乘
//	if (num1.size() < num2.size())
//		swap(num1, num2);
//	
//
//	for (int i = num1.size() - 1; i >= 0; --i)
//	{
//		int tag = 0;
//		string tmp;
//		for (int j = num2.size() - 1; j >= 0; --j)
//		{
//			tag += (num2[j] - '0') * (num1[i] - '0');
//			tmp.insert(0, 1, tag % 10 + '0');
//			tag /= 10;
//		}
//		if (tag != 0)
//			tmp.insert(0, 1, tag + '0');
//		tmp.append(num1.size()-1-i, '0');
//		res = Add(tmp, res);
//	}
//	return res;
//}
//
//int main()
//{
//	string num1("123");
//	string num2("456");
//	string res;
//	res = multiply(num1, num2);
//
//	cout << res << endl;
//
//	return 0;
//}