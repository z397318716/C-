#include<iostream>


using namespace std;

int MinNum(int a, int b)
{
	int tmp;
	tmp = a > b ? a : b;
	for (int i = 1; tmp < a * b; tmp = tmp * i, i++)
	{
		if (tmp % a == 0 && tmp % b == 0)
		{
			return tmp;
			//break;
		}  else
			return a * b;
	}
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << INT_MAX << endl;
	//cout << LONGLONG_MAX << endl;
	
	cout << MinNum(a, b);


	return 0;
}