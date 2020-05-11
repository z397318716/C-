#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int main()
{
	int n;
	int k;
	while (cin >> n)
	{
		vector<int> v1;
		map<int, int> m1;
		for (int i = 0; i < n; i++)
		{
			int tmp;
			cin >> tmp;
			m1[tmp] = 1;
			v1.push_back(tmp);
		}
		cin >> k;


		auto it = m1.begin();
		for (; it != m1.end() && k != 1; ++it, --k){}
		cout << it->first << endl;
	}
	return 0;
}