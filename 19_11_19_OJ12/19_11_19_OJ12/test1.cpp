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
// ��������ֵ��С��˼·:
// ��n��2,���ʼ��v1�б���,��n��ȥÿһ������������,��v1���������,�������,��v1�е������������ǲ�ֵ��С����������
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
// �ж�һ�����Ƿ�Ϊ����
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
// ˼·2:
// ��n/2 ��ʼ������,����������,
// Ȼ�����ж� n��ȥ��������ֵ�Ƿ�Ϊ����,����,���ӡ������ֵ,�����������
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