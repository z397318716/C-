// 幸运的袋子
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cont = 0;
void ContOne(int, vector<int>, int, int, int); //（1的个数，非1数，当前位数, 和, 积）
int main(void)
{
	int n, numb, OneCont(0);        //OneCont用来记录1的总个数
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
	cont = OneCont - 1; //将纯1数组先计算出来
	if (!list.empty())
	{
		sort(list.begin(), list.end()); //对数组排序
		for (int i = 1; i <= OneCont; i++) ContOne(i, list, 0, i, 1);
	}
	cout << cont << endl;
	return 0;
}
void ContOne(int OneNub, vector<int> list, int nowBit, int sum, int mult)
{
	for (int i = nowBit; i < list.size(); i++) //迭代计算和与积
	{
		sum += list[i], mult *= list[i];
		if (sum <= mult) //如果不符合，回溯至上一位
			break;
		else
			cont++;
		ContOne(OneNub, list, i + 1, sum, mult);
		sum -= list[i], mult /= list[i]; //回到上一位后需要恢复数值
		while (i < list.size() - 1 && list[i] == list[i + 1])
			i++;  //寻找不重复
	}
}