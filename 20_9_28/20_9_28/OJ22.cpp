#include<iostream>
#include<string>
#include<vector>

/************************************************************************/
/* ��̬�滮
	�����֪ n - 1 ����� ��ôֻ������ n-1 �Ļ�������ӱ仯, ��ͨ����������ݽṹ��ÿһ���Ľ������������, �����ظ�����
	n�������൱����n-1�Ļ�����������һ������
	n-1����µ�����Ҫô����һ�������������ڲ���Ҫô����һ���������ŵ��ⲿ���Ҳࣩ��
	��Ȼ֪���� i<n ������������ǾͿ��Զ�����������б�����

	"(" + ��i=pʱ�������ŵ�������ϡ� + ")" + ��i=qʱ�������ŵ�������ϡ�

	���� p + q = n-1���� p q ��Ϊ�Ǹ�������

	���ߣ�yuyu-13
	���ӣ�https://leetcode-cn.com/problems/generate-parentheses/solution/zui-jian-dan-yi-dong-de-dong-tai-gui-hua-bu-lun-da/
	��Դ�����ۣ�LeetCode��
	����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������*/
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