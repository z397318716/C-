#include<iostream>

using namespace std;

int Sum(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else if (n == 3)
		return 2;
	else
	{
		return Sum(n - 1) + Sum(n - 2);
	}
}

int main()
{
	int num;
	while (cin >> num)
	{
		cout << Sum(num) << endl;
	}

	return 0;
}