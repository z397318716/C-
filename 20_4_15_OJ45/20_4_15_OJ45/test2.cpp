// ţ���� -- �����ֵܵ���   ����ţ��������������
/************************************************************************/
/* ��ȷ����:
��������:
�������ֵ��е��ʵĸ���n��������n��������Ϊ�ֵ䵥�ʡ�
������һ�����ʣ����������ֵ����ֵܵ��ʵĸ���m
����������k

�������:
�������룬������ҵ����ֵܵ��ʵĸ���m
Ȼ��������ҵ����ֵܵ��ʵĵ�k�����ʡ� ���ֺ��ַ���ռһ��, ţ������������Ϊһ�����, ����
************************************************************************/
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

// �ж����������Ƿ����ֵܵ���--->ʹ��map�ж�
bool IsXD(string s1, string s2)
{
	map<char, int> m1;
	map<char, int> m2;

	for (int i = 0; i < s1.size(); i++)
	{
		m1[s1[i]]++;
	}
	for (int i = 0; i < s2.size(); i++)
	{
		m2[s2[i]]++;
	}
	// �ж� s1 ���Ƿ����s2�����е�Ԫ��
	for (int i = 0; i < s2.size(); i++)
	{
		m1[s2[i]]--;
		if (m1[s2[i]] < 0)
			return false;
	}
	// �ж� s2 ���Ƿ����s1�����е�Ԫ��
	for (int i = 0; i < s1.size(); i++)
	{
		m2[s1[i]]--;
		if (m2[s1[i]] < 0)
			return false;
	}
	return true;
}
void dict(vector<string> v1, string find, int n)
{
	vector<string> tmp;
	for (int i = 0; i < v1.size(); i++)
	{
		if (find == v1[i])
			continue;
		if (IsXD(find, v1[i]))
		{
			tmp.push_back(v1[i]);
		}

	}
	sort(tmp.begin(), tmp.end());
	if (!tmp.empty())
	{
		cout << tmp.size() << endl;
		if (n <= tmp.size())
		{
			cout << tmp[n - 1] << endl;
		}
	} else
	{
		cout << 0 << endl;
	}
}

int main()
{
	int num;
	while (cin >> num)
	{
		vector<string> v1;
		v1.resize(num);
		for (int i = 0; i < num; i++)
		{
			cin >> v1[i];
		}
		string find;
		int n;
		cin >> find;
		cin >> n;
		dict(v1, find, n);
	}



	return 0;
}