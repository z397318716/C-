#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ.

���룺height = [0,1,0,2,1,0,1,3,2,1,2,1]
�����6
���ͣ������������� [0,1,0,2,1,0,1,3,2,1,2,1] ��ʾ�ĸ߶�ͼ������������£����Խ� 6 ����λ����ˮ����ɫ���ֱ�ʾ��ˮ����

ʾ�� 2��
���룺height = [4,2,0,3,2,5]
�����9
	��ʾ��
	n == height.length
	0 <= n <= 3 * 104
	0 <= height[i] <= 105
 ��Դ�����ۣ�LeetCode��
 ���ӣ�https://leetcode-cn.com/problems/trapping-rain-water
 ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


/************************************************************************/
/* ˼·���Ը�������ͬʱ�������Һʹ����������, ��������������ֵ, (�൱�ڵõ�����״ͼ������ͼ������ͼ)
�������鱣���������ͬ�±�λ�ô�ȡ��Сֵ---��ʾ��ǰλ���ܹ��洢����ˮֵ                                                                     */
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