#include<iostream>
#include<vector>
#include<algorithm>
#include "test.h"
using namespace std;

int trap(vector<int>& height) {
	int res = 0;
	vector<int> max_left(height.size(), 0);
	vector<int> max_right(height.size(), 0);
	int maxl = 0, maxr = 0;
	for (int i = 0; i < height.size(); ++i)
	{
		maxl = max(height[i], maxl);
		max_left[i] = max(height[i], maxl);

		maxr = max(height[height.size() - i - 1], maxr);
		max_right[height.size() - i - 1] = max(height[height.size() - i - 1], maxr);
	}
	for (int i = 0; i < height.size(); ++i)
	{
		res += min(max_left[i], max_right[i]) - height[i];
	}


	return res;


}
