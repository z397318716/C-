#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int trap(vector<int>& height) {
    // 从左向右得到直方图的左视图, 在得到右视图, 每个位置取较小值
    int res = 0;
    if (height.empty())
        return res;
    vector<int> left(height.size(), 0);
    vector<int> right(height.size(), 0);
    int lmax, rmax = 0;
    for (int i = 0; i < height.size(); ++i) {
        // 从左向右, 得到直方图的左视图
        left[i] = max(lmax, height[i]);
        if (lmax < height[i])
            lmax = height[i];
        // 从右向左,得到直方图的右视图
        right[height.size() - 1 - i] = max(rmax, height[height.size() - 1 - i]);
        if (rmax < height[height.size() - 1 - i])
            rmax = height[height.size() - 1 - i];
    }
    for (int i = 0; i < height.size() - 1; ++i) {
        // 取左,右视图同一位置处, 较小值就是就可以储水的最高高度, 再减去构成直方图的值
        res += (min(left[i], right[i]) - height[i]);
    }
    return res;
}
