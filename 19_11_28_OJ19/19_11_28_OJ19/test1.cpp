//#include<iostream>
//
//using namespace std;
//
//int Bottles(int n)
//{
//	int num = n;        // ��ƿ����
//	int count = 0;    // ֱ�ӿ��Ի�����ƿ����
//	int sum = 0;		// ��������������
//	while (num > 1)
//	{
//		// ���ʣ������ƿ, �����ϰ��һƿ, ������һƿ�Ļ�ȡ
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