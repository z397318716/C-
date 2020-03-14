#pragma once
#include<iostream>
#include<ctime>
#include<cmath>

using namespace std;

typedef long DataType;
struct Key
{
	DataType _ekey;		//加密密匙
	DataType _dkey;		//解密密匙
	DataType _pkey;		//公钥
};

/*
	1. 随机产生两个不相等的素数
	2. 求这两个素数的乘积 n 
	3. 计算 n 的欧拉函数 f(n)
	4. 随机选择一个整数 e, 满足e与f(n)互质,且 1 < e < f(n)
	5. 计算 e 对 f(n)的模反元素 d  满足: ed % f(n) = 1
	6. 产生公钥(e, n), 产生私钥(d, n)

*/

class RSA
{
private:
	Key _key;
public:
	DataType GetPrime();	// 得到素数
	DataType GetPKey(DataType prime1, DataType prime2);		// 产生公钥
	DataType GetOrla(DataType prime1, DataType prime2);		// 计算欧拉函数
	DataType GetEKey(DataType orla);		// 随机产生 e   公钥(e, n)
	DataType GetDKey(DataType ekey, DataType pkey);		// 得到 d 私钥(d, n)
	DataType GetGcd(DataType data1, DataType data2);	// 计算两个数的最大公约数
	bool IsPrime(DataType data);		// 判断是否是素数
	
	// 加密
	DataType Ecrept(DataType data, DataType ekey, DataType pkey);
	// 解密
	DataType Decrept(DataType data, DataType ekey, DataType pkey);

};