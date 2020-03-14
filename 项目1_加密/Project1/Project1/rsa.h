#pragma once
#include<iostream>
#include<ctime>
#include<cmath>

using namespace std;

typedef long DataType;
struct Key
{
	DataType _ekey;		//�����ܳ�
	DataType _dkey;		//�����ܳ�
	DataType _pkey;		//��Կ
};

/*
	1. ���������������ȵ�����
	2. �������������ĳ˻� n 
	3. ���� n ��ŷ������ f(n)
	4. ���ѡ��һ������ e, ����e��f(n)����,�� 1 < e < f(n)
	5. ���� e �� f(n)��ģ��Ԫ�� d  ����: ed % f(n) = 1
	6. ������Կ(e, n), ����˽Կ(d, n)

*/

class RSA
{
private:
	Key _key;
public:
	DataType GetPrime();	// �õ�����
	DataType GetPKey(DataType prime1, DataType prime2);		// ������Կ
	DataType GetOrla(DataType prime1, DataType prime2);		// ����ŷ������
	DataType GetEKey(DataType orla);		// ������� e   ��Կ(e, n)
	DataType GetDKey(DataType ekey, DataType pkey);		// �õ� d ˽Կ(d, n)
	DataType GetGcd(DataType data1, DataType data2);	// ���������������Լ��
	bool IsPrime(DataType data);		// �ж��Ƿ�������
	
	// ����
	DataType Ecrept(DataType data, DataType ekey, DataType pkey);
	// ����
	DataType Decrept(DataType data, DataType ekey, DataType pkey);

};