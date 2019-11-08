#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int Min_Arr(int n, vector<size_t> v1)
{
	int count = 0;
	bool flag1 = true;
	bool flag2 = true;
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			break;
		}
		if (v1[i] <= v1[i + 1] && flag1 == true)
		{
			flag1 = false;
			if (i != 0)
			{
				flag2 = true;
				//count--;
				continue;
			}
			count += 1;
		}
		if (v1[i] >= v1[i + 1] && flag2 == true)
		{
			flag2 = false;
			if (i != 0)
			{
				flag1 = true;
				//count--;
				continue;
			}
			count += 1;
		}
	}


	return count;
}


int main()
{
	int n = 0;
	vector<size_t> v1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		size_t tmp = 0;
		scanf("%d", &tmp);
		v1.push_back(tmp);
	}
	cout << Min_Arr(n, v1);




	return 0;
}