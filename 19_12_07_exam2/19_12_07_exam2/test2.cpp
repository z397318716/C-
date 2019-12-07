#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MaxSum(vector<int> v1)
{
	int maxsum = v1[0];
	int tmp = v1[0];

	for (int i = 0; i < v1.size(); i++)
	{
		tmp = max(tmp + v1[i], v1[i]);
		if (tmp > maxsum)
			maxsum = tmp;
	}
	return maxsum;
}

int main()
{
	int n;
	vector<int> v1;
	cin >> n;
	while (n--)
	{
		int tmp;
		cin >> tmp;
		v1.push_back(tmp);
	}
	cout << MaxSum(v1) << endl;



	return 0;
}