#include<iostream>
#include<string>
#include<vector>

/************************************************************************/
/* 动态规划
	如果已知 n - 1 的情况 那么只考虑在 n-1 的基础上添加变化, 并通过合理的数据结构将每一步的结果都保存下来, 避免重复计算
	n个括号相当于在n-1的基础上新增了一个括号
	n-1情况下的括号要么在这一组新增的括号内部，要么在这一组新增括号的外部（右侧）。
	既然知道了 i<n 的情况，那我们就可以对所有情况进行遍历：

	"(" + 【i=p时所有括号的排列组合】 + ")" + 【i=q时所有括号的排列组合】

	其中 p + q = n-1，且 p q 均为非负整数。

	作者：yuyu-13
	链接：https://leetcode-cn.com/problems/generate-parentheses/solution/zui-jian-dan-yi-dong-de-dong-tai-gui-hua-bu-lun-da/
	来源：力扣（LeetCode）
	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
/************************************************************************/
using namespace std;
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<vector<string>> res;
		res.resize(n + 1);
		res[0] = { "" };
		res[1] = { "()" };
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				for (auto e : res[j])
				{
					for (auto k : res[i - j - 1])
					{
						string str = "(" + e + ")" + k;
						res[i].push_back(str);
					}
				}
			}
		}
		return res[n];
	}
};


int main()
{




	return 0;
}