/************************************************************************/
/* ���ӣ�https://www.nowcoder.com/questionTerminal/71d3849a19f04a1591c415964ac148f1
��Դ��ţ����
һֻ���������ÿ���ܲ���һ̥���ӡ�ÿֻС���ӵĳ�������һ�졣 ĳ��������һֻС���ӣ����ʵ�N���Ժ�������õ�����ֻ���ӡ�
��������:
�������ݰ������飬ÿ��һ�У�Ϊ����n(1��n��90)��
�������:
��Ӧ�����n���м�ֻ����(����û��������������)��                                                                     */
/************************************************************************/
#include<iostream>
#include<vector>

using namespace std;

vector<long long> Num()
{
	vector<long long> v1;
	v1.resize(91);
	v1[0] = 1;
	v1[1] = 1;
	for (int i = 2; i < 91; i++)
	{
		v1[i] = v1[i - 1] + v1[i - 2];
	}
	return v1;
}

int main()
{
	int tmp;
	vector<long long> v1(Num());
	while (cin >> tmp)
	{
		cout << v1[tmp] << endl;
	}



	return 0;
}