#include <iostream>
#include <vector>
using namespace std;



int main1()
{
	vector<int> v;
	vector<int>::iterator it;
	
	for (int i = 1; i <= 10; i++)
	{
		v.push_back(i);
	}


#if 0 // insert first way

	v.insert(v.begin()+5,6);
#elif 0
	v.insert(v.begin() + 5, 3, 20);
#else
	int a[5] = {12,13,1415,15,16};
	v.insert(v.begin()+5,a+1,a+3);

#endif

	for (auto &i : v)
	{
		cout << i << ' ';
	}




	return 0;
}
