#include <iostream>
#include<string>
#include<vector>
using namespace std;


void rotate(vector<int>& nums, int k) {
	/*int n = nums.size();
	k = k % n;

	vector<int> v1((nums.begin() + k + 1), nums.end());
	vector<int> v2(nums.begin(), (nums.begin() + k + 1));
	for (int j = 0; j < v2.size(); j++)
	{
	v1.push_back(v2[j]);
	}*/

	int n = nums.size();
	k = k % n;
	vector<int> v1(nums);
	for (int i = 0; i < k; i++)
	{
		vector<int> v1(v1.begin() + 1, v1.end());
		v1.push_back(nums[i]);
	}
	if (k == 0)
		nums = nums;
	else
		nums = v1;


	/*cout << '[';
	for (int i = 0; i < nums.size(); i++)
	{
	cout << v1[i] << ',';
	}
	cout << ']';*/
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> nums(arr,arr+7);
	rotate(nums, 3);

	/*int num, sum;
	num = sum = 7;
	sum = num++;
	sum++;
	++num;
	cout << sum;*/

	/*int i = 10, j = 10, k = 3;
	k *= i + j;
	cout << k;*/


	return 0;
}