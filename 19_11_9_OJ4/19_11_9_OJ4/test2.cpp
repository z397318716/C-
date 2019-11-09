#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

// 将 32位十进制数m 转换为n进制数 
string Solution(int m, int n)
{
	string s1;
	int tmp = 0;
	char s[16] = { '0','1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	while (m)
	{
		tmp = m % n;
		m = m / n;
		
		s1.push_back(s[tmp]);
	}

	return s1;
}



int main()
{
	int m = 0, n = 0;
	scanf("%ld %d", &m, &n);
	if (n <= 0)
	{
		return 0;
	}
	string s1(Solution(m, n));

	string::reverse_iterator it;
	for (it = s1.rbegin(); it != s1.rend(); it++)
	{
		cout << *it;
	}

	return 0;
}