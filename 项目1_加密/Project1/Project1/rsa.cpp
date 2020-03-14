#include "rsa.h"


// 得到素数
DataType RSA::GetPrime()
{
	// 设置时间种子
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
// 计算公共部分 n    (e, n)  (d, n)
DataType GetPKey(DataType prime1, DataType prime2)
{
	return prime1 * prime2;
}
// 计算欧拉函数
DataType GetOrla(DataType prime1, DataType prime2)
{
	return (prime1 - 1) * (prime2 - 1);
}
// 随机产生 e   公钥(e, n)
// e满足与 orla 互质, 且 e < orla
DataType GetEKey(DataType orla)
{

}
DataType GetDKey(DataType ekey, DataType pkey);		// 得到 d 私钥(d, n)
DataType GetGcd(DataType data1, DataType data2);	// 计算两个数的最大公约数
// 判断是否是素数
bool IsPrime(DataType data)
{
	// 1. 判断从2开始到 data - 1 处    遍历

	// 2. 判断从2 到 sqrt(data) -------复杂度低
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
// 判断两数是否互质
// 求商判断法---> 用较大数除以较小数,所得余数如果与较小数互质,则原来的两个数互质
bool IsCoPrime(DataType data1, DataType data2)
{
	// 使 data1 > data2
	if (data1 < data2)
	{
		swap(data1, data2);
	}

	if (data1 == 1 && data2 == 1)
		return true;
	else if (data1 < 1 || data2 < 1 || data1 == data2)
		return false;
	else if (data1 == 1 || data2 == 1)		// 1 与任何正整数都互质
		return true;

	
	DataType tmp = 0;
	while (true)
	{
		

	}
}

// 加密
DataType Ecrept(DataType data, DataType ekey, DataType pkey);
// 解密
DataType Decrept(DataType data, DataType ekey, DataType pkey);
