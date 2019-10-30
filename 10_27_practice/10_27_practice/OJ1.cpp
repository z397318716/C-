/************************************************************************/
/* 一个含有n项的数列(n<=2000000)求每一项前的m个数到它这个区间内的最小值       */
/* 若前面的数不足m项则从第一个数开始,若前面没有数则输出0						*/	
/* 输入格式 第一行两个数 n, m第二行,n个正整数为所给的数列*/
/************************************************************************/


// ST算法
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> n_min(int n, int m, vector<int> arr)
{
	vector<int> a1(m,0);
	vector<int>::iterator it = a1.begin();
	int min_num = 0;
	vector<int> v1;
	for (int i = 0; i < arr.size(); i++)
	{
		if (i == 0)
		{
			v1.push_back(0);
			continue;
		}
	
		a1[(i-1)%m] = arr[i - 1];
		if (i < m)
		{
			min_num = *min_element(it, it + i);
		}
		else
		{
		min_num = *min_element(it, it + m);

		}
		v1.push_back(min_num);
	}
	return v1;
}


int main()
{
	int a[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	vector<int> arr(a,a+sizeof(a)/sizeof(a[0]));

	vector<int> v2;
	v2 = n_min(10, 2, arr);

	for (auto &i : v2)
	{
		cout << i << endl;
	}



	return 0;
}