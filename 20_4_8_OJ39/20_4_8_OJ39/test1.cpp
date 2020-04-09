#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;



int main()
{
	string s1, s2;
	long long len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2)
	{
		int sum = 0;
		int l1 = s1.size();
		int l2 = s2.size();
		int k = 0;
		if (l1 < len2)
			s1.append(len2 - l1, 'a' - 1);
		if (l2 < len2)
			s2.append(len2 - l2, 'z' + 1);
		// �ҵ�һ������ȵ���ĸ���±�
		while (s1[k] == s2[k])
			k++;
		// ���� s[k] > s1[k] && s[k] < s2[k] �Ĳ���
		for (int i = len1 - 1; i < len2; i++)
		{
			if (i == k)
			{
				if (k == len1 - 1 && k == len2 - 1)
					sum += s1[k] - s1[k] - 1;
				else
					sum += s2[k] - s1[k];
			} else
				sum += (s2[k] - s1[k] - 1)*pow(26, i - k);
		}
		k += 1;
		// ���� s[k] == s1[k] �� s[k] == s2[k] �����
		for (int i = len1; i <= len2; i++)
		{
			for (int j = k; j < i; j++)
			{
				sum += ('z' - s1[j])*pow(26, i - j - 1);
			}
			for (int j = k; j < i; j++)
			{
				sum += (s2[j] - 'a')*pow(26, i - j - 1);
			}
		}
		cout << sum << endl;
	}




	return 0;
}