#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long MaxChildArrSum(vector<long long> v1)
{
	long long sum = v1[0];
	long long maxtmp = v1[0];
	for (int i = 0; i < v1.size(); i++)
	{
		/*
		if(maxtmp < 0)
		{
		maxtmp = v1[i];
		}
		else
		{
		maxtmp += v1[i];
		}
		*/
		maxtmp = max(maxtmp + v1[i], v1[i]);
		if (maxtmp > sum)
		{
			sum = maxtmp;
		}
	}
	return sum;
}

int main()
{
	int num = 0;
	long long tmp = 0;
	vector<long long> v1;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> tmp;
		v1.push_back(tmp);
	}

	cout << MaxChildArrSum(v1);


	return 0;
}