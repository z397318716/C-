//�ݹ�˼�룬��n���ռ��˿��Եݹ鵽n-1���ռ�����n-2���ռ���֮��
#include<iostream>
using namespace std;

long int Failrec(int n)
{
	if (n < 2)
		return 0;
	if (n == 2)
		return 1;
	if (n == 3)
		return 2;
	return (n - 1)*(Failrec(n - 1) + Failrec(n - 2));
}

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		cout << Failrec(n) << endl;
	}
	return 0;
}