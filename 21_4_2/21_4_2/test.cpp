#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int trap(vector<int>& height) {
    // �������ҵõ�ֱ��ͼ������ͼ, �ڵõ�����ͼ, ÿ��λ��ȡ��Сֵ
    int res = 0;
    if (height.empty())
        return res;
    vector<int> left(height.size(), 0);
    vector<int> right(height.size(), 0);
    int lmax, rmax = 0;
    for (int i = 0; i < height.size(); ++i) {
        // ��������, �õ�ֱ��ͼ������ͼ
        left[i] = max(lmax, height[i]);
        if (lmax < height[i])
            lmax = height[i];
        // ��������,�õ�ֱ��ͼ������ͼ
        right[height.size() - 1 - i] = max(rmax, height[height.size() - 1 - i]);
        if (rmax < height[height.size() - 1 - i])
            rmax = height[height.size() - 1 - i];
    }
    for (int i = 0; i < height.size() - 1; ++i) {
        // ȡ��,����ͼͬһλ�ô�, ��Сֵ���ǾͿ��Դ�ˮ����߸߶�, �ټ�ȥ����ֱ��ͼ��ֵ
        res += (min(left[i], right[i]) - height[i]);
    }
    return res;
}
