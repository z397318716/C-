//#include<vector>
//#include<iostream>
//#include<cstdlib>
//using std::vector;
//
//template<typename T>
//void merge_sort_recursive(vector<T>& arr, vector<T>& tmp, int left, int right) {
//	if (left >= right)
//		return;
//	int mid = left + (right - left) / 2;
//	int start1 = left, end1 = mid;
//	int start2 = mid + 1, end2 = right;
//	merge_sort_recursive(arr, tmp, start1, end1);
//	merge_sort_recursive(arr, tmp, start2, end2);
//	int k = left;
//	while (start1 <= end1 && start2 <= end2) {
//		tmp[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
//	}
//	while (start1 <= end1) {
//		tmp[k++] = arr[start1++];
//	}
//	while (start2 <= end2) {
//		tmp[k++] = arr[start2++];
//	}
//	for (k = left; k <= right; ++k) {
//		arr[k] = tmp[k];
//	}
//}
//template<class T>
//void merge_sort(vector<T> &arr) {
//	vector<T> tmp(arr.size());
//	merge_sort_recursive(arr, tmp, 0, arr.size() - 1);
//}
//
//
//
//
//int main() {
//	vector<int> arr;
//	for (int i = 0; i < 1000; ++i) {
//		int tmp = rand() % 1000;
//		arr.push_back(tmp);
//	}
//	merge_sort(arr);
//
//
//
//	return 0;
//}