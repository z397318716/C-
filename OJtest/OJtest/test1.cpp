///************************************************************************/
///* https://leetcode-cn.com/problems/ransom-note/
//	����� leetcode
///************************************************************************/
//#include<iostream>
//#include<string>
//#include<map>
//#include<unordered_map>
//
//using namespace std;
//
//class Solution {
//public:
//	
//	/*bool canConstruct(string ransomNote, string magazine) {
//		if (ransomNote.empty())
//			return true;
//		int j = 0;
//		for (int i = 0; i < magazine.size(); i++)
//		{
//			if (j == ransomNote.size() - 1 && magazine[i] == ransomNote[j])
//			{
//				return true;
//			}
//			if (magazine[i] == ransomNote[j])
//			{
//				j++;
//			} else
//			{
//				if (j != 0)
//				{
//					j = 0;
//					i--;
//				}  else
//					j = 0;
//			}
//
//		}
//		return false;
//	}*/
//
//	// �������, �����Ϊ�Ǳ���Ҫ��magazine �а�˳���ȡ�� ransomNote
//	//	ʵ���� �ж� magizine�е��ַ��Ƿ���� ���ransomNote
//	// ˼·:ʹ�� unordered_map ����ӳ���ϵ���ж�
//	bool canConstruct(string ransomNote, string magazine) {
//		unordered_map<char, int> m1;
//
//		for (int i = 0; i < magazine.size(); i++)
//		{
//			m1[magazine[i]]++;
//		}
//		for (int i = 0; i < ransomNote.size(); i++)
//		{
//
//			m1[ransomNote[i]]--;
//		}
//		for (auto & i : m1)
//		{
//			if (i.second < 0)
//				return false;
//		}
//		return true;
//	}
//};
//
//int main()
//{
//	Solution A;
//	string a("bg");
//	string b("efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj");
//
//	if (A.canConstruct(a, b))
//	{
//		cout << "true" << endl;
//	}  else
//		cout << "false" << endl;
//
//	return 0;
//}