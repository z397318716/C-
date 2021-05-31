/***********************************************
* ¹é²¢ÅÅÐò
***************/
#include<vector>
#include<algorithm>
using std::vector;
using std::min;
// µÝ¹é°æ
template<class T>
void merge_sort_recursive(vector<T> &arr, vector<T> tmp, int left, int right) {
	if (left >= right)
		return;
	int len = right - left;
	int mid = left + (len >> 1);
	int start1 = left, end1 = mid;
	int start2 = mid + 1, end2 = right;
	merge_sort_recursive(arr, tmp, start1, end1);
	merge_sort_recursive(arr, tmp, start2, end2);
	int k = left;
	while (start1 <= end1 && start2 <= end2) 
		tmp[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
	while (start1 <= end1)
		tmp[k++] = arr[start1++];
	while (start2 <= end2)
		tmp[k++] = arr[start2++];
	for (k = left; k <= right; k++) {
		arr[k] = tmp[k];
	}
}
template<class T>
void merge_sort(vector<T> &arr, const int len) {
	vector<T> tmp(len);
	merge_sort_recursive(arr, tmp, 0, len - 1);
}

// µü´ú°æ
template<typename T>
void merge_sort_nonrecur(vector<T> &arr, const int len) {
	vector<T> tmp1(len);
	for (int i = 1; i < len; i += i) {
		for (int start = 0; start < len; start += i + i) {
			int low = start, mid = min(start + i, len);
			int high = min(start + i + i, len);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				tmp1[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
			while (start1 < end1)
				tmp1[k++] = arr[start1++];
			while (start2 < end2) {
				tmp1[k++] = arr[start2++];
			}
			
		}
		swap(arr, tmp1);
	}
}


int main() {
	vector<int> tmp({ 1,3,5,7,9,2,4,6,8,10,9 });
	merge_sort_nonrecur(tmp, tmp.size());
	merge_sort(tmp, tmp.size());

}