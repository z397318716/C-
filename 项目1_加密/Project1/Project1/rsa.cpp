#include "rsa.h"


// �õ�����
DataType RSA::GetPrime()
{
	// ����ʱ������
	srand(time(NULL));
	DataType prime;
	while (true)
	{
		prime = rand() % 100 + 2;
		if (IsPrime(prime))
			break;
	}
	return prime;
}
// ���㹫������ n    (e, n)  (d, n)
DataType GetPKey(DataType prime1, DataType prime2)
{
	return prime1 * prime2;
}
// ����ŷ������
DataType GetOrla(DataType prime1, DataType prime2)
{
	return (prime1 - 1) * (prime2 - 1);
}
// ������� e   ��Կ(e, n)
// e������ orla ����, �� e < orla
DataType GetEKey(DataType orla)
{

}
DataType GetDKey(DataType ekey, DataType pkey);		// �õ� d ˽Կ(d, n)
DataType GetGcd(DataType data1, DataType data2);	// ���������������Լ��
// �ж��Ƿ�������
bool IsPrime(DataType data)
{
	// 1. �жϴ�2��ʼ�� data - 1 ��    ����

	// 2. �жϴ�2 �� sqrt(data) -------���Ӷȵ�
	int tmp = sqrt(data);
	for (int i = 2; i < tmp; i++)
	{
		if (data % i == 0)
		{
			return false;
		}
	}
	return true;
}
// �ж������Ƿ���
// �����жϷ�---> �ýϴ������Խ�С��,��������������С������,��ԭ��������������
bool IsCoPrime(DataType data1, DataType data2)
{
	// ʹ data1 > data2
	if (data1 < data2)
	{
		swap(data1, data2);
	}

	if (data1 == 1 && data2 == 1)
		return true;
	else if (data1 < 1 || data2 < 1 || data1 == data2)
		return false;
	else if (data1 == 1 || data2 == 1)		// 1 ���κ�������������
		return true;

	
	DataType tmp = 0;
	while (true)
	{
		

	}
}

// ����
DataType Ecrept(DataType data, DataType ekey, DataType pkey);
// ����
DataType Decrept(DataType data, DataType ekey, DataType pkey);
