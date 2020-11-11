#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> res;
		if (intervals.empty())
			return res;
		sort(intervals.begin(), intervals.end());
		vector<int> tmp;
		vector<bool> flag(intervals.size(), false);
		for (int i = 0; i < intervals.size(); ++i){
			if (flag[i])
				continue;
			tmp = intervals[i];
			for (int j = 0; j < intervals.size(); ++j){
				if (j == i)
					continue;

				// 如果有重合区域, 确定右边界
				if (tmp[1] >= intervals[j][0]){
					tmp[1] = max(tmp[1], intervals[j][1]);
					flag[j] = true;
				}
			}
			res.push_back(tmp);
			//tmp.clear();
		}
		return res;
	}
};
int main(){
	vector<vector<int>> tmp({ { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } });
	vector<vector<int>> res;
	Solution A;
	res = A.merge(tmp);

	return 0;
}