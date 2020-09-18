#include<iostream>
#include<math.h>

using namespace std;



int main()
{
	int count = 0;
	for (int i = 2; i <= 2020; i += 2)
	{
		if (2020 % i == 0)
		{
			count++;
			cout << i << endl;
		}
			
	}
	cout << "count" << count << endl;


	return 0;
}