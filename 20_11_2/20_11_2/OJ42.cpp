#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水.

输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。

示例 2：
输入：height = [4,2,0,3,2,5]
输出：9
	提示：
	n == height.length
	0 <= n <= 3 * 104
	0 <= height[i] <= 105
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/trapping-rain-water
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/************************************************************************/
/* 思路：对给定数组同时从左向右和从右向左遍历, 保存遍历过的最大值, (相当于得到了柱状图的左视图和右视图)
将这两组保存的数组相同下标位置处取最小值---表示当前位置能够存储的雨水值                                                                     */
/************************************************************************/
class Solution {
public:
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
};
int main()
{

	return 0;
}