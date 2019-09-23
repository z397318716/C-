#include <iostream>
#include <vector>
using namespace std;


int singleNumber(vector<int> & nums)
{
	int res = 0;
	for (auto &i : nums)
	{
		res ^= i;
	}
	return res;
}

int main2()
{



	return 0;
}