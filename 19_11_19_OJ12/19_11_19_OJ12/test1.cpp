#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
vector<int> SuNum(int n)
{
vector<int> v1;
for (int i = 2; i <= n; i++)
{
int flag = 0;
for (int j = 2; j < i; j++)
{
if (i % j == 0)
{
flag = 1;
}
}
if (flag == 0)
{
v1.push_back(i);
}
}
return v1;
}
*/
/*
void PairNum(int n)
{
vector<int> v1;
v1 = SuNum(n);
// 找两个差值最小的思路:
// 给n除2,向后开始在v1中遍历,用n减去每一个遍历到的数,在v1中找这个数,如果存在,则v1中的这两个数就是差值最小的两个素数
int tmp = n / 2;
vector<int>::iterator it1;
vector<int>::iterator it2;
int a, b;
for (int i = tmp; i < n; i++)
{
it1 = find(v1.begin(), v1.end(), i);
if (it1 != v1.end())
{
b = *it1;
a = n - b;
it2 = find(v1.begin(), v1.end(), a);
if (it2 != v1.end())
{
cout << a << endl;
cout << b << endl;
break;
}
}

}
}
*/
// 判断一个数是否为素数
bool IfSu(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
// 思路2:
// 从n/2 开始向后遍历,遍历到素数,
// 然后在判断 n减去该素数的值是否为素数,若是,则打印这两个值,否则继续遍历
void PairNum(int n)
{
	//int tmp = n / 2;
	int a, b;
	for (int i = n / 2; i < n; i++)
	{
		if (IfSu(i) && IfSu(n - i))
		{
			a = n - i;
			b = i;
			break;
		}
	}
	cout << a << endl;
	cout << b << endl;
}


int main()
{
	int num;
	cin >> num;
	PairNum(num);

	return 0;
}