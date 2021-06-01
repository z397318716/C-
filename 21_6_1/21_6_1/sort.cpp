#include<iostream>
#include<vector>
using std::vector;

template<typename T>
class Sort{ 
public:
	void quick_sort(vector<T>& arr) {
		quick_sort_recursive(arr, 0, arr.size() - 1);
	}
	void merge_sort(vector<T>& arr) {
		vector<T> tmp(arr.size());
		merge_sort_recursive(arr, tmp, 0, arr.size() - 1);
	}
private:
	void quick_sort_recursive(vector<T>& arr, int left, int right) {
		if (left >= right)
			return;
		int i, j, tmp;
		i = left, j = right, tmp = arr[left];
		while (i < j) {
			while (i < j && arr[j] >= tmp)
				j--;
			arr[i] = arr[j];
			while (i < j && arr[i] <= tmp)
				i++;
			arr[j] = arr[i];
		}
		arr[i] = tmp;
		quick_sort_recursive(arr, left, i - 1);
		quick_sort_recursive(arr, i + 1, right);
	}
	void merge_sort_recursive(vector<T>& arr, vector<T>& tmp, int left, int right) {
		if (left >= right)
			return;
		int mid = left + (right - left) / 2;
		int start1 = left, end1 = mid;
		int start2 = mid + 1, end2 = right;
		merge_sort_recursive(arr, tmp, start1, end1);
		merge_sort_recursive(arr, tmp, start2, end2);
		int k = left;
		while (start1 <= end1 && start2 <= end2) {
			tmp[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
		}
		while (start1 <= end1) {
			tmp[k++] = arr[start1++];
		}
		while (start2 <= end2) {
			tmp[k++] = arr[start2++];
		}
		for (k = left; k <= right; ++k) {
			arr[k] = tmp[k];
		}
	}
};


int main() {
	vector<int> arr;
	for (int i = 0; i < 1000; ++i) {
		int tmp = rand() % 1000;
		arr.push_back(tmp);
	}
	Sort<int> A;
	//A.merge_sort(arr);
	A.quick_sort(arr);



	return 0;
}