/************************************************************************/
/* ���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ������磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��                                                                     */
/************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>

using namespace std;

// ����һ:��������--  O(N^2)
// �жϵڶ��������ַ��Ƿ��ڵ�һ����,�ھ�ɾ��
std::string Del_Str(std::string &str1, std::string str2)
{
	for (int i = 0; i < str1.size(); i++)
	{
		for (int j = 0; j < str2.size(); j++)
		{
			if (str2[j] == ' ')
			{
				continue;
			}
			if (str1[i] == str2[j])
			{
				str1.erase(str1.begin() + i);
			}
		}
	}
	return str1;
}

// ������: hashӳ��ķ�ʽ
// ---1.���ڶ����ַ����е��ַ���ӳ�䵽һ�� hashtable��,�����ж�һ���ַ��Ƿ����ַ�����
// ---2.���һ���ַ����ַ�����,��ʹ��ɾ��,��ΪЧ��̫��,-->�������ַ����е��ַ���ӽ��µ��ַ�����,��󷵻�����ַ���
std::string Del_Str_Harsh(string s1, string s2)
{
	//int harshtable[256] = { 0 };
	map<char, int> m1;
	string tmp;
	for (int i = 0; i < s2.size(); i++)
	{
		++m1[s2[i]];
	}
	for (int i = 0; i < s1.size(); i++)
	{
		if (m1[s1[i]] == 0)
		{
			tmp.push_back(s1[i]);
		}
	}
	return tmp;
}

int main()
{
	std::string s1;
	std::string s2;
	getline(cin, s1);
	getline(cin, s2);

	cout << Del_Str_Harsh(s1, s2);

	//Del_Str(s1, s2);
	//cout << s1 << endl;

	return 0;
}