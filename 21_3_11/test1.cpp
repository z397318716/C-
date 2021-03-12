//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//void QuickSort(vector<int>& v1, int l, int r) {
//	int i = l, j = r;
//	while (i < j) {
//		int tmp = v1[i];
//		while (i < j && v1[j] >= tmp)
//			--j;
//		v1[i] = v1[j];
//		while (i < j && v1[i] <= tmp)
//			++i;
//		v1[j] = v1[i];
//
//		v1[i] = tmp;
//		QuickSort(v1, l, i - 1);
//		QuickSort(v1, i + 1, r);
//	}
//
//}
//
//int main() {
//	vector<int> v1({ 1,3,5,7,9,0,2,4,6,8,6,5,7 });
//	QuickSort(v1, 0, v1.size()-1);
//	for (auto e : v1) {
//		cout << e << ' ';
//	}
//
//
//	return 0;
//}