#include <iostream>
#include <vector>

using namespace std;

void quick_sort_re(vector<int>& arr, int left, int right) {
	if (left >= right)
		return;
	int i = left, j = right, tmp = arr[left];
	while (i < j) {
		while (i < j && arr[j] >= tmp)
			j--;
		arr[i] = arr[j];
		while (i < j && arr[i] <= tmp)
			++i;
		arr[j] = arr[i];
	}
	arr[i] = tmp;

	quick_sort_re(arr, left, i - 1);
	quick_sort_re(arr, i + 1, right);
}

void quick_sort(vector<int>& arr) {
	// ตÝน้---------------------------------------------------------
	quick_sort_re(arr, 0, arr.size() - 1);

}


int main() {

	vector<int> arr({ 1,3,5,7,9,2,4,4,6,5,8,10 });
	quick_sort(arr);
	for (auto e : arr) {
		cout << e << ' ';
	}
	cout << endl;

	return 0;
}