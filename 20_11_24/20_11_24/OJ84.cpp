#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		/*
		超时:
		以当前柱子为中心, 向左右两边遍历其左右边界
		int res = 0;
		for(int i = 0; i < heights.size(); i++){
		int l = i, r = i;
		while(l >= 0 && heights[l] >= heights[i]){
		l--;
		}
		l++;
		while(r < heights.size() && heights[r] >= heights[i]){
		r++;
		}
		r--;
		res = max(res, (r - l + 1) * heights[i]);
		}
		return res;
		*/
		if (heights.size() == 0)
			return 0;
		else if (heights.size() == 1)
			return heights[0];
		int res = 0;
		vector<int> s1;
		heights.insert(heights.begin(), 0);
		heights.push_back(0);
		for (int i = 0; i < heights.size(); i++){
			while (!s1.empty() && heights[s1.back()] > heights[i]){
				int cur = s1.back();
				s1.pop_back();
				int left = s1.back() + 1;
				int right = i - 1;
				res = max(res, (right - left + 1) * heights[cur]);
			}
			s1.push_back(i);
		}
		return res;
	}
};

int main(){


	return 0;
}