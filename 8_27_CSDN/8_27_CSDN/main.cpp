#include <iostream>
using namespace std;
// namespace�ؼ��ֺ�� �����ռ������
namespace N1	// N1Ϊ�����ռ������
{
	// �����ռ��е�����,�ȿ����Ǳ���Ҳ�����Ǻ���
	int a = 20;
	int b = 10;
	int add(int a, int b)
	{
		return a + b;
	}
	// �����ռ�����Ƕ��
	namespace N2
	{
		int n = 1;
		int sub(int a, int b)
		{
			return a - b;
		}
	}
}


using N1::b;
using namespace N2;
int main()
{

	//cout << a << endl;

	cout << N1::a;
	cout << b;
	cout << n;
	return 0;
}