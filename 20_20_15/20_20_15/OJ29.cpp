#include<iostream>


using namespace std;
class Solution {
public:
	int divide(int dividend, int divisor) {
		/*
		循环减去除数,记录次数*/
		if (divisor == 1)
			return dividend;
		if (divisor == -1)
		{
			if (dividend == INT_MIN)
				return INT_MAX;
			return dividend * (-1);
		}
		int flag = 1;
		if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
			flag = -1;
		int count = 0;
		long long tmp = abs(dividend);
		long long div = abs(divisor);
		while (tmp >= div)
		{
			tmp = tmp - div;
			count++;
			if (count == INT_MAX)
			{
				break;
			}

		}
		return flag * count;
	}
};


int main()
{

	cout << INT_MAX << endl;
	cout << (int)abs(-2147483648) << endl;

	return 0;
}