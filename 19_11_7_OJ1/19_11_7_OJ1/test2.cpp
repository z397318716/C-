///************************************************************************/
///* ���������ַ���,ɾ����һ���ַ����еڶ����ַ���������Ԫ��                                                                     */
///************************************************************************/
//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//// ��������һ:����
//std::string Del_Str(std::string &str1, std::string str2)
//{
//	for (int i = 0; i < str1.size(); i++)
//	{
//		for (int j = 0; j < str2.size(); j++)
//		{
//			if (str2[j] == ' ')
//			{
//				continue;
//			}
//			if (str1[i] == str2[j])
//			{
//				str1.erase(str1.begin() + i);
//			}
//		}
//	}
//	return str1;
//}
//
//
//int main()
//{
//	std::string s1;
//	std::string s2;
//	getline(cin, s1);
//	getline(cin, s2);
//
//	
//	Del_Str(s1, s2);
//	cout << s1 << endl;
//
//	return 0;
//}