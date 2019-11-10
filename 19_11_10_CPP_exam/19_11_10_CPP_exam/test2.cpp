#include<iostream>
#include<vector>

using namespace std;


int findElement(vector<int> A, int n, int x) {

	// write code here
	vector<int>::iterator it;
	vector<int> v1(A);
	vector<int> v2;
	for (it = A.begin(); it != A.end() - 1; it++)
	{
		if ((*it) > (*(it + 1)))
		{
			vector<int> tmp1(it + 1, A.end());
			vector<int> tmp2(A.begin(), it);
			v1 = tmp1;
			for (auto &i : tmp2)
			{
				v1.push_back(i);
			}
			break;
		}
	}

	// 二分查找 有序数组v1
	int left = 0;
	int right = v1.size();
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (v1[mid] == x)
		{
			return mid;
		} else if (v1[mid] > x)
		{
			right = mid;
		} else
		{
			left = mid;
		}

	}
}



int main()
{
	vector<int> v1{ 1, 2, 3, 4, 5, 6 };
	cout << findElement(v1, 6, 5);


	return 0;
}