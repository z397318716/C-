///************************************************************************/
///* ��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����*/  
///* ʱ�����ƣ�1�� �ռ����ƣ�32768K                                         */
///************************************************************************/
//#include<iostream>
//using namespace std;
//
//class Solution
//{
//public:
//
//	// ʱ�临�Ӷ� O(n)
//	// ����:�ݹ� �߼��������·
//	int Sum_Solution(int n)
//	{
//		/*
//		if (n == 1)
//		{
//			return 1;
//		}
//		else
//		{
//			return Sum_Solution(n - 1) + n;
//		}
//		*/
//
//		// ���� �߼������ ��·ԭ�� ���� if �ж�
//		// �߼��������·ԭ��: a && b a�Ľ��Ϊ false ������ڼ������ִ��b
//		int a = 1;
//		(n > 1) && (a = n + Sum_Solution(n - 1));
//		//a = n + Sum_Solution(n - 1);
//		
//		return a;
//		
//	}
//};
//
//template<class T>
//bool IsEqual(T& left, T& right)
//{
//	return left == right;
//}
//void Test()
//{
//	char* p1 = "hello";
//	char* p2 = "world";
//	if (IsEqual(p1, p2))
//		cout << p1 << endl;
//	else
//		cout << p2 << endl;
//}
//
//
//
//int main()
//{
//	/*Solution t1;
//	int a = t1.Sum_Solution(100);
//	cout << a;
//	*/
//	Test();
//	system("pause");
//	return 0;
//}
////��������ƫ�ػ�Ϊָ������
//template <typename T1, typename T2>
//class Data <T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//
