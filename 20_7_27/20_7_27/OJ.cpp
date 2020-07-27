#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rob(vector<int>& nums) {
	// 1个房  只偷这一个
	// 两个房 挑最大的一个
	// 三个房 第一加第三或者 第二(第二 > 第一加第三)
	// k+2个房 前k个房最大加上最后一个最大的, 
	// dp[k + 2] = dp[k] + ,max(nums[k+1], nums[k+2])
	//int res = 0;
	vector<int> dp(nums.size(), 0);
	if (nums.size() == 0)
		return 0;
	else if (nums.size() == 1)
		return nums[0];
	else if (nums.size() == 2)
		return max(nums[0], nums[1]);
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);
	for (int i = 2; i < nums.size(); ++i)
	{
		dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
	}
	//res = dp[nums.size()-1];
	return dp[nums.size() - 1];
}

int main()
{

	vector<int> v1({ 1, 2, 3, 1 });
	cout << rob(v1) << endl;

	return 0;
}