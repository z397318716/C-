//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class MaxGap {
//public:
//	int findMaxGap(vector<int> A, int n) {
//		// write code here
//		vector<int> tmp(A);
//		sort(tmp.begin(), tmp.end());
//		// �ҵ������е����ֵ
//		int max = tmp[n - 1];
//		// ������ֵ��������λ,�Ǽ�ȥĩβֵ��Ϊ�󲿷�max��ȥ�Ҳ���max ������ֵ
//		// ������ֵ������ĩβ,ͬ��
//		if (A[0] == max || A[n - 1] == max)
//		{
//			return abs(A[0] - A[n - 1]);
//		}
//		// ������ֵ������ĩβ, �򷵻� max-A[0] ��max-A[n-1] ������
//		else
//		{
//			return abs(max - A[n - 1]) > abs(max - A[0]) ? abs(max - A[n - 1]) : abs(max - A[0]);
//		}
//
//	}
//};
//
//int main()
//{
//	vector<int> v1{ 2, 7, 3, 1, 1 };
//	MaxGap a;
//	cout << a.findMaxGap(v1, 5) << endl;
//
//
//
//	return 0;
//}