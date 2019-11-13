#include<iostream>
#include<vector>
#include<cstdlib>
#define min(a,b) (((a) < (b)) ? (a) : (b))
using namespace std;

// µÝ¹é
int FibNum(int x)
{
	if (x == 0)
		return 0;
	else if (x == 1)
		return 1;
	else
		return FibNum(x - 1) + FibNum(x - 2);
}
// ·ÇµÝ¹é
int FibNum1(int x)
{
	int f1 = 0;
	int f2 = 1;
	int tmp = 0;
	if (x == 0)
	{
		return f1;
	} else if (x == 1)
	{
		return f2;
	} else
	{
		for (int i = 2; i < x; i++)
		{
			tmp = f1 + f2;
			f1 = f2;
			f2 = tmp;
		}
		return f2;
	}
}
int MinStep(int num)
{
	int step = 0;
	int a, b;
	int i = 0;
	if (num < 0)
	{
		return 0 - num;
	}
	while (1)
	{
		a = FibNum1(i);
		b = FibNum1(i + 1);

		if (a < num && b > num)
		{
			step = min(num - a, b - num);
			break;
		}
		i++;
	}
	return step;
}


int main()
{
	int n;
	cin >> n;
	//cout << INT_MAX << endl;
	cout << FibNum1(n);
	//cout << MinStep(n);


	return 0;
}