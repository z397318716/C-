#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>


int main()
{
	int arr[] = { 1, 2, 3, 5, 4, 2, 2, 3 };
	std::set<int> s1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	std::multiset<int> s2(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (auto &e : s1)
	{
		std::cout << e << ' ';
	}
	std::cout << std::endl;
	for (auto &e : s2)
	{
		std::cout << e << ' ';
	}
	std::cout << '\n';
	
	std::map<int, int> m1;
	for (auto &e : s2)
	{
		m1[e]++;
	}
	auto it1 = m1.begin();
	for (auto &e :m1)
	{
		std::cout << e.first << '-' << e.second;
		std::cout << std::endl;
	}
	

	return 0;
}