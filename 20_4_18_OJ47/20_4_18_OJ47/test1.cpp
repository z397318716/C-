/************************************************************************/
/* m��Ŀ����
�Ѻ�Ա��С��������ü�����������Σ���ĳ��С������һһ����Ϸ�ű��ݣ�����
�ı��ݽ��������ų����ʹ��������ǰ�������ۣ�С�����������˽⵽����Ϸ
���������һ���½�Ŀ������޺�����������Ϸ��Ա���޺����ݡ����ǵ���ȫ���أ�
Ҫ����޺������У�վ��ĳ���˼��ϵ���Ӧ�üȱ��Լ����ֱ��Լ��ݣ�����ȡ�
�ų���Ҫ���ν�Ŀ�е��޺���������ߣ����������ڶ࣬����ͷ����ΰ�����Ա
�����⡣С�������������ܼ򵥣�����ͳ���˲�������޺������ݵ�������Ա
��������أ����Һܿ��ҵ�������޺�������Ա���С�����������Ҳ�õ�������
һ��������ر����ҳ����Ե���������޺����ĸ߶ȣ���ݱ�����Ϸ��Ա����
���Ϊ1��N��
��������:
����һ��������N����ʾ��Ա������
֮��N�У�ÿ�����������ֱ��Ӧ��Ϸ��Ա��ţ����غ���ߡ�
�������:
������m����ʾ�޺����ĸ߶ȡ�
                                                                     */
/************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
bool cmp(pair<int, int> v1, pair<int, int> v2)
{
	if (v1.first < v2.first)
		return true;
	else if (v1.first == v2.first)
	{
		return v1.second > v2.second;
	}
	return false;
}

int main()
{
	int num;
	while (cin >> num)
	{
		int a, w, h;
		vector<pair<int, int>> v1;
		v1.resize(num);
		int id;
		for (int i = 0; i < num; i++)
		{
			cin >> id >> v1[i].first >> v1[i].second;
		}
		sort(v1.begin(), v1.end(), cmp);
		vector<int> dp;
		dp.resize(num, 1);
		int level = 1;
		for (int i = 1; i < num; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (v1[i].second >= v1[j].second)
				{
					dp[i] = max(dp[i], dp[j] + 1);
					level = max(dp[i], level);
				}
			}
		}
		cout << level << endl;

	}
	return 0;
}