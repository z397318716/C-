#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
vector<int> Num()
{
	vector<int> v1;
	v1.resize(100001);
	v1[0] = 1;
	v1[1] = 1;
	for (int i = 2; i < 100001; i++)
	{
		v1[i] = (v1[i - 1] + v1[i - 2]) % 1000000;
	}
	return v1;
}

int main()
{
	vector<int> tmp(Num());
	int num;
	while (cin >> num)
	{
		if (num < 29)
			cout << tmp[num] << endl;
		else
			cout << setfill('0') << setw(6) << tmp[num] << endl;
	}


	return 0;
}