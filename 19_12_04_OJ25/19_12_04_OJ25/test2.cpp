// ������
// write your code here cpp
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int NumRoot(int n)
{
	//vector<long long> v1;
	int tmp = n;
	int a = 0;
	int root = 0;
	while (tmp)
	{
		a += tmp % 10;
		tmp = tmp / 10;
	}
	while (a > 9)
	{
		a = NumRoot(a);
	}
	return a;
}
int main()
{
	string s1;  // ��Ϊ����������1000λ������string����, ��һ�ξͽ�ÿһλ����������
	
	
	while (cin >> s1)
	{
		int num = 0;
		string::iterator it = s1.begin();
		for (; it != s1.end(); it++)
		{
			num += *it - '0';
		}
		cout << NumRoot(num) << endl;
	}


	return 0;
}