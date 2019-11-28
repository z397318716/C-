//#include<iostream>
//
//using namespace std;
//
//int Bottles(int n)
//{
//	int num = n;        // 空瓶个数
//	int count = 0;    // 直接可以换到的瓶子数
//	int sum = 0;		// 换到的饮料总数
//	while (num > 1)
//	{
//		// 如果剩两个空瓶, 则向老板借一瓶, 完成最后一瓶的换取
//		if (num == 2)
//		{
//			sum += 1;
//			break;
//		}
//		count = num / 3;
//		sum += count;
//		num = count + num % 3;
//	}
//	return sum;
//}
//
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		if (num == 0)
//			break;
//		cout << Bottles(num) << endl;
//	}
//
//
//	return 0;
//}