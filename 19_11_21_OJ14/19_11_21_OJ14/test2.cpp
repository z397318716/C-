// ���˵Ĵ���
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cont = 0;
void ContOne(int, vector<int>, int, int, int); //��1�ĸ�������1������ǰλ��, ��, ����
int main(void)
{
	int n, numb, OneCont(0);        //OneCont������¼1���ܸ���
	vector<int> list;
	cin >> n;
	while (n--)
	{
		cin >> numb;
		if (numb > 1)
			list.push_back(numb);
		else
			OneCont++;
	}
	cont = OneCont - 1; //����1�����ȼ������
	if (!list.empty())
	{
		sort(list.begin(), list.end()); //����������
		for (int i = 1; i <= OneCont; i++) ContOne(i, list, 0, i, 1);
	}
	cout << cont << endl;
	return 0;
}
void ContOne(int OneNub, vector<int> list, int nowBit, int sum, int mult)
{
	for (int i = nowBit; i < list.size(); i++) //������������
	{
		sum += list[i], mult *= list[i];
		if (sum <= mult) //��������ϣ���������һλ
			break;
		else
			cont++;
		ContOne(OneNub, list, i + 1, sum, mult);
		sum -= list[i], mult /= list[i]; //�ص���һλ����Ҫ�ָ���ֵ
		while (i < list.size() - 1 && list[i] == list[i + 1])
			i++;  //Ѱ�Ҳ��ظ�
	}
}