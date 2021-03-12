//#include<iostream>
//#include<vector>
//using namespace std;
//
//void QuickSort(vector<int> &v1, int l, int r) {
//	int i = l, j = r;
//	
//	while(i < j) {
//		int tmp = v1[i];
//		
//			while (j > i && v1[j] >= tmp)// 不取等号会死循环
//				--j;
//			v1[i] = v1[j];
//			while (i < j && v1[i] <= tmp)
//				++i;
//			v1[j] = v1[i];
//		
//		v1[i] = tmp;
//		QuickSort(v1, l, i - 1);
//		QuickSort(v1, i + 1, r);
//	}
//}
//
//
//int main() {
//
//	vector<int> v1({ 1,3,5,6,7,8,9,2,3,4,5,6 });
//	QuickSort(v1, 0, v1.size() - 1);
//	for (auto e : v1) {
//		cout << e << ' ';
//	}
//
//	return 0;
//}